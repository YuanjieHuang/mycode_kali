#! /usr/bin/python

# autotest: doctest
# autotest: doctest.testfile:test/upgrade_prep.doctest

###############################################################################
# Copyright (c) 2008-2010, 2017 VMware, Inc.
#
# This file is part of Weasel.
#
# Weasel is distributed in the hope that it will be useful, but WITHOUT
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
# FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
# version 2 for more details.
#
# You should have received a copy of the GNU General Public License along with
# this program; if not, write to the Free Software Foundation, Inc., 51
# Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
#

'''
Prepare an ESX / ESXi host for upgrade.

Set up the host so that it is ready to boot directly into the ESXi installer
without requiring user intervention. This will unpack the ESXi ISO, extract
any necessary files and will configure the bootloader.
'''

from __future__ import print_function

import datetime
import os
import re
import sys
import stat
import shutil
import logging
import optparse
import socket
import subprocess
try:
    import upgrade_precheck
except ImportError:
    try:
        import precheck as upgrade_precheck
    except ImportError:
        import PRECHECK as upgrade_precheck

# Switch for single reboot upgrade, value set in build time
USE_PROFILE_UPDATE = True

# Directory where this file is running. Script expects data files, helper
# utilities to exist here.
try:
    # On Python 2.2 (ESX 3.5), __file__ isn't defined for the main script.
    SCRIPT_DIR = os.path.abspath(os.path.dirname(__file__))
except NameError:
    SCRIPT_DIR = os.path.dirname(os.path.abspath(sys.argv[0]))

# Allow us to ship extra Python modules in a zip file.
sys.path.insert(0, os.path.join(SCRIPT_DIR, "esximage.zip"))

from vmware.esximage import Database, Errors, Vib
from vmware.esximage.AcceptanceLevels import CERTSDIRS
from vmware.esximage.Utils import HashedStream, XmlUtils

#logging.basicConfig(level=logging.DEBUG)
logging.basicConfig()
log = logging.getLogger()
log.setLevel(logging.INFO)

systemProbe = None
pathToIsoinfo = '/tmp/isoinfo'
pathToISO = '/boot/upgrade_scratch'
ESXIMG_DBTAR_NAME = "imgdb.tgz"
lockerPkgDir = '/locker/packages'
# The version of ESXi after which we will try and pull forward third party vibs
# when doing a VUM upgrade

# certificates and revoke list for vib verification
CERT_FILES = ['vmware.cert', 'vmpartner.cert']
CRL_FILES = ['vmpartner.crl']

class PrepException(Exception): pass

options = None # optparse options

GRUB_CONF_ENTRY = '''\
title Upgrade from ESX to ESXi
  rootnoverify (hd0,0)
  makeactive
  chainloader +1
'''

#------------------------------------------------------------------------------
def findUpgradeScratchPath(isoPath):
    '''isoPath is the path that the file is found on inside the ISO'''
    isoPath = isoPath.lstrip('/')

    # Depending on how the ISO was made or extracted, the case could have
    # been mangled.  Try changing the case before giving up.
    origPath = os.path.join(pathToISO, isoPath)
    upperPath = os.path.join(pathToISO, isoPath.upper())
    lowerPath = os.path.join(pathToISO, isoPath.lower())
    localPath = origPath

    for path in [origPath, upperPath, lowerPath]:
        if os.path.exists(path):
            localPath = path
            break
    if localPath != origPath:
        log.info('%s could not be found, trying %s' % (origPath, localPath))
    return localPath

#------------------------------------------------------------------------------
def run(cmdTuple):
    log.info('calling %s' % ' '.join(cmdTuple))
    p = subprocess.Popen(cmdTuple,
                         stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = p.communicate()
    if p.returncode != 0:
        raise Exception('%s failed. (%s)' % (cmdTuple[0], stderr))

#------------------------------------------------------------------------------
def getoutput(cmd):
    process = subprocess.Popen(cmd, shell=True,
                               stdout=subprocess.PIPE,
                               stderr=sys.stderr)
    output, erroutput = process.communicate()
    # decode bytes in python3
    if sys.version_info[0] >= 3:
      output = output.decode()
    return output

#------------------------------------------------------------------------------
def matchOutput(output, pattern):
    for line in output.splitlines():
        match = pattern.search(line)
        if match:
            return match
    return None

#------------------------------------------------------------------------------
def parseVswitchReport():
    ''' return list of vswitches and their uplinks as follows:
    INFO:root:switches: [[('VM Network', ['vmnic0']), ('Management Network', ['vmnic0', 'vmnic2'])]]
    '''
    cmd = 'esxcfg-vswitch -l'
    output = getoutput(cmd)
    lines = output.splitlines()
    inReport = False
    hdr = re.compile(r"^(Switch\sName|DVS\sName)\s+.*$")
    portDetail = re.compile(r'^(.*)(\s+\d+\s+\d+\s+)(.*)$')
    portEntries = []
    switches = []
    skipNext = False
    for line in lines:
        if skipNext:
            skipNext = False
            continue
        result = hdr.match(line)
        if result:
            if not inReport:
                inReport = True
            else:
                switches.append(portEntries)
                portEntries = []
            # portDetail matches vswitch detail line that follows the header
            # skip that line to avoid matching it
            skipNext = True
        else:
            if inReport:
                fields = portDetail.split(line)
                if fields and len(fields) >= 5:
                    ifName = fields[1].strip()
                    uplinks = fields[3].strip()
                    if ifName != 'Uplinks' and ifName != 'Client':
                        uplinks = uplinks.split(",") # PR 674888
                        uplinks = [item.strip() for item in uplinks]
                        portEntries.append((ifName, uplinks))
    if portEntries:
        switches.append(portEntries)
    return switches

#------------------------------------------------------------------------------
def getUplinkFromVswitch(device, portgroupName):
    '''Find the uplink associated with the given portgroup Name
    If there are multiple uplinks for the specified portgroup only the first
    uplink will be returned. This function will properly return the uplink
    information in a DVS configuration as well'''
    theSwitch = None
    switches = parseVswitchReport()
    log.info("switches: %s" % switches)
    log.info('device="%s" portgroup="%s"' % (device, portgroupName))
    for vswitch in switches: # find the relevant vswitch
        for port in vswitch:
            log.info('port[0] = %s port[1] = %s' % (port[0], port[1]))
            if port[0] == portgroupName or port[1][0] == device:
                theSwitch = vswitch
                log.info('match found')
                break
    if theSwitch:
        for port in theSwitch:
            for nic in port[1]:
               if nic.startswith('vmnic'):
                  return nic
        log.error("No pnic found in '%s'" % port[1])
        return None
    else:
        log.error("Uplink for switch containing %s(%s) is incomplete." % (device, portgroupName))
    return None


#------------------------------------------------------------------------------
def getMacAddressForUplink(uplinkName):
    cmd = 'esxcfg-nics -l'
    pattern = re.compile(r'%s.*(..:..:..:..:..:..)' % uplinkName)
    output = getoutput(cmd)
    match = matchOutput(output, pattern)
    if not match:
        log.error('No mac address found for uplink: %s' % uplinkName)
        return None
    else:
        return match.group(1)


#------------------------------------------------------------------------------
def findMacFromInterface(ifName, portgroupName):
    '''Find the mac address associated with the specified ifName and portgroup name.'''

    uplinkName = getUplinkFromVswitch(ifName.strip(), portgroupName.strip())
    if not uplinkName:
       log.warn('Failed to find uplink for specified portgroup: %s' % portgroupName)
       return None

    macAddress = getMacAddressForUplink(uplinkName)
    if not macAddress:
       log.warn('Failed to find mac address for specified uplink: %s' % uplinkName)
       return None

    return macAddress

#------------------------------------------------------------------------------
def GetIpAddress(ipstr):
    '''
    convert ip string to packed binary representation or raises socket.error
    '''
    if ':' in ipstr:
        af = socket.AF_INET6
    else:
        af = socket.AF_INET
    return socket.inet_pton(af, ipstr)

#------------------------------------------------------------------------------
def findMacAddress():
    '''When the host reboots, it needs to resume communication with VUM.  For
    that to happen, the same physical NIC should be brought up, with the
    same IP address
    '''
    examined = dict()
    matchIP = GetIpAddress(options.ip)
    cmd = 'esxcfg-vmknic -l'
    ipv4Pattern = re.compile(r'''
              (?P<name>vmk\d+)
              \s+(?P<pgName>\S.*\S*) # pgName could potentially be the dvPort name
              \s*IPv4
              \s+(?P<ip>\d+\.\d+\.\d+\.\d+)
              \s+(?P<netmask>\d+\.\d+\.\d+\.\d+)
              \s+.*
              \s+(?P<mac>..:..:..:..:..:..)
              \s+.*
              \s+true                 # only find the enabled vmknics
              \s+(?P<type>\S+)
              ''', re.VERBOSE)
    ipv6Pattern = re.compile(r'''
              (?P<name>vmk\d+)
              \s+(?P<pgName>\S.*\S*) # pgName could potentially be the dvPort name
              \s*IPv6
              \s+(?P<ip>\S+)
              \s+(?P<netmask>\S+)
              \s+.*
              \s+(?P<mac>..:..:..:..:..:..)
              \s+.*
              \s+true                 # only find the enabled vmknics
              \s+(?P<type>\S+)
              ''', re.VERBOSE)
    output = getoutput(cmd)
    nicDict = None
    matches = 0
    for line in output.splitlines():
        match = ipv4Pattern.search(line)
        if match:
            matches += 1
            matchDict = match.groupdict()
            if matchDict and GetIpAddress(matchDict['ip']) == matchIP:
                nicDict = matchDict
                break
            else:
                examined[matchDict['ip']] = matchDict['name']
        # Did't find an ipv4 match, maybe it was ipv6
        match = ipv6Pattern.search(line)
        if match:
            matches += 1
            matchDict = match.groupdict()
            if matchDict and GetIpAddress(matchDict['ip']) == matchIP:
                nicDict = matchDict
                break
            else:
                examined[matchDict['ip']] = matchDict['name']
    if not nicDict:
        raise Exception('%s found no NIC matching IP address %s. matches: %d, examined: %s'
                        % (cmd, options.ip, matches, str(examined)))
    log.info('found name=%s pgName=%s' % (nicDict['name'], nicDict['pgName']))
    nicDict['mac'] = findMacFromInterface(nicDict['name'], nicDict['pgName'])
    if not nicDict['mac']:
        raise Exception('MAC address could not be discovered')
    options.mac = nicDict['mac']
    log.info('using mac %s' % options.mac)
    # If the user supplied a netmask on the cmd line, it overrides
    if not (hasattr(options, 'netmask') and options.netmask):
        options.netmask = nicDict['netmask']

#------------------------------------------------------------------------------
def getIsoFileStream(isoPath):
    '''isoPath is the path that the file is found on inside the ISO'''
    localPath = findUpgradeScratchPath(isoPath)
    return open(localPath)

def _getIsoFileStream(fpath):
    '''To figure out which files need to be copied, read the isolinux.cfg
    file from the ISO.
    '''
    for path in [pathToIsoinfo, pathToISO]:
        if not os.path.exists(path):
            # we can't count on subprocess.Popen() to error out properly
            # because of the "unknown encoding: string-escape" bug on old
            # versions of ESXi (if curious, set pathToISO='/foo/bar')
            raise Exception('No such file %s' % path)
    os.chmod(pathToIsoinfo, stat.S_IRWXU) # make sure it's executable
    if not fpath.startswith('/'):
        log.warn('file path %s should start with /' % fpath)
        fpath = '/' + fpath
    fpath = fpath.upper() # isoinfo only takes uppercase names
    if '.' not in fpath:
        fpath += '.' # isoinfo appends . to filenames without one
    fpath += ';1' # TODO: there may be a flag to may make this unneeded
    cmdTuple = pathToIsoinfo, '-i', pathToISO, '-x', fpath
    devnull = open('/dev/null', 'w')
    log.info('calling %s' % str(cmdTuple))
    try:
        process = subprocess.Popen(cmdTuple,
                                   stdout=subprocess.PIPE,
                                   stderr=devnull)
    except Exception as ex:
        # if the exception happened during the child process, the traceback
        # will be hidden unless we manually print it out.
        if hasattr(ex, 'child_traceback'):
            log.error(ex.child_traceback)
        raise

    return process.stdout
    # Note: I'm trusting the garbage collector to close the open file

#------------------------------------------------------------------------------
def copyFromUpgradeScratch(isoPath, destPath):
    '''isoPath is the path that the file is found on inside the ISO.'''
    log.info('Writing ISO file %s to %s' % (isoPath, destPath))
    localPath = findUpgradeScratchPath(isoPath)
    try:
        shutil.copy(localPath, destPath)
    except Exception as ex:
        msg = ('Copy %s to %s failed (%s). Check that file exists on the ISO.'
               % (localPath, destPath, str(ex)))
        log.error(msg)
        raise Exception(msg)

#------------------------------------------------------------------------------
def copyFromIso(isoPath, destPath):
    log.info('writing iso file %s to %s' % (isoPath, destPath))
    fstream = getIsoFileStream(isoPath)
    outfile = open(destPath, 'w')
    shutil.copyfileobj(fstream, outfile)
    outfile.close()
    if os.path.getsize(destPath) == 0:
        msg = ('Copy of %s to %s failed. Check that file exists on the ISO.'
               % (isoPath, destPath))
        log.error(msg)
        raise Exception(msg)

#------------------------------------------------------------------------------
def parseBootCfg(fn):
    '''Given a filename that should be the lines of a boot.cfg
    file, return a list of filenames from the "kernel" and "modules" lines
    '''
    kernelPattern = re.compile(r'^\s*kernel\s*=\s*(\S+)', re.IGNORECASE)
    kernelArg = ''
    modulesPattern = re.compile(r'^\s*modules\s*=\s*(\S.*)', re.IGNORECASE)
    modulesTail = ''

    stream = getIsoFileStream(fn)

    for line in stream:
        line = line.strip()
        kernelMatch = kernelPattern.search(line)
        if kernelMatch:
            kernelArg = kernelMatch.group(1)
            kernelArg = kernelArg.strip()
        modulesMatch = modulesPattern.search(line)
        if modulesMatch:
            modulesTail = modulesMatch.group(1)

    log.info('kernel "%s", modules "%s"' % (kernelArg, modulesTail))

    modulesArgs = []
    for arg in modulesTail.split(' --- '):
        arg = arg.strip()
        arg = arg.split(' ', 1)[0]
        modulesArgs.append(arg) # Your head just exploded

    if not (kernelArg and modulesArgs):
        raise Exception('Failure parsing the boot.cfg file')
    return [kernelArg] + modulesArgs

#------------------------------------------------------------------------------
def parseIsoLinuxCfg(fn):
    '''Given a file name that should be an isolinux.cfg
    file, return a list of filenames from the "kernel" and "append" lines
    '''
    kernelPattern = re.compile(r'^\s*kernel\s+(\S+)', re.IGNORECASE)
    kernelArg = ''
    appendPattern = re.compile(r'^\s*append\s+(\S.*)', re.IGNORECASE)
    appendTail = ''

    stream = getIsoFileStream(fn)

    for line in stream:
        line = line.strip()
        kernelMatch = kernelPattern.search(line)
        if kernelMatch:
            kernelArg = kernelMatch.group(1)
            kernelArg = kernelArg.strip()
        appendMatch = appendPattern.search(line)
        if appendMatch:
            appendTail = appendMatch.group(1)

    log.info('kernel "%s", append "%s"' % (kernelArg, appendTail))

    appendArgs = []
    for arg in appendTail.split(' --- '):
        arg = arg.strip()
        words = arg.split(' ', 1)
        if len(words) == 2:
            appendArgs.extend(parseBootCfg('/' + words[1]))
        else:
            appendArgs.append(words[0])

    if not (kernelArg and appendArgs):
        raise Exception('Failure parsing the isolinux.cfg file')
    return [kernelArg] + appendArgs

#------------------------------------------------------------------------------
def parseFeatureStates(bootCfgIsoPath):
    ''' Parses feature switch kernel opts from ISO's boot.cfg
    '''
    kerneloptsPattern = re.compile(r'^\s*kernelopt\s*=\s*(\S.*)', re.IGNORECASE)
    featureStates = []
    stream = getIsoFileStream(bootCfgIsoPath)
    for line in stream:
        line = line.strip()
        kerneloptsMatch = kerneloptsPattern.search(line)
        if kerneloptsMatch:
            kernelopts = kerneloptsMatch.group(1).split()
            featureStates = [k.strip() for k in kernelopts
                             if 'FeatureState.' in k]
    log.info('Feature States: %s' % str(featureStates))
    return featureStates

def makeKernelArgs():
    if not (hasattr(options, 'mac') and options.mac):
        findMacAddress()
    if not (hasattr(options, 'ip') and options.ip):
        raise Exception('Need IP address')
    args = 'ks=file:///ks.cfg netdevice=%s ip=%s netmask=%s' %\
           (options.mac, options.ip, options.netmask)
    if (hasattr(options, 'gateway') and options.gateway):
        args += ' gateway=%s' % options.gateway
    args += ' ' + ' '.join(parseFeatureStates('/boot.cfg'))
    return args.strip()

#------------------------------------------------------------------------------
def addSpecialAppendArgs(appendLine, extraArgs):
    '''
    Input:
     appendLine='a --- b --- c', extraArgs='netdevice=X ip=Y'
    Output:
    'a netdevice=X ip=Y --- b --- c --- upgrade.tgz'
    '''
    if '---' not in appendLine:
        log.warn('No "---" found in append line')
        return '%s %s' % (appendLine, extraArgs)
    head, tail = appendLine.split(' --- ', 1)
    upgradeTgz = 'upgrade.tgz'
    return '%s %s --- %s --- %s' % (head, extraArgs, tail, upgradeTgz)


#------------------------------------------------------------------------------
def makeKickstart(savebootbank="/altbootbank"):
    '''Make a new ks.cfg'''
    try:
        realpath = os.path.realpath(savebootbank)
    except NameError as ex:
        # if there's not altbootbank, upgrade_prep won't
        # do anything useful in this case
        raise PrepException("Can't find altbootbank")

    bootuuid = os.path.basename(realpath)
    extraArgs = '--savebootbank=' + bootuuid

    if options.ignoreprereqwarnings:
        extraArgs += ' --ignoreprereqwarnings'

    if options.ignoreprereqerrors:
        extraArgs += ' --ignoreprereqerrors'

    contents = ('# automatically created by upgrade_prep.py'
                '\naccepteula'
                '\nupgrade --diskBootedFrom %s'
                '\n' % (extraArgs)
               )
    contents = contents + ('\nreboot\n')
    return contents

#------------------------------------------------------------------------------
def makeUpgradeVgz(dest):
    log.info('creating the ks.cfg and upgrade.tgz files')
    contents = makeKickstart(os.path.dirname(dest))
    fp = open('/tmp/ks.cfg', 'w')
    fp.write(contents)
    fp.close()
    cmdList = ['/bin/tar']
    cmdList += ['-C', '/tmp', '-c', '-z',
                'ks.cfg', '-f', dest]
    run(cmdList)

#------------------------------------------------------------------------------
def makeUseroptsGz(bootbankRoot, newUseroptsDir):
    import gzip
    path = os.path.join(bootbankRoot, 'useropts.gz')
    newOpts = makeKernelArgs()
    log.info('Adding new options to %s (%s)' % (path, newOpts))
    fp = gzip.GzipFile(filename=path)
    opts = None
    # handle bytes for python3
    if sys.version_info[0] >= 3:
        opts = (fp.read().decode() + newOpts + '\n').encode()
    else:
        opts = fp.read() + ' ' + newOpts + '\n'
    fp.close()

    path = os.path.join(newUseroptsDir, 'useropts.gz')
    fp = gzip.GzipFile(filename=path, mode='w')
    fp.write(opts)
    fp.close()

#------------------------------------------------------------------------------
def makeBootCfg(origBootCfg, neededFilesList, highestUpdated):
    '''Make a new boot.cfg using a list of needed files as given
    by parseIsoLinuxCfg, [kernelArg, appendArg1, appendArg2, ...]
    The new boot.cfg will have an "Updated" flag higher than the
    boot.cfg files on the host.
      Input:
    asdf
    kernel=abc
    kernelopt=
    updated=1
    bootstate=3
    modules=a --- b --- c
      Output:
    asdf
    kernel=a
    kernelopt=ks=file:///ks.cfg netdevice=X ip=Y
    updated=2
    bootstate=0
    modules=b --- c --- weasel.gz --- ks.gz
    '''
    # To set up boot.cfg, modify the old boot.cfg to use the entries
    # extracted from the isolinux.cfg file on the ISO.

    # neededFilesList should be mboot.c32 (the bootloader, which we discard
    # because by the time we're reading boot.cfg the mboot bootloader is
    # already running), then "vmkboot.gz" or "b.b00", (depending how the ISO
    # was made), which gets set as the kernel= parameter, then all remaining
    # modules

    kernelArg = neededFilesList[1]
    kernelArgTokens = kernelArg.split()
    if len(kernelArgTokens) > 1:
        kernelArg = kernelArgTokens[0]
        tail = ' '.join(kernelArgTokens[1:])
        log.info('Dropping additional arguments (%s) to %s' % (tail, kernelArg))
    appendArgs = neededFilesList[2:]
    appendArgs = ' --- '.join(appendArgs)
    appendArgs = addSpecialAppendArgs(appendArgs, '')

    bootCfgLines = []
    for line in origBootCfg.splitlines():
        # NOTE: kernelopts can't be set by writing to boot.cfg in ESXi.
        #       backup.sh will clobber all kernelopts in the
        #       boot.cfg file and write in kernelopts based on esx.conf
        #       entries.
        if line.startswith('updated='):
            # make the "updated" flag higher than that of the boot.cfg on
            # the other bootbank so that this is the bootbank that gets booted.
            updated = int(highestUpdated) + 1
            line = 'updated=%d' % updated
        if line.startswith('bootstate='):
            # I don't know what bootstate does, but apparently it has to be
            # 0, not 3.
            line = 'bootstate=0'
        if line.startswith('kernel='):
            line = 'kernel=' + kernelArg
        if line.startswith('kernelopt='):
            pass
        if line.startswith('modules='):
            line = 'modules='+ appendArgs
        bootCfgLines.append(line)

    bootCfg = '\n'.join(bootCfgLines)
    return bootCfg

#------------------------------------------------------------------------------
def getDB(path, isTar=False):
    ''' Load up the database at the location provided by the user.
            path : Path to the db.
            isTar : Whether it is a compressed db or not.
    '''
    imgdb = None
    try:
        if os.path.exists(path):
            if isTar:
                imgdb = Database.TarDatabase(dbpath = path, dbcreate = False)
            else:
                imgdb = Database.Database(dbpath = path, dbcreate = False)
            imgdb.Load()
            for vibid in imgdb.profile.vibIDs:
                imgdb.profile.vibs[vibid] = imgdb.vibs[vibid]
        else:
            log.debug("The path %s does not exist." % (str(path)))
    except:
        log.exception("Error reading database : %s" % (str(path)))
        imgdb = None

    return imgdb

#------------------------------------------------------------------------------
def verifyProfileAuth():
    '''Verify vib signature and payload checksum in the profile
    '''
    # image profile
    imgdbPath = findUpgradeScratchPath(ESXIMG_DBTAR_NAME)
    imgdb = getDB(imgdbPath, isTar=True)
    profile = imgdb.profile

    # certificates and crls
    cacerts = []
    crls = []
    for certdir in CERTSDIRS:
        cacerts += [os.path.join(certdir, cert) for cert in CERT_FILES]
        crls += [os.path.join(certdir, crl) for crl in CRL_FILES]

    # read chunk size
    BUFFER_SIZE = 64 * 1024

    for vibid in profile.vibIDs:
        # iterate each vib
        vib = profile.vibs[vibid]
        try:
            log.info('Verifying signature of vib %s' % vib.name)
            # verify vib signature
            vib.VerifySignature(verifyobj=None, cacerts=cacerts, crls=crls)
            for payload in vib.payloads:
                if payload.checksums:
                    # verify each payload's checksum
                    log.info('Checking checksum of payload %s' % payload.name)
                    checksum = payload.GetPreferredChecksum()
                    hashalgo = checksum.checksumtype.replace("-", "")
                    # open the payload using localname
                    localname = profile.vibstates[vibid].payloads[payload.name]
                    localpath = findUpgradeScratchPath(localname)
                    # skip file that does not exist
                    if not os.path.isfile(localpath):
                        log.warn('Payload file %s does not exist, ' \
                                 'skip checksum check' % localname)
                        continue
                    sourcefp = open(localpath, 'rb')
                    # use hashedstream to verify checksum while reading
                    sourcefp = HashedStream.HashedStream(sourcefp,
                                                         checksum.checksum,
                                                         hashalgo)
                    inbytes = sourcefp.read(BUFFER_SIZE)
                    while inbytes:
                        inbytes = sourcefp.read(BUFFER_SIZE)
                    sourcefp.close()
                else:
                    # no checksum available
                    raise Exception('Checksum of payload %s is not available'
                             % payload.name)
        except Exception as e:
            log.error('Verify image profile authenticity failed: %s' % str(e))
            raise e

#------------------------------------------------------------------------------
def getPayloadLists(profile):
    '''Return two lists, the tgz, vgz files for the regular modules and
    the tgz files for the locker modules
    '''

    modules = list()
    lockermodules = list()

    try:
        vibcollection = profile.vibs

        for vibid, payload in profile.GetBootOrder():
            vibType = profile.vibs[vibid].vibtype
            plType = payload.payloadtype
            localname = payload.localname

            # Locker VIBs go to locker partition
            if vibType == profile.vibs[vibid].TYPE_LOCKER:
                if plType == payload.TYPE_TGZ:
                    lockermodules.append(localname)
                else:
                    log.debug('Locker module was not TGZ: %s' % localname)
            elif plType == payload.TYPE_BOOT:
                modules.append(localname)
            elif plType in (payload.TYPE_VGZ, payload.TYPE_TGZ,
                            payload.TYPE_INSTALLER_VGZ):
                modules.append(localname)

    except Exception as e:
        # log the original exception for later troubleshooting.
        msg = "Could not obtain module order from esximage db"
        log.exception(msg)
        raise PrepException(msg)

    if len(modules) < 2:
        raise PrepException("One or more boot modules missing")
    return (modules, lockermodules)

#------------------------------------------------------------------------------
def rebuildDb(bootbankDb, lockerPkgDir):
    '''Rebuild bootbankDb and create DB in locker
       Remove locker VIBs from bootbank database and create database in locker
       partition with locker VIBs
       Parameters:
          * bootbankDb - file path to bootbank database tar file
          * lockerPkgDir - packages directory in locker partion
    '''
    lockervibs = list()
    try:
        db = Database.TarDatabase(bootbankDb, dbcreate=False)
        db.Load()
        utctz = XmlUtils._utctzinfo
        profile = db.profile
        vibs = db.vibs
        assert profile
        for vibid in profile.vibIDs:
            vibs[vibid].installdate = datetime.datetime.now(utctz)
            if vibs[vibid].vibtype == vibs[vibid].TYPE_LOCKER:
                lockervibs.append(vibs[vibid])
        # locker VIBs are in a separate DB
        for vib in lockervibs:
            log.info('removing locker vib %s from main db' % vib)
            profile.RemoveVib(vib.id)
            vibs.RemoveVib(vib.id)
        db.Save(savesig=True)
    except Exception as e:
        msg = "Could not rebuild bootbank database"
        log.exception(msg)
        raise PrepException("Could not rebuild bootbank database")

    # create locker DB
    dbdir = os.path.join(lockerPkgDir, 'var/db/locker')
    try:
        if os.path.exists(dbdir):
            shutil.rmtree(dbdir)
        db = Database.Database(dbdir, addprofile=False)
        for vib in lockervibs:
            log.info('adding locker vib %s to locker db' % vib)
            db.vibs.AddVib(vib)
        db.Save()
    except Exception as e:
        msg = 'Could not create locker database'
        log.exception(msg)
        raise PrepException(msg)

#------------------------------------------------------------------------------
def prepareEsxiBootloader():
    log.info('preparing the bootloader for ESXi')

    # Since we're already booted into visor, we're going to assume that the
    # config in /bootbank (state.tgz) is our valid state, the state we want
    # to apply to the newly upgraded system.  Furthermore, we don't know what
    # exists on /altbootbank -- it may even be a ESXi 3.5 bootbank that is
    # too small to do anything useful with.
    # So we want to preserve the state found in /bootbank and reboot into
    # /bootbank as well.

    # First some sanity checks
    def getBootstateAndUpdated(bootbankPath):
        '''extract from boot.cfg the values for the keys "bootstate" and
        "updated"
        '''
        retval = {'bootstate': None, 'updated': None}
        bootCfgPath = os.path.join(bootbankPath, 'boot.cfg')
        if not os.path.isfile(bootCfgPath):
            return retval
        fp = open(bootCfgPath)
        for line in fp:
            for key in retval:
                if line.startswith(key):
                    _key, val = line.split('=', 1)
                    retval[key] = int(val)
        return retval

    #users may hit an issue where boot.cfg in altbootbank goes missing doing vum upgrade, refer PR#1708288
    #if boot.cfg is missing in altbootbank, create a new one with invalid state
    if (not os.path.exists('/altbootbank/boot.cfg')):
        with open('/altbootbank/boot.cfg','w') as bootCfgToWrite:
            newLines = []
            with open('/bootbank/boot.cfg','r') as bootCfgContent:
                for line in bootCfgContent:
                    if line.startswith('bootstate='):
                        line = 'bootstate=3\n'
                    newLines.append(line)
            contentToWrite = ''.join(newLines)
            bootCfgToWrite.write(contentToWrite)

    bbCfg = getBootstateAndUpdated('/bootbank')
    altCfg = getBootstateAndUpdated('/altbootbank')

    backupCmd = ["/sbin/backup.sh", "0"]
    try:
       log.info("Saving current system state ...")
       run(backupCmd)
    except Exception as ex:
       log.warn("Failed to update saved state: %s" % str(ex))

    if None in list(bbCfg.values()):
        # Shouldn't happen - otherwise how did we boot?
        raise Exception('/bootbank/boot.cfg was empty or missing'
                        ' "updated" or "bootstate"')

    if altCfg['bootstate'] and altCfg['bootstate'] == 1:
        # Happens when we "update" and then attempt an "upgrade" without
        # first rebooting.
        raise Exception('/altbootbank/boot.cfg has "bootstate=1".'
                        ' Can not upgrade without first rebooting.')

    liveVibInstalled = False
    if (altCfg['updated']
        and altCfg['updated'] >= bbCfg['updated']):
        if altCfg['bootstate'] == 0:
            # Live vib is installed and the host is not rebooted yet.
            # We should choose altbootbank for src bootbank.
            liveVibInstalled = True
        elif altCfg['bootstate'] != 3: # bootstate=3 means it's marked "blank"
            # Shouldn't happen - otherwise we should have booted into /altbootbank
            raise Exception('/altbootbank/boot.cfg has a higher "updated"'
                            ' value than in /bootbank/boot.cfg.')

    if liveVibInstalled:
        # Live vib is installed on /altbootbank/ and not rebooted yet.
        # So consider /altbootbank/ as a booted bootbank.
        bootbankRoot = "/altbootbank/"
        updated = altCfg['updated']
    else:
        bootbankRoot = "/bootbank/"
        updated = bbCfg['updated']

    #We write everything to altbootbank and reboot into there,
    # so we can copy over third party vibs.

    bootedbootbankRoot = bootbankRoot
    # Set target bootbank to non-booted bootbank.
    if bootbankRoot == "/bootbank/":
        bootbankRoot = "/altbootbank/"
    else:
        bootbankRoot = "/bootbank/"

    # Try to make the useropts first, since that is the most likely to fail.
    copyFromUpgradeScratch('/useropts.gz', os.path.join(bootbankRoot, 'useropts.gz'))
    makeUseroptsGz(bootbankRoot, '/tmp/')

    neededFiles = parseIsoLinuxCfg('/isolinux.cfg')

    persistedModules = []
    # clear the bootbank directory
    for filename in os.listdir(bootbankRoot):
        if filename.lower() == 'boot.cfg' or \
           filename.startswith(('local.tgz', 'state.', 'jumpstrt.')):
            # In addition to boot.cfg, local.tgz and state.tgz,
            # backup.sh may be working with temporary local.tgz.<pid>
            # state.tgz.<pid> files or state.<pid> folder in bootbank,
            # they should be left alone.
            continue
        os.remove(os.path.join(bootbankRoot, filename))

    for filename in ['local.tgz', 'state.tgz', 'jumpstrt.gz']:
        # TODO TOCTTOU race condition.
        if os.path.isfile(os.path.join(bootedbootbankRoot, filename)):
            log.info("Persisting %s into new system" % filename)
            # If the version is 5, copy over these files They might just
            # get replaced, but this appears to be persisting them.
            # Note: if liveVibInstalled is True, then we will be copying
            # the jumpstrt.gz file from /abltbootbank to /bootbank. This
            # is fine since backup.sh saves the copy of jumpstrt.gz to
            # altbootbank during live vib install. Hence, the source here
            # will always be the updated jumpstrt.gz.
            shutil.copy(os.path.join(bootedbootbankRoot, filename),
                os.path.join(bootbankRoot, filename))
            persistedModules.append(filename)

    # clear the /locker/packages directory
    for filename in os.listdir(lockerPkgDir):
        shutil.rmtree(os.path.join(lockerPkgDir, filename))

    # clear the ProductLockerLocation option so that it refreshes it
    # upon the next reboot
    cmdTuple = ('/sbin/esxcfg-advcfg', '--del-option',
                'ProductLockerLocation')
    try:
        run(cmdTuple)
    except Exception as ex:
        # There may not be a ProductLockerLocation VIB if this was an
        # ISO that didn't have the tools VIB
        log.info(str(ex))
        log.info("Probably no tools VIB was present")

    # copy the imgdb.tgz to /bootbank
    imgdbPath = os.path.join(bootbankRoot, 'imgdb.tgz')
    copyFromUpgradeScratch('/imgdb.tgz', imgdbPath)

    # open db to get image profile
    imgdb = getDB(imgdbPath, isTar=True)
    if not imgdb:
        raise Exception('Cannot read database')
    profile = imgdb.profile

    # get lists of boot and locker payload
    bootPayloads, lockerPayloads = getPayloadLists(profile)

    # imports are done inside the function so we don't have to worry about
    # missing Python modules if this is run on old ESX hosts (ver < 4.0)
    import gzip
    import tarfile

    # copy over vgz files
    for fpath in neededFiles:
        if not fpath.startswith('/'):
            fpath = '/' + fpath
        if os.path.basename(fpath) in persistedModules:
            # don't overwrite persisted modules
            continue
        if os.path.basename(fpath) in lockerPayloads:
            localPath = findUpgradeScratchPath(fpath)
            log.info('gzip opening %s' % localPath)
            gStream = gzip.GzipFile(filename=localPath)
            tStream = tarfile.TarFile(fileobj=gStream)
            tStream.extractall(lockerPkgDir)
        else:
            destname = bootbankRoot + fpath
            copyFromUpgradeScratch(fpath, destname)

    # rebuild the DB so that it no longer references the locker payloads
    rebuildDb(imgdbPath, lockerPkgDir)

    # make a upgrade.tgz file with ks.cfg inside
    makeUpgradeVgz(os.path.join(bootbankRoot, 'upgrade.tgz'))

    # the locker files are already extracted, don't put them in boot.cfg
    bootCfgModules = []
    for fpath in (neededFiles + persistedModules):
        if not fpath.startswith('/'):
            fpath = '/' + fpath
        if (os.path.basename(fpath) not in lockerPayloads and
            fpath not in bootCfgModules):
            bootCfgModules.append(fpath)

    origBootCfgPath = os.path.join(bootbankRoot, 'boot.cfg')
    fp = open(origBootCfgPath)
    origBootCfg = fp.read()
    fp.close()
    newBootCfg = makeBootCfg(origBootCfg, bootCfgModules, updated)

    # Make sure we grab useropts.gz from /tmp/ and put it into bootbank.
    shutil.copy('/tmp/useropts.gz', bootbankRoot)

    # TODO: there is a race condition here.  backup.sh runs periodically, and
    #       it writes to boot.cfg.  If we get unlucky, backup.sh may have just
    #       opened this boot.cfg and after we finish our write, it will do its
    #       write and clobber anything we just did.
    fp = open(origBootCfgPath, 'w')
    log.info('writing to '+ origBootCfgPath)
    log.info(newBootCfg)
    fp.write(newBootCfg)
    fp.close()

#------------------------------------------------------------------------------
def calcExpectedPaths():
    global pathToISO
    pathToISO = upgrade_precheck.RAMDISK_NAME
    if os.path.exists(upgrade_precheck.RAMDISK_NAME):
        # upgrade_precheck has already allocated the correct-sized ramdisk
        log.info('RAM disk already exists')
        return
    if upgrade_precheck.metadata:
        size = upgrade_precheck.metadata.sizeOfISO
    else:
        log.warn('Could not get ISO size from the precheck metadata.'
                 ' Guessing 400MiB')
        size = 400*1024*1024 # 400 MiB
    upgrade_precheck.allocateRamDisk(upgrade_precheck.RAMDISK_NAME,
                                     sizeInBytes=size)
#------------------------------------------------------------------------------
def showExpectedPaths():
    print('image=%s' % pathToISO)
    print('isoinfo=%s' % pathToIsoinfo)

#------------------------------------------------------------------------------
def main(argv):
    global options
    parser = optparse.OptionParser()
    parser.add_option('-s', '--showexpectedpaths',
                      dest='showExpectedPaths', default=False,
                      action='store_true',
                      help=('Show expected paths for ISO, isoinfo, and user'
                            ' agent.'))
    parser.add_option('-v', '--verbose',
                      dest='verbose', default=False,
                      action='store_true',
                      help=('Verbosity. Turns the logging level up to DEBUG'))
    parser.add_option('--ip',
                      dest='ip', default='',
                      help=('The IP address that the host should bring up'
                            ' after rebooting.'))
    parser.add_option('--netmask',
                      dest='netmask', default='',
                      help=('The subnet mask that the host should bring up'
                            ' after rebooting.'))
    parser.add_option('--gateway',
                      dest='gateway', default='',
                      help=('The gateway that the host should use'
                            ' after rebooting.'))
    parser.add_option('--ignoreprereqwarnings',
                      dest='ignoreprereqwarnings', default='False',
                      help=('Ignore the precheck warnings during upgrade/install.'))

    parser.add_option('--ignoreprereqerrors',
                      dest='ignoreprereqerrors', default='False',
                      help=('Ignore the precheck errors during upgrade/install.'))

    options, args = parser.parse_args()

    if options.verbose:
        log.setLevel(logging.DEBUG)
    global systemProbe
    product, version = upgrade_precheck._parseVmwareVersion()
    upgrade_precheck.init(product, version)
    systemProbe = upgrade_precheck.systemProbe
    assert systemProbe.bootDiskPath
    log.info('found boot disk %s' % systemProbe.bootDiskPath)
    assert systemProbe.bootDiskVMHBAName
    log.info('found boot disk vmhba name %s' % systemProbe.bootDiskVMHBAName)

    calcExpectedPaths()

    if options.showExpectedPaths:
        showExpectedPaths()
        return 0

    # Use image profile upgrade for 6.5 and later hosts
    if USE_PROFILE_UPDATE and version >= [6, 5, 0]:

        # vmware package is designed to be able to spread across muliple
        # places. For subpackage of the same name (esximage), compiled copy
        # is preferred by the runtime. We want to always use the package in
        # esximage.zip, we can accomplish this by importing esximage package
        # from esximage.zip/vmware directly, which will not be confused with
        # the library in the host /lib64 folder.
        sys.path.insert(0, os.path.join(SCRIPT_DIR, "esximage.zip", "vmware"))
        from esximage.Transaction import Transaction

        log.info('Performing image profile update from ESXi %s' % version)
        try:
            t = Transaction()
            res = t.InstallVibsFromDeployDir(pathToISO)
        except Exception as e:
            log.error('Failed to perform image profile update: %s' % e)
            raise
        log.info('VIB installed: %s' % str(res.installed))
        log.info('VIB removed: %s' % str(res.removed))
        log.info('VIB skipped: %s' % str(res.skipped))
        return 0

    if not options.ip:
        log.error('No IP address given')
        return 1

    verifyProfileAuth()
    prepareEsxiBootloader()
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv))
    #import doctest
    #doctest.testmod()

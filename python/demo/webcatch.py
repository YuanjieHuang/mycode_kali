# # coding=utf-8
# import re
# import urllib.request as urllib
#
# def getHtml(url):
#     page = urllib.urlopen(url)
#     html = page.read()
#     return html
# html = getHtml("http://www.qq.com/")
#
#
# reg = '<a class="title" target="_blank" href="(.*?)">(.*?)</a>[\n][\s]*'
# reg += '<p class="abstract">[\n](.*)[\n][\s]*'
# reg += '</p>[\n][\s]*<div class="meta">[\n][\s]*'
# reg += '<a class="collection-tag" target="_blank" href="/c/.*?">(.*?)</a>[\n][\s]*'
# reg += '<a target="_blank" href="/p/.*?">[\n][\s]*'
# reg += '<i class="iconfont ic-list-read"></i> (.*)[\n]'
# reg += '</a>[\s]*<a target="_blank" href="/p/.*?">[\n][\s]*'
# reg += '<i class="iconfont ic-list-comments"></i> (.*)[\n]'
# reg += '</a>[\s]*<span><i class="iconfont ic-list-like"></i> (.*)</span>[\n][\s]*'
# reg += '<span><i class="iconfont ic-list-money"></i> (.*)</span>'
#
# #当正则表达式过长时，我们选取这种方式将其分割
#
# page = re.compile(reg)
# html = html.decode('utf-8')
# artlist = re.findall(page,html)
#
# for arts in artlist: #arts中包含了文件名，链接部分，阅读量等等
#     for art in arts:
#        if art.startswith("/p/"): #获取链接
#          print ("http://www.qq.com" + art)
#        else:
#            print (art)
#
# # import urllib.request
# # # print(urllib.__file__)
# # def getHtml(url):
# #  page = urllib.request.urlopen(url)
# #  html = page.read()
# #  return html
# # html = getHtml("http://www.baidu.com")
# # print(html)

# # coding=utf-8
# import urlile('<.*?>')
# data = data.decode('utf-8')
# c_t = r1.findall(data)
#
# print(c_t)lib.request
# import re
# url = 'http://www.163.com'
# file = 'd:/test.html'
#
# data = urllib.request.urlopen(url).read()
#
# r1 = re.comp

from urllib import request
from bs4 import BeautifulSoup
import re
import time
url = "https://www.zhihu.com/question/22918070"
html = request.urlopen(url).read().decode('utf-8')
soup = BeautifulSoup(html, 'html.parser')
# print(soup.prettify())

# 用Beautiful Soup结合正则表达式来提取包含所有图片链接（img标签中，class=**，以.jpg结尾的链接）的语句
links = soup.find_all('img', "origin_image zh-lightbox-thumb", src=re.compile(r'.jpg$'))
print(links)

# 设置保存图片的路径，否则会保存到程序当前路径
path = r''  # 路径前的r是保持字符串原始值的意思，就是说不对其中的符号进行转义
for link in links:
 print(link.attrs['src'])
 # 保存链接并命名，time.time()返回当前时间戳防止命名冲突
 request.urlretrieve(link.attrs['src'], path + '\%s.jpg' % time.time())  # 使用request.urlretrieve直接将所有远程链接数据下载到本地
# 结果：
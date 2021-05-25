**环境准备：**

1.安装python3

2.安装pycharm集成开发环境

3.安装requests库、BeautiflulSoup库、scrapy库

##### Requests库：爬取网页

```python
import requests
r= requests.get("http://www.baidu.com")
print(r.status_code)
type(r)
r.headers
r.encoding = 'utf-8'
r.apparent_encoding
r.text
r.content
```

```python

```

| 方法                                   | 说明                                           |
| -------------------------------------- | ---------------------------------------------- |
| requests.request()                     | 构造一个请求，支撑以下各方法的基础方法         |
| requests.get(url,params=None,**kwargs) | 获取HTML网页的主要方法，对应HTTP的GET          |
| requests.head()                        | 获取HTML网页的头消息方法，对应HTTP的HEAD       |
| requests.post()                        | 向HTML网页提交POST请求的方法，对应于HTTP的POST |
| requests.put()                         | ……PUT请求……，……PUT……                           |
| requests.patch()                       | 向HTML网页提交局部修改请求，对应于HTTP的PATCH  |
| requests.delete()                      | 向HTML网页提交删除请求，对应于HTTP的DELETE     |

```python
requests.request(method,url,**kwargs)	如：r = requests.request('GET',url,**kwargs)

**kwargs:13个，控制访问的参数，均为可选项
    params:字典或字节序列，作为参数增加到url中，如：
        kv = {'key1':'value1','key2':'value2'}
        r = reqeusts.request('GET', 'http://www.baidu.com',params=kv)
        pirnt(r.url)
     data:字典、字节序列或文件对象，作为Request的内容，如：
        kv = {'key1':'value1','key2':'value2'}
        r = reqeusts.request('GET', 'http://www.baidu.com',data=kv)
        body = '主体内容'
        r = reqeusts.request('GET', 'http://www.baidu.com',data=body)
     json:JSON格式的数据，作为Request的内容
     header:字典，HTTP定制头
     cookies:字典或CookieJar，Request中的cookie
     auth:元组，支持HTTP认证功能
     files:字典类型，向服务器传输文件，如：
        fs = {'file': open('data.xls', 'rb')}
        r  = requests..request('POST', 'url', files=fs)
     timeout:设定超时时间，以秒为单位
     proxies:字典类型，设定访问代理服务器，可以增加登陆认证
        pxs = {'http':'http://user:pass@10.10.10.1:1234',
                'https:'http://10.10.10.1:4321'}
        r = requests.request('GET', 'http://www.baidu.com' , proxies=pxs)
	 allow_redirects:True/False,默认True,重定向开关
     stream:True/False,默认True,获取内容立即下载开关
     verify:True/False,默认True,认证SSL证书开关
     cerl:本地SSL证书路径
     

```



###### Response对象的属性

| 属性                | 说明                                             |
| ------------------- | ------------------------------------------------ |
| r.status_code       | HTTP请求的返回状态，200表示连接成功，404表示失败 |
| r.text              | HTTP响应内容的字符串形式，即url对应的页面内容    |
| r.encoding          | 从HTTP header中猜测的响应内容编码方式            |
| r.apparent_encoding | 从内容中分析出的响应内容编码方式（备选编码方式） |
| r.content           | HTTP响应内容的二进制形式                         |

###### Requests库的异常

| 异常                      | 说明                                        |
| ------------------------- | ------------------------------------------- |
| requests.ConnectionError  | 网络连接错误异常，如DNS查询失败、拒绝连接等 |
| requests.HTTPError        | HTTP错误异常                                |
| requests.URLRequired      | URL缺失异常                                 |
| requests.TooManyRedireets | 超过最大重定向次数，产生重定向异常          |
| requests.ConnectTimeout   | 连接远程服务器超时异常                      |
| requests.Timeout          | 请求URL超时，产生超时异常                   |

```python
1


r.raise_for_status()	如果不是200,产生异常requests.HTTPError
```

###### HTTP协议

HTTP,Hypertext Transfer Protocol,超文本传输协议

一个基于“请求与响应”模式的、无状态的应用层协议。

URL格式 http://host[:port][path]





###### HTTP协议对资源的操作

| 方法   | 说明                                                      |
| ------ | --------------------------------------------------------- |
| GET    | 请求URL位置的资源                                         |
| HEAD   | 请求获取URL位置资源的响应消息报告，即获得该资源的头部信息 |
| POST   | 请求URL位置的资源后附加新的数据                           |
| PUT    | 请求向URL位置存储一个资源，覆盖URL位置的资源              |
| PATCH  | 请求局部更新URL位置的资源，即改变该处资源的部分内容       |
| DELETE | 请求删除URL位置存储的资源                                 |

###### 网络爬虫的限制

来源审查：判断User-Agent进行限制

​		检查来访HTTP协议头的User-Agent域，只响应浏览器的访问

发布公告：Robots协议(建议但非约束，可以不遵守，但存在法律风险)

​		告知所有爬虫网站的爬取策略，要求爬虫遵守。

​		Robots协议：Robots Exclusion Standard 网络爬虫排除标准

​			作用：网站告知网络爬虫哪些页面可以抓取，哪些不行。

​			形式：在网站根目录下的robots.txt文件。如，http://news.sina.cn/robots.txt

**通过爬虫在百度搜索Python:**

```python
import requests
keyword = "Python"
try:
    kv = {'wd':keyword}
    r = requests.get("http://www.baidu.com/s",params = kv)
    print(r.status_code)
    r.raise_for_status()
    print(r.request.url)
	print(len(r.text)
except:
    print("爬取失败")
```

网络图片的爬取和存储

网络图片链接的格式：

http://www.example.com/picture.jpg 如国家地理：http://www.nationalgeographic.com.cn

```python
import requests
import os
url  = "http://..../*.jpg"
root = "D://pics//"
path = root + url.split('/')[-1]
try:
    if not os.path.exists(root):
        os.mkdir(root)
    if not os.path.exists(path):
        r = requests.get(url)
        with open(path, 'wb') as f:
            f.write(r.content)
            f.close()
            print("file saved")
     else:
        print("file existed")
except:
    print("爬取失败")
```

IP地址查询：

```python
import requests
url = "http://m.ip138.com/ip.asp?ip="
try:
    r = requests.get(url+'202.204.80.112')
    r.raise_for_status()
    r.encoding = r.apparent_encoding
    print(r.text[-500:])
except:
    print("爬取失败")
```

###### Beautiful Soup库：解析HTML页面、信息标记与提取方法

```python
from bs4 import BeautifulSoup
soup = BeautifulSoup('<p>data</p>', 'html.parser')
```

**Beautiful Soup类的5种基本元素**

| 基本元素        | 说明                                                     |
| --------------- | -------------------------------------------------------- |
| Tag             | 标签，最基本的信息组织单元，分别用<>和</>标明开头和结尾  |
| Name            | 标签的名字，<p>...</p>的名字是'p',格式<tag>.name         |
| Atrributes      | 标签的属性，字典形式组织，格式：<tag>.atrs               |
| NavigableString | 标签内非属性字符串，<>...</>中字符串，格式：<tag>.string |
| Comment         | 标签内字符串的注释部分，一种特殊的Comment类型            |

 **标签树的遍历**

​	*标签树的下行遍历：*

| 属性         | 说明                                                    |
| ------------ | ------------------------------------------------------- |
| .contents    | 子节点的列表，将<tag>所有儿子节点存入列表               |
| .children    | 子节点的迭代类型，与.contents类似，用于循环便利儿子节点 |
| .descendants | 子孙节点的迭代类型，包括所有子孙节点 ，用于循环遍历     |

```python
for child in soup.body.children:
    print(child)
```

*标签树的上行遍历：*

| 属性     | 说明                                         |
| -------- | -------------------------------------------- |
| .parent  | 节点的父亲标签                               |
| .parents | 节点先辈标签的迭代类型，用于循环遍历先辈节点 |

```python
soup = BeautifulSoup(demo, "html.parser")
for parent in soup.a.parents:
    if parent is None:
        print(parent)
    else:
        print(parent.name)
```

*标签树的平行遍历：只发生在同一个父节点下的各节点之间*

| 属性               | 说明                                 |
| ------------------ | ------------------------------------ |
| .next_sibling      | 返回HTML文本顺序的下一个平行节点标签 |
| .previous_sibling  | ……上一个……                           |
| .next_siblings     | 迭代类型                             |
| .privious_siblings | 迭代类型                             |

###### 基于bs4库的HTML格式输出

通过prettify()方法

###### 信息标记的三种方法

XML：eXtensible Markup Language

JSON：JavaScript Object Notation 有类型的健值对key:value，无注释功能，如"name":"深圳"

YAML：YAML Ain't Markup Language  无类型键值对key:value，有注释功能，如name:深圳

​			使用缩进取代括号，减号“-”表达并列关系，竖线“|”表达整块注释

bs4库中的find_all方法：

<>.find_all(name, attrs, recursive, string, **kwargs)

​		name:对标签名称的检索字符串

​		atrs:对标签属性值的检索字符串

​		recursive:是否对子孙全部检索，默认True

​		string:<>...</>中字符串区域的检索字符串

​	<tag>(..)等价于<tag>.find_all(..)

​	soup(..)等价于soup.find_all(..)



```python
import re
for tag in soup.find_all(re.compile('b')):
	print(tag.name)
```



##### Scrapy库：爬取网站或系列网站

爬虫框架结构：5+2结构

spiders 

item pipelines

engine

download

scheduler





##### 定制开发：爬取全网
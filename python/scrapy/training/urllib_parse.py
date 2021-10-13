'''
#导入parse模块
from urllib import parse
#构建查询字符串字典
query_string = {
'wd' : '爬虫'
}
#调用parse模块的urlencode()进行编码
result = parse.urlencode(query_string)
#使用format函数格式化字符串，拼接url地址
url = 'http://www.baidu.com/s?{}'.format(result)
print(url)

string = '%E7%88%AC%E8%99%AB'
result = parse.unquote(string)
print(result)

#注意url的书写格式，和 urlencode存在不同
url = 'http://www.baidu.com/s?wd={}'
word = input('请输入要搜索的内容:')
#quote()只能对字符串进行编码
query_string = parse.quote(word)
print(url.format(query_string))

# 1、字符串相加
baseurl = 'http://www.baidu.com/s?'
params='wd=%E7%88%AC%E8%99%AB'
url = baseurl + params
# 2、字符串格式化（占位符）
params='wd=%E7%88%AC%E8%99%AB'
url = 'http://www.baidu.com/s?%s'% params
# 3、format()方法
url = 'http://www.baidu.com/s?{}'
params='wd=%E7%88%AC%E8%99%AB'
url = url.format(params)
'''
from urllib import request
from urllib import parse
# 拼接URL地址
def get_url(word):
    url = 'http://www.baidu.com/s?{}'
    #此处使用urlencode()进行编码
    params = parse.urlencode({'wd':word})
    url = url.format(params)
    return url
# 发请求,保存本地文件
def request_url(url,filename):
    headers = {'User-Agent':'Mozilla/5.0 (Windows NT 6.1; WOW64; rv:6.0) Gecko/20100101 Firefox/6.0'}
    # 请求对象 + 响应对象 + 提取内容
    req = request.Request(url=url,headers=headers)
    res = request.urlopen(req)
    html = res.read().decode('utf-8')
    # 保存文件至本地
    with open(filename,'w',encoding='utf-8') as f:
     f.write(html)
# 主程序入口
if __name__ == '__main__':
    word = input('请输入搜索内容:')
    url = get_url(word)
    filename = word + '.html'
    request_url(url,filename)
import urllib.request
improt re


def imageCrawler(url,toPath):
 headers={}
 req=urllib.request.Reques(url,headers=headers)
 response=urllib.request.urlopen(req)
 HtmlStr=response.read
 with open() as f:
  f.write(HtmlStr)
  pat=



url="http://search.yhd.com/c0-0/k%25E5%25A5%25B3%25E8%25A3%2585/"
toPath=r"C:\Users\Administrator\PycharmProject\image"

imageCrawler(url,toPath)

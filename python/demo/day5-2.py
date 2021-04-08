import ti
# print(time.time())
# print(time.gmtime())
# print(time.localtime())
# print(time.mktime(time.localtime()))
#将时间元组转成字符串
# b=time.localtime()
# s=time.asctime(b)
# print(s)
#
# q=time.strftime("%Y-%m-%d %H-:%M:%S",b)
# print(q)
# print (time.clock())

# time.clock()
# sum=0
# for i in range(1000000):
#  sum+=i
# print(time.clock())

import calendar
# print(calendar.month(2018,9))

# print(calendar.calendar(2018))
# print(calendar.isleap(2004))

from PIL import Image
im=Image.open("111.jpg")
print=(im.format,im.size,im.mode)
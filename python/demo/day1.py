# def fib(n):    # write Fibonacci series up to
#    """Print a Fibonacci series up to n."""
#    a, b = 0, 1
#    while a <n:
#        print(a, end=' ')
#        a, b = b, a+b
# f=fib
# f(1000)
# fib(0)


# def ask_ok(prompt, retries=4, complaint='Yes or no, please!'):
#     while True:
#         ok = input(prompt)
#         if ok in ('y', 'ye', 'yes'):
#             return True
#         if ok in ('n', 'no', 'nop', 'nope'):
#             return False
#         retries = retries - 1
#         if retries < 0:
#             raise OSError('uncooperative user')
#         print(complaint)
# ask_ok('Do you really want to quit?')
# ask_ok('OK to overwrite the file?', 2)
# ask_ok('OK to overwrite the file?', 2, 'Come on, only yes or no!')


# def parrot(voltage, state='a stiff', action='voom', type='Norwegian Blue'):
#     print("-- This parrot wouldn't", action, end=' ')
#     print("if you put", voltage, "volts through it.")
#     print("-- Lovely plumage, the", type)
#     print("-- It's", state, "!")
# parrot(1000)                                          # 1 positional argument
# parrot(voltage=1000)                                  # 1 keyword argument
# parrot(voltage=1000000, action='VOOOOOM')             # 2 keyword arguments
# parrot(action='VOOOOOM', voltage=1000000)             # 2 keyword arguments
# parrot('a million', 'bereft of life', 'jump')         # 3 positional arguments
# parrot('a thousand', state='pushing up the daisies')  # 1 positional, 1 keyword

# 用户输入数字
# num1=int(input('input num1'))
# num2=int(input('input num2'))
# sum=num1+num2
# print('数字 {0} 和 {1} 相加结果为： {2}'.format(num1, num2, sum))
# print('两数之和为 %.1f' %(float(input('输入第一个数字：'))+float(input('输入第二个数字：'))))

# 计算实数和复数平方根
# 导入复数数学模块

# import cmath
# num = int(input("请输入一个数字: "))
# num_sqrt = cmath.sqrt(num)
# print('{0} 的平方根为 {1:0.3f}+{2:0.3f}j'.format(num, num_sqrt.real, num_sqrt.imag))

# 二次方程式 ax**2 + bx + c = 0
# a、b、c 用户提供，为实数，a ≠ 0

# 导入 cmath(复杂数学运算) 模块
# import cmath
# a = float(input('输入 a: '))
# b = float(input('输入 b: '))
# c = float(input('输入 c: '))
# # 计算
# d = (b ** 2) - (4 * a * c)
# # 两种求解方式
# sol1 = (-b - cmath.sqrt(d)) / (2 * a)
# sol2 = (-b + cmath.sqrt(d)) / (2 * a)
# print('结果为 {0} 和 {1}'.format(sol1, sol2))


# def is_number

# (s):
# #  try:
# #   float(s)
# #   return True
# #  except ValueError:
# #   pass
# #
# #  try:
# #   import unicodedata
# #   unicodedata.numeric(s)
# #   return True
# #  except (TypeError, ValueError):
# #   pass
# print(is_number('foo'))  # False
# print(is_number('1'))  # True

# year = int(input("输入一个年份: "))
# if (year % 4) == 0:
#    if (year % 100) == 0:
#        if (year % 400) == 0:
#            print("{0} 是闰年".format(year))   # 整百年能被400整除的是闰年
#        else:
#            print("{0} 不是闰年".format(year))
#    else:
#        print("{0} 是闰年".format(year))       # 非整百年能被4整除的为闰年
# else:
#    print("{0} 不是闰年".format(year))

# Python 程序用于检测用户输入的数字是否为质数

# 用户输入数字
# num = int(input("请输入一个数字: "))

# # 质数大于 1
# if num > 1:
#     # 查看因子
#     for i in range(2, num):
#         if (num % i) == 0:
#             print(num, "不是质数")
#             print(i, "乘于", num // i, "是", num)
#             break
#     else:
#         print(num, "是质数")
# # 如果输入的数字小于或等于 1，不是质数
# else:
#     print(num, "不是质数")

# !/usr/bin/python3

# 输出指定范围内的素数
# take input from the user
# lower = int(input("输入区间最小值: "))
# upper = int(input("输入区间最大值: "))
# for num in range(lower, upper + 1):
#     # 素数大于 1
#     if num > 1:
#         for i in range(2, num):
#             if (num % i) == 0:
#                 break
#         else:
#             print(num)

# 通过用户输入数字计算阶乘

# # 获取用户输入的数字
# num = int(input("请输入一个数字: "))
# factorial = 1
# # 查看数字是负数，0 或 正数
# if num < 0:
#     print("抱歉，负数没有阶乘")
# elif num == 0:
#     print("0 的阶乘为 1")
# else:
#     for i in range(1, num + 1):
#         factorial = factorial * i
#     print("%d 的阶乘为 %d" % (num, factorial)

# # 九九乘法表
# for i in range(1, 10):
#         for j in range(1, i+1):
#             print('{}x{}={}\t'.format(i, j, i*j), end='')
#         print()

# # Python 斐波那契数列实现
# # 获取用户输入数据
# nterms = int(input("你需要几项？"))
# # 第一和第二项
# n1 = 0
# n2 = 1
# count = 2
# # 判断输入的值是否合法
# if nterms <= 0:
#     print("请输入一个正整数。")
# elif nterms == 1:
#     print("斐波那契数列：")
#     print(n1)
# else:
#     print("斐波那契数列：")
#     print(n1, ",", n2, end=" , ")
#     while count < nterms:
#         nth = n1 + n2
#         print(nth, end=" , ")
#         # 更新值
#         n1 = n2
#         n2 = nth
#         count += 1

# # 获取指定期间内的阿姆斯特朗数
# lower = int(input("最小值: "))
# upper = int(input("最大值: "))
#
# for num in range(lower, upper + 1):
#     # 初始化 sum
#     sum = 0
#     # 指数
#     n = len(str(num))
#
#     # 检测
#     temp = num
#     while temp > 0:
#         digit = temp % 10
#         sum += digit ** n
#         temp //= 10
#
#     if num == sum:
#         print(num)

# # !/usr/bin/python3
# sites = ["Baidu", "Google", "Runoob", "Taobao"]
# for site in sites:
#     if site == "Runoob":
#         print("菜鸟教程!")
#         break
#     print("循环数据 " + site)
# else:
#     print("没有循环数据!")
# print("完成循环!")

# #逻辑运算符
# a=10
# b=20
# print(a and b)
# print(a or b)
# print(not a)

# # 以下实例我们可以输出函数的注释：
# def a():
#     '''这是文档字符串'''
#     "double"
#     # jj
#     pass
# print(a.__doc__)

# a, b, c, d = 20, 5.5, True, 4+3j
# print(type(a), type(b), type(c), type(d))


# str = 'Runoob'
#
# print(str)  # 输出字符串
# print(str[0:-1])  # 输出第一个到倒数第二个的所有字符
# print(str[0])  # 输出字符串第一个字符
# print(str[2:5])  # 输出从第三个开始到第五个的字符
# print(str[2:])  # 输出从第三个开始的后的所有字符
# print(str * 2)  # 输出字符串两次
# print(str + "TEST")  # 连接字符串
#
# print('Ru\noob')
# print(r'Ru\noob')

# # 列表是写在方括号([])之间、用逗号分隔开的元素列表
# list = ['abcd', 786, 2.23, 'runoob', 70.2]
# tinylist = [123, 'runoob']
# print(list)  # 输出完整列表
# print(list[0])  # 输出列表第一个元素
# print(list[1:3])  # 从第二个开始输出到第三个元素
# print(list[2:])  # 输出从第三个元素开始的所有元素
# print(tinylist * 2)  # 输出两次列表
# print(list + tinylist)  # 连接列表

# 元组写在小括号 () 里，元素之间用逗号隔开
# 可以把字符串看作一种特殊的元组。
# tuple = ('abcd', 786, 2.23, 'runoob', 70.2)
# tinytuple = (123, 'runoob')
#
# print(tuple)  # 输出完整元组
# print(tuple[0])  # 输出元组的第一个元素
# print(tuple[1:3])  # 输出从第二个元素开始到第三个元素
# print(tuple[2:])  # 输出从第三个元素开始的所有元素
# print(tinytuple * 2)  # 输出两次元组
# print(tuple + tinytuple)  # 连接元组
#
# tup1 = ()    # 空元组
# tup2 = (20,) # 一个元素，需要在元素后添加逗号
# string、list和tuple都属于sequence（序列）。

# # 集合（set）是一个无序不重复元素的序列
# student = {'Tom', 'Jim', 'Mary', 'Tom', 'Jack', 'Rose'}
#
# print(student)  # 输出集合，重复的元素被自动去掉
#
# # 成员测试
# if ('Rose' in student):
#     print('Rose 在集合中')
# else:
#     print('Rose 不在集合中')
#
# # set可以进行集合运算
# a = set('abracadabra')
# b = set('alacazam')
# print(a)
# print(a - b)  # a和b的差集
# print(a | b)  # a和b的并集
# print(a & b)  # a和b的交集
# print(a ^ b)  # a和b中不同时存在的元素

# 字典当中的元素是通过键来存取的，而不是通过偏移存取。
# 字典是一种映射类型，字典用"{ }"标识，它是一个无序的键(key) : 值(value)对集合。
# 键(key)必须使用不可变类型。
# 在同一个字典中，键(key)必须是唯一的。
# dict = {}
# dict['one'] = "1 - 菜鸟教程"
# dict[2] = "2 - 菜鸟工具"
# tinydict = {'name': 'runoob', 'code': 1, 'site': 'www.runoob.com'}
# print(dict['one'])  # 输出键为 'one' 的值
# print(dict[2])  # 输出键为 2 的值
# print(tinydict)  # 输出完整的字典
# print(tinydict.keys())  # 输出所有键
# print(tinydict.values())  # 输出所有值

# print(dict([('Runoob', 1), ('Google', 2), ('Taobao', 3)]))#!!!!
# print({x: x**2 for x in (2, 4, 6)})#!!!!


# import random
# l=random.choice(range(10))
# print(l)

# %s 将一个值插入到一个有字符串格式符 %s 的字符串中。
# tup1 = (50)
# print(type(tup1))  # 不加逗号，类型为整型)
# print(tup1)
# tup2 = (50,)
# type(tup2)  # 加上逗号，类型为元组
# print(tup2)  # 加上逗号，类型为元组
# tup = ('Google', 'Runoob', 1997, 2000)
# print(tup)
# del tup
# print(tup)#元祖不存在，报错

# import sys
# def fibonacci(n):  # 生成器函数 - 斐波那契
#     a, b, counter = 0, 1, 0
#     while True:
#         if (counter > n):
#             return
#         yield a#????
#         a, b = b, a + b
#         counter += 1
# f = fibonacci(10)  # f 是一个迭代器，由生成器返回生成
# while True:
#     try:
#         print(next(f), end=" ")
#     except StopIteration:
#         sys.exit()


# def ChangeInt(a):
#     a = 10
#     return a
# b = 2
# ChangeInt(b)
# print(b)  # 结果是 2

# # 可写函数说明
# def changeme(mylist):
#     "修改传入的列表"
#     mylist.extend([1, 2, 3, 4])
#     print("函数内取值: ", mylist)
#     return
# # 调用changeme函数
# mylist = [10, 20, 30]
# changeme(mylist)
# print("函数外取值: ", mylist)


# def printinfo(arg1, *vartuple):
#     "打印任何传入的参数"
#     print("输出: ")
#     print(arg1)
#     print(vartuple)
# printinfo(70, 60, 50)

# def printinfo(arg1, *vartuple):
#     "打印任何传入的参数"
#     print("输出: ")
#     print(arg1)
#     for var in vartuple:
#         print(var)
#     return
# printinfo(10)
# printinfo(70, 60, 50)
#
#
# def printinfo(arg1, **vardict):
#     print(arg1)
#     print(vardict)
# printinfo(1, a=2, b=3)

# def f(a,b,*,c):
#       return a+b+c
# #f(1,2,3)
# l=f(1,2,c=3)
# print(l)

# 匿名函数lambda [arg1 [,arg2,.....argn]]:expression
# sum = lambda arg1, farg2: arg1 + arg2
# print("相加后的值为 : ", sum(10, 20))
# print("相加后的值为 : ", sum(20, 20))

# Python 中只有模块（module），类（class）以及函数（def、lambda）才会引入新的作用域
# if True:
#  msg = 'I am from Runoob'
# print(msg)
#


# num = [1]
# def fun1(num):
#     # global num  # 需要使用 global 关键字声明
#     print(num)
#     num.append([123])
#     print(num)
# fun1([2,])
# print(num)

# def outer():
#     num = 10
#     def inner():
#         nonlocal num   # nonlocal关键字声明
#         num = 100
#         print(num)
#     inner()
#     print(num)
# outer()
#
#
#
#
# freshfruit = ['  banana', '  loganberry ', 'passion fruit  ']
# print([weapon.strip() for weapon in freshfruit])
#
# vec=[2,4,6]
# print([3*x for x in vec])
# print([[x, x**2] for x in vec])
# print([3*x for x in vec if x > 3])

# vec1 = [2, 4, 6]
# vec2 = [4, 3, -9]
# print([x*y for x in vec1 for y in vec2])
# print([x+y for x in vec1 for y in vec2])
# print([vec1[i]*vec2[i] for i in range(len(vec1))])
# print([str(round(355/113, i)) for i in range(1, 6)])


# basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
# for f in sorted(set(basket)):
#   print(f)

# questions = ['name', 'quest', 'favorite color']
# answers = ['lancelot', 'the holy grail', 'blue']
# for q, a in zip(questions, answers):
#     print('What is your {0}?  It is {1}.'.format(q, a))

# knights = {'gallahad': 'the pure', 'robin': 'the brave','a':'b'}
# for k, v in knights.items():
#     print(k, v)

# matrix = [
#      [1, 2, 3, 4],
#      [5, 6, 7, 8],
#      [9, 10, 11, 12],
#  ]
# print([[row[i] for row in matrix] for i in range(4)])#???
# #
# transposed=[]
# for i in range(4):
#     transposed.append([row[i] for row in matrix])
# print(transposed)
#
# transposed = []
# for i in range(4):
#      # the following 3 lines implement the nested listcomp
#      transposed_row = []
#      for row in matrix:
#          transposed_row.append(row[i])
#      transposed.append(transposed_row)
# print(transposed)

import sys
# for i in sys.argv:
#     print(i)
# print('\n\nPython 路径为：', sys.path, '\n')
# print(dir(sys))

# if __name__ == '__main__':
#    print('程序自身在运行')
# else:
#    print('我来自另一模块')

# f = open("d:/a.txt", "w")
# num=f.write( "Python 是一个非常好的语言。\n是的，的确非常好!!\n" )
# # str=f.readlines()
# print(num)
# f.tell()
# # for line in f:
# #     print(line, end='')
# f.close()

# table = {'Google': 1, 'Runoob': 2, 'Taobao': 3}
# for name, number in table.items():
#      print('{0:10} ==> {1:10d}'.format(name, number))

# import pickle
# # 使用pickle模块将数据对象保存到文件
# data1 = {'a': [1, 2.0, 3, 4+6j],
#          'b': ('string', u'Unicode string'),
#          'c': None}
# selfref_list = [1, 2, 3]
# selfref_list.append(selfref_list)
# output = open('data.pkl', 'wb')
# # Pickle dictionary using protocol 0.
# pickle.dump(data1, output)
# # Pickle the list using the highest protocol available.
# pickle.dump(selfref_list, output, -1)
# output.close()


# import pprint, pickle
# #使用pickle模块从文件中重构python对象
# pkl_file = open('data.pkl', 'rb')
# data1 = pickle.load(pkl_file)
# pprint.pprint(data1)
# data2 = pickle.load(pkl_file)
# pprint.pprint(data2)
# pkl_file.close()


# class JustCounter:
#     __secretCount = 0  # 私有变量
#     publicCount = 0  # 公开变量
#     def count(self):
#         self.__secretCount += 1
#         self.publicCount += 1
#         print(self.__secretCount)
# counter = JustCounter()
# counter.count()
# counter.count()
# print(counter.publicCount)
# print(counter.__secretCount)  # 报错，实例不能访问私有变量

# class Site:
#     def __init__(self, name, url):
#         self.name = name  # public
#         self.__url = url  # private
#     def who(self):
#         print('name  : ', self.name)
#         print('url : ', self.__url)
#     def __foo(self):  # 私有方法
#         print('这是私有方法')
#     def foo(self):  # 公共方法
#         print('这是公共方法')
#         self.__foo()
# x = Site('菜鸟教程', 'www.runoob.com')
# x.who()  # 正常输出
# x.foo()  # 正常输出
# # x.__foo()  # 报错

# class Vector:
#     def __init__(self, a, b):
#         self.a = a
#         self.b = b
#     def __str__(self):
#         return 'Vector (%d, %d)' % (self.a, self.b)
#     def __add__(self, other):
#         return Vector(self.a*other.a, self.b*other.b)
# v1 = Vector(2, 10)
# v2 = Vector(5, -2)
# print(v1+v2)
#
# class people:
#     def __init__(self,name,age):
#         self.name=name
#         self.age=age
#
#     def __str__(self):
#         return '这个人的名字是%s,已经有%d岁了！'%(self.name,self.age)
# a=people('孙悟空',999)
# print(a)

# def this_fails():
#     x = 1 / 0
# try:
#     this_fails()
# except ZeroDivisionError as err:
#     print('Handling run-time error:', err)

# import sys
# try:
#     f = open('myfile.txt')
#     s = f.readline()
#     i = int(s.strip())
# except OSError as err:
#     print("OS error: {0}".format(err))
# except ValueError:
#     print("Could not convert data to an integer.")
# except:
#     print("Unexpected error:", sys.exc_info()[0])
#     raise


# with open("d:/a.txt") as f:
#     for line in f:
#         print(line, end="")
#
# import _thread
# import time
# def print_time( threadName, delay):
#    count = 0
#    while count < 5:
#       time.sleep(delay)
#       count += 1
#       print ("%s: %s" % ( threadName, time.ctime(time.time()) ))
# try:
#    _thread.start_new_thread( print_time, ("Thread-1", 2, ) )
#    _thread.start_new_thread( print_time, ("Thread-2", 4, ) )
# except:
#    print ("Error: 无法启动线程")
# while 1:
#    pass
#

# import threading
# import time
# exitFlag = 0
# class myThread (threading.Thread):
#     def __init__(self, threadID, name, counter):
#         threading.Thread.__init__(self)
#         self.threadID = threadID
#         self.name = name
#         self.counter = counter
#     def run(self):
#         print ("开始线程：" + self.name)
#         print_time(self.name, self.counter, 5)
#         print ("退出线程：" + self.name)
# def print_time(threadName, delay, counter):
#     while counter:
#         if exitFlag:
#             threadName.exit()
#         time.sleep(delay)
#         print ("%s: %s" % (threadName, time.ctime(time.time())))
#         counter -= 1
# thread1 = myThread(1, "Thread-1", 1)
# thread2 = myThread(2, "Thread-2", 2)
# thread1.start()
# thread2.start()
# thread1.join()
# thread2.join()
# print ("退出主线程")

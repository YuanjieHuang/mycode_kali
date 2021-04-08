# import tkinter
# top = tkinter.Tk()
# # 进入消息循环
# top.mainloop()

# from tkinter import * # 导入 Tkinter 库
#
# root = Tk()  # 创建窗口对象的背景色
# # 创建两个列表
# li = ['C', 'python', 'php', 'html', 'SQL', 'java']
# movie = ['CSS', 'jQuery', 'Bootstrap']
# listb = Listbox(root)  # 创建两个列表组件
# listb2 = Listbox(root)
# for item in li:  # 第一个小部件插入数据
#  listb.insert(0, item)
#
# for item in movie:  # 第二个小部件插入数据
#  listb2.insert(0, item)
#
# listb.pack()  # 将小部件放置到主窗口中
# listb2.pack()
# root.mainloop()  # 进入消息循环

# list to dictionnary
# i = ['a', 'b']
# l = [1, 2]
# print (dict([i,l]))

# #要求把这两个文件中的信息合并(按字母顺序排列), 输出到一个新文件C中
# if __name__ == '__main__':
#  import string
#  fp = open('text1.txt')
#  a = fp.read()
#  fp.close()
#  fp = open('text2.txt')
#  b = fp.read()
#  fp.close()
#  fp = open('test3.txt', 'w')
#  l = list(a + b)
#  l.sort()
#  s = ''
#  s = s.join(l)
#  fp.write(s)
#  fp.close()


# str = input('请输入一个字符串:\n')
# with open('test1.txt','w') as f:
#     f.write(str.upper())

# #coding=utf-8
# filename = input('输入文件名:\n')
# fp = open(filename , "w+")
# ch = ''
# while '#' not in ch:
#     fp.write(ch)
#     ch = input('输入字符串:\n')
# fp.close()


# #一个猜数游戏，判断反应快慢。
# if __name__ == '__main__':
#  import time
#  import random
#
#  play_it = input('do you want to play it.(\'y\' or \'n\')')
#  while play_it == 'y':
#   c = input('input a character:\n')
#   i = random.randint(0, 2 ** 32) % 100
#   print('please input number you guess:\n')
#   start = time.clock()
#   a = time.time()
#   guess = int(input('input your guess:\n'))
#   while guess != i:
#    if guess > i:
#     print('please input a little smaller')
#     guess = int(input('input your guess:\n'))
#    else:
#     print('please input a little bigger')
#     guess = int(input('input your guess:\n'))
#   end = time.clock()
#   b = time.time()
#   var = (end - start) / 18.2
#   print(var)
#   # print 'It took you %6.3 seconds' % time.difftime(b,a))
#   if var < 15:
#    print('you are very clever!')
#   elif var < 25:
#    print('you are normal!')
#   else:
#    print('you are stupid!')
#   print('Congradulations')
#   print('The number you guess is %d' % i)
#   play_it = input('do you want to play it.')


# def test():
#  for i in range(3000):
#   print(i)
# if __name__ == '__main__':
#  from timeit import timeit
#  t = timeit('test()', 'from __main__ import test', number=1)
#  print(t)

'''
某个公司采用公用电话传递数据，数据是四位的整数，在传递过程中是加密的，加密规则如下：
每位数字都加上5,然后用和除以10的余数代替该数字，再将第一位和第四位交换，
第二位和第三位交换。'''
# from sys import stdout
# if __name__ == '__main__':
#  a = int(input('输入四个数字:\n'))
#  aa = []
#  aa.append(a % 10)
#  aa.append(a % 100 / 10)
#  aa.append(a % 1000 / 100)
#  aa.append(a / 1000)
# 
#  for i in range(4):
#   aa[i] += 5
#   aa[i] %= 10
#  for i in range(2):
#   aa[i], aa[3 - i] = aa[3 - i], aa[i]
#  for i in range(3, -1, -1):
#   stdout.write(str(aa[i]))


# 读取7个数（1—50）的整数值，每读取一个值，程序打印出该值个数的＊。
# if __name__ == '__main__':
# #     n = 1
# #     while n <= 7:
# #         a = int(input('input a number:\n'))
# #         while a < 1 or a > 50:
# #             a = int(input('input a number:\n'))
# #         print (a * '*')
#         n += 1##???

# if __name__ == '__main__':
#     str = 'qerqwe'
#     str2 = 'dsdd'
#     str3 = 'wrwr'
#     strjoin = ''
#     strjoin = strjoin.join([str,str2,str3])
#     print(strjoin)


# if __name__ == '__main__':
#     zi = int(input('输入一个数字:\n'))
#     n1 = 1
#     c9 = 1
#     m9 = 9
#     sum = 9
#     while n1 != 0:
#         if sum % zi == 0:
#             n1 = 0
#         else:
#             m9 *= 10
#             sum += m9
#             c9 += 1
#     print ('%d 个 9 可以被 %d 整除 : %d' % (c9,zi,sum))
#     r = sum / zi
#     print ('%d / %d = %d' % (sum,zi,r))

# # 求0—7所能组成的奇数个数
# if __name__ == '__main__':
#     sum = 4
#     s = 4
#     for j in range(2,9):
#         print (sum)
#         if j <= 2:
#             s *= 7
#         else:
#             s *= 8
#         sum += s
#     print('sum = %d' % sum)


# 海滩上有一堆桃子，五只猴子来分。第一只猴子把这堆桃子平均分为五份，
# 多了一个，这只猴子把多的一个扔入海中，拿走了一份。
# 第二只猴子把剩下的桃子又平均分成五份，又多了一个，它同样把多的一个扔入海中，
# 拿走了一份，第三、第四、第五只猴子都是这样做的，问海滩上原来最少有多少个桃子？
# if __name__ == '__main__':
#     i = 0
#     j = 1
#     x = 0
#     while (i < 5) :
#         x = 4 * j
#         for i in range(0,5) :
#             if(x%4 != 0) :
#                 break
#             else :
#                 i += 1
#             x = (x/4) * 5 +1
#         j += 1
#     print (x)

# 猴子分桃，最少问题分析：问最少有多少只桃子，则岸上最后剩的桃子数目越小，则原岸上的桃子越少
# 假设最后岸上还剩4x只桃子,可以利用递归方法求解
# num = int(input("输入猴子的数目:"))
# def fn(n):
#  if n == num:
#   return (4 * x)  # 最后剩的桃子的数目
#  else:
#   return (fn(n + 1) * 5 / 4 + 1)
# x = 1
# while 1:
#  count = 0
#  for i in range(1, num):
#   if fn(i) % 4 == 0:
#    count = count + 1
#  if count == num - 1:
#   print("海滩上原来最少有%d个桃子" % int(fn(0)))
#   break
#  else:
#   x = x + 1

# import operator
# __author__ = 'Lei Zhong'
# person = {"li":18,"wang":50,"zhang":20,"sun":22}
# print (max(person.iteritems(), key=operator.itemgetter(1))[0])    # 获取最大值的 key
# print (max(person.values())                                      # 获取最大值)

# person = {"li":18,"wang":50,"zhang":20,"sun":22}
# def find_max(dict):
#     max_age = 0
#     for key, value in dict.items():
#         if value > max_age:
#             max_age = value
#             name = key
#     print (name)
#     print (max_age)
# find_max(person)

# if __name__ == '__main__':
#     for i in range(5):
#         n = 0
#         if i != 1: n += 1
#         if i == 3: n += 1
#         if i == 4: n += 1
#         if i != 4: n += 1
#         if n == 3: print (64 + i)

# if __name__ == '__main__':
#     ptr = []
#     for i in range(5):
#         num = int(input('please input a number:\n'))
#         ptr.append(num)
#     print (ptr)
#     ptr.reverse()
#     print (ptr)


# 企业发放的奖金根据利润提成
# i = int(input('净利润:'))
# arr = [1000000,600000,400000,200000,100000,0]
# rat = [0.01,0.015,0.03,0.05,0.075,0.1]
# r = 0
# for idx in range(0,6):
#     if i>arr[idx]:
#         r+=(i-arr[idx])*rat[idx]
#         # print( (i-arr[idx])*rat[idx])
#         i=arr[idx]
# print (r)

'''
# 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
程序分析：
假设该数为 x。
1、则：x + 100 = n2, x + 100 + 168 = m2
2、计算等式：m2 - n2 = (m + n)(m - n) = 168
3、设置： m + n = i，m - n = j，i * j =168，i 和 j 至少一个是偶数
4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。
5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。
6、由于 i * j = 168， j>=2，则 1 < i < 168 / 2 + 1。
7、接下来将 i 的所有数字循环计算即可。
'''
# for i in range(1,85):
#     if 168 % i == 0:
#         j = 168 / i;
#         if  i > j and (i + j) % 2 == 0 and (i - j) % 2 == 0 :
#             m = (i + j) / 2
#             n = (i - j) / 2
#             x = n * n - 100
#             print(x)

# 将一个列表的数据复制到另一个列表中
# a = [1, 2, 3]
# b = a[:]

# import time,datetime
#
# time.sleep(1)
# TIME = datetime.datetime.now()
# print(TIME.strftime("%Y.%m.%d %H-%M-%S"))


# f1 = 1
# print(type(f1))
# f2 = 1
# for i in range(1,22):
#     print ('%12ld %12ld' % (f1,f2),)
#     if (i % 3) == 0:
#         print ('')
#     f1 = f1 + f2
#     f2 = f1 + f2

# Tn = 0
# Sn = []
# n = int(input('n = '))
# a = int(input('a = '))
# for count in range(n):
#  Tn = Tn + a
#  a = a * 10
#  Sn.append(Tn)
#  print(Tn)
# Sn = reduce(lambda x, y: x + y, Sn)#??
# print("计算和为：", Sn)


# tour = []
# height = []
# hei = 100.0  # 起始高度
# tim = 2  # 次数
# for i in range(1, tim + 1):
#  # 从第二次开始，落地时的距离应该是反弹高度乘以2（弹到最高点再落下）
#  if i == 1:
#   tour.append(hei)
#  else:
#   tour.append(2 * hei)
#  hei /= 2
#  height.append(hei)
# print('总高度：tour = {0}'.format(sum(tour)))
# print('第10次反弹高度：height = {0}'.format(height[-1]))


# a = 2.0
# b = 1.0
# l = []
# l.append(a / b)
# for n in range(1,20):
#     b,a = a,a + b
#     l.append(a / b)
# print(lambda x,y: x + y,l)


# # 一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如6=1＋2＋3.编程找出1000以内的所有完数。
# from sys import stdout
# for j in range(2, 1001):
#  k = []
#  n = -1
#  s = j
#  for i in range(1, j):
#   if j % i == 0:
#    n += 1
#    s -= i
#    k.append(i)
#  if s == 0:
#   print( j)
#   for i in range(n):
#    stdout.write(str(k[i]))
#    stdout.write(' ')
#   print(k[n])

# for i in range(ord('x'),ord('z') + 1):
#     for j in range(ord('x'),ord('z') + 1):
#         if i != j:
#             for k in range(ord('x'),ord('z') + 1):
#                 if (i != k) and (j != k):
#                     if (i != ord('x')) and (k != ord('x')) and (k != ord('z')):
#                         print ('order is a -- %s\t b -- %s\tc--%s' % (chr(i),chr(j),chr(k)))

# n = 0
# s = 0
# t = 1
# for n in range(1,21):
#     t *= n
#     s += t
# print ('1! + 2! + 3! + ... + 20! = %d' % s)
#
# s = 0
# l = range(1,21)
# def op(x):
#     r = 1
#     for i in range(1,x + 1):
#         r *= i
#     return r
# s = sum(map(op,l))
# print ('1! + 2! + 3! + ... + 20! = %d' % s)
# u=map(lambda x, y: x + y, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])
# def square(x) :            # 计算平方数
#    return x ** 2
# v=map(square, [1, 2, 3, 4, 5])
# print(list(u),list(v))

#
# def output(s, l):
#  if l == 0:
#   return
#  print(s[l - 1])
#  output(s, l - 1)
# s = input('Input a string:')
# l = len(s)
# output(s, l)

# a = int(input("请输入一个数字:\n"))
# x = str(a)
# flag = True
# for i in range(len(x) // 2):
#  if x[i] != x[-i - 1]:
#   flag = False
#   break
# if flag:
#  print("%d 是一个回文数!" % a)
# else:
#  print("%d 不是一个回文数!" % a)

# 有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，
# 他说比第3个人大2岁。问第三个人，又说比第2人大两岁。
# 问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。
# 请问第五个人多大？
# def age(n):
#  if n == 1:
#   c = 10
#  else:
#   c = age(n - 1) + 2
#  return c
# print(age(5))

#
# # 将一个数组逆序输出
# if __name__ == '__main__':
#     a = [9,6,5,4,1]
#     N = len(a)
#     print (a)
#     for i in range(len(a) // 2):
#         a[i],a[N - i - 1] = a[N - i - 1],a[i]
#     print (a)


# # 现输入一个数，要求按原来的规律将它插入数组中。
# if __name__ == '__main__':
#     # 方法一 ： 0 作为加入数字的占位符
#     a = [1,4,6,9,13,16,19,28,40,100,0]
#     print( '原始列表:',list(a))
#     number = int(input("\n插入一个数字:\n"))
#     end = a[9]
#     if number > end:
#         a[10] = number
#     else:
#         for i in range(10):
#             if a[i] > number:
#                 temp1 = a[i]
#                 a[i] = number
#                 for j in range(i + 1,11):
#                     temp2 = a[j]
#                     a[j] = temp1
#                     temp1 = temp2
#                 break
#     print ('排序后列表:',list(a))

# # 求一个3*3矩阵主对角线元素之和
# if __name__ == '__main__':
#     a = []
#     sum = 0.0
#     for i in range(3):
#         a.append([])
#         for j in range(3):
#             a[i].append(float(input("input num:\n")))
#     for i in range(3):
#         sum += a[i][i]
#     print (sum)


# class bcolors:
#  HEADER = '\033[95m'
#  OKBLUE = '\033[94m'
#  OKGREEN = '\033[92m'
#  WARNING = '\033[93m'
#  FAIL = '\033[91m'
#  ENDC = '\033[0m'
#  BOLD = '\033[1m'
#  UNDERLINE = '\033[4m'
# print(bcolors.WARNING + "警告的颜色字体?" + bcolors.ENDC)

# L = [1,2,3,4,5]
# s1 = ','.join(str(n) for n in L)
# print (s1)

# a = ['one', 'two', 'three']
# for i in a[::-1]:
#     print (i)

# # 输出指定范围内的素数
# lower = int(input("输入区间最小值: "))
# upper = int(input("输入区间最大值: "))
# for num in range(lower, upper + 1):
#  # 素数大于 1
#  if num > 1:
#   for i in range(2, num):
#    if (num % i) == 0:
#     break
#   else:
#    print(num)

# MAXIMUM = lambda x, y: (x > y) * x + (x < y) * y
# MINIMUM = lambda x, y: (x > y) * y + (x < y) * x
# if __name__ == '__main__':
#  a = 10
#  b = 20
#  print( 'The largar one is %d' % MAXIMUM(a, b))
#  print('The lower one is %d' % MINIMUM(a, b))
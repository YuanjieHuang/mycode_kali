# print yanghui trangle
# if __name__ == '__main__':
#     a = []
#     for i in range(10):
#         a.append([])
#         for j in range(10):
#             a[i].append(0)
#     for i in range(10):
#         a[i][0] = 1
#         a[i][i] = 1
#     for i in range(2,10):
#         for j in range(1,i):
#             a[i][j] = a[i - 1][j-1] + a[i - 1][j]
#     from sys import stdout
#     for i in range(10):
#         for j in range(i + 1):
#             stdout.write(str(a[i][j]))
#             stdout.write(' ')
#         print

# # 打印椭圆
# if __name__ == '__main__':
#  from tkinter import *
#  x = 360
#  y = 160
#  top = y - 30
#  bottom = y - 30
#  canvas = Canvas(width=400, height=600, bg='white')
#  for i in range(20):
#   canvas.create_oval(250 - top, 250 - bottom, 250 + top, 250 + bottom)
#   top -= 5
#   bottom += 5
#  canvas.pack()
#  mainloop()

# # 有n个人围成一圈，顺序排号。从第一个人开始报数（从1到3报数），凡报到3的人退出圈子，
# # 问最后留下的是原来第几号的那位
# if __name__ == '__main__':
#  nmax = 50
#  n = int(input('请输入总人数:'))
#  num = []
#  for i in range(n):
#   num.append(i + 1)
#  i = 0
#  k = 0
#  m = 0
#  while m < n - 1:
#   if num[i] != 0: k += 1
#   if k == 3:
#    num[i] = 0
#    k = 0
#    m += 1
#   i += 1
#   if i == n: i = 0
#  i = 0
#  while num[i] == 0: i += 1
#  print(num[i])

# # 有n个整数，使其前面各数顺序向后移m个位置，最后m个数变成最前面的m个数
# if __name__ == '__main__':
#  n = int(input('整数 n 为:\n'))
#  m = int(input('向后移 m 个位置为:\n'))
#  def move(array, n, m):
#   array_end = array[n - 1]
#   for i in range(n - 1, -1, - 1):
#    array[i] = array[i - 1]
#   array[0] = array_end
#   m -= 1
#   if m > 0: move(array, n, m)
#  number = []
#  for i in range(n):
#   number.append(int(input('输入一个数字:\n')))
#  print('原始列表:', number)
#  move(number, n, m)
#  print('移动之后:', number)

# import math
# class PTS:
#  def __init__(self):
#   self.x = 0
#   self.y = 0
# points = []
# def LineToDemo():
#  from tkinter import *
#  screenx = 400
#  screeny = 400
#  canvas = Canvas(width=screenx, height=screeny, bg='white')
#
#  AspectRatio = 0.85
#  MAXPTS = 15
#  h = screeny
#  w = screenx
#  xcenter = w / 2
#  ycenter = h / 2
#  radius = (h - 30) / (AspectRatio * 2) - 20
#  step = 360 / MAXPTS
#  angle = 0.0
#  for i in range(MAXPTS):
#   rads = angle * math.pi / 180.0
#   p = PTS()
#   p.x = xcenter + int(math.cos(rads) * radius)
#   p.y = ycenter - int(math.sin(rads) * radius * AspectRatio)
#   angle += step
#   points.append(p)
#  canvas.create_oval(xcenter - radius, ycenter - radius,
#                     xcenter + radius, ycenter + radius)
#  for i in range(MAXPTS):
#   for j in range(i, MAXPTS):
#    canvas.create_line(points[i].x, points[i].y, points[j].x, points[j].y)
#  canvas.pack()
#  mainloop()
#
#
# if __name__ == '__main__':
#  LineToDemo()


# # 求0—7所能组成的奇数个数。
# if __name__ == '__main__':
#     sum = 4
#     s = 4
#     for j in range(2,9):
#         print(sum)
#         if j <= 2:
#             s *= 7
#         else:
#             s *= 8
#         sum += s
#     print('sum = %d' % sum)


# if __name__ == '__main__':
#     from tkinter import *
#     canvas = Canvas(width = 400,height = 600,bg = 'white')
#     left = 20
#     right = 50
#     top = 50
#     num = 15
#     for i in range(num):
#         canvas.create_oval(250 - right,250 - left,250 + right,250 + left)
#         canvas.create_oval(250 - 20,250 - top,250 + 20,250 + top)
#         canvas.create_rectangle(20 - 2 * i,20 - 2 * i,10 * (i + 2),10 * ( i + 2))
#         right += 5
#         left += 5
#         top += 10
#     canvas.pack()
#     mainloop()
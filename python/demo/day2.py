# import calendar
# cal = calendar.month(2018,8 )
# print (cal)
# print(dir([]))
# 引入 datetime 模块
# import datetime
# def getYesterday():
#     today = datetime.date.today()
#     oneday = datetime.timedelta(days=1)
#     yesterday = today - oneday
#     return yesterday
# print(getYesterday())

# # # 写文件
# with open("test.txt", "w") as out_file:
#     out_file.write("该文本会写入到文件中\n看到我了吧！")
# Read a file
# with open("test.txt", "rt") as in_file:
#     text = in_file.read()
# print(text)

# params = {"server":"mpilgrim", "database":"master", "uid":"sa", "pwd":"secret"}
# print(["%s=%s" % (k, v) for k, v in params.items()])
# t=";".join(["%s=%s" % (k, v) for k, v in params.items()])
# print(t)
#
# li = [1, 9, 8, 4]
# print([elem*2 for elem in li])

# params = {"server":"mpilgrim", "database":"master", "uid":"sa", "pwd":"secret"}
# print(["%s=%s" % (k, v) for k, v in params.items()])

# li = ["a", "mpilgrim", "foo", "b", "c", "b", "d", "d"]
# print([elem for elem in li if li.count(elem) == 1])
# import sys
# print(sys.builtin_module_names)

# class Bird:
#     '''this is my first type'''
#     def __init__(self,sex='man'):
#         self.__feathers='yes'
#         self.__bones='hollow'
#         self.__eggs='hard-shell'
#         self.__sex=sex
#     def set_sex(self,sex):
#         self.__sex=sex
#     def get_sex(self):
#         return self.__sex
#     def __str__(self):
#         return 'feather-{0},bones-{1},eggs-{2},sex-{3}'.format(self.__feathers,self.__bones,self.__eggs,self.__sex)
#     sex=property(get_sex,set_sex)
# bird=Bird()
# bird.set_sex('women')
# print(bird)
# print(bird.__doc__)
class Empty:
    pass

class TheFirstDemo:
    '''这是一个学习Python定义的第一个类'''
    # 下面定义了一个类属性
    add = 'http://c.biancheng.net'
    # 下面定义了一个say方法
    def say(self, content):
        print(content)

class CLanguage :
    # 下面定义了2个类变量
    name = "C语言中文网"
    add = "http://c.biancheng.net"
    def __init__(self,name,add):
        #下面定义 2 个实例变量
        self.name = name
        self.add = add
        print(name,"网址为：",add)
    # 下面定义了一个say实例方法
    def say(self, content):
        print(content)

# 将该CLanguage对象赋给clanguage变量
clanguage = CLanguage("C语言中文网","http://c.biancheng.net")
# 为clanguage对象增加一个money实例变量
clanguage.money= 159.9
print(clanguage.money)

#删除新添加的 money 实例变量
del clanguage.money
#再次尝试输出 money，此时会报错
print(clanguage.money)
'''
使用函数、lambda 表达式为 clanguage 对象动态增加了方法，
但对于动态增加的方法，Python 不会自动将方法调用者绑定到它们的第一个参数，
因此程序必须手动为第一个参数传入参数值，如下面程序中 ① 号、② 号代码所示。
'''
# 先定义一个函数
def info1(self):
    print("---info函数---", self)
# 使用info对clanguage的foo方法赋值（动态绑定方法）
clanguage.foo = info1
# Python不会自动将调用者绑定到第一个参数，
# 因此程序需要手动将调用者绑定为第一个参数
clanguage.foo(clanguage)  # ①
# 使用lambda表达式为clanguage对象的bar方法赋值（动态绑定方法）
clanguage.bar = lambda self: print('--lambda表达式--', self)
clanguage.bar(clanguage) # ②

def info(self,content):
    print("C语言中文网地址为：%s" % content)
# 导入MethodType
from types import MethodType
clanguage.info = MethodType(info, clanguage)
# 第一个参数已经绑定了，无需传入
clanguage.info("http://c.biancheng.net")



class CLanguage :
    name = "xxx"  #类变量
    add = "http://"  #类变量
    def __init__(self):
        self.name = "C语言中文网"   #实例变量
        self.add = "http://c.biancheng.net"   #实例变量
    # 下面定义了一个say实例方法
    def say(self):
        self.catalog = 13  #实例变量
    def count(self,money):
        sale = 0.8*money   #局部变量直接以“变量名=值”的方式进行定义
        print("优惠后的价格为：",sale)
clang = CLanguage()
clang.count(100)
clang = CLanguage()
#修改 clang 对象的实例变量
clang.name = "python教程"
clang.add = "http://c.biancheng.net/python"
print(clang.name)
print(clang.add)
clang2 = CLanguage()
print(clang2.name)
print(clang2.add)
#输出类变量的值
print(CLanguage.name)
print(CLanguage.add)


    class Rect:
        def __init__(self,area):
            self.__area = area
        @property
        def area(self):
            return self.__area
        @area.setter
        def area(self, value):
            self.__area = value
        @area.deleter
        def area(self):
            self.__area = 0
    rect = Rect(30)
    #直接通过方法名来访问 area 方法
    print("矩形的面积是：",rect.area)
    rect.area = 90
    print("修改后的面积：",rect.area)
    del rect.area
    print("删除后的area值为：",rect.area)



    class People:
        def __init__(self):
            self.name = People
        def say(self):
            print("People类",self.name)
    class Animal:
        def __init__(self):
            self.name = Animal
        def say(self):
            print("Animal类",self.name)
    #People中的 name 属性和 say() 会遮蔽 Animal 类中的
    class Person(People, Animal):
        pass
    zhangsan = Person()
    zhangsan.name = "张三"
    zhangsan.say()
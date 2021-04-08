#描述符类
class revealAccess:
    def __init__(self, initval = None, name = 'var'):
        self.val = initval
        self.name = name
    def __get__(self, obj, objtype):
        print("Retrieving",self.name)
        return self.val
    def __set__(self, obj, val):
        print("updating",self.name)
        self.val = val
class myClass:
    x = revealAccess(10,'var "x"')
    y = 5
m = myClass()
print(m.x)
m.x = 20
print(m.x)
print(m.y)


class CLanguage:
    #构造函数
    def __init__(self,n):
        self.__name = n
    #设置 name 属性值的函数
    def setname(self,n):
        self.__name = n
    #访问nema属性值的函数
    def getname(self):
        return self.__name
    #删除name属性值的函数
    def delname(self):
        self.__name="xxx"
    #为name 属性配置 property() 函数
    name = property(getname, setname, delname, '指明出处')
#调取说明文档的 2 种方式
#print(CLanguage.name.__doc__)
help(CLanguage.name)
clang = CLanguage("C语言中文网")
#调用 getname() 方法
print(clang.name)
#调用 setname() 方法
clang.name="Python教程"
print(clang.name)
#调用 delname() 方法
del clang.name
print(clang.name)
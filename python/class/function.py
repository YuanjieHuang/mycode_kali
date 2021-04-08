    def dis_str(str1,str2):
        print("str1:",str1)
        print("str2:",str2)
    #位置参数  实参和形参数量必须一致；实参和形参位置必须一致
    dis_str("http://c.biancheng.net/python/","http://c.biancheng.net/shell/")
    #关键字参数
    # 关键字参数是指使用形式参数的名字来确定输入的参数值。通过此方式指定函数实参时，不再需要与形参的位置完全一致，只要将参数名写正确即可。
    dis_str("http://c.biancheng.net/python/",str2="http://c.biancheng.net/shell/")
    dis_str(str2="http://c.biancheng.net/python/",str1="http://c.biancheng.net/shell/")

    # 偏函数名 = partial(func, *args, **kwargs)
    from functools import partial
    #定义个原函数
    def display(name,age):
        print("name:",name,"age:",age)
    #定义偏函数，其封装了 display() 函数，并为 name 参数设置了默认参数
    GaryFun = partial(display,name = 'Gary')
    #由于 name 参数已经有默认值，因此调用偏函数时，可以不指定
    GaryFun(age = 13)

    # 闭包中外部函数返回的不是一个具体的值，而是一个函数。一般情况下，返回的函数会赋值给一个变量，这个变量可以在后面被继续执行调用。
    #闭包函数，其中 exponent 称为自由变量
    def nth_power(exponent):
        def exponent_of(base):
            return base ** exponent
        return exponent_of # 返回值是 exponent_of 函数
    square = nth_power(2) # 计算一个数的平方
    cube = nth_power(3) # 计算一个数的立方
    print(square(2))  # 计算 2 的平方
    print(cube(2)) # 计算 2 的立方

    def nth_power(exponent):
        def exponent_of(base):
            return base ** exponent
        return exponent_of
    square = nth_power(2)
    #查看 __closure__ 的值
    print(square.__closure__)

# lambda 表达式的语法格式如下：
# name = lambda [list] : 表达式
    def name(list):
        return 表达式
    name(list)

    add = lambda x,y:x+y
    print(add(3,4))

    a = 1
    exec("a = 2") #相当于直接执行 a=2
    print(a)
    a = exec("2+3") #相当于直接执行 2+3，但是并没有返回值，a 应为 None
    print(a)
    a = eval('2+3') #执行 2+3，并把结果返回给 a
    print(a)
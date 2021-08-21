int test1()
{
    int a = 3;
    test1();		//递归, 非尾递归 
    //返回后继续处理 
    a = a + 4;
    return a;
}

int test2()
{
    int q = 4;
    q = q + 5;
    return q + test1();	//非尾递归, 仍然有加法要做
}

int test3()
{
    int b = 5;
    b = b + 2;
    return test1();	//尾递归
}

int test4()
{
    test3();	//不在尾位置
    test3();	//不在尾位置
    return test3();	//在尾位置
}

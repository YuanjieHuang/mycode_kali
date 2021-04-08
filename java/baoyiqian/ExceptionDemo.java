/*
异常：程序在运行时出现不正常情况

由来：问题也是在现实生活中一个具体的事物，也可以通过Java的类的形式进行描述。并封装成对象。
	  其实就是Java对不正常情况进行描述后的对象体现。

对问题的划分：两种：严重的问题，非严重的问题。。

对于严重的，Java通过Error类进行描述。
对于Error一般不编写针对性的代码对其进行处理。

对于非严重的，Java通过Exception类进行描述。
    处理
无论Error或者Exception都具有一些共性内容。
比如：不正常情况的信息，引发原因等。


2,异常的处理
Java提供了特有的语句进行处理。
try
{
	需要被检查的代码；
}
catch(异常类 变量)
{
	处理异常的代码;(处理方式)
}
finally
{
	一定会执行的语句;
}

Throwable
	|--Error
	|--Exception

3,对捕获到的异常对象进行常见方法操作。
Sting getMesseger(); 

在函数上声明异常。
便于提高安全性，让调用出进行处理。不处理编译失败。

对异常的处理。

1，声明异常时，建议声明更为更为具体的异常。这样处理的可以更具体。
2，对方声明几个异常，就对应偶几个catch快。
	如果多个catch快中的异常出现继承关系，父类异常catch快放在最下面。
建议在进行catch处理时，catch中一定要定义具体处理方式。
不要简单定义一句e.printStackTrace(),
也不要简单的就书写一条输出语句。
3，
*/

/*
自定义异常。
需求：在本程序中，对于除数时-1，也视为时错误的是无法进行运算的。
那么就需要对这个问题进行自定义的描述。 


一般情况在函数内出现异常，函数上需要声明。

发现打印的结果只有异常的名称，却没有异常的信息。
因为自定义的异常并未定义信息。

如何定义异常信息呢？
因为父类中已经把异常的信息的操作都完成了。
所以子类只要在构造时，将异常信息传递给父类通过super语句。
那么就可以直接通过getMessage方法获取字定义的异常信息。

自定义异常：
必须是自定义类继承Exception
原因：
异常体系有一个特点：因为异常类和异常对象都被抛出。
他们都具备可抛性。这个可抛性是Throwable这个体系独有特性。
只有这个体系中的类和对象才可以被throws和throw操作。


Throws和Throw的区别
Throws使用在函数上
Throw使用在函数内

throws后面跟的异常类，可以跟多个,用逗号隔开。
Throw后跟的是异常对象



*/
class Demo
{
	int div(int a,int b)throws Exception//在功能上通过throws的关键字声明了该功能有可能会出现问题。
	{
		return a/b;
	}
}
class  ExceptionDemo
{
	public static void main(String[] args) 
	{
		Demo d=new Demo();
		try
		{
			int x=d.div(4,0);
			
		System.out.println("x="+x);

		}
		catch (Exception e)
		{
			
			System.out.println("除零了");
		}
		
		
		System.out.println("Over");
	}
}

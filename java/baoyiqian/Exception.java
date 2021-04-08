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
*/
class Demo
{
	int div(int a,int b)
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

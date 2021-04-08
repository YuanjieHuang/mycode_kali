/*
接口：初期理解，可以认为是一个特殊的抽象类。
	当抽象类中的方法都是抽象的，那么该类可以通过接口的形式来表示。
class用于定义类
interface用于定义接口

接口定义时，格式特点：
1，接口的常见定义：常量，抽象方法。
2，接口中的成员都有固定修饰符
	常量：public static final
	方法：public abstract
记住：接口中的成员都是public的

接口可以被类多实现（一个类可以同时实现多个接口），
也是对多继承不支持的转换形式，Java支持多实现。
接口与接口的关系为继承，且 支持多继承


*/

interface Inter
{
	public static final int NUM=3;
	public abstract void show();
}
class Test implements Inter
{
	public void show(){}
}
interface A
{
}

class InterfaceDemo 
{
	public static void main(String[] args) 
	{
		Test t=new Test();
		System.out.println("Test.NUM");
		System.out.println("Inter.NUM");
		System.out.println("t.NUM");
	}
}

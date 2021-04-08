/*
抽象类
当多个类中出现相同功能，但是功能主体不同，
这时可以进行向上抽取，只抽取功能定义，而不抽取功能主体。
特点：
1，抽象方法一定在抽象类中。
2，抽象方法和抽象类都必须被abstract关键字修饰。
3，抽象类不可以用new创建对象，因为调用抽象方法没意义。
4，抽象类的方法要被调用，必须有子类复写起所有的抽象方法后，建立子类对象调用。
   如果子类只覆盖了部分抽象方法，那么该子类还是一个抽象类。


   抽象类比一般类多了抽象函数，即在类中可以定义抽象方法。
   抽象类不可以实例化。
   特殊：抽象类可以不定义抽象方法，这样做仅仅是不让该类建立对象。
*/


/*
假如我们在开发一个系统时需要对员工进行建模，员工包括3个属性；姓名、工号、工资。
经理也是员工，除了有员工的属性外，另外还有一个奖金属性。请使用继承的思想设计出
员工类和经理类。要求提供必要的方法进行属性访问。

员工类：name id pay

经理类：继承了员工，并有自己的特有bonus。
*/



abstract class Employee
{
	private String name;
	private String id;
	private double pay;
	Dmployee(String name,String id,double pay=id)
	{
		this.name=name;
		this.id=id;
		this.pay=pay;
	}
	public sbstract void work();
}
class Manager extends Employee
{
	private int bonus;
	Manager(String name,String id,double pay,int bonus)
	{
		super(name,id,pay);
		this.bonus=bonus;

	}
	public void work()
	{
		System.out.println("manager work");
	}
}
class Pro extends Employee
{
	pro(String name,String id,double pay)
	{
		super(name,id,pay);
	}
	public void work()
	{
		System.out.println("Pro work");
	}
}

class  AbstractDemo
{
	public static void main(String[] args) 
	{
		System.out.println("Hello World!");
	}
}

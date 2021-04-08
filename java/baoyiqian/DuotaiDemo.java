/*
多态：可以理解为事物存在多种体现形态。
人：男人，女人
猫 x=new 猫();
动物 x=new 猫();
  
1,多态的体现
	父类的引用指向了自己的子类对象。
	父类的引用也可以接受自己的子类对象。

2，多态的前提
	必须时类与类之间有关系。要么继承，要么实现。
	存在覆盖

3，多态的好处
	提高程序的扩展性

4，多态的弊端
	提高了扩展性，但是只能使用父类的引用访问父类的成员。

5，多态的应用
	 



*/

/*
在多态中成员函数的特点：
在编译时期：参阅引用型变量所属的类中是否有调用的方法。如果有，编译通过，如果没有，编译失败。
在运行时期：参阅对象所属的类中是否有调用的方法。
总结：成员函数在多态调用时，编译看左边，运行看右边。 

在多态中，成员变量的特点：
无论编译和运行，都参考左边（引用型变量所属的类）

在多态中，静态成员函数的特点:
无论编译和运行，都参考左边



*/

abstract class Animal
{
	public abstract void eat();
}

class Cat extends Animal
{
	public void eat()
	{
		System.out.println("吃鱼");
	}
	public void catchMouse()
	{
		System.out.println("抓老鼠");
	}

}
class Dog extends Animal
{
	public void eat()
	{
		System.out.println("吃骨头");
	}
	public void kanjia()
	{
		System.out.println("看家");
	}

}

class Pig extends Animal
{
	public void eat()
	{
		System.out.println("饲料");
	}
	public void gongDi()
	{
		System.out.println("拱地");
	}

}



class  DuotaiDemo
{
	public static void main(String[] args) 
	{
		/*
		function(new Cat());
		function(new Dog());
		function(new Pig());
		System.out.println("Hello World!");
		*/
		Animal a = new Cat();//类型提升。向上转型
		a.eat();
		//如果想要调用猫的特有方法时，如何操作？
		//强制将父类的引用转成子类类型。向下转型
		Cat c=(Cat)a;
		c.catchMouse();
		//千万不要将父类对象转成子类类型。
		//我们能转换的是父类应用指向了自己的子类对象时，该应用可以被提升，也可以被强制转换。
		//多态自始至终都是子类对象在做着变化

	}
	
	public static void function(Animal a) //Animal a=new Cat();
	{
		a.eat();
	}
	
}

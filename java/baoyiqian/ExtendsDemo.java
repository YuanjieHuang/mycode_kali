/*
子父类出现后，类成员的特点：
类中成员：
1，变量。
    如果子类中出现非私有的同名成员变量时，子类要访问本类中的变量，用this;子类要访问父类中的同名变量，用super。
2，函数。
	当子父类出现一摸一样的函数时，当子类对象调用该函数，会运行子类函数的内容。如同父类的函数被覆盖一样
	这种情况时函数的另一特性：重写（覆盖）。
	当子类继承父类，演习了父类的功能到子类中，但是子类虽具备该功能，但是功能的内容却和父类不一致，
	这时，没有必要定义新功能，而是使用覆盖特殊，保留父类的功能定义，并重写内容。

	覆盖：
	子类覆盖父类，必须保证子类权限大于等于父类权限，才可以覆盖，否则编译失败。
	静态只能覆盖静态。
	注意：
	重载：只看同名函数的参数列表。
	重写：子父类方法要一摸一样。

3，构造函数。
	在对子类对象进行初始化时，父类的构造函数也会运行，
	那是因为子类的构造函数默认第一行有一条饮食的语句super();
	super();会访问父类中空参数的构造函数，而且子类中所有的构造函数默认第一行都是super();

	为什么子类一定要访问父类中的构造函数？
	因为父类中的数据子类可以直接获取，所以子类对象在建立时，需要先查看父类时如何对这些数据进行初始化的。
	所以子类在对象初始化时，要先访问以下父类中的构造函数。
	如果要访问父类中指定的构造函数，可以通过手动定义super语句方式来指定。
	super语句一定定义在子类构造函数的第一行。

	子类的实例化过程
	结论：
	子类的所有构造函数，默认都会访问父类中空参数的构造函数。
	因为子类每一个构造函数的第一行都有一句隐式super();
	当父类中没有空参数的构造函数时，子类必须手动通过super语句形式来指定要访问父类中的构造函数。
	当然：子类的构造函数第一行也可以手动指定this语句来访问本类中的构造函数。
	子类中至少会有一个构造函数会访问父类中的构造函数。
*/

class Fu
{
	private int num=4;
}

class Zi extends Fu
{
	
	//super();调用父类构造函数。
	int num=5;
	void show()//默认权限 
	{
		System.out.println(super.num);
	}
}



class  ExtendsDemo
{
	public static void main(String[] args) 
	{
		Zi z=new Zi();
		z.show();
		
		System.out.println("Hello World!");
	}
}

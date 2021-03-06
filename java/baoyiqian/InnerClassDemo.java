/*
内部类的访问规则：
1，内部类可以直接访问外部类中的成员，包括私有。
	原因：内部类中持有了一个外部类的引用。格式:外部类名.this.

2，外部类要访问内部类，必须建立内部类对象。

访问格式：
1，当内部类定义在外部类的成员位置上，而非私有，可以在外部其他类中。
可以直接建立内部类对象。
格式
	外部类名.内部类名 变量名=外部类对象.内部类对象;
	Outer.Inner in=new Outer().new Inner();
2,当内部类在成员位置上，就可以被成员修饰符修饰。
	比如，private:将内部类在外部类中进行封装。
	static:内部类就具备了static特性。

注意：当内部类中定义了静态成员，或外部静态类访问该内部类时，
	  该内部类必须时static的。

当描述事物时，事物的内部还有事物，该事物用内部类来描述。
	因为内部事物在使用外部事物内容。

*/
class Outer
{
	private static int x=3;
	static class Inner//内部类
	{
		int x=4;
		void function()
		{
			int x=6;
			System.out.println("inner:"+Inner.this.x);//this.x:打印4。Outer.this.x打印3。x打印3.
		}
	}
	void method()
	{
		Inner in =new Inner();
		in.function();
		
		
	}
}


class  InnerClassDemo
{
	public static void main(String[] args) 
	{
		
		new Outer.Inner().function();//在外部类其他类中，直接访问static内部类的非静态成员。
		//Outer.Inner.function();//在外部类其他类中，直接访问static内部类的静态成员。
		//Outer out=new Outer();
	//	out.method();
		//直接访问内部类中的成员。
		//Outer.Inner in=new Outer().new Inner();
		//in.function();

	}
}

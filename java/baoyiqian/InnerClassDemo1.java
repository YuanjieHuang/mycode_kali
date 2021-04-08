/*
内部类定义在局部时，
1，不可以被成员修饰符修饰
2，可以直接访问外部类中的成员，因为还持有外部类中的引用
	但是不可以访问它所在的局部中的变量，只能访问被final修饰的局部变量。
*/
/*
匿名内部类：
1，匿名内部类其实就是内部类的简写格式
2,定义匿名内部类的前提：
	内部类必须是继承一个类或者实现接口
3,匿名内部类的格式：new 父类或接口(){定义子类的内容}
4，匿名内部类就是一个匿名子类对象，而且这个对象有点胖，可以理解为带内容的对象。
*/



abstract class AbsDemo
{
	abstract void show();
}

class Outer
{
	int x=3;
	/*
	class Inner extends AbsDemo
	{
		void show()
		{
			System.out.println("show:"+x)
		}
	}
	*/
	public void function()
	{
		
		AbsDemo d=new AbsDemo()
		//new Inner().show();
		//new AbsDemo()
		{
			void show()
			{
				System.out.println("x===="+x);
			}//.show;
			void abc()
			{
				System.out.println("haha");
			}
		}
	};//
	d.show();
	//d.abc();//编译失败
}
class InnerClassDemo1  
{
	public static void main(String[] args) 
	{
		new Outer().function();//?????
	}
}

/*
静态代码块。
格式：
static
{
	静态代码块中的执行语句。
}
特点：随着类的加载而执行，只执行一次。
用于给类初始化。
*/

/*
静态：static
用法：是一个修饰符，用于修饰成员（成员变量,成员函数）
当成员被静态修饰后，就多了一个调用方式，出来可以被对象调用外，还可以直接被类名调用。类名.静态成员。
static特点：
1，随着类的加载而加载
2，优先于对象存在
3，被所有对象所共享
4，可以直接被类名调用
*/

class staticCode 
{
	public static void main(String[] args) 
	{
		System.out.println("Hello World!");
	}
}
class person
{
	String name;//成员变量，实例变量
	static String country="CN";//静态的成员变量，类变量。
	public void show()
	{
		System.out.println(name+":::::"+country);
	}
}

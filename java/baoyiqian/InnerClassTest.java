



interface Inter
{
	void method();
}
class Test
{
	//补足代码。通过匿名内部类
	/*
	static class Inner implements Inter
	{
		public void method()
		{
			System.out.println("method run")l

		}
	}
	static Intre function()
	{
		return new Inner();
	}
	*/
	static Intre function()
	{
		return new Inner()
		{
			public void method()
		{
			System.out.println("method run")l

		}

		};
	}
}

class InnerClassDemoTest 
{
	public static void main(String[] args) 
	{
		Test.function().method();
		//Test.function():Test类中有ige静态的方法function.
		//.method):function这个方法运算后的结果是一个对象。而且是一个Inter类型的对象。
		//因为只有是Inter类型的对象，才可以调用method方法。
	}
	show(new Inter()
	{
		public void method()
		{
			System.out.println("method show run");
		}
	});
	public static void show(Inter in)
	{
		in.method();
	}
}
class static void main(String[] args)
{
	new Object()
	{
		public void function()
		{
		}
	}.function();
}
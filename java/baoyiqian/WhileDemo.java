class WhileDemo 
{
	public static void main(String[] args) 
	{
		/*
		定义初始化表达式；
		while(条件表达式）
		{
			循环体（执行语句）；
		}
		
		int x=1;
		while (x<3)
		{
			System.out.println("x="+x);
			++x;//加2：x+=2;
		}
		*/
		//do while结构
		int x=1;
		do
		{
			System.out.println("do:x="+x);
			++x;
		}
		while (x<0);
		int y=1;
		while (y<0)
		{
			System.out.println("y="+y);
			++y;
		}
	}
}

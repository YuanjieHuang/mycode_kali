class ForDemo 
{
	public static void main(String[] args) 
	{
		/*
		for(初始化表达式；循环条件表达式；循环后的操作表达式）
		{
			执行语句
		}
		*/
		for(int x=0;x<3;x++)//x作用范围为for大阔号内
		{
			System.out.println("x="+x);
		}
		System.out.println("x=="+x);
		int y=0;
		while(y<3)
		{
			System.out.println("y="+y);
			y++;
		}
		System.out.println("y=="+y);
		
		int x=1;
		for(System.out.println("a");x<3;System.out.println("c"),x++)
		{
			System.out.println("d");
			//x++;
		}
	//结果adcdc
	for(int y=0;y<3;y++)
		{
	}
	
	int y=0;
	for( ;y<3; )
		{
			y++;
		}
	/*
	无限循环的最简单表现形式。
	for( ; ; ){}//默认为true
	while(true){}
	*/
	}
}

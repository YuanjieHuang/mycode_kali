class  SwitchDemo
{
	public static void main(String[] args) 
	{
		/*需求1：简单加减乘除运算。
		int a=4,b=2;
		char ch='+';
		switch(ch)//只用于byte short int char四种类型。
		{
			case '-':
				System.out.println(a-b);
			break;
			case '+':
				System.out.println(a+b);
			break;
			case '*':
				System.out.println(a*b);
			break;
			case '/':
				System.out.println(a/b);
			break;
			default:
				System.out.println("nonleagle");
			}
			*/
		//需求2：输入数字显示对应月份。
		int x=4;
		switch(x)
		{
			case 3:
			case 4:
			case 5:
			System.out.println("春季");
			break;
			case 6:
			case 7:
			case 8:
			System.out.println("夏季");
			case 9:
			case 10:
			case 11:
			System.out.println("秋季");
			break;
			case 12:
			case 1:
			case 2:
			System.out.println("冬季");


		}
		
	}
}

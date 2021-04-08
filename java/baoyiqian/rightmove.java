class  rightmove
{
	public static void main(String[] args) 
	{	
		int num=60;
		//获取60的最低4位，通过&15；
		int n1=num&15;
		System.out.println(n1>9?(char)(n1-10+'A'):n1);//三元运算符
		//要获取下一组思维，将60右移4位
		int temp=60>>>4;//>>>不带符号右移
		int n2=temp&15;
		System.out.println(n2>9?(char)(n2-10+'A'):n2);
	/*	0~9 'A' 'B' 'C' 'D' 'E' 'F'
		     10  11 12  13   14  15
		12-10=2+'A'=(char)67;

		System.out.println("Hello World!");
		*/
	int x=1,y;
	y=(x>1)?100:200;
	System.out.println("y="+y);

	}
}

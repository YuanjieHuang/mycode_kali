class  
{
	public static void main(String[] args) 
	{	/*如何交换两个变量的值*/
		int n=3,m=8;
		System.out.println("n="+n+"m="+m);
		//1，通过第三方变量
		int temp;
		temp=n;
		n=m;
		m=temp;
		System.out.println("n="+n+"m="+m);
		//2,不通过第三方变量
		n=n+m;//如果n和m的值非常大，容易超出int范围
		m=n-m;
		n=n-m;
		//利用^
		n=n^m;
		m=n^m;//(n^m)^m;
		n=n^m;//n^(n^m);//?????
	}
}

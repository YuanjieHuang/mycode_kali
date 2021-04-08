class  ArrayTest6
{
	public static void main(String[] args) 
	{
		toHex(60);
	}
	/*
	查表法：



	*/
	public static void toHex(int num)
	{
		char[] chs={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F',};
		//定义一个临时容器。
		char[] arr=new char[8];
		int pos=0;
		while(num!=0)
		{
			int temp=num&15;
			//System.out.println("chs[temp]");
			arr[pos++]=chs[temp];
			num=num>>>4;
		}
		//存储数据的arr数组遍历。
		for(int x=arr.length-1;x>0;x--)
		{
			System.out.println(arr[x]+",");
		}
	}
}

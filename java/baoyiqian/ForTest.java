/*
1,获取1~10的和，并打印。
2，1~100之间7的倍数的个数，并打印。
*/

class ForTest 
{
	public static void main(String[] args) 
	{
		//1，定义变量用于存储不断变化的和。
		int sum=0;
		//2,定义变量，记录不断变化的的被加的数。
		int x=1;
		while(x<=10)
		{
			sum=sum+x;
			x++;
		}
		System.out.println("sum="+sum);
		/*
		循环注意：
		一定要明确哪些语句需要参与循环，哪些不需要参与循环。 
		*/
		//用for实现
		int su=0;
		for(int y=0; y<=10; y++)
		{
			su+=y;
		}
		System.out.println("su="+su);
		/*
		累加思想：
		通过变量记录住每次变化的结果。
		通过循环的形式，实现累加动作。
		*/
	}
}

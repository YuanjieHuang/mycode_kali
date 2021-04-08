/*
打印下图
*****
****
***
**
*
*
**
***
****
*****
思路：发现图形有多行多列，要使用嵌套循环。
技巧：
尖朝上，可以改变条件，让条件随着外循环变换；
尖超下，可以改变初始化值，让初始化值随着外循环变化。
*/
//语句嵌套形式就是语句中还有语句。
//循环嵌套

class ForForDemo 
{
	public static void main(String[] args) 
	{
		//int z=0;
		for(int x=0;x<5;x++)//外循环控制行数，共五行
		{
			for(int y=x;y<5;y++)      //下图可用：for(int y=0;y<=x;y++)
			{
				System.out.print("*");
			}
			//z++;
			System.out.println();//控制换行
		}
		
		
		System.out.println("---------------");
		/*
		打印下图
		1
		12
		123
		1234
		12345
		*/
		for (int x=1;x<=5;x++ )
		{
			for (int y=1;y<=x ; y++)
			{
				System.out.print(y);
			}
			System.out.println();
		}
		System.out.println("-------------");
		/*
		九九乘法表
		*/
		for (int x=1;x<=9 ; x++)
		{
			for (int y=1; y<=x;y++ )
			{
				System.out.print(y+"*"+x+"="+y*x+"\t");//对齐:\t
			}
			System.out.println();
		}

	}
}

/*
1,先明确函数定义的格式
修饰符 返回值类型 函数名（参数类型 形式参数1，参数类型 形式参数2，）
{
	执行语句；
	return 返回值；//void:代表函数没有具体返回值的情况，当函数的返回值类型是void是，函数中的return语句可以省略不写。
}
*/

class FunctionDemo 
{
	public static void main(String[] args) 
	{
		int x=getResult(4);
		System.out.println("x="+x);
	}
	public static int getResult(int num)
	{
		/*
		System.out.println(num*3+5);
		return;//可以省略
		*/
		return num*3+5;
	}
	/*
	如何定义一个函数？
	1，先明确函数运算结果
	因为这是在明确函数的返回值类型
	2，明确是否需要未知的内容参与运算
	因为这是在明确函数的参数列表（参数的类型和参数的个数）
	*/
	/*需求：判断两个数是否相同。
	思路：
	1，明确功能的结果：结果是：Boolean。
	2，功能是否有未知的内容参与运算。有，两个数
	*/
	public static boolean compare(int a,int b)
	{
		/*
		if (a==b)
		
			return true;
		else//可以不写
			return false;
		*/
		//return (a==b)?true;false;
		return a==b;
	}
	/*
	需求：定义功能，对两个数进行比较，获取较大的数。
	*/
	public static int getMax(int a,int b)
	{
		return (a>b)?a:b;
	}

	}
}

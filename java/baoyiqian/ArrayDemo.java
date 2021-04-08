class ArrayDemo 
{
	public static void main(String[] args) 
	{
		/*
		//元素类型[] 数组名=new 元素类型[元素个数或数组长度]
		//需求：想定义一个可以存储3个整数的容器。
		int[] x=new int[3]//new:在内存中产生容器实体,此x表示数组类型。 
		*/
		//数组的操作：
		//获取数组中的元素，通常会用遍历。
		int[] arr={3,6,5,1,8,9,67};
		//int[] arr=new int[3];
		//数组中有一个属性可以直接获取到数组元素个数。length.
		//使用方式：数组名称.length=
		/*
		System.out.println("length:"+arr.length);
		int sum=0;
			for(int x=0;x<arr.length;x++)
		{
			System.out.println("arr["+x+"]="+arr[x]+";");//arr[0]=0;
		}
		*/
		
		//printArray(arr);
		int max=getMax(arr);
		System.out.println("max="+max);
		int max=getMax_2(arr);
		System.out.println("max="+max);
	}
	/*
	//定义功能，用于打印数组中的元素，元素间用逗号隔开。
	public static void printArray(int[] arr)//????
		{
			System.out.print("[");
			for(int x=0;x<arr.length;x++)
			{
				if(x!=arr.length-1)
					System.out.print(arr[x]+",");
				else
					System.out.println(arr[x]+"]");
			}
		}
		*/
		/*
		获取数组中的最大值。
		思路：
		1，获取最值需要进行比较，每次比较都会有一个较大的值。因为该值不确定，通过一个变量进行临时存储。
		2，让数组中的每一个元素都和这个变量中的值进行比较。如果大于了变量的值，就用该变量记录较大的值。
		3，当所有的元素都比较完成，那么该变量中存储的就是数组中的最大值了。
		步骤：
		1，定义变量。初始化为数组中的任意一个元素即可。
		2，通过循环语句对数组进行遍历。
		3，在变量过程中定义判断条件，如果遍历到的元素比变量中的元素大，就赋值给该变量。
		需要定义一个功能来完成，以便提高复用性。
		1，明确结果，数组中的最大元素 int.
		2，未知内容：一个数组。int[]
		*/
		public static int getMax(int[] arr)
		{
			int max=arr[0];
			for(int x=1;x<arr.length;x++)
			{
			if(arr[x]>max)
				max=arr[x];
			}
			return max;
		}
		/*
		获取最大值的另一种方式。
		可不可以将临时变量初始化为0呢？可以。这种方式，其实是在初始化为数组中任意一个角标。
		*/
		public static int getMax_2(int[] arr)
		{
			int max=0;
			for(int x=1;x<arr.length;x++)
			{
			if(arr[x]>arr[max])
				max=x;
			}
			return arr[max];
		}
			
}

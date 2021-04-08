/*
对给定数组进行排序。
*/



class  ArrayTest
{
	public static void main(String[] args) 
	{
		int[] arr={4,6,2,3,9,7};
		printArray(arr);
		bubbleSort(arr);
		printArray(arr);
		System.out.println(Integer.toBinaryString(60));//计算60对应的二进制数

	}
	//选择排序
	public static void selectSort(int[] arr)
	{
		for (int x=0;x<arr.length-1 ;x++ )
		{
			for (int y=x+1;y<arr.length ;y++ )
			{
				if (arr[x]>arr[y])
				{
					int temp=arr[x];
					arr[x]=arr[y];
					arr[y]=temp;

				}
			}
		}
	}
	//冒泡排序：相邻的两个元素进行比较，如果符合条件则换位。
	//第一圈最值出现在最后。
	public static void bubbletSort(int[] arr)
	{
		for (int x=0;x<arr.length-1 ;x++ )
		{
			for (int y=0;y<arr.length-x-1 ;y++ )//-x:让每一次比较的元素减少，-1：避免角标越界。
			{
				if (arr[y]>arr[y+1])
				{
					int temp=arr[y];
					arr[y]=arr[y+1];
					arr[y+1]=temp;

				}
			}
		}
	}
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
	//Arrays.sort(arr);//java中已经定义好的一种排序方式，开发中对数组排序，要使用该句代码。
	//位置置换功能
	public static void swap(int[],int a, int b)
	{
		int temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
	}
	//数组的查找操作
	//定义功能，获取key第一次出现在数组中的位置。
	public static int getIndex(int[] arr,int key)
	{
		for(int x=0;x<arr.length;x++)
		{
			if(arr[x]==key)
				return x;
		}
		return -1;
	}
	//折半查找 （对于有序数组）
	//第二张方法
	public static int halfSearch_2(int [] arr,int key)
	{
		int min=0,max=arr.length-1,mid;
		while(min<max)
		{
			mid=(max+min)>>1;
			if(key>arr[mid]
				min=mid+1;
			else if(key<arr[mid]
				max=mid-1;
			else
				return mid;
		}
		return -1//????
	}
	//第一张方法
	public static int halfSearch(int [] arr,int key)
	{
		int min=0,max=arr.length-1,mid;
		min=0;
		max=arr.length-1;
		mid=(max+min)/2;
		while(mid!=arr[mid])
		{
			
			if(key>arr[mid]
				min=mid+1;
			else if(key<arr[mid]
				max=mid-1;
			if(min>max)
				return -1;//return min;得到插入数的位置
			mid=(min+max)/2;//不能少？
			
		}
		return mid;
	}
	//十进制---二进制
	public static void toBin(int num)
	{	
		StringBuffer sb=new StringBuffer();//存储数据的容器
		while(num>0)
		{
			//System.out.println(num%2);
			sb.append(num%2);//方法是添加
			num=num/2
		}
		System.out.println(sb.reverse());
	}
	//十进制-----十六进制
	public static void toHex(int num)
	{
		StringBuffer sb=new StringBuffer();
		for (int x=0;x<8 ;x++ )
		{
			int temp=num&15;
			if(temp>9)
				//System.out.println((char) (temp-10+'A'));
				sb.append((char) (temp-10+'A'));
			else
				//System.out.println(temp);
				sb.append(temp);
			num>>>4;//三个大于号为了最高为补0

		}
		System.out.println(sb.reverse());

	}



}

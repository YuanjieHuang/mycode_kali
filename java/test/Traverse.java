package test;
import java.util.*;
class Traverse 
{
	public static void main(String[] args) 
	{	int l=10;
		int[] a=new int[10];//定义10*10的二维数组
		for(int i=0;i<=a.length-1;i++){
			a[i]=i;
			System.out.println(a[i]);
		}
		int[][] b=new int[10][10];//定义一个10*10的二维数组。
		for(int j=0;j<10;j++) {
			for (int k=0;k<10;k++) {
				b[j][k]=l;
				l++;
				System.out.println(b[j][k]);
			}
		}
		LinkedList ll=new LinkedList();
		ll.add("a");
		ll.add("b");
		ll.add("c");
		ll.add("d");
		System.out.println(ll.size());
		ListIterator it=ll.listIterator();
		
		while(it.hasNext())
		{
//			Object obj=it.hasNext();
			System.out.println(it.next());
		}
	}
}
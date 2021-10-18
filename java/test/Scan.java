package test;
import java.util.*;

public class Scan {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s=new Scanner(System.in);
		System.out.println("please input a integer!");
		long a=s.nextLong();
		String ss=Long.toString(a);
		char[] ch=ss.toCharArray();
		int j=ch.length;
		System.out.println(a+"是一个"+j+"位数");
		for(int i=j-1;i>=0;i--)
		{
			System.out.println(ch[i]);
		}

	}

}

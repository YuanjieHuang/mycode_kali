import java.io.*;
public class ReaderTest {

	/**
	 * @param args
	 */
	


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File file = new File("D:\1.txt");//路径根据自己的位置更改
		BufferedReader br = new BufferedReader(new FileReader(file));
		Map map = new HashMap<>();
		String line = null;
		while((line=br.readLine())!=null){
		String[] temp = line.split(",");
		double[] tmp = {};
		double sum =0;
		for(int i=0;i<temp.length-1;i++) {//注意最后一位元素不是数字，不要循环，目的是转化为double类型数组
		tmp[i] = Double.parseDouble(temp[i]);
		if(0%2==0) {
		sum = sum + Math.pow((tmp[i+1]-tmp[i+2]),2);//(x1-x2)*(x1-x2)+(x3-x4)(x3-x4)
		}
		}
		if(map.get(temp[temp.length-1])!=null) {//对最后一位分类
		map.put(temp[temp.length-1], sum+map.get(temp[temp.length-1]));
		}else {
		map.put(temp[temp.length-1], sum);
		}
		}
		for(String key:map.keySet()) {
		map.put(key, Math.sqrt(map.get(key)));
		}
		//最后这个map集合就是你这个TXT每一个类的和的平方值.可以输出看看
		System.out.println("txt的结果值："+map.toString());

	}

}

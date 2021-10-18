//汉诺塔问题
package hanuota;

public class MainClass {
	
    public static void main(String[] args) {
    	int count=0;
        int nDisks = 1;
        doTowers(nDisks, 'A', 'B', 'C');
        fibonacci(10);
    }
    public static void doTowers(int topN, char from, char inter, char to) {
        if (topN == 1){
            System.out.println("Disk 1 from "
            + from + " to " + to);
        }else {
            doTowers(topN - 1, from, to, inter);
            System.out.println("Disk "
            + topN + " from " + from + " to " + to);
            doTowers(topN - 1, inter, from, to);
        }
    }
       public static int fibonacci(int n) {
            if (n == 1 || n == 2) {     // 递归终止条件
                return 1;       // 简单情景
            }
            return fibonacci(n - 1) + fibonacci(n - 2); // 相同重复逻辑，缩小问题的规模
        }
       
    
}

　　int main()
　　{   Counter cnt(3); 		//定义一个Counter类的对象，报警值为3
　　
　　    cnt.print(); 			//显示对象的当前值，此时输出为0
　　    ++cnt;
　　    cnt.print(); 			//此时输出为1
　　    (++cnt).print(); 		//调用前缀的++，输出2
　　    (cnt++).print(); 		//调用后缀的++，当前对象的value已经加1，报警，但输出的是2
　　    cnt.print(); 			//输出值为3
　　    return 0;
　　}
　　

void YangHuiTriangle()
{  
	Queue  Q;
	Q.MakeEmpty();
	Q.EnQueue(1); 	//第一行元素入队
	for (n = 2; n <= N; n++) { 	//产生第n行元素并入队, 同时打印第n-1行的元素
		Q.EnQueue(1); 	//第n行的第一个元素入队
		//用队中第n-1行元素产生第n行的中间n-2个元素并入队
		for (i = 1; i <= n-2; i++) {
			temp = DeQueue();
			cout << temp <<"";     	//打印第n-1行的元素
			x = Q.GetFront();
			temp = temp + x;      	//利用队中第n-1行元素产生第n行元素
			Q.EnQueue (temp);  
		}
		x = DeQueue();  
		cout <<x <<endl;    	//打印第n-1行的最后一个元素
		Q.EnQueue(1)   		//第n行的最后一个元素入队
	}
}

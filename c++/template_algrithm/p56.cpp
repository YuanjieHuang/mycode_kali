//把一个长整型数num转换为一个r进制数输出
void Transform(long num, int r) 
{
	Stack<int> a;  //利用栈a存储转换后得到的每一位数字
	while (num != 0) {  //由低到高求出r进制数的每一位并入栈
		int k = num % r;
		a.Push(k);
		num/=r;
	}
	while(!a.IsEmpty()) //由高到低输出r进制数的每一位
		cout << a.Pop();
	cout << endl;
}

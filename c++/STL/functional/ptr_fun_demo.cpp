//============================================================================
 // Name        : CopyInts4.cpp
 // Author      : motein
 // Version     :
 // Copyright   : Your copyright notice
 // Description : Hello World in C++, Ansi-style
 //============================================================================
 
 #include <iostream>
 #include <algorithm>
 #include <vector>
 using namespace std;
 
 int u_func(int a)
 {
     int ret = a;
     return ret;
 }
 
 int b_func(int a,int b)
 {
     return a+b;
 }
 
 void call()
 {
     pointer_to_unary_function<int,int> uf(u_func);
     cout << uf(100) << endl;
 
     pointer_to_binary_function<int,int,int> bf(b_func);
     cout << bf(111,222) << endl;
 
     cout << ptr_fun(u_func)(100) << endl;
     cout << ptr_fun(b_func)(111,222) << endl;
 
 }
 
 int main()
 {
     call();
     return 0;
 }
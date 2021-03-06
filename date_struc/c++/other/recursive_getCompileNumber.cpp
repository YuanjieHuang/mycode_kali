#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//求组合 
int comm(int n,int k){
	if (k>n)
		return 0;
	else if(n==k||k==0)
		return 1;
	else
		return comm(n-1,k)+comm(n-1,k-1);	
} 
int main(int argc, char** argv) {
	int n,k;
	cout<<"Please enter two integer n and k:";
	cin >>n>>k;
	cout<<"C(n,k)="<<comm(n,k)<<endl;
	return 0;
}

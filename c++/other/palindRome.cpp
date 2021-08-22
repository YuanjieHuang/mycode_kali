#include <iostream>
using namespace std;


const double TINY_VALUE = 1e-10;

double tsin(double x){
	double g = 0;
	double t = x;
	int n= 1;
	do{
		g+=t;
		n++;
		t=-t*x*x/(2*n-1)/(2*n-2);
		}while (fabs(t)>=TINY_VALUE);
		return g;
		}
		//sin函数 
int test_tsin() {
	double k,r,s;
	cout <<"r=";
	cin >>r;
	cout <<"s=";
	cin >> s;
	if (r*r<=s*s) 
		k=sqrt(tsin(r)*tsin(r)+tsin(s)*tsin(s));
		else
		k = tsin(r*s)/2;
		cout << k <<endl;
		return 0;
}


bool symm(unsigned n){
	unsigned i = n;
	unsigned m = 0;
	while (i> 0){
		m = m*10 + i%10;
		i/=10; 
	}
	return m ==n; 
} 

int test_symm() {
	for(unsigned m = 11;m<1000;m++)
	if(symm(m)&&symm(m*m)&&symm(m*m*m)){
		cout << "m="<<m;
		cout << "m*m="<<m*m;
		cout << "m*m*m="<<m*m*m<<endl;
		}
	 return 0;
}

//求组合 
int recursive_getCompileNumber(int n,int k){
	if (k>n)
		return 0;
	else if(n==k||k==0)
		return 1;
	else
		return recursive_getCompileNumber(n-1,k)+recursive_getCompileNumber(n-1,k-1);	
} 
int test_recursive_getCompileNumber() {
	int n,k;
	cout<<"Please enter two integer n and k:";
	cin >>n>>k;
	cout<<"C(n,k)="<<recursive_getCompileNumber(n,k)<<endl;
	return 0;
}

int main() {
	test_tsin();
	test_symm();
	test_recursive_getCompileNumber();
	 return 0;
}

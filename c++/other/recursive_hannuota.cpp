#include <iostream>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//把src针上的最上面一个盘子移动到dest针上,清华3-4-4 
void move(char src,char dest){
	cout <<src <<"-->"<<dest <<endl;
} 

//将n个盘子从src针移动到dest针，以medium针为媒介 
void hanoi(int n,char src, char medium, char dest){
	if (n==1)
	move(src,dest);
	else{
		hanoi(n-1,src,dest,medium);
		move(src,dest);
		hanoi(n-1,medium,src,dest);
	}
}

int main(int argc, char** argv) {
	int m;
	cout << "Enter the number of diskes:";
	cin>>m;
	cout<<"the steps to moving"<<m<<"iskes:"<<endl;
	hanoi(m,'A','B','C'); 
	return 0;
}

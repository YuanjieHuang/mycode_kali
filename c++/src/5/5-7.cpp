//文件名：5-7.cpp
//矩阵乘法
#include <iostream>
using namespace std;
#define MAX_SIZE 10  //矩阵的最大规模

int main()
{   int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    int i, j, k, NumOfRowA, NumOfColA, NumOfColB;

    //输入A和B的大小
    cout << "\n输入A的行数、列数和B的列数：";
    cin >> NumOfRowA  >> NumOfColA >> NumOfColB; 

    //输入A
    cout << "\n输入A:\n";
    for (i=0; i< NumOfRowA; ++i)
        for (j=0; j < NumOfColA; ++j)  {
	          cout << "a[" << i << "][" << j << "] = ";   
	          cin >> a[i][j];
        }
         
    //输入B
    cout << "\n输入B:\n";
    for (i=0; i< NumOfColA; ++i)
        for (j=0; j< NumOfColB; ++j)    {
            cout << "b[" << i << "][" << j << "] = ";   
            cin >> b[i][j];
        }

    //执行A×B
    for (i=0; i< NumOfRowA; ++i)
        for (j=0; j< NumOfColB; ++j) {
            c[i][j] = 0;   
            for (k=0; k<NumOfColA; ++k)   c[i][j] += a[i][k] * b[k][j];
        }

    //输出C
    cout << "\n输出C:";
    for (i=0; i < NumOfRowA; ++i) {
        cout << endl;
        for (j=0; j< NumOfColB; ++j)  cout << c[i][j] << '\t';
    }
　　
    return 0;
}


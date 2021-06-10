//文件名：5-8.cpp
//打印N阶魔阵
#include <iostream>
using namespace std;

#define MAX 15 //最高为打印15阶魔阵

int main()
{   int magic[MAX][MAX] = {0}; //将magic每个元素设为0
    int row, col, count, scale;
  
    //输入阶数scale  
    cout << "input scale\n"; 
    cin >> scale;
  
    //生成魔阵  
    row=0; col = (scale - 1) / 2; magic[row][col] = 1;
    for (count = 2; count <= scale * scale; count++) { 
        if (magic[(row - 1 + scale) % scale][(col + 1) % scale] == 0) {
           row = ( row - 1 + scale ) % scale; 
           col = ( col + 1 ) % scale;
	     }
       else  row = ( row + 1 ) % scale;
       magic[row][col] = count;
    }

    //输出 
    for (row=0; row<scale; row++){
        for (col=0; col<scale; col++)    cout << magic[row][col] << '\t';
        cout << endl;
    }

    return 0;
 }


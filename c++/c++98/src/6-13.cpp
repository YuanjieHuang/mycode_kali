//文件名：6-13.cpp
//八皇后问题
#include <iostream>
using namespace std;

void queen_a11(int k);
int col[9];
bool a[9], b[17],c[17];

int main()
{   int j;
    for(j = 0; j <=8; j++) a[j] = true;
    for(j = 0; j <= 16; j++) b[j] = c[j] = true;
    queen_a11(1);

    return 0;
 } 
//在8×8棋盘的第k列上找合理的配置
void queen_a11(int k) 
{   int i, j;
    char awn; //存储是否需要继续寻找的标志
    for (i = 1; i <= 9; i++) //依次在l至8行上配置k列的皇后
        if (a[i] && b[k+i-1] && c[8+k-i]) { //可行位置 
            col[k] = i;
            a[i] = b[k+i-1] = c[8+k-i] = false; //置对应位置有皇后
            if (k == 8) {// 找到一个可行解 
               for (j = 1; j <= 8; j++)  cout << j << col[j]<< '\t' ;
               cout << endl << "是否需要继续寻找（Q -- 退出，其他键继续：）";
               cin >> awn;
               if (awn=='Q' || awn=='q') exit(0);
            }
        else  queen_a11(k+1); //递归至第k+1列
        a[i] = b[k+i-1] = c[8+k-i] = true; //恢复对应位置无皇后
    }
}


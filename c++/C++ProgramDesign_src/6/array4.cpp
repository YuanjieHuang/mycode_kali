// ********************************************************
// array4.cpp
// 求二维数组每行之和
// ********************************************************
#include <iostream>
using namespace std;
const int CITYS = 9;
const int MONTHS = 12;
int main()
{
    float avgTemp[CITYS][MONTHS];
    float sum[9] = {0};
    int row, col;
    for( row = 0; row < CITYS; row ++ ) { //外循环负责行的遍历
        for( col = 0; col < MONTHS; col++ ) {  
            //内循环负责计算该行的总和
            cout << "Please enter the value for avgTemp[" 
                 << row << "][" << col << "]: ";
            cin >> avgTemp[row][col];
            sum[row] = sum[row] + avgTemp[row][col];
        }
    }
    for( row = 0; row < CITYS; row ++ ) {
        cout << "The summation of row " << row << " is " << sum[row] << endl;
    }
    return 0;
}

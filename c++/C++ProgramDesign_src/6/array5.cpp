// **********************************************************
// array5.cpp
// 求二维数组每列之和
// **********************************************************
#include < iostream >
using namespace std;
const int CITYS = 9;
const int MONTHS = 12;
int main()
{
     float avgTemp[CITYS][MONTHS];
     float sum[12] = {0};
     int row, col;
     for( col = 0; col < MONTHS; col++ ) { //外循环负责列的遍历
         for(row = 0; row < CITYS; row++ ) {
             //内循环负责计算该列的总和
             cout << "Please enter the value for avgTemp[" 
                   << row << "][" << col << "]: ";
             cin >> avgTemp[row][col];
             sum[col] = sum[col] + avgTemp[row][col];
         }
     }
     for( col = 0; col < MONTHS; col ++ )
        cout << "The summation of col" << col << " is " << sum[col] << endl;
     return 0;
}

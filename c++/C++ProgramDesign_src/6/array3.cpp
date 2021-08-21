// ********************************************************
// array3.cpp
// 求二维数组中所有元素之和。采用两重循环遍历整个数组。
// ********************************************************
#include < iostream >
using namespace std;
const int CITYS = 9;
const int MONTHS = 12;
int main()
{
    float avgTemp[CITYS][MONTHS];
    float sum = 0;
    int row, col;
    for( row = 0; row < CITYS; row ++ ) {  // 注意行列下标都不要越界
        for( col = 0; col < MONTHS; col++ )	{
            cout << "Please enter the value for avgTemp[" 
                  << row << "][" << col << "]: ";
            cin >> avgTemp[row][col];
            sum = sum + avgTemp[row][col];
        }
    }
    cout << "The summation is " << sum << endl;
    return 0;
}

// ********************************************************
// array2.cpp
// 功能：说明二维数组的声明和引用
// ********************************************************
#include < iostream >
using namespace std;
int main()
{
    float avgTemp[9][12];
    int row, col;
        for( row = 0; row < 9; row ++ ) {
            for( col = 0; col < 12; col++ ) {
                cin >> avgTemp[row][col];
            }
        }
    return 0;
}

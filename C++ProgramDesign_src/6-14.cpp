// **********************************************************
// pointerArray1.cpp
// 功能：用以说明通过指针引用数组元素
// **********************************************************
#include < iostream >
using namespace std;
int main()
{
    float score[5] = { 50, 60, 70, 80,90 };
    int i;
    for( i = 0; i < 5; i++ ) { // ①
        cout << score[i] << "   ";
    }
    cout << endl;
    for( i = 0; i < 5; i++ ) { // ②
        cout << *(score+i) << "   ";
    }
    return 0;
}

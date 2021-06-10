程序清单6-15
// **********************************************************
// pointerArray2.cpp
// 功能：用以说明通过指针变量引用数组元素
// **********************************************************

#include < iostream >
using namespace std;

int main()
{
    float score[5] = { 50, 60, 70, 80, 90 };
    float* p = score;
    int i;
	
    for( i = 0; i < 5; i++ ) { // ①
   
        cout << p[i] << "  ";
    }

    cout << endl;

    for( i = 0; i < 5; i++ ) { // ②
   
        cout << *(p+i) << "  ";
    }
    
    return 0;
}

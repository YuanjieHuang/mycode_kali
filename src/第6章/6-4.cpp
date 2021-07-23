//文件名：6-4
//读入一串整型数据，将其逆序排列并输出排列后的数据
#include <iostream>
using namespace std;
	
#define MAX 10

int ReadIntegerArray(int array[ ], int max, int flag );
void ReverseIntegerArray(int array[ ], int size);
void PrintIntegerArray(int array[ ], int size);

int main()
{   int IntegerArray[MAX], flag, CurrentSize;

    cout << "请输入结束标记：";
    cin >> flag;

    CurrentSize = ReadIntegerArray(IntegerArray, MAX, flag );
    ReverseIntegerArray(IntegerArray, CurrentSize);
    PrintIntegerArray(IntegerArray, CurrentSize);
    return 0;
}

//函数：ReadIntegerArray
//作用：接收用户的输入，存入数组array，max是array的大小，flag是输入结束标记。
//当输入数据个数达到最大长度或输入了flag时结束
int ReadIntegerArray(int array[ ], int max, int flag )
{   int size = 0;
 
    cout <<"请输入数组元素，以" << flag << "结束：:" ;
    while (size <= max) {
        cin >> array[size];
        if (array[size] == flag) break; else ++size;
    }

    return size;
}

//函数：ReverseIntegerArray
//作用：将array中的元素按逆序存放，size为元素个数
void ReverseIntegerArray(int array[ ], int size)
{   int i, tmp;

    for (i=0; i < size / 2; i++){
        tmp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = tmp;
    }
}

//函数：PrintIntegerArray
//作用：将array中的元素显示在屏幕上。size是array中元素的个数
void PrintIntegerArray(int array[ ], int size)
{   int i;

    if (size == 0) return;
    cout << "逆序是：" << endl;
    for (i=0; i<size; ++i)  cout << array[i] << '\t';
    cout << endl;
}


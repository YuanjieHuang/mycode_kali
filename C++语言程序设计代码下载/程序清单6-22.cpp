程序清单6-22
// ********************************************************
// dynamicAlloc2D.cpp
// 介绍利用new和delete进行二维内存空间的动态分配和释放
// ********************************************************

#include <iostream>
using namespace std;

void input( float** , int , int  );
void average( float** , int , int , float*  );
void output( float* , int  );

int main()
{
    float **score;
    float *avg;
    int stuNum, courseNum, i;

    cout << "请输入学生数量：" << endl;
    cin >> stuNum;
    cout << "请输入考试科目数量：" << endl;
    cin >> courseNum;

    score = new float*[ stuNum ];	//① 分配行指针的内存
    for (i = 0;i < stuNum; i++ ) 
        score[i] = new float[ courseNum ];	//② 分配每行元素的内存

    avg = new float[ stuNum ];

    input( score, stuNum, courseNum );
    average( score, stuNum, courseNum, avg );
    output( avg, stuNum );

    for ( i = 0; i < stuNum; i++)	//③ 释放每行元素的内存
        delete []score[i];

    delete []score;	//④ 释放行指针的内存

    delete avg;

    return 0;
}

void average( float** score, int stuNum, int courseNum, float* avg )
{
    int i, j;
    float sum;

    for( i = 0; i < stuNum; i++ ) {
        sum = 0.0;

        for( j = 0; j < courseNum; j++ ) {
            sum = sum + score[i][j];
        }
        avg[i] = sum / courseNum;
    }
}

void input( float** score, int stuNum, int courseNum )
{
    int i, j;

    for( i = 0; i < stuNum; i++ ) {
        for( j = 0; j < courseNum; j++ ) {
            cout << "输入第" << i+1 << "名考生第" << j+1 << "科目成绩： ";
            cin >> score[ i ][ j ];
        }
    }
}

void output( float* avg, int stuNum )
{
    int i;

    for( i = 0; i < stuNum; i++ ) {
        cout << "第" << i+1 << "名考生平均分为：  ";
        cout << avg[ i ] << endl;
    }
}

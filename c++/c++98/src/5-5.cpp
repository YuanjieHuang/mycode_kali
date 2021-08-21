//文件名：5-5.cpp
//直接选择排序
#include <iostream>
using namespace std;

int main( )
{   int lh, rh, k, tmp;
    int array[ ] = {2, 5, 1, 9, 10, 0, 4, 8, 7, 6};
  
    for (lh = 0; lh < 10; lh++)
    {     
        rh = lh;
        for (k = lh; k < 10; ++k)
            if ( array[k] < array[rh] )   rh = k;
        tmp = array[lh];  array[lh] = array[rh];  array[rh] = tmp;
    }
 
    for (lh =0; lh<10; ++lh)  cout << array[lh] << ' ';

    return 0;
}


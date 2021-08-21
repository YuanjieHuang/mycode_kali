//文件名：5-4.cpp
//二分查找
#include <iostream>
using namespace std;

int main()
{   int lh, rh, mid, x;
    int array[ ]={0,1,2,3,4,5,6,7,8,9};

    cout <<"请输入要查找的数据：";  cin >> x;

    lh = 0;  rh = 9;
    while ( lh <= rh )            //查找区间存在
    { mid = ( lh + rh ) / 2;      //计算中间位置
      if ( x== array[mid] ) {
		      cout << x << "的位置是：" << mid << endl; 
		      break; 
      }
      if ( x < array[mid]) rh = mid - 1; else lh = mid + 1;
    }
    if (lh > rh) cout << "没有找到" << endl;

    return 0;
}


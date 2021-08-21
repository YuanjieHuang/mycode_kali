#include <cassert>
#include "IntArray.h"

IntArray::IntArray(const IntArray &arr)
      {low = arr.low;  high = arr.high;
       storage = new int [high - low + 1];
       for (int i = 0; i < high -low + 1; ++i)  storage[i] = arr.storage[i];
	}

IntArray &IntArray::operator=(const IntArray & a)
{ if (this == &a) return *this; //防止自己复制自己
  delete [] storage; //归还空间
  low = a.low;  high = a.high;
  storage = new int[high - low + 1]; //根据新的数组大小重新申请空间
  for (int i=0; i <= high - low; ++i) storage[i] = a.storage[i]; //复制数组元素
  return *this;
}

int & IntArray::operator[](int index)
{ assert(index >= low && index <= high); 
  return storage[index - low];
}

const int & IntArray::operator[](int index) const
{ assert(index >= low && index <= high); 
  return storage[index - low];
}

ostream &operator<<(ostream &os, const IntArray &obj)
{ os << "数组内容为：\n";
  for (int i=obj.low; i<=obj.high; ++i) os << obj[i] << '\t';
  os << endl;
  return os;
}

istream &operator>>(istream &is, IntArray &obj)
{ cout << "请输入数组元素[" << obj.low << ", " << obj.high << "]:\n";
  for (int i=obj.low; i<=obj.high ; ++i)   is >> obj[i] ;
  return is;
}
bool operator==(const IntArray &obj1, const IntArray &obj2)
{ if (obj1.low != obj2.low || obj1.high != obj2.high) return false;
  for (int i = obj1.low; i<=obj1.high; ++i) 
         if (obj1[i] != obj2[i]) return false;
  return true;
}

int main()
{   
    IntArray array1(20,30), array2;

    cin >> array1; //利用流提取运算符重载输入array1
    cout << "array1 "; cout << array1; //利用流插入运算符重载输出array1

    array2 = array1; //利用赋值运算符重载将array1赋给array2

    cout << "执行 array2 = array1, array2 ";
    cout << array2;

    //利用==重载比较array1和array2
    cout << "array1 == array2 是 " << ((array1 == array2)  ? "true" : "false") << endl; 

    array2[25] = 0; //利用下标运算符重载为array2的元素赋值

    cout << "执行array[25] = 0后, array1 == array2 是 "
         << ((array1 == array2)  ? "true" : "false") << endl; 

    return 0;
}
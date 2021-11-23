#include <iostream>
#include <cassert>
#include <set>

#include <bits/stdc++.h> 
#include <type_traits> 

using namespace std;

int my_is_same() 
{ 
  
    cout << boolalpha; 
  
    cout << "is int & int32_t is same? "
         << is_same<int, int32_t>::value 
         << endl; 
  
    cout << "is int & int64_t is same? "
         << is_same<int, int64_t>::value 
         << endl; 
  
    cout << "is float & int32_t is same? "
         << is_same<float, int32_t>::value 
         << endl; 
  
    cout << "is int & int is same? "
         << is_same<int, int>::value << endl; 
    cout << "is int & unsigned int is same? "
         << is_same<int, unsigned int>::value 
         << endl; 
  
    cout << "is int & signed int is same? "
         << is_same<int, signed int>::value 
         << endl; 
  
    return 0; 
}

typedef int integer_type; 
  
// Declare structures 
struct A { 
    int x, y; 
}; 
struct B { 
    int x, y; 
}; 
typedef A C; 
  
// Driver Code 
int my_is_same2() 
{ 
  
    cout << boolalpha; 
  
    cout << "is_same:" << endl; 
    cout << "int, const int is_same:"
         << is_same<int, const int>::value 
         << endl; 
  
    cout << "int, integer_type is_same:"
         << is_same<int, integer_type>::value 
         << endl; 
  
    cout << "A, B is_same:"
         << is_same<A, B>::value 
         << endl; 
  
    cout << "A, C is_same:"
         << is_same<A, C>::value 
         << endl; 
  
    cout << "signed char, int8_t is_same:"
         << is_same<signed char, int8_t>::value 
         << endl; 
  
    return 0; 
}

template<typename T>
T* PrintType(int* x)
{
	if (std::is_same<T, int>::value) {
		std::cout << "int type" << std::endl;
		return reinterpret_cast<T*>(x);
	}
	else {
		std::cout << "not int type" << std::endl;
		return nullptr;
	}
}
 
template<typename T>
const T* PrintType(const int* x)
{
	if (std::is_same<T, int>::value) {
		std::cout << "const int type" << std::endl;
		return reinterpret_cast<const T*>(x);
	}
	else {
		std::cout << "not const int type" << std::endl;
		return nullptr;
	}
}
 
void TestTemplateType()
{
	int x = 5;
	const int y = 6;
	PrintType<int>(&x);
	PrintType<double>(&x);
	PrintType<int>(&y);
	PrintType<double>(&y);
 
}
 
int main(int argc, char* argv[])
{
 
	TestTemplateType();
	my_is_same() ;
	my_is_same2() ;
 
	return 0;
}
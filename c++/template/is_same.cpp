#include <iostream>
#include <cassert>
#include <set>

using namespace std;

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
 
 
	return 0;
}
#include <iostream>
using namespace std;
class Demo {
public:
	Demo (int x) : value(x) { }
private:
	int value;
};
template <typename T>
class TempDemo {
public:
	TempDemo(T v1, T v2)
	{
		member = (v1 >= v2);
	}
private:
	bool member;
};
int main()
{
	Demo dobj1(8), dobj2(12);
	TempDemo<Demo> tobj(dobj1, dobj2);
	// ...使用dobj和tobj的代码略
	return 0;
}
		top = temp;				
	} 
	catch (std::bad_alloc e) {		
		throw;						
	}
}

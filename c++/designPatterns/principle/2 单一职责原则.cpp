#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>

using namespace std;


#if 0
class Clothes
{
public:
	void shopping() {
		cout << "休闲的服装" << endl;
	}
	void working() {
		cout << "休闲的服装" << endl;
	}
};
#endif

class ClothesShpping
{
public:
	void style() {
		cout << "休闲的服装" << endl;
	}
};
class ClothesWorking
{
public:
	void style() {
		cout << "休闲的服装" << endl;
	}
};

int main(void)
{
#if 0
	Clothes c1;
	c1.shopping();

	c1.shopping();
#endif
	ClothesShpping cs; 
	cs.style();

	ClothesWorking cw;
	cw.style();
	
	return 0;
}
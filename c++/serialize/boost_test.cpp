#include <iostream>
#include <boost\archive\text_oarchive.hpp>
#include <boost\archive\text_iarchive.hpp>
//#include <boost\archive\binary_oarchive.hpp>
//#include <boost\archive\binary_iarchive.hpp>
#include <string>
#include <fstream>

void Save()
{
	/*打开Test.bin 此种方法是利用构造函数打开*/
	std::ofstream file("Test.bin");

	/*定义oa为二进制存储类型*/
	boost::archive::text_oarchive oa(file);
	//boost::archive::binary_oarchive oa(file);

	int nNum = 0;
	std::cout << "输入int型" << std::endl;
	std::cin >> nNum;

	float fFloat = 0.0f;
	std::cout << "输入float型" << std::endl;
	std::cin >> fFloat;

	oa << nNum << fFloat;

	file.close();
}

void Load()
{
	std::ifstream file("Test.bin");

	/*定义ia为二进制读取类型*/
	boost::archive::text_iarchive ia(file);
	//boost::archive::binary_iarchive ia(file);

	/*读取顺序应和存储顺序相同 类型也需要相同*/
	int n = 0;
	float f = 0.0f;
	ia >> n >> f;
	std::cout << n << " " << f << std::endl;

	file.close();
}

int main()
{
	int nTemp = 0;

	std::cout << "1.输入并存储  2.读取并显示" << std::endl;
	std::cin >> nTemp;

	switch (nTemp)
	{
	case 1:
		Save();
		break;
	case 2:
		Load();
		break;
	default:
		break;
	}

	while (1);

	return 0;
}

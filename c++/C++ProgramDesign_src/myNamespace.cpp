// 为了避免与标准库中定义的swap函数冲突，
// 将自定义的swap函数放在自定义名字空间中
namespace myNamespace {
	template <typename T>
	void swap(T&, T&);
	void swap(double&, double&);
}
// 定义函数模板swap
template <typename T>
void myNamespace::swap(T& v1, T& v2)
// 交换形参v1和v2，并输出swap通用版本的提示
// 前置条件： v1和v2已创建
// 后置条件：
//     v1 == v2@entry，v2 == v2@entry
//     并在标准输出设备上输出字符串"enter generic version of swap()"
{	
	std::cout << "enter generic version of swap()" << std::endl;
	T temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
// 重载函数模板swap，定义特殊的行为
void myNamespace::swap(double& v1, double& v2)
// 交换形参v1和v2，并输出swap特殊版本的提示
// 前置条件： v1和v2已创建
// 后置条件：
//     v1 == v2@entry，v2 == v2@entry
//     在标准输出设备上输出字符串"enter special version of swap()"
{	
	std::cout << "enter special swap(doubl&, double&)" << std::endl;
	double temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}

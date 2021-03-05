#include "apply.h"
// int main()
// {
//   // Secret s { "Secret Class", ConstructorKey{} }; // ERROR, 无法访问ConstructorKey的构造函数

//   SecretFactory sf;
//   Secret s = sf.getSecret("Secret Class");
// }

template <typename T>
typename std::enable_if<std::is_integral<T>::value,bool>::type is_odd(T i)
{
  return (i%2) == 1;
}

template <typename T, typename = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i)
{
  return (i%2) == 0;
}

int main()
{
  int i { 2 }; // i是整型值
    
  std::cout << std::boolalpha; // bool值会展示成"true", "false"而不是"0", "1"
  std::cout << "i is odd: " << is_odd(i) << '\n';
  std::cout << "i is even: " << is_even(i) << '\n';

  double d { 2.0 }; // d是双精度浮点数

  std::cout << "i is odd: " << is_odd(i) << '\n'; // ERROR, 编译失败
  std::cout << "i is even: " << is_even(i) << '\n'; // ERROR, 编译失败
}
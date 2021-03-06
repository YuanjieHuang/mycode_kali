#ifndef APPLY_H
#define APPLY_H
#include <iostream>
#define FRIEND


template <typename _Tp, typename _Alloc>
struct _Vector_base
{
  typedef _Alloc<_Tp> _Tp_alloc_type; // 分配器的具体类型
  typedef _Tp* pointer; // 存储类型

  // 数据存储的具体实现
  struct _Vector_impl : public _Tp_alloc_type
  {
    pointer _M_start; // 存储的开始
    pointer _M_finish; // 存储的结束
    pointer _M_end_of_storage; // 已经分配的空间，即capacity
  };
};

template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
class vector : protected _Vector_base<_Tp, _Alloc>
{
};


template <typename _Tp, typename _Alloc>
struct _Vector_base
{
  typedef _Alloc<_Tp> _Tp_alloc_type; // 分配器的具体类型
  typedef _Tp* pointer; // 存储类型

  // _Vector_impl利用该变量进行内存的分配
  _Tp_alloc_type _alloc;
    
  // 数据存储的具体实现
  struct _Vector_impl
  {
    pointer _M_start; // 存储的开始
    pointer _M_finish; // 存储的结束
    pointer _M_end_of_storage; // 已经分配的空间，即capacity
  };
};

template <bool _Cond, typename _Tp = void>
struct enable_if { };

template <typename _Tp>
struct enable_if<true, _Tp>
{
  typedef _Tp type;
};

#ifdef FRIEND
class Secret
{
  friend class SecretFactory;

private:
  // SecretFactory可以访问该构造函数
  explicit Secret(std::string str) : _data{std::move(str)} {}

  // SecretFactory同时也可以访问该函数，但是这可能会给我们造成麻烦
  void addData(const std::string& moreData) { _data.append(moreData); }

private:
  // SecretFactory无论如何也不应该访问该数据
  std::string _data;
};
#else
/*----------empty VS friend------------*/
class Secret
{
public:
  class ConstructorKey {
    // 如果其他的类想要访问Secret的构造函数，可以在这里添加友元
    friend class SecretFactory;
  private:
    // 构造函数为private很关键
    ConstructorKey() {}; // ①
    ConstructorKey(const ConstructorKey&) = default; // ②
  };

  // 设置为public是为了让SecretFactory访问
  explicit Secret(std::string str, ConstructorKey) : _data{std::move(str)} {}

private:
  void addData(const std::string& moreData) { _data.append(moreData); }

  std::string _data;
};

class SecretFactory
{
public:
  Secret getSecret(std::string str) {
    // RVO
    return Secret { std::move(str), Secret::ConstructorKey{} };
  }

  void modify(Secret& secret, const std::string& additionalData) {
    // secret.addData(additionalData); // ERROR, addData是私有的，此时空类已经限制了SecretFactory访问Secret的函数
  }
};
#endif
#endif
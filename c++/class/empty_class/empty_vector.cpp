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
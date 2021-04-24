class forward_iterator_tag {};
class random_access_iterator_tag {};

class MySimpleForwardIterator {
public:
  typedef typename forward_iterator_tag tag;
  // ...
};

class MySimpleRandomIterator {
public:
  typedef typename random_access_iterator_tag tag;
  // ...
};

template<class iterator, class tag>
void myfunc_int(iterator it, tag t) {
  // general implementation of myfunc
}

template<class iterator>
void myfunc_int<iterator, forward_iterator_tag>(iterator it) {
  // Implementation for forward iterators
}

template<class iterator>
void myfunc_int<iterator, random_access_iterator_tag>(iterator it) {
  // Implementation for random access iterators
}

template<class iterator>
void myfunc(iterator it) {
  myfunc_int<iterator, typename iterator::tag>(it);
}
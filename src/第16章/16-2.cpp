template <class T>
void seqList<T>::doubleSpace() 
{   T *tmp = storage;

    size *= 2;
    storage = new T[size];
    for (int i = 0; i < current_size; ++i) storage[i] = tmp[i];
    delete [] tmp;
}

template <class T>
void seqList<T>::insert( Itr &p, const T &x) 
{   T *q;

    if (size == current_size) {
        int offset = p.pos - storage;
        doubleSpace(); 
        p.pos = storage + offset;		//迭代器指回新空间中的相应对象
    }
    q = storage + current_size;

    while (q > p.pos) { *q = *(q-1); --q;}	//迭代器指出的对象后的所有对象后移一个位置
 
    *p.pos = x;
    ++current_size;
}


template <class T>
void seqList<T>::erase(const Itr &p) 
{   T *q =p.pos ;

    --current_size;
    while (q < storage + current_size)  { *q = *(q+1);   ++q;}
}

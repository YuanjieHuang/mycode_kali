template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize = MaxListSize;
    element = new T[MaxSize];
    length = 0;
} 


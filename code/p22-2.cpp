//把第k个元素取至x中
template<class T> 
bool LinearList<T>::Find(int k, T& x) const  
{ 
    //如果不存在第k个元素, 则返回false, 否则返回true
    if (k < 1 || k > length) return false; 	//不存在第k个元素
    x = element[k - 1];
    return true;
}

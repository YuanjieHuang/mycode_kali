#include <cstdio>
#include <list>
using namespace std;
#if 0
void NormalFunc()
{
	printf("这里是普通函数\n");
}
 
class A
{
public:
	static void StaticFunc()
	{
		printf("这里是成员静态函数\n");
	}
	void MemberFunc()
	{
		printf("这里是成员非静态函数\n");
	}
};
int main()
{
	//普通函数
	typedef void(*NormalFuncp)();
	//成员函数
	typedef void(A::*MemberFuncp)();
 
	NormalFuncp fun1 = NormalFunc;
	MemberFuncp fun2 = &A::MemberFunc;
	NormalFuncp fun3 = A::StaticFunc;
	A a;
	fun1();
	(a.*fun2)();//用 .* 或者 ->* 的语法来调用
	fun3();
 
	return 0;
}
#endif


class IDelegate
{
public:
    virtual ~IDelegate() { }
    virtual bool isType(const std::type_info& _type) = 0;
    virtual void invoke() = 0;
    virtual bool compare(IDelegate *_delegate) const = 0;
};

class CStaticDelegate : public IDelegate
{
public:
    typedef void (*Func)();
 
    CStaticDelegate(Func _func) : mFunc(_func) { }
 
    virtual bool isType(const std::type_info& _type) { return typeid(CStaticDelegate) == _type; }
 
    virtual void invoke() { mFunc(); }
 
    virtual bool compare(IDelegate *_delegate) const
    {
        if (0 == _delegate || !_delegate->isType(typeid(CStaticDelegate)) ) return false;
        CStaticDelegate * cast = static_cast<CStaticDelegate*>(_delegate);
        return cast->mFunc == mFunc;
    }
 
private:
    Func mFunc;
};

template<class T>
class CMethodDelegate : public IDelegate
{
public:
    typedef void (T::*Method)();
 
    CMethodDelegate(T * _object, Method _method) : mObject(_object), mMethod(_method) { }
 
    virtual bool isType( const std::type_info& _type) { return typeid(CMethodDelegate<T>) == _type; }
 
    virtual void invoke()
    {
        (mObject->*mMethod)();
    }
 
    virtual bool compare(IDelegate *_delegate) const
    {
        if (0 == _delegate || !_delegate->isType(typeid(CMethodDelegate<T>))) return false;
        CMethodDelegate<T>* cast = static_cast<CMethodDelegate<T>*>(_delegate);
        return cast->mObject == mObject && cast->mMethod == mMethod;
    }
 
private:
    T * mObject;
    Method mMethod;
};

inline IDelegate* newDelegate( void (*_func)() )
{
    return new CStaticDelegate(_func);
}
 
template<class T>
inline IDelegate* newDelegate( T * _object, void (T::*_method)() )
{
    return new CMethodDelegate<T>(_object, _method);
}

class CMultiDelegate
{
public:
    typedef std::list<IDelegate*> ListDelegate;
    typedef ListDelegate::iterator ListDelegateIterator;
    typedef ListDelegate::const_iterator ConstListDelegateIterator;
 
    CMultiDelegate () { }
    ~CMultiDelegate () { clear(); }
 
    bool empty() const
    {
        for (ConstListDelegateIterator iter = mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
        {
            if (*iter) return false;
        }
        return true;
    }
 
    void clear()
    {
        for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
        {
            if (*iter)
            {
                delete (*iter);
                (*iter) = 0;
            }
        }
    }
 
    CMultiDelegate& operator+=(IDelegate* _delegate)
    {
        for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
        {
            if ((*iter) && (*iter)->compare(_delegate))
            {
                delete _delegate;
                return *this;
            }
        }
        mListDelegates.push_back(_delegate);
        return *this;
    }
 
    CMultiDelegate& operator-=(IDelegate* _delegate)
    {
        for (ListDelegateIterator iter=mListDelegates.begin(); iter!=mListDelegates.end(); ++iter)
        {
            if ((*iter) && (*iter)->compare(_delegate))
            {
                if ((*iter) != _delegate) delete (*iter);
                (*iter) = 0;
                break;
            }
        }
        delete _delegate;
        return *this;
    }
 
    void operator()( )
    {
        ListDelegateIterator iter = mListDelegates.begin();
        while (iter != mListDelegates.end())
        {
            if (0 == (*iter))
            {
                iter = mListDelegates.erase(iter);
            }
            else
            {
                (*iter)->invoke();
                ++iter;
            }
        }
    }
 
private:
    CMultiDelegate (const CMultiDelegate& _event);
    CMultiDelegate& operator=(const CMultiDelegate& _event);
 
private:
    ListDelegate mListDelegates;
};

void Say()
{
	printf("你好\n");
}
class A
{
public :
	void Say(){ printf("你不好\n"); }
};
int main()
{
	CMultiDelegate onclick;
	onclick += newDelegate(Say);
 
	onclick += newDelegate(&A(),&A::Say);   //注意这里不能传入 new A(), 因为会内存泄漏。
 
	onclick();
    return 0;
}
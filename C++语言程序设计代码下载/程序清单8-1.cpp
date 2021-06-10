程序清单8-1
// **********************************************************
// accessControl.cpp
// 演示在继承中派生类对基类成员的访问控制
// **********************************************************

class Base {
public:	
	int getBaseI()
    {
		baseTemp = baseI;
		return baseI;
	}; 	// 公有成员函数
protected:	
	int baseI; 	// 受保护成员
private:	
	int baseTemp; 	// 私有成员
};

// 公有派生：在Derived1类中baseI是受保护成员，getBaseI()是公有成员
// baseTemp不可访问
class Derived1: public Base { 
public: 
	int getDrv1I()
     {
          // 编译出错，因为从Base继承下来的baseTemp不可访问
	     baseTemp = baseI; 
	     return baseI; 
	}
};

// 受保护派生：在Derived2类中baseI是受保护成员，getBaseI()变成受保护成员
// baseTemp不可访问
class Derived2: protected Base { 
public: 
	int getDrv2I()
     {
	     // 编译出错，因为从Base继承下来的baseTemp不可访问
	     baseTemp = baseI; 
	     return baseI; 
	}
};

// 私有派生：在Derived3类中baseI和getBaseI()都变成私有成员
// baseTemp不可访问
class Derived3: private Base{	
public: 
	int getDrv3I()
  	{
          // 编译出错，因为从Base继承下来的baseTemp不可访问
	     baseTemp = baseI; 
 	     return baseI; 
   	}
};

int main()
{
	Derived1 drv1;
	Derived2 drv2;
	Derived3 drv3;

	// getBaseI()在Derived1类中是公有成员
	drv1.getBaseI();

	// 编译错：在Derived2类中getBaseI()变成受保护成员，外部不可访问
	drv2.getBaseI();

	// 编译错：在Derived3类中getBaseI()变成了私有成员，外部不可访问
	drv3.getBaseI();
	return 0;
}  

// 一、禁用继承
class Super final
{

};

// 二、禁用重写

class Super
{
    public:
    Super();
    virtual void func() final;
}
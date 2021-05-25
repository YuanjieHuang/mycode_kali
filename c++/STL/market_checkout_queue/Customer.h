    #ifndef CUSTOMER_H
    #define CUSTOMER_H
    #include <stddef.h>
    class Customer
    {
    protected:
        size_t service_t ; //顾客结账需要的时间
    public:
        explicit Customer(size_t st) :service_t(st){}
        //模拟随着时间的变化，顾客结账所需时间也会减短
        Customer& time_decrement()
        {
            if (service_t > 0)
                --service_t;
            return *this;
        }
        bool done() const { return service_t == 0; }
    };
    #endif
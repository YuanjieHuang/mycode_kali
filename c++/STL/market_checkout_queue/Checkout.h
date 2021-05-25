    #ifndef CHECKOUT_H
    #define CHECKOUT_H
    #include <queue> // For queue container
    #include "Customer.h"
    class Checkout
    {
    private:
        std::queue<Customer> customers; //该队列等到结账的顾客数量
    public:
        void add(const Customer& customer) { customers.push(customer); }
        size_t qlength() const { return customers.size(); }
       
        void time_increment()
        {
            if (!customers.empty())
            { 
                //有顾客正在等待结账，如果顾客结账了，就出队列
                if (customers.front().time_decrement().done())
                    customers.pop(); 
            }
        }
        bool operator<(const Checkout& other) const { return qlength() < other.qlength(); }
        bool operator>(const Checkout& other) const { return qlength() > other.qlength(); }
    };
    #endif
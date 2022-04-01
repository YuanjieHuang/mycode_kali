# ifndef array_hpp
#define array_hpp

//带返回值的宏函数
#define fun(a) ({a+5; a;})
#define sum(arr) \
({\
    int sum = 0;\
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)\
    {\
        sum += arr[i];\
    }\
    sum;\
})

template<typename T, int N>
int array_sum(T (&arr)[N])
{
    int sum = 0;
    for(int i = 0; i <= N; i++)
        sum +=i;
    return sum;
}

#endif
/*
宏不支持递归
尽可能为每个形参加上括号
*/
/*********************宏定义打印 分级打印 数组打印 BEGIN **************************/
#define __LOG_OFF__  1 // close all log
#define LOG_ERROR 1
#define LOG_WARN 2
#define LOG_DEBUG 3
#define LOG_INFO 4
#define LOG_STR 5
#define LOG_RETURN 6
#define LOG_CARRY 7
 
#ifdef __LOG_OFF__
#define debug(...) printf(__VA_ARGS__)
 
#define debugAssert(...) printf("\n[File:%s]\n"   \
    "[Function:%s]\n" \
    "[Line:%d] \n"    \
    "\n[]log:%s]\n",  \
    __FILE__, __FUNCTION__, __LINE__, __VA_ARGS__);
#else
#define debug(...) 
#define debugAssert(x) 
#endif
 
#ifdef LOG_ERROR //打印错信息
#define log_error(...) debug(__VA_ARGS__)
#endif
 
#ifdef LOG_WARN //打印报警信息
#define log_warn(...) debug(__VA_ARGS__)
#endif
 
#ifdef LOG_DEBUG //打印各种值
#define log_debug(...) debug(__VA_ARGS__)
#endif
 
#ifdef LOG_INFO //打印纯字符信息
#define log_info(...) debug(__VA_ARGS__)
#endif
 
#ifdef LOG_STR //打印字符串数组
#define log_str(...) debug(__VA_ARGS__)
#endif
 
 
#ifdef LOG_RETURN//打印返回值
#define log_return(...) debug(__VA_ARGS__)
#endif
 
#ifdef LOG_CARRY//打印数组 十六进制打印 空位补0
#define log_carry(BUFSIZ,len) \
    do  \
    { \
        for(int i = 0;i<len;i++) \
        { \
            printf("%02X ",BUFSIZ[i]); \
        } \
        debug("\r\n"); \
    }while(0)
#endif

/*********************classical**************************/
#define TEST(type)                                             \
class _TempClass##type : public TestBase {                     \
public:                                                        \
    virtual void Fun();                                        \
private:                                                       \
    static RegHelper reg_obj_;                                 \
};                                                             \
RegHelper _TempClass##type::reg_obj_(new type());              \
virtual void _TempClass##type::Fun()

#define PP_NARG(...) PP_NARG_(__VA_ARGS__, PP_RSEQ_N())
#define PP_NARG_(...) PP_ARG_N(__VA_ARGS__)
#define PP_ARG_N( \
        _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
        _11,_12,_13,_14,_15,_16, N, ...) N
#define PP_RSEQ_N() \
        16,15,14,13,12,11,10, \
        9,8,7,6,5,4,3,2,1,0
// 得到指定地址上的一个字节或字
#define  MEM_B( x )  ( *( (byte *) (x) ) )
#define  MEM_W( x )  ( *( (word *) (x) ) )
// 得到一个结构体中field所占用的字节数
#define FSIZ( type, field ) sizeof( ((type *) 0)->field )
// 得到一个变量的地址
#define B_PTR( var ) ( (byte *) (void *) &(var) ) 
#define W_PTR( var ) ( (word *) (void *) &(var) )
#define UPCASE( c ) ( ((c) >= "a" && (c) <= "z") ? ((c) - 0x20) : (c) )
#define DECCHK( c ) ((c) >= "0" && (c) <= "9")
#define HEXCHK( c ) ( ((c) >= "0" && (c) <= "9") ||((c) >= "A" && (c) <= "F") ||((c) >= "a" && (c) <= "f") )
// 防止溢出的一个方法
#define INC_SAT( val ) (val = ((val)+1 > (val)) ? (val)+1 : (val))
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( (a[0]) ) )

#define MALLOC(n, type) ((type *)malloc((n)* sizeof(type)))
#define SAFE_DELETE(p) do{ delete p; p = NULL} while(0)
// 获得结构体(TYPE)的变量成员(MEMBER)在此结构体中的偏移量。
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
// 根据"结构体(type)变量"中的"域成员变量(member)的指针(ptr)"来获取指向整个结构体变量的指针。
#define container_of(ptr, type, member) ({          \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
    (type *)( (char *)__mptr - offsetof(type,member) );})
#define MAX( a, b) ( (a) > (b) (a) : (b) )
#define MIN( x, y ) ( ((x) < (y)) ? (x) : (y) )

/*===================================NOT VERY WELL===========================================*/
#define loop(a, b) for(int i=0;i<(b);++i)\
{\
(a)+=i;\
}
#define STRING(x) #x;
// const char *str = STRING( test_string );
// #define myprintf(templt,...) fprintf(stderr,templt,__VA_ARGS__)
// #define myprintf(templt, ...) fprintf(stderr,templt, ##__VAR_ARGS__)

// #define myprintf(templt,args...) fprintf(stderr,templt,args)


#define PSQR(x) printf("the square of " #x " is %d.\n",(x)*(x))
#define XNAME(n) x##n
#define PXN(n) printf("x"#n" = %d\n",x##n)
#define PR(...) printf(__VA_ARGS__)

#define FREE(ptr)\
if(NULL != ptr)\
{\
    free(ptr);\
    ptr = NULL;\
}


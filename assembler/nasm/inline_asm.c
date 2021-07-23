// 上面代码的源地址存在esi寄存器中，目的地址存在EDI中。接着开始复制操作，直到遇到0结束。约束符constraint 为”&S”,”&D”,”&a”，
// 指定了使用的寄存器为esi，edi和eax。很明显这些寄存器是clobber寄存器，因为它们的内容会在函数执行后被改变。
// 此外我们也能看出为什么memory被放在clobber list中，因为d0, d1, d2被更新了。
 
//     我们再来看一个类似的函数。该函数用来移动一块双字（double word）。注意这个函数是用宏来定义的。
    `#define mov_blk(src, dest, numwords) \
    __asm__ __volatile__ (                                          \
                           "cld\n\t"                                \
                           "rep\n\t"                                \
                           "movsl"                                  \
                           :                                        \
                           : "S" (src), "D" (dest), "c" (numwords)  \
                           : "%ecx", "%esi", "%edi"                 \
                           )`
    
//     该函数没有输出，但是块移动过程导致ecx, esi, edi内容被改变，所以我们必须把它们放在clobber list中。
 
// 5. 在Linux中，系统调用是用GCC内联汇编的形式实现的。让我们来看看一个系统调用是如何实现的。所有的系统调用都是用宏来写的 (在linux/unistd.h)。
// 例如，一个带三个参数的系统调用的定义如下:
      #define _syscall3(type,name,type1,arg1,type2,arg2,type3,arg3) \
    type name(type1 arg1,type2 arg2,type3 arg3) \
    { \
    long __res; \
    __asm__ volatile (  "int $0x80" \
                      : "=a" (__res) \
                      : "0" (__NR_##name),"b" ((long)(arg1)),"c" ((long) arg2)), \
                        "d" ((long)(arg3))); \
    __syscall_return(type,__res); \
    }`
    
    // 所有带三个参数的系统调用都会用上面这个宏来执行。这段代码中，系统调用号放在eax中，参数分别放在ebx，ecx，edx中，最后用”int 0x80”执行系统调用。
    // 返回值放在eax中。
     
    // Linux中所有的系统调用都是用上面类似的方式实现的。比如Exit系统调用，它是带单个参数的系统调用。实现的代码如下:
    {
        asm(  "movl $1,%%eax;         /* SYS_exit is 1 */
            xorl %%ebx,%%ebx;      /* Argument is in ebx, it is 0 */
            int  $0x80"            /* Enter kernel mode */
            );
    }
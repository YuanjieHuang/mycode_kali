/*
/usr/lib/crt1.o  --->包含入口函数_start
/usr/lib/crti.o
/usr/lib/crtn.o
链接器输入文件的顺序一般是：
ld crt1.o.crti.o [user_bojects] [system_libraries] crtn.o
gcc -nostartfile -nostdlib
__attribute__((section(".init")))必须使用汇编指令，不能让编译器产生"ret"指令
*/
#include <stdio.h>
void my_init(void) __attribute__ ((constructor));
void my_init(void)
{
    printf("Hello ");
}
// typedef void(*ctor_t)(void);
// ctor_t __attribute__((section (".ctors"))) my_init_p = &my_init;

int main()
{
    printf("world.\n");
    return 0;
}
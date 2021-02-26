#include <stdio.h>
#if 0
Inline Assembly:
__asm__("assembly code");

__asm__(assembler template 
	: output operands                  /* optional */
	: input operands                   /* optional */
	: list of clobbered registers      /* optional */
	);
#endif
int main() 
{
        int a = 10, b;
    // __asm__　__volatile__("Instruction List" : Output : Input : Clobber/Modify);
    //  __asm__可简写为asm，用于标识一段汇编指令，__volatile__可简写为volatile，用于告诉编译器不需要对asm中的汇编指令做优化，原封不动的保留即可
	asm("movl %1, %%eax\n\t"
		"movl %%eax, %0\n\t"
		 :"=r"(b)        /* output */
		 :"r"(a)         /* input */
		 :"%eax"         /* clobbered register */
		);
    
    // __asm__("movl $1, %eax\n\t"
	// "movl $4, %ebx\n\t"
	// "int $0x80");
    // __asm__("nop"); 
	printf("Result: %d, %d\n", a, b);
	return 0;
}
char *str = "Hello world.\n";

void print()
{
    asm(
        "movl $13,%%edx \n\t"
        "movl %0,%%ecx \n\t"
        "movl $0,%%ebx \n\t"
        "movl $4,%%eax \n\t"
        "int $0x80 \n\t"
        ::"r"(str):"edx","ecx","ebx"
    );
}

void exit()
{
    asm(
        "movl $42,%ebx \n\t"
        "movl $1,%eax \n\t"
        "int  $0x80 \n\t"
    );
}

void nomain()
{
    print();
    exit();
}
// gcc -c -fno-builtin -m32 minist_program_helloWorld.c 
// ld -static -e nomain -m elf_i386 -o minist_program_helloWorld minist_program_helloWorld.o
int main()
{
    int ret;
    char msg[] = "hello\n";
    __asm__ volatile (
        "call *%%esi"
        : "=a" (ret)
        : "a" (4),
        "S" (0xffffe4000),
        "b" ((long) 1),
        "c" ((long) msg),
        "d" ((long) sizeof(msg))
    );
    return 0;
}
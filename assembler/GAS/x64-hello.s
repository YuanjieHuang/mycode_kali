    .global _start
    .text
    _start:
        # write(1, message, 13)
        mov     $1, %rax                # system call 1 is write
        mov     $1, %rdi                # file handle 1 is stdout
        mov     $msg, %rsi              # address of string to output
        mov     $len, %rdx              # number of bytes
        syscall                         # invoke operating system to do the write
        # exit(0)
        mov     $60, %rax               # system call 60 is exit
        xor     %rdi, %rdi              # we want return code 0
        syscall                         # invoke operating system to exit
    .data
    msg:
        .ascii  "Hello, world\n"
        len = . - msg   # length of our dear string

    // $ as -o x64-hello.o x64-hello.s
    // $ ld -o x64-hello x64-hello.o


// .text                           # section declaration

// 			                          # we must export the entry point to the ELF linker or
//     .global _start              # loader. They conventionally recognize _start as their
// 			                          # entry point. Use ld -e foo to override the default.

// _start:

//                                 # write our string to stdout

// 	  movl    $len,%edx           # third argument: message length
// 	  movl    $msg,%ecx           # second argument: pointer to message to write
// 	  movl    $1,%ebx             # first argument: file handle (stdout)
// 	  movl    $4,%eax             # system call number (sys_write)
// 	  int     $0x80               # call kernel

//                                 # and exit

// 	  movl    $0,%ebx             # first argument: exit code
// 	  movl    $1,%eax             # system call number (sys_exit)
// 	  int     $0x80               # call kernel

// .data                           # section declaration

// msg:
// 	.ascii    "Hello, world!\n"   # our dear string
// 	len = . - msg                 # length of our dear string


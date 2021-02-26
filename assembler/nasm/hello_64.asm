;"Hello world!" program for 64-bit mode Linux in NASM style assembly
;  build: nasm -f elf64 -F dwarf hello.asm
;  link:  ld -o hello hello.o

DEFAULT REL			; use RIP-relative addressing modes by default, so [foo] = [rel foo]

SECTION .rodata			; read-only data can go in the .rodata section on GNU/Linux, like .rdata on Windows
Hello:		db "Hello world!",10        ; 10 = `\n`.
len_Hello:	equ $-Hello                 ; get NASM to calculate the length as an assemble-time constant
;;  write() takes a length so a 0-terminated C-style string isn't needed. It would be for puts

SECTION .text

global _start
_start:
	mov eax, 1				; __NR_write syscall number from Linux asm/unistd_64.h (x86_64)
	mov edi, 1				; int fd = STDOUT_FILENO
	lea rsi, [rel Hello]			; x86-64 uses RIP-relative LEA to put static addresses into regs
	mov rdx, len_Hello		; size_t count = len_Hello
	syscall					; write(1, Hello, len_Hello);  call into the kernel to actually do the system call
     ;; return value in RAX.  RCX and R11 are also overwritten by syscall

	mov eax, 60				; __NR_exit call number (x86_64)
	xor edi, edi				; status = 0 (exit normally)
	syscall					; _exit(0)

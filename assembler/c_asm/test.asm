; This is primarily from this really awesome SO answer http://stackoverflow.com/a/20085862/184212

bits 32
extern _printf
global _main

section .data
  message db "number: %d!", 10, 0
  number1 dd 123
  number2 dd 456

section .text
_main:
  ; I legit don't get this, it's something to do with "alignment"
  ; which I think means that esp has to be congruent to 0 mod 16
  ; but I don't understand why or how we're supposed to know that it's misaligned
  ; also, I think subtracting is putting more on the stack and adding is removing from it
  ; I find it confusing that 12 is the right number, regardless of how many args I pass
  sub esp, 12
  mov dword[esp], message
  mov eax, [number1] ; seems we have to do this because it's not smart enough to let us dereference number1 directly
  mov dword[esp+4], eax
  call _printf
  add esp, 12
  mov eax, 0

  ; Call it a second time to prove that things generally work
  sub esp, 12
  mov dword[esp], message
  mov eax, [number2]
  mov dword[esp+4], eax
  call _printf
  add esp, 12
  mov eax, 0

  ; exit with a status of not-zero, just to prove it worked
  push dword 7
  call my_exit

my_exit:
  mov eax, 1  ; syscall number for exit program
  int 80h      ; interrupt 80 invokes a syscall
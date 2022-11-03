section  .text                     ; text segment
global   _start

_start:
jmp short ender

starter:
; SYSCAL: Write(1, msg, 14)
xor eax, eax
xor ebx, ebx
xor ecx, ecx
mov al, 4   ; put 4 into eax since write is syscall #4
mov bl, 1   ; put 1 into ebx since stdout is 1
pop ecx;
mov dl, 10 ; put the address of the string int ecx
int 0x80     ; call the kernel to make the system call happen

; SYSCALL: exit(0)
xor eax, eax
mov al, 1 ; put 1 into eax since exit is syscall 1
mov ebx, 0 ; exit with success
int 0x80   ; do the syscall

ender:
call starter
db "hallowarld"

; compile with the following
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; nasm -f elf helloworld.asm
; ld -m elf_i386 helloworld.o 
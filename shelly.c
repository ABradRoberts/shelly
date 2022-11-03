
/*
0000000000000000 <msg>:
   0:	48                   	rex.W
   1:	65 6c                	gs insb (%dx),%es:(%rdi)
   3:	6c                   	insb   (%dx),%es:(%rdi)
   4:	6f                   	outsl  %ds:(%rsi),(%dx)
   5:	2c 20                	sub    $0x20,%al
   7:	57                   	push   %rdi
   8:	6f                   	outsl  %ds:(%rsi),(%dx)
   9:	72 6c                	jb     77 <msg+0x77>
   b:	64 21 0a             	and    %ecx,%fs:(%rdx)

Disassembly of section .text:

0000000000000000 <_start>:
   0:	b8 04 00 00 00       	mov    $0x4,%eax
   5:	bb 01 00 00 00       	mov    $0x1,%ebx
   a:	b9 00 00 00 00       	mov    $0x0,%ecx
   f:	ba 0e 00 00 00       	mov    $0xe,%edx
  14:	cd 80                	int    $0x80
  16:	b8 01 00 00 00       	mov    $0x1,%eax
  1b:	bb 00 00 00 00       	mov    $0x0,%ebx
  20:	cd 80                	int    $0x80


 eb 1a 31 c0 31 db 31 c9 b0 04 b3 01 59 b2 0a cd
 80 31 c0 b0 01 bb 00 00 00 00 cd 80 e8 e1 ff ff
 ff 68 61 6c 6c 6f 77 61 72 6c 64
*/

// char shelly[] =
//     "\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72\x6c\x64\x21\x0a"
//     "\xb8\x04\x00\x00\x00"
//     "\xbb\x01\x00\x00\x00"
//     "\xb9\x00\x20\x40\x00"
//     "\xba\x0e\x00\x00\x00"
//     "\xcd\x80"
//     "\xb8\x01\x00\x00\x00"
//     "\xbb\x00\x00\x00\x00"
//     "\xcd\x80";

// char shelly[] = 
//  "\xeb\x1a\x31\xc0\x31\xdb\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x0a\xcd"
//  "\x80\x31\xc0\xb0\x01\xbb\x00\x00\x00\x00\xcd\x80\xe8\xe1\xff\xff"
//  "\xff\x68\x61\x6c\x6c\x6f\x77\x61\x72\x6c\x64";
char shelly[] = "\xeb\x1a\x31\xc0\x31\xdb\x31\xc9\xb0\x04\xb3\x01\x59\xb2\x0a\xcd\x80\x31\xc0\xb0\x01\xbb\x00\x00\x00\x00\xcd\x80\xe8\xe1\xff\xff\xff\x68\x61\x6c\x6c\x6f\x77\x61\x72\x6c\x64";

int main(){
    int *ret; //return pointer for manipulating saved return
    ret = (int *)&ret + 2; // set return to point to the saved return value on the stack
    (*ret) = (int)shelly; // change the saved return value to the address of the shellycode so it executes :) here goes nuthin...
}

// fuuuuuuck this is pissin me off, imma go back to webapps where i'm cool and smart
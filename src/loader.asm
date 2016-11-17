BITS 32

section .text
    align 4
	dd 0x1BADB002
	dd 0x00
	dd - (0x1BADB002 + 0x00)

global kstart
extern kmain

kstart:
	mov esp, stack_space
	push eax
	call kmain
.halt:
	cli
	jmp .halt

section .bss
resb 8192
stack_space:

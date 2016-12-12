%macro print 2
mov rax,1
mov rdi,1
mov rsi,%1
mov rdx,%2
syscall
%endmacro

section .data
nl db 10

section .bss
temp resb 1
count resb 1

section .text
global _start
_start:
	pop r8
	mov al,r8b
	mov [count],al
	add r8b,30h
	mov [temp],r8b
	print temp,1
		
pop_again: 
	print nl,1
	pop r8
up:	mov al,[r8]
	cmp al,00
	je nxt
	mov [temp],al
	print temp,1
	inc r8
	jmp up	
nxt:	dec byte[count]
	jnz pop_again
	print nl,1
	
mov rax,60
mov rdi,0
syscall
	

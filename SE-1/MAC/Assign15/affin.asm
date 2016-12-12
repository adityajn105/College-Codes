%macro print 2
	push rax
	push rbx
	push rcx
	push rdx
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

section .bss
temp resb 128
original resb 128
conv resb 128

section .data
msg1 db "Original affinity "
msg1len equ $-msg1
msg2 db "Changed affinity "
msg2len equ $-msg2
nline db "",10

section .text
global _start
_start:

	mov eax,242
	mov ebx,0
	mov ecx,128
	mov edx,temp
	int 80h
	
	mov dl,[temp]
	cmp dl,09
	jbe skip
	add dl,07
skip:	add dl,30h
		mov [original],dl
		
		print msg1,msg1len
		print original,1
		print nline,1
		
		mov al,01
		mov [temp],al
		
		mov eax,241
		mov ebx,0
		mov ecx,128
		mov edx,temp
		int 80h
		
		mov eax,242
		mov ebx,0
		mov ecx,128
		mov edx,temp
		int 80h
		
		mov dl,[temp]
		
		add dl,30h
		mov [conv],dl
		
		print msg2,msg2len
		print conv,1
		print nline,1
		
		mov eax,1
		mov ebx,0
		int 80h
		

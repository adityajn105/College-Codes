%macro print 2
	push rax
	push rbx
	push rcx
	push rdx
	mov rax,1
	mov rdi,1
	mov rsi,%1
	mov rdx,%2
	syscall
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro
extern getpass

section .data
msgp db "Enter a password : ",0
msgplen equ $-msgp
passw db "test123"
passwlen equ $-passw
passwc db "Password is correct ",10
passwclen equ $-passwc
passwnc db "Password is incorrect ",10
passwnclen equ $-passwnc
nline db "",10

section .text
global main
main:
		mov rdi,msgp
		call getpass
		mov rbx,rax	;rax holds pointer to entered password
		print rbx,15
		print nline,1
		mov rsi,passw
		mov rdi,rbx
		mov rcx,passwlen
		
next_byte :
			mov al,[rsi]	;cld
			mov bl,[rdi]	;repe cmpsb
			inc rsi			;jz ok
			inc rdi			;disp passwnc
			cmp al,bl		;jmp quit
			jne over		;ok : disp passwc
			dec rcx			;quit
			jnz next_byte
			
			print passwc,passwclen
			jmp quit
	over :	print passwnc,passwnclen
quit :
		mov rax,60
		mov rdi,0
		syscall
			
			

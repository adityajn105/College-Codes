%macro inout 4
push rax
push rbx
push rcx
push rdx
mov eax,%1
mov ebx,%2
mov ecx,%3
mov edx,%4
int 80h
pop rdx
pop rcx
pop rbx
pop rax
%endmacro

section .data
msg1 db "Enter a string:",20h
msg1len equ $-msg1

msg2 db "-----Enter ur choice------",10,"1.Length",10,"2.Reverse",10,"3.Palindrome",10,"4.Exit",10
msg2len equ $-msg2

msg3 db "length is:",20h
msg3len equ $-msg3

msg4 db "String is palindrome",10
msg4len equ $-msg4

msg5 db "String is not palindrome",10
msg5len equ $-msg5

msg6 db "Reversed String is:",20h
msg6len equ $-msg6

nwln db 10

section .bss
string resb 16				;buffer to store input string
cho resb 2	
leng resb 2				;strores ASCII value of length
revstr resb 16				;buffer to store reversed string
len resb 1				;stores decimal value of length
temp resb 1


section .text
global _start
_start:

inout 4,1,msg1,msg1len
inout 3,0,string,16

again:	inout 4,1,msg2,msg2len	
	inout 3,0,cho,2		

	cmp byte[cho],32h		;choice no 2
	je rev	
	cmp byte[cho],33h		;choice no 3
	je pali
	ja exit


	call length		
	jmp again

rev:	call reverse
	jmp again

pali:	call palindrome
	jmp again
exit:
	mov eax,1
	mov ebx,0
	int 80h



length:
		mov edx,0	
		mov esi,string		;esi points to starting address of string
	con:	cmp byte[esi],0Ah	;cmp byte with 0A
		je ok1			;jump if equal to routine to display length
		inc edx			;increament counter
		inc esi			;increament pointer
		jmp con
		
	ok1:	mov byte[len],dl	;len storing decimal value of length
		
		mov esi,leng		;storing ASCII value of length in leng
		mov cl,2
	conve:	rol dl,4
		mov byte[temp],dl
		and dl,0fh
		cmp dl,9h
		jbe add30
		add dl,07h
	add30:	add dl,30h
		mov byte[esi],dl
		mov dl,byte[temp]
		inc esi
		dec cl
		jnz conve	

		
		inout 4,1,msg3,msg3len
		inout 4,1,leng,2	;display length
		inout 4,1,nwln,1
		ret

palindrome:
		mov esi,string		;initialize pointer to string
		mov edi,revstr		;initialize pointer to revstr
		
	con2:	mov bl,byte[esi]	
		cmp byte[edi],bl	;cmp first byte of string and revstr
		jne ok2			;if not equal then string is not palindrome
		inc esi			;increament pointer to string
		inc edi			;increament pointer to revstr
		cmp byte[esi],0Ah	;cmp byte of string with 0A
		je ok3			;if equal then string are palindrome
		jmp con2
		
	ok2:	inout 4,1,msg5,msg5len
		inout 4,1,nwln,1
		ret
	ok3:	inout 4,1,msg4,msg4len
		inout 4,1,nwln,1
		ret
		

reverse:
		mov esi,revstr		;initialize pointer to buffer of revstr
		mov edi,string		;initialize pointer to string
		mov edx,0		
		add dl,byte[len]
		dec dl
		add edi,edx		;move pointer of string to end of that string
	
		mov cl,byte[len]	;initailize counter which equals length of string
	con3:	mov bl,byte[edi]	
		mov byte[esi],bl
		inc esi			;increament pointer to revstr 
		dec edi			;decreament pointer to string
		dec cl			;decreament counter
		jz ok4			;if counter equals zero then string is reversed
		jmp con3
	ok4:	inout 4,1,msg6,msg6len
		inout 4,1,revstr,16	;print reversed string
		inout 4,1,nwln,1
		ret
	

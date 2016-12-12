;Name - Darpan Bafana
;Class -Se comp 1
;roll no- 202026

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
	msg1 db "please enter no of nos:",20h
	msg1len equ $-msg1

	msg2 db "Enter no:",20h
	msg2len equ $-msg2
	
	msg3 db "The sum is:",20h
	msg3len equ $-msg3
	
	nwln db 10
	nwlen equ $-nwln

section .bss
	no resb 2
	noasc resb 9
	temp resd 1
	result resb 8

section .text
global _start
_start:
	inout 4,1,msg1,msg1len
	inout 3,0,no,2	;no of numbers to be added is stored in buffer no

	mov esi,no	;esi points to starting of buffer no
	mov cl,byte[esi];cl has first byte of no
	
	cmp cl,39h	;conversion from ascii to hex
	jbe sub30
	sub cl,07h
sub30:	sub cl,30h
	
	mov ebx,0h	;ebx will have sum
	mov eax,0h	;eax will have carry

accept:	
	inout 4,1,msg2,msg2len	
	inout 3,0,noasc,9	;number accepted is stored in noasc
	
	mov esi,noasc	;esi points to starting address of noasc
	mov edi,8h	;counter
	mov edx,0h	

conv2:	cmp byte[esi],0Ah	;if byte contain ascii for enter key then leave loop
	je adds
	cmp byte[esi],39h	;if byte greater than 39h subtract 37h else 30h
	jbe sub302
	sub byte[esi],07h
sub302: sub byte[esi],30h
	
	rol edx,4	;rotate edx by four bits for packing
	add dl,byte[esi]	;
	inc esi	;increament pointer
	dec edi	;decreament counter
	jnz conv2
	
adds:	add ebx,edx	;sum is obtained in ebx
	jnc next
	inc eax		;carry is obtained in eax
next:	inc esi
	dec cl
	jnz accept

	inout 4,1,msg3,msg3len	
	call print	;call procedure to print carry
	mov eax,ebx
	call print	;call procedure to print sum
	inout 4,1,nwln,nwlen ;prints new line

	mov eax,1	;system exit call
	mov ebx,0
	int 80h

	
	

print:
	mov esi,result	;pointer to buffer result initialized
	mov cl,8	;counter initialized
	
conve:	rol eax,4
	mov [temp],eax	;temp is temprory storage for eax
	and eax,0fh
	cmp al,09h
	jbe add30
	add al,07h
add30:
	add al,30h
	mov byte[esi],al	;copy al to byte of reult pointed by esi
	inc esi
	mov eax,[temp]	;recover eax	
	dec cl
	jnz conve
	inout 4,1,result,8
	ret
	

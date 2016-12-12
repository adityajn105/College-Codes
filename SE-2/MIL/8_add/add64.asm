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
menu db "1.Successive Addition",10,"2.Shift and Add",10,"3.Exit",10
menulen equ $-menu

msg1 db "Enter first no (32 bits):",20h
msg1len equ $-msg1

msg2 db "Enter second no (32 bits):",20h
msg2len equ $-msg2

msg3 db "Product is:",20h
msg3len equ $-msg3

nwln db 10

section .bss
no resb 9
temp resb 4
no1 resd 1
no2 resd 1
len resb 1
result resb 8
temp2 resd 1
cho resb 2


section .text
global _start
_start: 

	inout 4,1,menu,menulen
	inout 3,0,cho,2
	cmp byte[cho],33h
	jae exit

	inout 4,1,msg1,msg1len
	inout 3,0,no,9		;accept number in var no
	call convert		;call routine to convert ascii to hex 
	mov dword[no1],edx 	;move hex no in var no1
	inout 4,1,nwln,1	
	inout 4,1,msg2,msg2len	
	inout 3,0,no,9		;accept number 2 in var no
	call convert		
	mov dword[no2],edx
	inout 4,1,nwln,1

	cmp byte[cho],32h	
	je shadd

	mov edx,0
	mov edx,dword[no2]	;move number2 in dx
	mov ecx,dword[no1]	;initialize countee
	mov eax,0
	mov ebx,0

again:
	add eax,edx	;eax for sum		;sum will be in ax 
	jnc nc		;jump if no carry	
	inc ebx		;ebx for carry		;bx will contain carry
nc:	dec ecx		;decrement counter
	jnz again
	
	inout 4,1,msg3,msg3len
	call display	;display carry
	mov ebx,0	
	mov ebx,eax	;mov sum to bx
	call display	;display sum
	inout 4,1,nwln,1
	jmp _start

shadd:
	mov edx,0
	mov edx,dword[no1];no1 multiplier
	mov rax,0	
	mov eax,dword[no2];move no2 in eax
	mov rbx,0	;sum (8 bytes)
	mov cl,20h	;counter= no of bits in multiplier
	
rool:	shl rbx,1	;shift sum left by 1 bit
	rol edx,1	;rotate multiplier by 1 bit
	jnc nothing	;if MSB=1 then add otherwise do nothing
	add rbx,rax	;add no2 in sum
nothing:dec cl		;decrement counter
	jnz rool

	inout 4,1,msg3,msg3len
	mov eax,ebx	;mov lower 32 bits of sum to ax
	rol rbx,32	;upper 32 bits of ebx become lower 16 bits of ebx
	call display	;display upper 32 bits of sum
	mov ebx,eax	;move lower 32 bits in bx
	call display	;display lower 32 bits
	inout 4,1,nwln,1
	jmp _start

exit:	mov eax,1
	mov ebx,0
	int 80h

convert:		;conversion logic for ascii to hex for 32 bit no
	mov esi,no	
	mov cl,8h	;mov counter in cl
	mov edx,0h	
conve:	cmp byte[esi],0Ah
	je ok		
	cmp byte[esi],39h
	jbe sub30	
	sub byte[esi],07h
sub30:	sub byte[esi],30h
	
	rol edx,4	;rol edx by 4 bits
	add dl,byte[esi];add byte[esi] in dl
	inc esi		;inc esi
	dec cl		;dec counter
	jnz conve	
ok:	ret


display:		;display a 32 bit hex no
	mov esi,result
	mov cl,8
conve2:	rol ebx,4
	mov [temp2],ebx	
	and ebx,0fh	
	cmp bl,09h	
	jbe add30	
	add bl,07h	
add30:	add bl,30h
	mov byte[esi],bl
	inc esi
	mov ebx,[temp2]
	dec cl
	jnz conve2
	inout 4,1,result,8
	ret

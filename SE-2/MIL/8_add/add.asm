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

msg1 db "Enter first no:",20h
msg1len equ $-msg1

msg2 db "Enter second no:",20h
msg2len equ $-msg2

msg3 db "Product is:",20h
msg3len equ $-msg3

nwln db 10

section .bss
no resb 5
temp resb 2
no1 resw 2
no2 resw 2
len resb 1
result resb 4
temp2 resw 1
cho resb 2


section .text
global _start
_start:

	inout 4,1,menu,menulen
	inout 3,0,cho,2
	cmp byte[cho],33h
	jae exit

	inout 4,1,msg1,msg1len
	inout 3,0,no,5		;accept number in var no
	call convert		;call routine to convert ascii to hex 
	mov word[no1],dx 	;move hex no in var no1
	inout 4,1,nwln,1	
	inout 4,1,msg2,msg2len	
	inout 3,0,no,5		;accept number 2 in var no
	call convert		
	mov word[no2],dx
	inout 4,1,nwln,1

	cmp byte[cho],32h	
	je shadd

	mov edx,0
	mov dx,word[no2]	;move number2 in dx
	mov cx,word[no1]	;initialize countee
	mov eax,0
	mov ebx,0

again:
	add ax,dx	;eax for sum		;sum will be in ax 
	jnc nc		;jump if no carry	
	inc bx		;ebx for carry		;bx will contain carry
nc:	dec cx		;decrement counter
	jnz again
	
	inout 4,1,msg3,msg3len
	call display	;display carry
	mov ebx,0	
	mov bx,ax	;mov sum to bx
	call display	;display sum
	inout 4,1,nwln,1
	jmp _start

shadd:
	mov edx,0
	mov dx,word[no1];no1 multiplier
	mov eax,0	
	mov ax,word[no2];move no2 in ax
	mov ebx,0	;sum (4 bytes)
	mov cl,10h	;counter= no of bits in multiplier
	
rool:	shl ebx,1	;shift sum left by 1 bit
	rol dx,1	;rotate multiplier by 1 bit
	jnc nothing	;if MSB=1 then add otherwise do nothing
	add ebx,eax	;add no2 in sum
nothing:dec cl		;decrement counter
	jnz rool

	inout 4,1,msg3,msg3len
	mov ax,bx	;mov lower 16 bits of sum to ax
	rol ebx,16	;upper 16 bits of ebx become lower 16 bits of ebx
	call display	;display upper 16 bits of sum
	mov bx,ax	;move lower 16 bits in bx
	call display	;display lower 16 bits
	inout 4,1,nwln,1
	jmp _start

exit:	mov eax,1
	mov ebx,0
	int 80h

convert:		;conversion logic for ascii to hex for 16 bit no
	mov esi,no	
	mov cl,4h	;mov counter in cl
	mov edx,0h	
conve:	cmp byte[esi],0Ah
	je ok		
	cmp byte[esi],39h
	jbe sub30	
	sub byte[esi],07h
sub30:	sub byte[esi],30h
	
	rol dx,4	;rol dx by 4 bits
	add dl,byte[esi];add byte[esi] in dl
	inc esi		;inc esi
	dec cl		;dec counter
	jnz conve	
ok:	ret


display:		;display a 16 bit hex no
	mov esi,result
	mov cl,4
conve2:	rol bx,4
	mov [temp2],bx	
	and bx,0fh	
	cmp bl,09h	
	jbe add30	
	add bl,07h	
add30:	add bl,30h
	mov byte[esi],bl
	inc esi
	mov bx,[temp2]
	dec cl
	jnz conve2
	inout 4,1,result,4
	ret

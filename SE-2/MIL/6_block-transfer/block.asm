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
block db "OOOOOOOOOOADITYAOOOOOOOOOOO",10	;given block
blocklen equ $-block

given db "Given block is:",20h
givenlen equ $-given

msg1 db "Enter your choice",10,"1.Non-overlapping",10,"Overlapping",10,"2.Positive offset",10,"2.Negative offset",10,"3.Exit",10
msg1len equ $-msg1

msg2 db "Give Offset:",20h
msg2len equ $-msg2

msg3 db "Result is:",20h
msg3len equ $-msg3

done db "______________________",10
donelen equ $-done

nwln db 10

section .bss
cho resb 2
off resb 2


section .text
global _start:
_start:
	inout 4,1,given,givenlen
	inout 4,1,block,blocklen
	inout 4,1,msg1,msg1len
	inout 3,0,cho,2
	cmp byte[cho],32h
	je pos
	cmp byte[cho],33h	;if choice is 2
	je neg			;jump to neg
	ja exit			;if above exit
	
	;non overlapping
	mov esi,block		;esi points to given block
	mov edi,block		;edi points to given block
	add esi,15		;increament edi to point string
	add edi,15		;increament esi to point string
	mov edx,0		
	add edi,6		;add offset in edi
	mov ecx,6		;initialize counter
	std			;set direction flag for auto decrement od esi and edi
	rep movsb		;move bytes from esi to edi
	
	inout 4,1,msg3,msg3len
	inout 4,1,block,blocklen ;display given block
	inout 4,1,done,donelen
	jmp _start

pos:	;positive offset
	inout 4,1,msg2,msg2len	
	inout 3,0,off,2		;input offset
	mov esi,block		;esi points to given block
	mov edi,block		;edi points to given block
	add esi,15		;increament edi to point string
	add edi,15		;increament esi to point string
	mov edx,0		
	mov dl,byte[off]	;move offset in dl
	sub dl,30h		;convert offset in decimal
	add edi,edx		;add offset in edi
	mov ecx,6		;initialize counter
	std			;set direction flag for auto decrement od esi and edi
	rep movsb		;move bytes from esi to edi
	
	inout 4,1,msg3,msg3len
	inout 4,1,block,blocklen ;display given block
	inout 4,1,done,donelen
	jmp _start


neg:	;negative offset
	inout 4,1,msg2,msg2len
	inout 3,0,off,2		;input offset
	
	mov esi,block		;esi points to given block
	mov edi,block		;edi points to given block
	add esi,10		;increament esi by 10
	add edi,10		;increament edi by 10
	mov edx,0		
	mov dl,byte[off]	;move offset in dl
	sub dl,30h		;convert offset to decimal
	sub edi,edx		;subtract offset from edi
	mov ecx,6		;initialize counter
	cld			;clear direction flag for auto increament of esi and edi
	rep movsb		;move bytes from esi to edi

	inout 4,1,msg3,msg3len
	inout 4,1,block,blocklen;display given block
	inout 4,1,done,donelen
	jmp _start

exit:
	mov eax,1		;system exit call
	mov ebx,0
	int 80h

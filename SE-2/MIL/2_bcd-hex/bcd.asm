;Name -Aditya Jain
;Class- Se comp 1
;Roll no-202021
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
menu db "Enter yor choice",10,"1.BCD to hex",10,"2.Hex to BCD",10,"3.Exit",10
menulen equ $-menu
msg1 db "Please enter a bcd number:",20h
msg1len equ $-msg1
msg2 db "Equivalent hex is:",20h
msg2len equ $-msg2
msg3 db "Please enter a hex number:",20h
msg3len equ $-msg3
msg4 db "Equivalent BCD is:",20h
msg4len equ $-msg4
newln db 10

section .bss
num resb 11
result resb 8
temp resd 1
choice resb 2
hex resb 9
no resb 1
bcd resb 10
bcdasc resb 20

section .text
global _start
_start:
        
	inout 4,1,menu,menulen
	inout 3,0,choice,2
	mov esi,choice
	cmp byte[esi],32h	;jump to func for BCD display for hex no if choice 2
	je func2
	cmp byte[esi],32h	;if choice is greater then 2 then exit
	ja exit
	
	
	inout 4,1,msg1,msg1len
	inout 3,0,num,11	;ascii of bcd num is stored in num buffer
	mov esi,num		;esi is pointer to buffer num
	mov cl,10		;initialize counter
	
	mov eax,00h
	
loop:	mov edi,0Ah	
	cmp byte[esi],0Ah
	je cal
	cmp byte[esi],30h
	jb exit
	cmp byte[esi],39h
	ja exit
	mov ebx,00h
	mov bl,byte[esi]
	sub bl,30h
	
	mul edi
	add eax,ebx
	inc esi
	dec cl
	jnz loop
	
cal:	call hextoascii
	inout 4,1,msg2,msg2len
	inout 4,1,result,8
	inout 4,1,newln,1
	jmp _start
	
	
func2:
        inout 4,1,msg3,msg3len
        inout 3,0,hex,9	;hex buffer contain ascii of entered hex number
        mov esi,hex
        mov eax,0     
        mov ebx,0

loop2:  mov al,byte[esi]
        cmp al,0Ah	;exit loop if ascii for enter key is found in hex
        je next      	
        cmp al,39h	;convert ascii to hex
        jb sub30
        sub al,7h
sub30:  sub al,30h
        rol ebx,4
        add ebx,eax        	;ebx contain packed hex no
	inc esi			;increment pointer
	jmp loop2
	
next:	mov eax,ebx	
	mov cl,0
        mov ebx,0Ah
	mov esi,bcdasc
again:	mov edx,0h
	div ebx			;divide by 0Ah
	mov byte[esi],dl	;remainder is saved in buffer bcdasc(stack)
	inc cl			;increament counter
	inc esi		
	cmp eax,0h		;if quotient=0 then exit loop
	jne again
        	
        call hextoascii2	
        inout 4,1,msg4,msg4len
        inout 4,1,bcd,10
	inout 4,1,newln,1
	jmp _start
exit:
	mov eax,1
	mov ebx,0
	int 80h		



hextoascii:		;convert hex to ascii
	mov esi,result
	mov cl,8
	
conve:	rol eax,4
	mov [temp],eax
	and eax,0fh
	cmp al,09h
	jbe add30
	add al,07h
add30:
	add al,30h
	mov byte[esi],al
	inc esi
	mov eax,[temp]	
	dec cl
	jnz conve
	ret
	
hextoascii2:
	mov edi,bcd	;edi points to buffer bcd
conve2:
	dec esi		;esi is pointing to bcdasc(stack)	
	mov dl,byte[esi];
	add dl,30h	;convert obtain digit to is ascii
        mov byte[edi],dl
        inc edi		
        dec cl		;decrement counter
        jnz conve2
        ret
        	

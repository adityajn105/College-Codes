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
arr dd 123.44,152.56,456.23
tn dd 3.0
mean db "Mean is:",20h
meanlen equ $-mean
msg1 db "1.Enter your choice-",10,"1.Mean",10,"2.Variance",10,"3.Standard Deviation",10,"4.Exit",10
msg1len equ $-msg1
means dd 0.0
res dt 0.0
vares dt 0.0
stres dt 0.0
save dd 0.0
point db "."
pointl equ $-point
thousand dd 10000.0
variance dd 0.0
deviation dd 0.0
nwln db 10
nwlen equ $-nwln

section .bss
cho resb 2
by resb 1

section .text
global _start
_start:
	inout 4,1,msg1,msg1len
	inout 3,0,cho,2

	cmp byte[cho],32h
	je var
	cmp byte[cho],33h
	je std
	ja exit


	FINIT		;initialize NDP
	FLDZ		;Initialize ST(0) with 0.0
	mov esi,arr	;esi points to starting of arr
	mov cx,3h	;initialize counter
again:	FADD dword[esi]	;add first dword into ST(0)
	add esi,4	;increment esi to next dword
	dec cx		;decrement counter
	jnz again 	
	
	FDIV dword[tn]	;div sum of numbers by total numbers
	FST dword[mean]	;store ST(0) in mean buffer

	FMUL dword[thousand]	;multiply ST(0) with 10000

	FBSTP tword[res]	;Convert real data into BCD and pop to tword-res
	
	mov esi,res	;initialize pointer to res	
	call dispdec	;call routine to display BCD no in tword
	inout 4,1,nwln,nwlen
	jmp _start
	
var:	mov cx,3	;initialize counter with 3
	mov esi,arr	;initialize pointer esi to arr
aga:	
	FLDZ		;initialize ST(0) with 0.0
	FLD dword[esi] 	;Load dword pointer by esi in ST(0)
	
	FSUB dword[mean]	;ST(0) <-- ST(0)-mean
	FST dword[save]		;store ST(0) in dword-save
	FMUL dword[save]	;ST(0) <-- ST(0)*save                              

	FADD dword[variance] 	;ST(0) <-- ST(0)+variance
	FST dword[variance]	;variance <--ST(0)
	add esi,4		;increment pointer with 4
	dec cx			;decrement counter
	jnz aga	
	
	FDIV dword[tn]		;divide ST(0) by total num
	FMUL dword[thousand]	;Multiply ST(0) by 10000
	FBSTP tword[vares]	;convert real data into BCD and pop to tword-vares
	
	mov esi,vares		;esi points to tword-vares
	call dispdec		;call routine to display BCD no (in tword)
	inout 4,1,nwln,nwlen
	jmp _start

std:	
	FLDZ			;initialize ST(0) with 0.0
	FLD dword[variance]	;load dword-variance in ST(0)
	FSQRT			;ST(0) <-- sqrt(ST(0))
	FST dword[deviation]	;store ST(0) in dword-deviation
	FMUL dword[thousand]	;multiply ST(0) with 10000
	FBSTP tword[stres]	;convert real data into BCD and pop tword-stres	
	
	mov esi,stres		;esi points to tword-stres
	call dispdec		;call routine to display BCD no in tword
	inout 4,1,nwln,nwlen
	jmp _start


exit:
	mov eax,1
	mov ebx,0
	int 80h			
	

dispbyte:			;logic to display one byte of tword
	mov bl,byte[esi]	;copy byte into bl
	rol bl,4		;to display upper BCD digit
	and bl,0fh		;mask upper digit		
	add bl,30h		;convert digit to ASCII
	mov byte[by],bl		;mov ASCII digit to byte[by]
	inout 4,1,by,1		;display digit
	mov bl,byte[esi]	;again copy byte into bl
	and bl,0fh		;mask upper digit
	add bl,30h		;convert digit to ASCII
	mov byte[by],bl		;mov ASCII digit to byte[by]
	inout 4,1,by,1		;display digit
	ret

dispdec:			;logic to choose which byte to dislpay
	add esi,9		;increment esi so that it points to last digit 
	mov cx,0Ah		;intialize counter with 10
	jmp ok			

again2:	dec esi			;decrement pointer
	dec cx			;decremetn counter
	jz done			
ok:	cmp byte[esi],0		;compare byte with 00
	je again2		;skip until byte!=0 comes

again3:	call dispbyte		;call routine to display byte
	dec esi			;decremnent pointer
	dec cx			;decrement counter
	cmp cx,2		;if counter =2 display point
	jne again3

dpoint: inout 4,1,point,pointl

done:
again4: call dispbyte		;call routine to display byte
	dec esi			;decrement pointer
	dec cx			;decrement counter
	jnz again4		
	ret

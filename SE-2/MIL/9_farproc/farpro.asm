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
extern len1,len2,concated,substr,msg5,msg5len,msg6,msg6len,msg7,msg7len,string1,string2,substr,concated,nwln,count
global concat,substrings


concat:
	mov edi,concated ;move pointer to destination string
	mov esi,string1	;move pointer to string1
	mov cl,16	;initialize counter
com:	cmp byte[esi],0Ah 
	je next		;if byte is 0A then jump to next
	mov al,byte[esi]	
	mov byte[edi],al;copy byte to destination
	inc esi
	inc edi
	dec cl
	jnz com

next:	mov esi,string2	;move pointer to string 2
	mov cl,16	;initialize counter
com2:	cmp byte[esi],0Ah	
	je done
	mov al,byte[esi]
	mov byte[edi],al	;copy byte to destination
	inc esi
	inc edi
	dec cl
	jnz com2
	
done:	inout 4,1,nwln,1
	inout 4,1,msg5,msg5len
	inout 4,1,concated,32	;print concated string
	inout 4,1,nwln,1
	ret 

substrings:
	mov cx,0
	mov edx,0
again:	mov esi,string1	;pointer to main string
	add esi,edx
	mov edi,substr	;pointer to string to be searched
	
equal:	mov al,byte[edi]
	mov bl,byte[esi]
	cmp al,0Ah	;if substring ends then count++ 
	je found
	cmp bl,0Ah	;if main string ends
	je don

	cmp al,bl	;compare both bytes
	jne pro		;if string not equal jmp to pro
	inc esi		;if equal inc pointer to substring
	inc edi		;if equal inc pointer to main string
	jmp equal	

pro:	inc edx		;starting search from next byte
	jmp again
	
		
found:			;jmp here if string is found
	inc cx		;inc counter
	cmp bl,0Ah	;if main string ends
	je don		;jmp to don
	inc edx		
	jmp again

don:	cmp cx,00	;if count=0 then string not found
	jne occurs
	inout 4,1,msg7,msg7len
	jmp retu
occurs:	inout 4,1,msg6,msg6len	
	add cx,30h	;convert count to ASCII
	mov byte[count],cl		
	inout 4,1,count,1	;display count
	
retu:	inout 4,1,nwln,1	
	ret

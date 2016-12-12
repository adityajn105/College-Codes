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


section .data
fname db "text",0	;saves asciiz value of file(hello) in var(fname) 

section .bss
buffer resb 512		;reserve buffer of 512 bytes for contents	
fid resd 1	;reserve buffer of 4bytes for file discriptor
cnt resd 1	;reserve buffer of 4bytes for actual size of contents in buffer
result resb 2	;reserve 2 buyes for result
temp resb 1	;reserve 1 byte for temp


section .text
global _start
_start:

mov eax,005	;system open
mov ebx,fname	;asciiz filename
mov ecx,0	;read only
mov edx,700q	;owner have read, write and execute permissions
int 80h		
mov [fid],eax	;return file discriptor to file 		
sysread:
	;take input from file and store in buffer max 512bytes	
	mov eax,3	
	mov ebx,[fid]	
	mov ecx,buffer	
	mov edx,512	
	int 80H	
	mov [cnt],eax	;returns actual bytes stored in buffer	
	
	mov esi,buffer	;initialize pointer to buffer
	mov edi,[cnt]	;intialize counter for no of bytes in buffer
nxtbyte: mov cl,2	;initialize counter for both bytes of ascii
	mov ebx,result	;initialize pointer to result
	mov al,[esi]	;mov first ascii no to al

up:
	rol al,4	;rotate left content of al by 4 bits
	mov [temp],al	;preserve contents of al
	and al,0Fh	;mask upper 4 bit of al
	;conversion of lower 4bits into its ascii
	cmp al,09h	
	jbe add30
	add al,07h
add30:	add al,30h
	mov [ebx],al	;store content of al in address of ebx
	inc ebx		;increase ebx by i byte
	
	mov al,[temp]	;recover content of al
	dec cl		;decrease counter
	jnz up		;jump if not zero to up
	print result,2	;print result
	inc esi		;increament of pointer 
	dec edi		;decreament of counter of total bytes
	jnz nxtbyte	
		
	;if bytes displayed is equal to size of buffer then displays next 512 bytes
	cmp dword [cnt],512	
	jb exit			
	jmp sysread		

exit:
mov eax,6	;file close
mov ebx,[fid]	;file discriptor
int 80h
mov eax,1
mov ebx,0
int 80h

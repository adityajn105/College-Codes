section .data
fname db "assign10.asm",0	;saves asciiz value of file(hello) in var(fname) 

section .bss
buffer resb 512		;reserve buffer of 512 bytes for contents	
fid resd 1	;reserve buffer of 4bytes for file discriptor
cnt resd 1	;reserve buffer of 4bytes for actual size of contents in buffer

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
	
	;displays bytes stored in buffer
	mov eax,4	
	mov ebx,1	
	mov ecx,buffer	
	mov edx,[cnt]	
	int 80h		
	
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

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

global len1,len2,concated,substr,msg5,msg5len,msg6,msg6len,msg7,msg7len,string1,string2,nwln,count

extern concat,substrings

section .data
msg1 db "Enter string 1:",20h
msg1len equ $-msg1

msg2 db "Enter string 2:",20h
msg2len equ $-msg2

msg3 db "----Enter ur choice-----",10,"1.Concate",10,"2.Search Substring",10,"3.Exit",10
msg3len equ $-msg3

lengt1 db "length of string 1 is:",20h
lengt1len equ $-lengt1

lengt2 db "length of string 2 is:",20h
lengt2len equ $-lengt2

msg4 db "Enter Substring to be searched:",10
msg4len equ $-msg4

msg5 db "Concated Sttring is:",20h
msg5len equ $-msg5

msg6 db "Substring occurs:",20h
msg6len equ $-msg6

msg7 db "Substring not there"
msg7len equ $-msg7

msg8 db "Enter a string:",20h
msg8len equ $-msg8

nwln db 10

section .bss
string1 resb 16
string2 resb 16
cho resb 2
len1 resb 1
len2 resb 1
concated resb 32
substr resb 16
temp resb 1
leng resb 1
count resb 1

section .text
global _start:
_start:


	
	inout 4,1,nwln,1
choi:	inout 4,1,msg3,msg3len
	inout 3,0,cho,2
	
	cmp byte[cho],31h
	je concatenate
	cmp byte[cho],32h
	je ssubstring
	ja exit
	
concatenate: 	
		inout 4,1,msg1,msg1len
		inout 3,0,string1,16
		inout 4,1,msg2,msg2len
		inout 3,0,string2,16
		
		
		mov esi,string1		;esi points to string 1
		call length		;calculate length
		mov al,byte[leng]	
		mov byte[len1],al
		mov esi,string2		;esi points to string 2	
		call length		;calculate length
		mov al,byte[leng]
		mov byte[len2],al
	
		inout 4,1,lengt1,lengt1len
		inout 4,1,len1,1
		inout 4,1,nwln,1
		inout 4,1,lengt2,lengt2len
		inout 4,1,len2,1		

		call concat
	 	jmp choi

ssubstring:
		inout 4,1,msg8,msg8len
		inout 3,0,string1,16
		mov esi,string1
		call length
		mov al,byte[leng]
		mov byte[len1],al
		inout 4,1,nwln,1
		inout 4,1,lengt1,lengt1len
		inout 4,1,len1,1
		inout 4,1,nwln,1
		inout 4,1,msg4,msg4len
		inout 3,0,substr,16
		
		call substrings
		jmp choi

	
exit:	mov eax,1
	mov ebx,0
	int 80h	

length:				;logic to calculate length
		mov edx,0
	con:	cmp byte[esi],0Ah	;cmp byte with 0A
		je ok1			;jump if equal to routine to display length
		inc edx			;increament counter
		inc esi			;increament pointer
		jmp con
		
	ok1:
		mov esi,leng		;storing ASCII value of length in leng
		cmp dl,9h
		jbe add30
		add dl,07h
	add30:	add dl,30h
		mov byte[esi],dl
		ret




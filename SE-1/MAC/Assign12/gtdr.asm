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
msg db "Base address is:",20h
msglen equ $-msg
msg2 db "Limit is:",20h
msg2len equ $-msg2
imsg db "Contents of IDTR are   :",20h
imsgl equ $-imsg
gmsg db "Contents of GDTR are   :",20h
gmsgl equ $-gmsg
lmsg db "Contents of LDTR are   :",20h
lmsgl equ $-lmsg
tmsg db "Contents of TR are     :",20h
tmsgl equ $-tmsg
smsg db "Contents of MSW are    :",20h
smsgl equ $-smsg
nl db 10
nllen equ $-nl

section .bss
buff64 resq 1
buff16 resw 1
result1 resb 16
result2 resb 4
temp1 resq 1
temp2 resw 1


section .text
global _start
_start:

print gmsg,gmsgl
print nl,nllen
print msg,msglen
mov esi,buff64
sgdt [esi]	;contents of gdtr are stored in sgdt
mov r8,[esi]
call disp64
print nl,nllen
print msg2,msg2len
mov esi,buff16
mov bx,[esi]
call disp16
print nl,nllen

print imsg,imsgl
print nl,nllen
print msg,msglen
mov esi,buff64
sidt [esi]	;contents of idtr are stored in sidt
mov r8,[esi]
call disp64
print nl,nllen
print msg2,msg2len
mov esi,buff16
mov bx,[esi]
call disp16
print nl,nllen


print lmsg,lmsgl
print nl,nllen
mov esi,buff16
sldt [esi]	;contents of ldtr are stored in sldt
mov bx,[esi]
call disp16
print nl,nllen

print tmsg,tmsgl
print nl,nllen
mov esi,buff16
str [esi]	;contents of tr are stored in str
mov bx,[esi]
call disp16
print nl,nllen

print smsg,smsgl
print nl,nllen
mov esi,buff16
smsw [esi]	;contents of MSW are stored in smsw
mov bx,[esi]
call disp16
print nl,nllen

mov eax,1
mov ebx,0
int 80h



disp64:
	
	mov edi,result1	
	mov cl,10h    
again:	rol r8,4	
	mov [temp1],r8	
	and r8,0FH	
	cmp r8b,09	
	jbe skip	
	add r8b,07h	
skip:	add r8b,30H	
	mov [edi],r8b	
	inc edi		
	mov r8,[temp1]	
	dec cl		
	jnz again
	print result1,16
	ret			

disp16:
	
	mov edi,result2	
	mov cl,4    
again2:	rol bx,4	
	mov [temp2],bx	
	and bx,0FH	
	cmp bl,09	
	jbe skip2	
	add bl,07h	
skip2:	add bl,30H	
	mov [edi],bl	
	inc edi		
	mov bx,[temp2]	
	dec cl		
	jnz again2
	print result2,4	
	ret
	

.MODEL TINY
.CODE
ORG 100H
BEGIN:
	JMP INIT
	OLDINT DD 1
START:
	MOV AH,0AH	;program to display characters
	MOV AL,'*'	;to print '*'
	MOV BH,0
	MOV CX,0005H
	INT 10H

	JMP CS:OLDINT	;mov the original divide by zero int address

INIT:
	CLI		;clear direction flag
	MOV AH,35h	;get interrupt address
	MOV AL,0H	;interrupt no
	INT 21H
	
	MOV WORD PTR OLDINT,BX
	MOV WORD PTR OLDINT+2,ES
	
	MOV AH,25H	;modify ivt
	MOV AL,0	;int type 0
	MOV DX,OFFSET START	;starting address of user tsr
	INT 21H
	
	MOV AH,31H	;make program resident in ram
	MOV DX,OFFSET INIT	;size of resident code
	INT 21H
	
	STI	;set interrupt flag
	END BEGIN
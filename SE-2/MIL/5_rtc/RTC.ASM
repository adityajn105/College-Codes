.MODEL TINY
.CODE
ORG 100H
BEGIN:
        JMP INIT	;
        OLDINTO DD 1
        CURX DB 1
        CURY DB 1
        HOUR DB 1
        MIN DB 1
        SEC DB 1
START:
        MOV AH,03H	;get cursor position
        MOV BH,0	;at page 0
        INT 10H		
        MOV CS:CURY,DH	;y coordinate in DH
        MOV CS:CURX,DL	;x corordinate in DL
                                                                                           
        MOV AH,02H	;set cursor position
        MOV BH,0H	;at page 0
        MOV DH,21	;y coordinate
        MOV DL,60	;x coordinate
        INT 10H
        
        MOV AH,02H	;get real time
        INT 1AH		
        MOV CS:HOUR,CH	;hours in ch(bcd)
        MOV CS:MIN,CL	;min in cl(bcd)
        MOV CS:SEC,DH	;sec in dh(bcd)
       
        MOV AL,CS:HOUR  ;HOUR
        ROL AL,4	
        AND AL,0FH	;mask upper digit
        ADD AL,30H	;convert to ASCII

        MOV AH,0AH      ;program to display characters
        MOV BH,0	;at page 0
        MOV CX,1	;count is 1
        INT 10H

        MOV AL,CS:HOUR
        AND AL,0FH		
        ADD AL,30H
        MOV AH,02H	;set cursor position
        MOV BH,0H
        MOV DH,21
        MOV DL,61
        INT 10H


        MOV AH,0AH	
        MOV BH,0
        MOV CX,1
        INT 10H

        MOV AH,02H	;set cursor position
        MOV BH,0H
        MOV DH,21
        MOV DL,62
        INT 10H

        MOV AH,0AH	;print character on screen 
        MOV AL,':'	
        mov bh,0		;on page 0
        MOV CX,1
        INT 10H

                
        MOV AL,CS:MIN   ;MIN
        ROL AL,4
        AND AL,0FH
        ADD AL,30H

        MOV AH,02H
        MOV BH,0H
        MOV DH,21
        MOV DL,63
        INT 10H

        MOV AH,0AH      
        MOV BH,0
        MOV CX,1
        INT 10H

        MOV AL,CS:MIN
        AND AL,0FH
        ADD AL,30H

        MOV AH,02H
        MOV BH,0H
        MOV DH,21
        MOV DL,64
        INT 10H

        MOV AH,0AH
        MOV BH,0
        MOV CX,1
        INT 10H
        MOV AH,02H
        MOV BH,0H
        MOV DH,21
        MOV DL,65
        INT 10H

        MOV AH,0AH
        MOV AL,':'
        MOV CX,1
        INT 10H


        MOV AL,CS:SEC   ;SEC
        ROL AL,4
        AND AL,0FH
        ADD AL,30H

        MOV AH,02H
        MOV BH,0H
        MOV DH,21
        MOV DL,66
        INT 10H

        MOV AH,0AH      
        MOV BH,0
        MOV CX,1
        INT 10H

        MOV AL,CS:SEC
        AND AL,0FH
        ADD AL,30H

        MOV AH,02H
        MOV BH,0H
        MOV DH,21
        MOV DL,67
        INT 10H

        MOV AH,0AH
        MOV BH,0
        MOV CX,1
        INT 10H

        MOV AH,02H	;set cursor position
        MOV BH,0		;on page 0
        MOV DH,CS:CURY	;original y coordinate	
        MOV DL,CS:CURX	;original x coordinate
        INT 10H
        
        

        JMP CS:OLDINTO	;jump to old routine



INIT:
CLI	;clear direction flag
MOV AH,35H	;get interrupt address
MOV AL,8	;interrupt no 9
INT 21H

MOV WORD PTR OLDINTO,BX
MOV WORD PTR OLDINTO+2,ES

MOV AH,25H	;modifty ivt
MOV AL,8H	;int type 8
MOV DX,OFFSET START	;starting address of usr tsr
INT 21H

MOV AH,31H	;make program resident in memory
MOV DX,OFFSET INIT	;size of resident program
INT 21H

STI	;set interrupt flag
END BEGIN

.model small

.data
msg1 DB 10,13,"Addition is : $"
arr DB 01H, 02H, 03H, 04H, 05H
cnt1 DB 05H
cnt2 DB 05H
car DB 00H

.code
MOV AX,@DATA
MOV DS,AX

DISP MACRO MESS
MOV AH, 09H
LEA DX, MESS
INT 21H
ENDM

MOV BL, 00H
LEA SI, arr
UP2: ADD BL,[SI]
JNC lab
INC CAR
lab: INC SI
DEC CNT2
JNZ UP2

DISP msg1

;2 Digit Display Routine 
MOV CH, 04H
MOV CL, 04H
UP3: ROL BX, CL
MOV DX, BX
AND DX, 0FH
CMP DX, 09H
JBE dwn
ADD DX, 07H
dwn: ADD DX, 30H
MOV AH, 02H
INT 21H
DEC CH
JNZ UP3

MOV AH,4CH
INT 21H
END


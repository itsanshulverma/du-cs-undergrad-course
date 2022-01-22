;4) 32 bit binary division (User Input)

.MODEL SMALL
.STACK
.486
.DATA

	ad 	dd ?
	ad1 dd ?
	msg db 13, 10, "Enter the divisor(32 Bit): $"
	msg1 db 13, 10, "Enter the dividend(64 Bit): $"
	msg2 db 13, 10, "Quotient: $"
	msg3 db 13, 10, "Remainder: $"

.CODE
.STARTUP

	; Input of divisor(32 bit) 

	MOV DX, offset msg
	MOV AH, 09
	INT 21h

	MOV EBX, 0
	MOV CX, 4
	abc: SHL EBX, 8

	; 1st PART OF DIVISOR

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab1

	SUB AL, 37h

	ab1:
	AND AL, 00fh
	SHL AL, 4
	MOV BL, AL

	; 2nd PART OF DIVISOR

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab2

	SUB AL, 37h

	ab2:
	AND AL, 00fh
	ADD BL, AL

	LOOP abc

	MOV ad, EBX

	; Input of  dividend (64 bit)

	MOV DX, offset msg1
	MOV AH, 09
	INT 21h

	MOV EBX, 0
	MOV CX, 4
	abc1: SHL EBX, 8

	; 1st PART OF DIVIDEND

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab3

	SUB AL, 37h

	ab3:
	AND AL, 00fh
	SHL AL, 4
	MOV BL, AL

	; 2nd PART OF DIVIDEND

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab4

	SUB AL, 37h

	ab4:
	AND AL, 00fh
	ADD BL, AL

	LOOP abc1
	MOV EDX, EBX

	MOV EBX, 0
	MOV CX, 4
	abc11: SHL EBX, 8

	;1st DIGIT OF SECOND NO.

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab31

	SUB AL, 37h

	ab31:
	AND AL, 00fh
	SHL AL, 4
	MOV BL, AL

	;2nd  DIGIT OF SECOND NO.

	MOV AH, 01
	INT 21h

	CMP AL, 39h
	JBE ab41

	SUB AL, 37h

	ab41:
	AND AL, 00fh
	ADD BL, AL

	LOOP abc11

	MOV EAX, EBX
	MOV EBX, ad
	div EBX

	MOV ad,EAX
	MOV ad1,EDX


	; Printing 

	MOV DX, offset msg2
	MOV AH, 09
	INT 21h

	MOV EBX, ad1
	MOV CX, 4

	abc3 :rol EBX, 8

	MOV AL, BL
	AND AL, 0f0h
	SHR AL, 4
	ADD AL, 30h

	CMP AL, 39h
	JBE ab5

	ADD AL, 07h

	ab5:
	MOV DL,  AL
	MOV AH, 02
	INT 21h


	MOV AL, BL
	AND AL, 00fh
	ADD AL, 30h

	CMP AL, 39h
	JBE ab6

	ADD AL, 07h

	ab6:

	MOV DL, AL
	MOV AH, 02
	INT 21h

	LOOP abc3


	; Printing
	
	MOV DX, offset msg3
	MOV AH, 09
	INT 21h

	MOV EBX, ad
	MOV CX, 4

	abc4 :rol EBX, 8

	MOV AL, BL
	AND AL, 0f0h
	SHR AL, 4
	ADD AL, 30h

	CMP AL, 39h
	JBE ab7

	ADD AL, 07h

	ab7:
	MOV DL, AL
	MOV AH, 02
	INT 21h

	MOV AL, BL
	AND AL, 00fh
	ADD AL, 30h

	CMP AL, 39h
	JBE ab8

	ADD AL, 07h

	ab8:
	MOV DL, AL
	MOV AH, 02
	INT 21h

	LOOP abc4

.EXIT
END

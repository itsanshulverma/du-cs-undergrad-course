;3) 32 bit binary multiplication (User Input)

.MODEL SMALL
.STACK
.486
.DATA

first dd ?
second dd ?
INMSG1 db 13, 10, "Enter the first number(32 Bit): $"
INMSG2 db 13, 10, "Enter the second number(32 Bit): $"
OUTMSG db 13, 10, "Product: $"

.CODE
.STARTUP

; INPUT - FIRST 32-bit NUMBER

	; Print 'INMSG1'
	MOV DX, OFFSET INMSG1 ; DX <- Address of msg
	MOV AH, 09 ; 09 - Print string to stdout w/ echo
	INT 21H ; Interrupt - Application specific

	; Initialisations
	MOV EBX, 0 ; Clear EBX
	MOV CX, 4 ; Counter for loop
	
	L1: SHL EBX, 8 ; Shift 8 bits to left

	; 1st DIGIT of FIRST Part

	MOV AH, 01 ; 01 - single byte input 
	INT 21H ; Interrupt - Application specific

	; Compare input byte with 39H(ASCII for decimal 9)
	CMP AL, 39H 
	JBE isDigit1 ; if input is below(less) or equal (0-9)
	SUB AL, 37H ; if input is a letter (out of A,B,C,D,E,F)

	isDigit1: AND AL, 0FH ; Masking
	; (Now, AL will contain Hex value for ASCII input.)

	SHL AL, 4 ; Shift 4 bits to left i.e. append 0H
	MOV BL, AL ; Store it in BL

	; 2nd  DIGIT of FIRST Part (Same as FIRST Part)

	MOV AH, 01
	INT 21H

	CMP AL, 39H
	JBE isDigit2
	SUB AL, 37H

	isDigit2: AND AL, 0FH
	
	ADD BL, AL ; Add new input(in AL) to BL
	LOOP L1

	MOV first, EBX

; INPUT - SECOND 32-bit NUMBER [Same as FIRST NUMBER]

	MOV DX, OFFSET INMSG2
	MOV AH, 09
	INT 21H

	MOV EBX, 0
	MOV CX, 4

	L2: SHL EBX, 8

	; 1st DIGIT of FIRST Part
	MOV AH, 01
	INT 21H

	CMP AL, 39H
	JBE isDigit3
	SUB AL, 37H

	isDigit3: AND AL, 0FH

	SHL AL, 4
	MOV BL, AL

	; 2nd DIGIT of SECOND Part
	MOV AH, 01
	INT 21H

	CMP AL, 39H
	JBE isDigit4
	SUB AL, 37h

	isDigit4: AND AL, 00FH
	
	ADD BL, AL
	LOOP  L2

; MULTIPLICATION

	MOV EAX, first ; Copy first num to EAX for MUL
	MUL EBX ; Multiplication with contents of EBX is second num

	; Now, the product (64-bit) is stored as,
	MOV first, EAX ; least significant 32 bits
	MOV second, EDX ; most significant 32 bits

; OUTPUT - PRINTING RESULTS 

	; Print 'OUTMSG'
	MOV DX, OFFSET OUTMSG
	MOV AH, 09
	INT 21H

	; Print most significant 32 bits in ASCII

	MOV EBX, second
	MOV CX, 4

	L3: ROL EBX, 8

	MOV AL, BL
	AND AL, 0F0H
	SHR AL, 4
	ADD AL, 30H

	CMP AL, 39H
	JBE ab5
	ADD AL, 07H

	ab5:
	MOV DL, AL
	MOV AH, 02
	INT 21H


	MOV AL, BL
	AND AL, 00FH
	ADD AL, 30H

	CMP AL, 39H
	JBE ab6
	ADD AL, 07H

	ab6:
	MOV DL, AL
	MOV AH, 02
	INT 21H

	LOOP L3

	; Print least significant 32 bits in ASCII

	MOV EBX, first
	MOV CX, 4

	L4: ROL EBX,8

	MOV AL, BL
	AND AL, 0F0H
	SHR AL, 4
	ADD AL, 30H

	CMP AL, 39H
	JBE ab7
	ADD AL, 07H

	ab7:
	MOV DL, AL
	MOV AH, 02
	INT 21H

	MOV AL, BL
	AND AL, 00FH
	ADD AL, 30H

	CMP AL, 39H
	JBE ab8
	ADD AL, 07H

	ab8:
	MOV DL, AL
	MOV AH, 02
	INT 21H

	LOOP L4

.EXIT
End

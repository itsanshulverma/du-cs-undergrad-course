;1) 32 bit addition using four 16 bit registers
;	Written by Anshul Verma for University of Delhi

.MODEL TINY
.CODE
.STARTUP
	; First No - FA019A16H
    MOV     AX,  0FA01H
    MOV     BX,  9A16H
    ; Second No - 2D35A89FH
    MOV     CX,  2D35H
    MOV     DX,  0A89FH
    ADD     BX,  DX
    ADC     AX,  CX
.EXIT
END

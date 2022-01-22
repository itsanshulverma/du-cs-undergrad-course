;2) 32 bit subtraction using four 16 bit registers

.MODEL TINY
.CODE
.STARTUP
	; First No - FA012534H
    MOV     AX,  0FA01H
    MOV     BX,  2534H
    ; Second No - 2D35A89FH
    MOV     CX,  2D35H
    MOV     DX,  0A89FH
    SUB     BX,  DX
    SBB     AX,  CX
.EXIT
END
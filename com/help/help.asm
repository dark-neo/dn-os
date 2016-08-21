
; help.asm
; dark_neo
; 2014-08-24

; help command

global _start

_start:
	jmp	help_main

	%include "../../incl/sio.inc"		; resources for I/O
	%include "../../incl/com/help.inc"	; text resource for HELP command
help_main:
	call	helpcomshow
	ret

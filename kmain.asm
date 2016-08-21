
; kmain.asm
; dark_neo
; 2014-08-23

[BITS 16]
[ORG 0x07C00]				; BIOS boot segment.

section .text
	global	_start
	
_start:
	jmp	main

	%include "incl/sio.inc"
	%include "incl/string.inc"
	%include "incl/systext.inc"
	%include "incl/com/help.inc"
	%include "incl/com/kversion.inc"

main:
	xor	ax,	ax		; set to zero
	mov	ds,	ax              ; all
	mov	es,	ax              ; segments

	mov	si,	welc
	call 	printscr

	main.loop:
	mov	si,	prompt
	call	printscr
	
	mov	di,	buffer
	call	getinput

	mov	si,	buffer
	mov	di,	helpcom
	call	strcmp
	jc	helpcomshow		; if carry flag was set on *strcmp*
					; call, then show help.
	
	mov	si,	buffer
	mov	di,	kversioncom
	call	strcmp
	jc	kversionshow

	mov	si,	wrongcommand
	call	printscr
	jmp	main.loop


section	.data
	buffer times 64 db 0x00
	hellomsg 	db 	0x0D,0x0A,'hello',0x0D,0x0A,0x00

	times	0x1FE-($-$$) db 0x00
	db	0xAA
	db	0x55			; end of program


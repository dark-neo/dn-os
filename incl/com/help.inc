
; help.inc
; dark_neo
; 2014-08-23


helpcom		db	'help',0x00
helpcomtitle	db	0x0D,0x0A,'COMMAND REFERENCE',0x0D, 0x0A, 0x00
helpcomtitle2	db	0x0D,'-----------------',0x0D, 0x0A,0x00
helpcommsg0	db	0x0D,'help         Show this text and finish.'
		db	0x0D, 0x0A,0x00
helpcommsg1	db	0x0D,'version      Show kernel version.'
		db	0x0D,0x0A,0x00
helpcommsg2	db	0x0D,'shutdown     Shutdown the system.'
		db	0x0D,0x0A,0x00
helpcommsg3	db	0x0D,'reboot       Reboot the system.'
		db	0x0D,0x0A,0x0A,0x00

; helpcomshow
;	n_param:	0
;	param:		nothing
;	return:		nothing
helpcomshow:
	mov	si,		helpcomtitle
	call	printscr

	mov	si,		helpcomtitle2
	call	printscr

	mov	si,		helpcommsg0
	call	printscr

	mov	si,		helpcommsg1
	call	printscr

	mov	si,		helpcommsg2
	call	printscr	

	mov	si,		helpcommsg3
	call	printscr

	; At the end of all prints, return to main.loop
	; (in ../../skernel.asm)
	;jmp	main.loop
	ret


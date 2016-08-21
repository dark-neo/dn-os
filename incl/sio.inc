
; sio.inc
; dark_neo
; 2014-08-22

; Input/Output procedures

; printscr
;	n_param:	1
;	param:		string
;	return:		nothing
printscr:
	lodsb				;grab a byte from SI
	
	or	al,	al
	jz	.done			; if zero, get out

	mov	ah,	0x0E
	int	0x10			; print out the character

	jmp	printscr		; repeat process

	.done:
	ret				; get out

; getinput
;	n_param:	1
;	param:		string
;	return:		nothing
getinput:
	xor	cl,	cl		; reset counter
	
	.loop:
	mov	ah, 	0x00
	int	0x16			; wait for character

	cmp	al,	0x08		; backspace pressed?
	je	.backspace		; yes, handle it

	cmp	al,	0x0D		; enter pressed?
	je	.done			; yes, get out

	cmp	cl,	0x3F		; 63 chars inputted?
	je	.loop			; yes, only let in backspace and enter

	mov	ah, 	0x0E
	int	0x10			; print character pressed

	stosb				; put character in buffer
	inc	cl			; increase counter and go to next 
					; character
	jmp	.loop

	.backspace:
	cmp	cl,	0x00		; beginning of string?
	je	.loop			; yes, ignore the key

	dec	di			; go to previous char position
	mov	byte[di], 0x00		; delete character
	dec	cl			; decrement character counter

	mov	ah,	0x0E		; enable bios output
	mov	al,	0x08		; backspace code
	int	0x10			; backspace on the screen

	mov	al,	' '
	int	0x10			; black character out

	mov	al,	0x08		; backspace code
	int	0x10			; backspace again

	jmp	.loop

	.done:
	mov	al,	0x00		; null string terminator
	stosb				; store on buffer

	; newline
	mov	ah,	0x0E		; enable bios output
	mov	al,	0x0D		; \r
	int	0x10			; bios call
	mov	al,	0x0A		; \n
	int	0x10

	ret


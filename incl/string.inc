
; string.inc
; dark_neo
; 2014-08-23

; Library to operate with strings

; strcmp
;	n_param:	2
;	param:		str1, str2
;	return:		carry flag to set
strcmp:
	.loop:
	mov	al,	[si]		; grab a byte from SI
	mov	bl,	[di]		; grab a byte from DI
	cmp	al,	bl		; are bytes equals?
	jne	.notequal		; nope

	cmp	al,	0x00		; are both null?
	je	.done			; yes, return

	inc	di			; go to next byte
	inc	si			; go to next byte
	jmp	.loop			; repeat for next characters

	.notequal:
	clc				; clear the carry flag
	ret

	.done:
	stc				; set the carry flag
	ret


; kversion.inc
; dark_neo
; 2014-08-23

kversioncom	db	'version',0x00
kversionmsg	db	0x0D,'dn_OS 0.0.2pre-alpha'
		db	0x0D,0x0A,0x00

; kversionshow
;	n_param:	0
;	param:		nothing
;	return:		nothing
kversionshow:
	mov	si,	kversionmsg
	call	printscr
	jmp	main.loop


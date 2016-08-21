
; sys.inc
; dark_neo
; 2014-08-22

; System procedures

shutdcom   	   db	'shutdown',0x00
rebootcom	   db	'reboot',0x00
rebooterror_msg	   db	0x0D,0x0A,'ERROR REBOOTING YOUR SYSTEM.',0x0D,0x0A,0x00


	; SYSTEM SHUTDOWN

sysshutd:

	; SYSTEM REBOOT
sysreboot:

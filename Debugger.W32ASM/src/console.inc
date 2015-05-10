
CONSOLE_BUFFER_SIZE	equ	2000h

	.data
ConsoleCursorPos	db	1
ConsoleStart		db	'>', 0
ConsoleCaret		db	'_', 0

	.data?

ConsoleBuffer		db	CONSOLE_BUFFER_SIZE dup (?)
ConsoleCommand	db	201h dup (?)

	.code

DrawConsoleCommand		proc	STDCALL
	mov	edx, clientRect.rc_bottom
	shr	edx, 5
	dec	edx

	push	edx

	push	offset ConsoleStart
	push	edx
	push	0
	push	bmp_font_dis
	push	bufferDC
	call	drawString

	pop	edx
	push	edx

	push	offset ConsoleCommand
	push	edx
	push	1
	push	bmp_font
	push	bufferDC
	call	drawString

	pop	edx

	push	offset ConsoleCaret
	push	edx
	movzx	eax, ConsoleCursorPos
	push	eax
	push	bmp_font_sel
	push	bufferDC
	call	drawString
	
	ret
DrawConsoleCommand		endp

HandleConsoleKey		proc	STDCALL, keyCode:DWORD
	mov	eax, keyCode
	mov	edi, offset ConsoleCommand
	movzx	ecx, ConsoleCursorPos
	dec	ecx
	cmp	ecx, 200h
	je	handleconsolekey_nomore
	.IF eax == 8
		.IF ecx > 0
			dec	ecx
			add	edi, ecx
			xor	eax, eax
			stosb
			dec	ConsoleCursorPos
		.ENDIF
	.ELSEIF eax == 0Dh
		call	ProcessCommand
	.ELSE
		add	edi, ecx
		stosb
		inc	ConsoleCursorPos
	.ENDIF
handleconsolekey_nomore:
	ret
HandleConsoleKey		endp

ProcessCommand		proc	STDCALL
	; TODO: Process command

	xor	eax, eax
	mov	ecx, 80h
	mov	edi, offset ConsoleCommand
	rep	stosd
	mov	ConsoleCursorPos, 1
	ret
ProcessCommand		endp
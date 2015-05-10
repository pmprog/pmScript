	.data

res_General:
res_pmprog		db	'pmprog', 0
res_font		db	'stdfont', 0
res_font_sel		db	'hilfont', 0
res_font_dis		db	'disfont', 0
		db	00h

	.data?

bmp_General:
bmp_pmprog		dd	?
bmp_font		dd	?
bmp_font_sel		dd	?
bmp_font_dis		dd	?

height_General:
height_pmprog		dd	?
height_font		dd	?
height_font_sel	dd	?
height_font_dis	dd	?


bitmapDimensions	BITMAP	?

	.code

LoadResources		proc	STDCALL
	push	offset height_General
	push	offset bmp_General
	push	offset res_General
	call	ResourceLockAndLoad
	ret
LoadResources		endp

ResourceLockAndLoad	proc	STDCALL, res_Start:DWORD, bmp_Start:DWORD, height_Start:DWORD
	mov	esi, res_Start
	mov	edi, bmp_Start
	mov	edx, height_Start

lockandload_loop:
	cmp	byte ptr [esi], 00h
	je	lockandload_finish

	push	edx

	push	0
	push	0
	push	0
	push	IMAGE_BITMAP
	push	esi
	push	engineInst
	call	LoadImage
	stosd

	pop	edx

	.IF edx != 0
		push	edx

		push	offset bitmapDimensions
		push	BITMAP_
		push	eax
		call	GetObject

		pop	edx
		mov	eax, bitmapDimensions.bm_bmHeight
		mov	[edx], eax
		add	edx, 4h
	.ENDIF

lockandload_nextchk:
	inc	esi
	cmp	byte ptr [esi], 00h
	jne	lockandload_nextchk
	inc	esi

	jmp	lockandload_loop

lockandload_finish:
	ret
ResourceLockAndLoad	endp
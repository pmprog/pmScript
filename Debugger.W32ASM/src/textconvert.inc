
	.data

textConvHex		db	'0123456789ABCDEF', 0
textFontMap		db	'ABCDEFGHJIKLMNOPQRSTUVWXYZ/\_^abcdefghijklmnopqrstuvwxyz0123456789?!"@.,()*&%+-=|~¬<>:', 0

textTransCol		dd	0

	.data?

gfxRSrc		dd	?
gfxRDstX		dd	?
gfxRDstY		dd	?

	.code

convertDwordToString		proc	STDCALL, valNumber:DWORD, ptrBuffer:DWORD
	push	ebx
	push	edi
	push	ecx
	push	esi

	mov	edi, ptrBuffer
	mov	ebx, valNumber
	mov	ecx, 8
convertdword_loop:
	mov	esi, offset textConvHex
	mov	eax, ebx
	and	al, 0000000Fh			; Mask bottom nybble
	add	esi, eax
	movsb
	shr	ebx, 4				; Next nybble
	loop	convertdword_loop
	xor	eax, eax
	stosb					; Null terminate
	pop	esi
	pop	ecx
	pop	edi
	pop	ebx
	ret
convertDwordToString		endp

convertDwordToASCII		proc	STDCALL, myNumber:DWORD, ptrOutput:DWORD, digitCount:DWORD
	mov	ecx, digitCount
	mov	edi, ptrOutput
	mov	al, '0'
	rep	stosb
	std
	dec	edi
	mov	edx, myNumber
convertascii:
	mov	eax, edx
	xor	edx, edx
	mov	ecx, 10
	div	ecx
	xchg	eax, edx
	add	al, '0'
	stosb
	or	edx, edx
	jnz	convertascii
	cld
	ret
convertDwordToASCII		endp

convertASCIIToDword		proc	STDCALL, ptrString:DWORD
	mov	esi, ptrString
	xor	ebx, ebx
	xor	eax, eax
convertnumber:
	lodsb
	or	al, al
	jz	completednumber
	cmp	al, '0'
	jl	invalidnumber
	cmp	al, '9'
	jg	invalidnumber
	sub	al, '0'			; al = numeric value
	xchg	ebx, eax			; EBX = Prev Val, EAX = Additional 10
	mov	ecx, 10
	mul	ecx
	add	ebx, eax			; EBX = (Pre Val * 10) + Additional 10
	jmp	convertnumber

invalidnumber:
	xor	ebx, ebx
	dec	ebx
completednumber:
	xchg	eax, ebx
	ret
convertASCIIToDword		endp

drawString			proc	STDCALL, outputDC:DWORD, fontBmp:DWORD, textX:DWORD, textY:DWORD, ptrText:DWORD
	pusha

	push	fontBmp
	push	copierDC
	call	SelectObject

	push	0
	push	0
	push	copierDC
	call	GetPixel				; Get actual transparent colour
	mov	textTransCol, eax

	mov	eax, textX
	shl	eax, 4						; * 16
	mov	gfxRDstX, eax
	mov	eax, textY
	shl	eax, 5						; * 32
	mov	gfxRDstY, eax
	mov	gfxRSrc, 0

	push	ptrText
	call	lstrlen
	or	eax, eax
	jz	drawstring_finish
	mov	esi, ptrText		; ESI -> Text
	mov	edi, esi
	add	edi, eax		; EDX -> End of Text

createtextsprite_BltLoop:
	lodsb				; Get next character

	.IF al == 0Dh
		mov	eax, textX
		shl	eax, 4						; * 16
		mov	gfxRDstX, eax
		jmp	createtextsprite_nextchar
	.ENDIF
	.IF al == 0Ah
		add	gfxRDstY, 32
		jmp	createtextsprite_nextchar
	.ENDIF

	push	esi
	push	edi

	; Find char in string
	mov	esi, offset textFontMap
	dec	esi
createtextsprite_FindLoop:
	inc	esi
	cmp	byte ptr [esi], 0
	je	createtextsprite_nochar
	cmp	byte ptr [esi], al
	jne	createtextsprite_FindLoop

	; Blit char to sprite
	sub	esi, offset textFontMap		; ESI == Character Index
	shl	esi, 4h				; ESI == Start Character X
	mov	gfxRSrc.rc_left, esi

	push	textTransCol
	push	30
	push	16
	push	0
	push	gfxRSrc
	push	copierDC
	push	30
	push	16
	push	gfxRDstY
	push	gfxRDstX
	push	outputDC
	call	TransparentBlt

createtextsprite_nochar:
	add	gfxRDstX, 16	; Move blit window

	pop	edi
	pop	esi
createtextsprite_nextchar:
	cmp	esi, edi
	jne	createtextsprite_BltLoop
drawstring_finish:
	popa
	ret
drawString			endp
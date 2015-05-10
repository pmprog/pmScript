	.code

AllocFunc	proc	STDCALL, nMemSize:DWORD
	mov	eax,nMemSize
	push	eax
	push	GMEM_FIXED
	call	GlobalAlloc
	ret
AllocFunc	endp

DeallocFunc	proc	STDCALL, pBuffer:DWORD
	mov	eax,pBuffer
	push	eax
	call	GlobalFree
	xor	eax,eax
	dec	eax
	ret
DeallocFunc	endp

MemCopy	proc	STDCALL, ptrSrc:DWORD, ptrDest:DWORD, dataLength:DWORD
	push	esi
	push	edi
	push	ecx

	mov	ecx, dataLength
	push	ecx
	mov	esi, ptrSrc
	mov	edi, ptrDest
	shr	ecx, 2
	rep	movsd
	pop	ecx
	and	ecx, 00000003h
	rep	movsb

	pop	ecx
	pop	edi
	pop	esi
	ret
MemCopy	endp

CloneMemory	proc	STDCALL, ptrSrc:DWORD, lenSrc:DWORD
	push	lenSrc
	call	AllocFunc
	push	lenSrc
	push	eax
	push	ptrSrc
	call	MemCopy
	ret
CloneMemory	endp
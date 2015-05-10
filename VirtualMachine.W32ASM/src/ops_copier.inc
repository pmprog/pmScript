MoveDirection		macro	regkey
	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_DIRECTION
	.IF bl == 0
		inc	[esi].regkey
	.ELSE
		dec	[esi].regkey
	.ENDIF
			endm

MoveDirection4	macro	regkey
	push	ebx
	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_DIRECTION
	.IF bl == 0
		add	[esi].regkey, 4
	.ELSE
		sub	[esi].regkey, 4
	.ENDIF
	pop	ebx
			endm

	.code

;-----------------------------------------------------------------------------------------[ lods
vm_lods		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_cps
	push	esi
	call	internals_ReadValue
	MoveDirection4	reg_cps
	mov	[esi].reg_acc, eax

	inc	[esi].reg_ip
	ret
vm_lods		endp

;-----------------------------------------------------------------------------------------[ stos
vm_stos		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_acc
	push	[esi].reg_cpd
	push	esi
	call	internals_WriteValue
	MoveDirection4	reg_cpd

	inc	[esi].reg_ip
	ret
vm_stos		endp

;-----------------------------------------------------------------------------------------[ movs
vm_movs		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_cps
	push	esi
	call	internals_ReadValue
	MoveDirection4	reg_cps
	push	eax
	push	[esi].reg_cpd
	push	esi
	call	internals_WriteValue
	MoveDirection4	reg_cpd

	inc	[esi].reg_ip
	ret
vm_movs		endp

;-----------------------------------------------------------------------------------------[ lodsb
vm_lodsb		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_cps
	push	esi
	call	internals_ReadByte
	MoveDirection	reg_cps
	mov	[esi].reg_acc, eax

	inc	[esi].reg_ip
	ret
vm_lodsb		endp

;-----------------------------------------------------------------------------------------[ stosb
vm_stosb		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_acc
	push	[esi].reg_cpd
	push	esi
	call	internals_WriteByte
	MoveDirection	reg_cpd

	inc	[esi].reg_ip
	ret
vm_stosb		endp

;-----------------------------------------------------------------------------------------[ movsb
vm_movsb		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip

	push	[esi].reg_cps
	push	esi
	call	internals_ReadByte
	MoveDirection	reg_cps
	push	eax
	push	[esi].reg_cpd
	push	esi
	call	internals_WriteByte
	MoveDirection	reg_cpd

	inc	[esi].reg_ip
	ret
vm_movsb		endp

;-----------------------------------------------------------------------------------------[ std
vm_std			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	bl, [esi].reg_flags
	or	bl, VMFLAG_DIRECTION
	mov	[esi].reg_flags, bl

	inc	[esi].reg_ip
	ret
vm_std			endp

;-----------------------------------------------------------------------------------------[ cld
vm_cld			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	bl, [esi].reg_flags
	and	bl, NOT VMFLAG_DIRECTION
	mov	[esi].reg_flags, bl


	inc	[esi].reg_ip
	ret
vm_cld			endp

;-----------------------------------------------------------------------------------------[ xchg acc, cnt
vm_xchgacccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cnt
	mov	ebx, [esi].reg_acc
	mov	[esi].reg_acc, eax
	mov	[esi].reg_cnt, ebx
	inc	[esi].reg_ip
	ret
vm_xchgacccnt		endp

;-----------------------------------------------------------------------------------------[ xchg acc, dat
vm_xchgaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat
	mov	ebx, [esi].reg_acc
	mov	[esi].reg_acc, eax
	mov	[esi].reg_dat, ebx
	inc	[esi].reg_ip
	ret
vm_xchgaccdat		endp



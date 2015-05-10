

	.code

;-----------------------------------------------------------------------------------------[ rol immediate
vm_rolimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	rol	eax, cl

	add	[esi].reg_ip, 5
	ret
vm_rolimm		endp

;-----------------------------------------------------------------------------------------[ rol cnt
vm_rolcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	rol	eax, cl

	inc	[esi].reg_ip
	ret
vm_rolcnt		endp

;-----------------------------------------------------------------------------------------[ ror immediate
vm_rorimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	ror	eax, cl

	add	[esi].reg_ip, 5
	ret
vm_rorimm		endp

;-----------------------------------------------------------------------------------------[ ror cnt
vm_rorcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	ror	eax, cl

	inc	[esi].reg_ip
	ret
vm_rorcnt		endp

;-----------------------------------------------------------------------------------------[ shl immediate
vm_shlimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	shl	eax, cl

	add	[esi].reg_ip, 5
	ret
vm_shlimm		endp

;-----------------------------------------------------------------------------------------[ shl cnt
vm_shlcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	shl	eax, cl

	inc	[esi].reg_ip
	ret
vm_shlcnt		endp

;-----------------------------------------------------------------------------------------[ shr immediate
vm_shrimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	shr	eax, cl

	add	[esi].reg_ip, 5
	ret
vm_shrimm		endp

;-----------------------------------------------------------------------------------------[ shr cnt
vm_shrcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	shr	eax, cl

	inc	[esi].reg_ip
	ret
vm_shrcnt		endp




	.code

;-----------------------------------------------------------------------------------------[ mul immediate
vm_mulimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	mul	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_mulimm		endp

;-----------------------------------------------------------------------------------------[ mul variable
vm_mulvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	mul	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_mulvar		endp

;-----------------------------------------------------------------------------------------[ mul cnt
vm_mulcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	mul	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	inc	[esi].reg_ip
	ret
vm_mulcnt		endp

;-----------------------------------------------------------------------------------------[ div immediate
vm_divimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_divimm		endp

;-----------------------------------------------------------------------------------------[ div variable
vm_divvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_divvar		endp

;-----------------------------------------------------------------------------------------[ div cnt
vm_divcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags
	inc	[esi].reg_ip
	ret
vm_divcnt		endp

;-----------------------------------------------------------------------------------------[ mod immediate
vm_modimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, edx

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_modimm		endp

;-----------------------------------------------------------------------------------------[ mod variable
vm_modvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable
	mov	ecx, eax
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, edx

	push	[esi].reg_acc
	call	internals_SetFlags
	add	[esi].reg_ip, 5
	ret
vm_modvar		endp

;-----------------------------------------------------------------------------------------[ mod cnt
vm_modcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	mov	ecx, [esi].reg_cnt
	mov	eax, [esi].reg_acc
	xor	edx, edx
	div	ecx

	mov	[esi].reg_acc, edx

	push	[esi].reg_acc
	call	internals_SetFlags
	inc	[esi].reg_ip
	ret
vm_modcnt		endp



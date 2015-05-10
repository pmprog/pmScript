

	.code

;-----------------------------------------------------------------------------------------[ add acc, immediate
vm_addaccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	add	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_addaccimm		endp

;-----------------------------------------------------------------------------------------[ add acc, dat
vm_addaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	add	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_addaccdat		endp

;-----------------------------------------------------------------------------------------[ add acc, rnd
vm_addaccrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	add	[esi].reg_acc, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_addaccrnd		endp

;-----------------------------------------------------------------------------------------[ add acc, variable
vm_addaccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	add	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_addaccvar		endp

;-----------------------------------------------------------------------------------------[ add cnt, immediate
vm_addcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	add	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_addcntimm		endp

;-----------------------------------------------------------------------------------------[ add cnt, acc
vm_addcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	add	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_addcntacc		endp

;-----------------------------------------------------------------------------------------[ add cnt, dat
vm_addcntdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	add	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_addcntdat		endp

;-----------------------------------------------------------------------------------------[ add cnt, rnd
vm_addcntrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	add	[esi].reg_cnt, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_addcntrnd		endp

;-----------------------------------------------------------------------------------------[ add cnt, variable
vm_addcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	add	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_addcntvar		endp

;-----------------------------------------------------------------------------------------[ add dat, immediate
vm_adddatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	add	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_adddatimm		endp

;-----------------------------------------------------------------------------------------[ add dat, acc
vm_adddatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	add	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_adddatacc		endp

;-----------------------------------------------------------------------------------------[ add dat, rnd
vm_adddatrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	add	[esi].reg_dat, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_adddatrnd		endp

;-----------------------------------------------------------------------------------------[ add dat, variable
vm_adddatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	add	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_adddatvar		endp


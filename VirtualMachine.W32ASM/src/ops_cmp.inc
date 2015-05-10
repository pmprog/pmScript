

	.code

;-----------------------------------------------------------------------------------------[ cmp acc, cnt
vm_cmpacccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_cnt
	push	[esi].reg_acc
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpacccnt		endp

;-----------------------------------------------------------------------------------------[ cmp acc, dat
vm_cmpaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_dat
	push	[esi].reg_acc
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpaccdat		endp

;-----------------------------------------------------------------------------------------[ cmp acc, immediate
vm_cmpaccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	[esi].reg_acc
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpaccimm		endp

;-----------------------------------------------------------------------------------------[ cmp acc, variable
vm_cmpaccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)
	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value from address
	push	eax
	push	[esi].reg_acc
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpaccvar		endp

;-----------------------------------------------------------------------------------------[ cmp cnt, acc
vm_cmpcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_acc
	push	[esi].reg_cnt
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpcntacc		endp

;-----------------------------------------------------------------------------------------[ cmp cnt, dat
vm_cmpcntdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_dat
	push	[esi].reg_cnt
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpcntdat		endp

;-----------------------------------------------------------------------------------------[ cmp cnt, immediate
vm_cmpcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	[esi].reg_cnt
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpcntimm		endp

;-----------------------------------------------------------------------------------------[ cmp cnt, variable
vm_cmpcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)
	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value from address
	push	eax
	push	[esi].reg_cnt
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpcntvar		endp

;-----------------------------------------------------------------------------------------[ cmp dat, acc
vm_cmpdatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_acc
	push	[esi].reg_dat
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpdatacc		endp

;-----------------------------------------------------------------------------------------[ cmp dat, cnt
vm_cmpdatcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	push	[esi].reg_cnt
	push	[esi].reg_dat
	push	esi
	call	internals_CompareValues

	inc	[esi].reg_ip
	ret
vm_cmpdatcnt		endp

;-----------------------------------------------------------------------------------------[ cmp dat, immediate
vm_cmpdatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	[esi].reg_dat
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpdatimm		endp

;-----------------------------------------------------------------------------------------[ cmp dat, variable
vm_cmpdatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)
	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value from address
	push	eax
	push	[esi].reg_dat
	push	esi
	call	internals_CompareValues

	add	[esi].reg_ip, 5
	ret
vm_cmpdatvar		endp





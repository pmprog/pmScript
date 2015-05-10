
	.code

vm_pushimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_PushValue

	add	[esi].reg_ip, 5
	ret
vm_pushimm		endp

vm_pushvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets address of var

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_PushValue

	add	[esi].reg_ip, 5
	ret
vm_pushvar		endp

vm_pushacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_acc

	push	eax
	push	esi
	call	internals_PushValue

	inc	[esi].reg_ip
	ret
vm_pushacc		endp

vm_pushcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cnt

	push	eax
	push	esi
	call	internals_PushValue

	inc	[esi].reg_ip
	ret
vm_pushcnt		endp

vm_pushdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat

	push	eax
	push	esi
	call	internals_PushValue

	inc	[esi].reg_ip
	ret
vm_pushdat		endp

vm_pushcps		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cps

	push	eax
	push	esi
	call	internals_PushValue

	inc	[esi].reg_ip
	ret
vm_pushcps		endp

vm_pushcpd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cpd

	push	eax
	push	esi
	call	internals_PushValue

	inc	[esi].reg_ip
	ret
vm_pushcpd		endp

vm_popvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue

	add	[esi].reg_ip, 5
	ret
vm_popvar		endp

vm_popacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_acc, eax

	inc	[esi].reg_ip
	ret
vm_popacc		endp

vm_popcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_cnt, eax

	inc	[esi].reg_ip
	ret
vm_popcnt		endp

vm_popdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_dat, eax

	inc	[esi].reg_ip
	ret
vm_popdat		endp

vm_popcps		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_cps, eax

	inc	[esi].reg_ip
	ret
vm_popcps		endp

vm_popcpd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_cpd, eax

	inc	[esi].reg_ip
	ret
vm_popcpd		endp



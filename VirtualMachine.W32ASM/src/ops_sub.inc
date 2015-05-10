

	.code

;-----------------------------------------------------------------------------------------[ sub acc, immediate
vm_subaccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	sub	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subaccimm		endp

;-----------------------------------------------------------------------------------------[ sub acc, dat
vm_subaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	sub	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subaccdat		endp

;-----------------------------------------------------------------------------------------[ sub acc, rnd
vm_subaccrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	sub	[esi].reg_acc, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subaccrnd		endp

;-----------------------------------------------------------------------------------------[ sub acc, variable
vm_subaccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	sub	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subaccvar		endp

;-----------------------------------------------------------------------------------------[ sub cnt, immediate
vm_subcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	sub	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subcntimm		endp

;-----------------------------------------------------------------------------------------[ sub cnt, acc
vm_subcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	sub	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subcntacc		endp

;-----------------------------------------------------------------------------------------[ sub cnt, dat
vm_subcntdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	sub	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subcntdat		endp

;-----------------------------------------------------------------------------------------[ sub cnt, rnd
vm_subcntrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	sub	[esi].reg_cnt, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subcntrnd		endp

;-----------------------------------------------------------------------------------------[ sub cnt, variable
vm_subcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	sub	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subcntvar		endp

;-----------------------------------------------------------------------------------------[ sub dat, immediate
vm_subdatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	sub	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subdatimm		endp

;-----------------------------------------------------------------------------------------[ sub dat, acc
vm_subdatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	sub	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subdatacc		endp

;-----------------------------------------------------------------------------------------[ sub dat, rnd
vm_subdatrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_rnd
	sub	[esi].reg_dat, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_subdatrnd		endp

;-----------------------------------------------------------------------------------------[ sub dat, variable
vm_subdatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_ReadValue			; Get variable

	sub	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_subdatvar		endp


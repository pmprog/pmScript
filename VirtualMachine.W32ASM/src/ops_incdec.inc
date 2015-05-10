

	.code

;-----------------------------------------------------------------------------------------[ inc acc
vm_incacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	inc	[esi].reg_acc
	inc	[esi].reg_ip
	push	[esi].reg_acc
	call	internals_SetFlags
	ret
vm_incacc		endp

;-----------------------------------------------------------------------------------------[ inc cnt
vm_inccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	inc	[esi].reg_cnt
	inc	[esi].reg_ip
	push	[esi].reg_cnt
	call	internals_SetFlags
	ret
vm_inccnt		endp

;-----------------------------------------------------------------------------------------[ inc dat
vm_incdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	inc	[esi].reg_dat
	inc	[esi].reg_ip
	push	[esi].reg_dat
	call	internals_SetFlags
	ret
vm_incdat		endp

;-----------------------------------------------------------------------------------------[ dec acc
vm_decacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	dec	[esi].reg_acc
	inc	[esi].reg_ip
	push	[esi].reg_acc
	call	internals_SetFlags
	ret
vm_decacc		endp

;-----------------------------------------------------------------------------------------[ dec cnt
vm_deccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	dec	[esi].reg_cnt
	inc	[esi].reg_ip
	push	[esi].reg_cnt
	call	internals_SetFlags
	ret
vm_deccnt		endp

;-----------------------------------------------------------------------------------------[ dec dat
vm_decdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	dec	[esi].reg_dat
	inc	[esi].reg_ip
	push	[esi].reg_dat
	call	internals_SetFlags
	ret
vm_decdat		endp


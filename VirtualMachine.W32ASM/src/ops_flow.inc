
	.code

;-----------------------------------------------------------------------------------------[ jmp label
vm_jmp			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	[esi].reg_ip, eax

	ret
vm_jmp			endp

;-----------------------------------------------------------------------------------------[ je label
vm_je			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_ZERO
	jz	vm_je_nojump

	mov	[esi].reg_ip, eax

vm_je_nojump:
	ret
vm_je			endp

;-----------------------------------------------------------------------------------------[ jne label
vm_jne			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_ZERO
	jnz	vm_jne_nojump

	mov	[esi].reg_ip, eax

vm_jne_nojump:
	ret
vm_jne			endp

;-----------------------------------------------------------------------------------------[ jb label
vm_jb			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_BELOW
	jz	vm_jb_nojump

	mov	[esi].reg_ip, eax

vm_jb_nojump:
	ret
vm_jb			endp

;-----------------------------------------------------------------------------------------[ jbe label
vm_jbe			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	bl, [esi].reg_flags
	and	bl, VMFLAG_ZERO + VMFLAG_BELOW
	jz	vm_jbe_nojump

	mov	[esi].reg_ip, eax

vm_jbe_nojump:
	ret
vm_jbe		endp

;-----------------------------------------------------------------------------------------[ loop label
vm_loop		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5			; Premake the IP move incase check fails

	.IF [esi].reg_cnt > 0
		dec	[esi].reg_cnt

		push	edi
		push	esi
		call	internals_ReadValue			; Gets 32 bit value after opcode

		mov	[esi].reg_ip, eax
	.ENDIF

	ret
vm_loop		endp


;-----------------------------------------------------------------------------------------[ call label
vm_call		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	[esi].reg_ip, eax

	add	edi, 4
	push	edi
	push	esi
	call	internals_PushValue			; Push return location

	ret
vm_call		endp

;-----------------------------------------------------------------------------------------[ api immediate
vm_api			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi
	add	[esi].reg_ip, 5

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	[esi].ptr_api

	ret
vm_api			endp

;-----------------------------------------------------------------------------------------[ ret
vm_ret			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	push	esi
	call	internals_PopValue
	mov	[esi].reg_ip, eax

	ret
vm_ret			endp

;-----------------------------------------------------------------------------------------[ end
vm_end			proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	[esi].state, VMSTATE_ENDED
	ret
vm_end			endp


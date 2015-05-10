

	.code

;-----------------------------------------------------------------------------------------[ and acc, immediate
vm_andaccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	and	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_andaccimm		endp

;-----------------------------------------------------------------------------------------[ and acc, dat
vm_andaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	and	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_andaccdat		endp

;-----------------------------------------------------------------------------------------[ and acc, variable
vm_andaccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	and	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_andaccvar		endp

;-----------------------------------------------------------------------------------------[ and dat, immediate
vm_anddatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	and	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_anddatimm		endp

;-----------------------------------------------------------------------------------------[ and dat, acc
vm_anddatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	and	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_anddatacc		endp

;-----------------------------------------------------------------------------------------[ and dat, variable
vm_anddatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	and	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_anddatvar		endp

;-----------------------------------------------------------------------------------------[ or acc, immediate
vm_oraccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	or	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_oraccimm		endp

;-----------------------------------------------------------------------------------------[ or acc, dat
vm_oraccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	or	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_oraccdat		endp

;-----------------------------------------------------------------------------------------[ or acc, variable
vm_oraccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	or	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_oraccvar		endp

;-----------------------------------------------------------------------------------------[ or dat, immediate
vm_ordatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	or	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_ordatimm		endp

;-----------------------------------------------------------------------------------------[ or dat, acc
vm_ordatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	or	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_ordatacc		endp

;-----------------------------------------------------------------------------------------[ or dat, variable
vm_ordatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	or	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_ordatvar		endp


;-----------------------------------------------------------------------------------------[ xor acc, immediate
vm_xoraccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	xor	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xoraccimm		endp

;-----------------------------------------------------------------------------------------[ xor acc, dat
vm_xoraccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_dat
	xor	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_xoraccdat		endp

;-----------------------------------------------------------------------------------------[ xor acc, variable
vm_xoraccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	xor	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xoraccvar		endp

;-----------------------------------------------------------------------------------------[ xor dat, immediate
vm_xordatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	xor	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xordatimm		endp

;-----------------------------------------------------------------------------------------[ xor dat, acc
vm_xordatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	xor	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_xordatacc		endp

;-----------------------------------------------------------------------------------------[ xor dat, variable
vm_xordatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	xor	[esi].reg_dat, eax

	push	[esi].reg_dat
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xordatvar		endp

;-----------------------------------------------------------------------------------------[ not acc
vm_notacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	not	[esi].reg_acc

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_notacc		endp

;-----------------------------------------------------------------------------------------[ not dat
vm_notdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	not	[esi].reg_dat

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_notdat		endp

;-----------------------------------------------------------------------------------------[ neg acc
vm_negacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	neg	[esi].reg_acc

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_negacc		endp

;-----------------------------------------------------------------------------------------[ neg dat
vm_negdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	neg	[esi].reg_dat

	push	[esi].reg_dat
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_negdat		endp

;-----------------------------------------------------------------------------------------[ and cnt, immediate
vm_andcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	and	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_andcntimm		endp

;-----------------------------------------------------------------------------------------[ and cnt, acc
vm_andcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	and	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_andcntacc		endp

;-----------------------------------------------------------------------------------------[ and cnt, variable
vm_andcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	and	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_andcntvar		endp

;-----------------------------------------------------------------------------------------[ or cnt, immediate
vm_orcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	or	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_orcntimm		endp

;-----------------------------------------------------------------------------------------[ or cnt, acc
vm_orcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	or	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_orcntacc		endp

;-----------------------------------------------------------------------------------------[ or cnt, variable
vm_orcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	or	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_orcntvar		endp

;-----------------------------------------------------------------------------------------[ xor cnt, immediate
vm_xorcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	xor	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xorcntimm		endp

;-----------------------------------------------------------------------------------------[ xor cnt, acc
vm_xorcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_acc
	xor	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_xorcntacc		endp

;-----------------------------------------------------------------------------------------[ xor cnt, variable
vm_xorcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode
	push	eax
	push	esi
	call	internals_ReadValue			; Gets variable

	xor	[esi].reg_cnt, eax

	push	[esi].reg_cnt
	call	internals_SetFlags

	add	[esi].reg_ip, 5
	ret
vm_xorcntvar		endp

;-----------------------------------------------------------------------------------------[ and acc, cnt
vm_andacccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_cnt
	and	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_andacccnt		endp

;-----------------------------------------------------------------------------------------[ or acc, cnt
vm_oracccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_cnt
	or	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_oracccnt		endp

;-----------------------------------------------------------------------------------------[ xor acc, cnt
vm_xoracccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine

	mov	eax, [esi].reg_cnt
	xor	[esi].reg_acc, eax

	push	[esi].reg_acc
	call	internals_SetFlags

	inc	[esi].reg_ip
	ret
vm_xoracccnt		endp


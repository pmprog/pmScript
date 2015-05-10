

	.code

;-----------------------------------------------------------------------------------------[ mov acc, immediate
vm_movaccimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	[esi].reg_acc, eax

	add	[esi].reg_ip, 5
	ret
vm_movaccimm		endp

;-----------------------------------------------------------------------------------------[ mov cnt, immediate
vm_movcntimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	[esi].reg_cnt, eax

	add	[esi].reg_ip, 5
	ret
vm_movcntimm		endp

;-----------------------------------------------------------------------------------------[ mov dat, immediate
vm_movdatimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	mov	[esi].reg_dat, eax

	add	[esi].reg_ip, 5
	ret
vm_movdatimm		endp

;-----------------------------------------------------------------------------------------[ mov acc, cnt
vm_movacccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cnt
	mov	[esi].reg_acc, eax
	inc	[esi].reg_ip
	ret
vm_movacccnt		endp

;-----------------------------------------------------------------------------------------[ mov acc, dat
vm_movaccdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat
	mov	[esi].reg_acc, eax
	inc	[esi].reg_ip
	ret
vm_movaccdat		endp

;-----------------------------------------------------------------------------------------[ mov acc, rnd
vm_movaccrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_rnd
	mov	[esi].reg_acc, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax
	inc	[esi].reg_ip
	ret
vm_movaccrnd		endp

;-----------------------------------------------------------------------------------------[ mov cnt, acc
vm_movcntacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_acc
	mov	[esi].reg_cnt, eax
	inc	[esi].reg_ip
	ret
vm_movcntacc		endp

;-----------------------------------------------------------------------------------------[ mov cnt, dat
vm_movcntdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat
	mov	[esi].reg_cnt, eax
	inc	[esi].reg_ip
	ret
vm_movcntdat		endp

;-----------------------------------------------------------------------------------------[ mov cnt, rnd
vm_movcntrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_rnd
	mov	[esi].reg_cnt, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax
	inc	[esi].reg_ip
	ret
vm_movcntrnd		endp

;-----------------------------------------------------------------------------------------[ mov dat, acc
vm_movdatacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_acc
	mov	[esi].reg_dat, eax
	inc	[esi].reg_ip
	ret
vm_movdatacc		endp

;-----------------------------------------------------------------------------------------[ mov dat, cnt
vm_movdatcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cnt
	mov	[esi].reg_dat, eax
	inc	[esi].reg_ip
	ret
vm_movdatcnt		endp

;-----------------------------------------------------------------------------------------[ mov dat, rnd
vm_movdatrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_rnd
	mov	[esi].reg_dat, eax
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax
	inc	[esi].reg_ip
	ret
vm_movdatrnd		endp

;-----------------------------------------------------------------------------------------[ mov acc, variable
vm_movaccvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	mov	[esi].reg_acc, eax

	add	[esi].reg_ip, 5
	ret
vm_movaccvar		endp

;-----------------------------------------------------------------------------------------[ mov cnt, variable
vm_movcntvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	mov	[esi].reg_cnt, eax

	add	[esi].reg_ip, 5
	ret
vm_movcntvar		endp

;-----------------------------------------------------------------------------------------[ mov dat, variable
vm_movdatvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	mov	[esi].reg_dat, eax

	add	[esi].reg_ip, 5
	ret
vm_movdatvar		endp

;-----------------------------------------------------------------------------------------[ mov cps, variable
vm_movcpsvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	mov	[esi].reg_cps, eax

	add	[esi].reg_ip, 5
	ret
vm_movcpsvar		endp

;-----------------------------------------------------------------------------------------[ mov cpd, variable
vm_movcpdvar		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	eax
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	mov	[esi].reg_cpd, eax

	add	[esi].reg_ip, 5
	ret
vm_movcpdvar		endp

;-----------------------------------------------------------------------------------------[ mov variable, immediate
vm_movvarimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)
	mov	edx, eax				; EDX -> variable address

	add	edi, 4					; Gets next 32 bit value
	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (value)

	push	eax
	push	edx
	push	esi
	call	internals_WriteValue			; Store immediate in variable

	add	[esi].reg_ip, 9
	ret
vm_movvarimm		endp

;-----------------------------------------------------------------------------------------[ mov variable, acc
vm_movvaracc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	[esi].reg_acc
	push	eax
	push	esi
	call	internals_WriteValue			; Store acc in variable

	add	[esi].reg_ip, 5
	ret
vm_movvaracc		endp

;-----------------------------------------------------------------------------------------[ mov variable, cnt
vm_movvarcnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	[esi].reg_cnt
	push	eax
	push	esi
	call	internals_WriteValue			; Store acc in variable

	add	[esi].reg_ip, 5
	ret
vm_movvarcnt		endp

;-----------------------------------------------------------------------------------------[ mov variable, dat
vm_movvardat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	[esi].reg_dat
	push	eax
	push	esi
	call	internals_WriteValue			; Store acc in variable

	add	[esi].reg_ip, 5
	ret
vm_movvardat		endp

;-----------------------------------------------------------------------------------------[ mov variable, rnd
vm_movvarrnd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode (address)

	push	[esi].reg_rnd
	push	eax
	push	esi
	call	internals_WriteValue			; Store acc in variable

	push	[esi].reg_rnd
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	add	[esi].reg_ip, 5
	ret
vm_movvarrnd		endp

;-----------------------------------------------------------------------------------------[ mov cps, acc
vm_movcpsacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_acc
	mov	[esi].reg_cps, eax
	inc	[esi].reg_ip
	ret
vm_movcpsacc		endp

;-----------------------------------------------------------------------------------------[ mov cpd, acc
vm_movcpdacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_acc
	mov	[esi].reg_cpd, eax
	inc	[esi].reg_ip
	ret
vm_movcpdacc		endp

;-----------------------------------------------------------------------------------------[ mov acc, cps
vm_movacccps		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cps
	mov	[esi].reg_acc, eax
	inc	[esi].reg_ip
	ret
vm_movacccps		endp

;-----------------------------------------------------------------------------------------[ mov acc, cpd
vm_movacccpd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cpd
	mov	[esi].reg_acc, eax
	inc	[esi].reg_ip
	ret
vm_movacccpd		endp

;-----------------------------------------------------------------------------------------[ mov cps, dat
vm_movcpsdat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat
	mov	[esi].reg_cps, eax
	inc	[esi].reg_ip
	ret
vm_movcpsdat		endp

;-----------------------------------------------------------------------------------------[ mov cpd, dat
vm_movcpddat		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_dat
	mov	[esi].reg_cpd, eax
	inc	[esi].reg_ip
	ret
vm_movcpddat		endp

;-----------------------------------------------------------------------------------------[ mov dat, cps
vm_movdatcps		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cps
	mov	[esi].reg_dat, eax
	inc	[esi].reg_ip
	ret
vm_movdatcps		endp

;-----------------------------------------------------------------------------------------[ mov dat, cpd
vm_movdatcpd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cpd
	mov	[esi].reg_dat, eax
	inc	[esi].reg_ip
	ret
vm_movdatcpd		endp

;-----------------------------------------------------------------------------------------[ mov cps, cpd
vm_movcpscpd		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cpd
	mov	[esi].reg_cps, eax
	inc	[esi].reg_ip
	ret
vm_movcpscpd		endp

;-----------------------------------------------------------------------------------------[ mov cpd, cps
vm_movcpdcps		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	eax, [esi].reg_cps
	mov	[esi].reg_cpd, eax
	inc	[esi].reg_ip
	ret
vm_movcpdcps		endp


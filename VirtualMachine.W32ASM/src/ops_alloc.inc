

	.code

;-----------------------------------------------------------------------------------------[ alloc immediate
vm_allocimm		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	ebx, [esi].code_len

	mov	edi, [esi].reg_ip
	inc	edi

	push	edi
	push	esi
	call	internals_ReadValue			; Gets 32 bit value after opcode

	push	eax
	push	esi
	call	internals_Allocate			; Allocate the extra memory

	mov	[esi].reg_acc, ebx			; acc -> new area
	add	[esi].reg_ip, 5
	ret
vm_allocimm		endp

;-----------------------------------------------------------------------------------------[ alloc cnt
vm_alloccnt		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	ebx, [esi].code_len

	push	[esi].reg_cnt
	push	esi
	call	internals_Allocate			; Allocate the extra memory

	mov	[esi].reg_acc, ebx			; acc -> new area
	inc	[esi].reg_ip
	ret
vm_alloccnt		endp

;-----------------------------------------------------------------------------------------[ alloc acc
vm_allocacc		proc	STDCALL, ptrMachine:DWORD
	mov	esi, ptrMachine
	mov	ebx, [esi].code_len

	push	[esi].reg_acc
	push	esi
	call	internals_Allocate			; Allocate the extra memory

	mov	[esi].reg_acc, ebx			; acc -> new area
	inc	[esi].reg_ip
	ret
vm_allocacc		endp
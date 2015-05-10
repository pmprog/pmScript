

virtualmachine	struct
	state		dd	?		; Machine State
	reg_acc	dd	?		; Accumulator
	reg_cnt	dd	?		; Counter
	reg_dat	dd	?		; Data
	reg_rnd	dd	?		; Random Number
	reg_cps	dd	?		; Copier Source
	reg_cpd	dd	?		; Copier Destination
	reg_ip		dd	?		; Instruction Pointer
	reg_sp		dd	?		; Stack Pointer (inside stack area)
	reg_flags	db	?		; Flags ( 0000cdbz - d = direction, b = below, z = zero, c = carry )
	code_ptr	dd	?		; Points to the memory holding the script
	code_len	dd	?		; Length of the compiled script
	stack_ptr	dd	?		; Pointer to the stack buffer
	stack_len	dd	?		; Length of stack buffer
	init_ip	dd	?		; Initial starting IP (for restarting the machine)
	ptr_api	dd	?		; Address of client callback for script API :: Callback(ptrMachine:DWORD, intAPINumber:DWORD)
	txt_crash	db	200h dup (?)	; Crash details for script
virtualmachine	ends


VMSTATE_READY		equ	0
VMSTATE_RUNNING	equ	1
VMSTATE_PAUSED	equ	2
VMSTATE_ENDED		equ	3
VMSTATE_CRASH		equ	4

VMFLAG_CARRY		equ	00001000b
VMFLAG_DIRECTION	equ	00000100b
VMFLAG_BELOW		equ	00000010b
VMFLAG_ZERO		equ	00000001b

	.data
crash_outofstack	db	'Out of stack space', 0
crash_outofstack_len	equ	offset $ - offset crash_outofstack

crash_emptystack	db	'Stack already empty', 0
crash_emptystack_len	equ	offset $ - offset crash_emptystack

crash_invalidaddr	db	'Address out of range', 0
crash_invalidaddr_len	equ	offset $ - offset crash_invalidaddr

crash_allocfail	db	'Memory allocation failed', 0
crash_allocfail_len	equ	offset $ - offset crash_allocfail

	.code

;-------------------------------------------------------------------------------------------[ Memory access functions (Internal Use)

internals_PushValue		proc	STDCALL, ptrMachine:DWORD, valNew:DWORD
	push	esi
	push	eax

	mov	esi, ptrMachine			; Gets Machine
	mov	eax, [esi].reg_sp			; Reads stack pointer
	cmp	eax, [esi].stack_len			; Compares point to stack length
	jl	intPush_okay				; If we have space, jump to intPush_okay

	push	crash_outofstack_len
	push	offset crash_outofstack
	call	internals_SetCrashMsg		; Report out of stack space
	jmp	intPush_leave

intPush_okay:
	push	edi
	mov	edi, [esi].stack_ptr			; Gets the memory address of stack
	add	edi, eax				; Move to our current position
	mov	eax, valNew
	movsd						; Store the value
	add	[esi].reg_sp, 4			; Move the stack up
	pop	edi

intPush_leave:
	pop	eax
	pop	esi
	ret
internals_PushValue		endp

internals_PopValue		proc	STDCALL, ptrMachine:DWORD
	push	esi
	mov	esi, ptrMachine			; Gets machine
	mov	eax, [esi].reg_sp			; Reads stack pointer
	or	eax, eax				; Checks not at the floor
	jg	intPop_okay				; Got poppable value, jump to intPop_okay

	push	crash_emptystack_len
	push	offset crash_emptystack
	call	internals_SetCrashMsg		; Report empty stack
	jmp	intPop_leave

intPop_okay:
	push	edi
	sub	eax, 4					; Move stack down
	mov	[esi].reg_sp, eax			; Store new stack position
	mov	edi, [esi].stack_ptr
	add	edi, eax				; EDI -> Stack item
	lodsd						; Load stack value
	pop	edi

intPop_leave:
	pop	esi
	ret
internals_PopValue		endp

internals_ReadValue		proc	STDCALL, ptrMachine:DWORD, ptrOffset:DWORD
	push	esi
	push	ebx
	mov	esi, ptrMachine			; Gets machine
	mov	eax, ptrOffset			; Gets script address
	cmp	eax, 0					; Checks the address is >= 0
	jl	intReadV_error
	mov	ebx, [esi].code_len			; Checks the address is <= script length - 4
	sub	ebx, 4					; (ReadValue does 32bits, so make sure don't try and read past end of script)
	cmp	eax, ebx
	jg	intReadV_error

	mov	esi, [esi].code_ptr
	add	esi, eax				; ESI -> Address in code
	lodsd

	jmp	intReadV_leave

intReadV_error:
	push	crash_invalidaddr_len
	push	offset crash_invalidaddr
	call	internals_SetCrashMsg		; Address out of range error

intReadV_leave:
	pop	ebx
	pop	esi
	ret
internals_ReadValue		endp

internals_WriteValue		proc	STDCALL, ptrMachine:DWORD, ptrOffset:DWORD, valNew:DWORD
	push	esi
	push	ebx
	mov	esi, ptrMachine			; Gets machine
	mov	eax, ptrOffset			; Gets script address
	cmp	eax, 0					; Checks the address is >= 0
	jl	intWriteV_error
	mov	ebx, [esi].code_len			; Checks the address is <= script length - 4
	sub	ebx, 4					; (WriteValue does 32bits, so make sure don't try and read past end of script)
	cmp	eax, ebx
	jg	intWriteV_error

	push	edi
	mov	edi, [esi].code_ptr
	add	edi, eax				; EDI -> Address in code
	mov	eax, valNew				; EAX == New Value
	stosd
	pop	edi

	jmp	intWriteV_leave

intWriteV_error:
	push	crash_invalidaddr_len
	push	offset crash_invalidaddr
	call	internals_SetCrashMsg		; Address out of range error

intWriteV_leave:
	pop	ebx
	pop	esi
	ret
internals_WriteValue		endp

internals_ReadByte		proc	STDCALL, ptrMachine:DWORD, ptrOffset:DWORD
	push	esi
	push	ebx
	mov	esi, ptrMachine			; Gets machine
	mov	eax, ptrOffset			; Gets script address
	cmp	eax, 0					; Checks the address is >= 0
	jl	intReadB_error
	mov	ebx, [esi].code_len			; Checks the address is <= script length - 1
	dec	ebx					; (ReadByte does 8bits, so make sure don't try and read past end of script)
	cmp	eax, ebx
	jg	intReadB_error

	mov	esi, [esi].code_ptr
	add	esi, eax				; ESI -> Address in code
	xor	eax, eax
	lodsb						; EAX/AL == Read byte

	jmp	intReadB_leave

intReadB_error:
	push	crash_invalidaddr_len
	push	offset crash_invalidaddr
	call	internals_SetCrashMsg		; Address out of range error

intReadB_leave:
	pop	ebx
	pop	esi
	ret
internals_ReadByte		endp

internals_WriteByte		proc	STDCALL, ptrMachine:DWORD, ptrOffset:DWORD, valNew:DWORD
	push	esi
	push	ebx
	mov	esi, ptrMachine			; Gets machine
	mov	eax, ptrOffset			; Gets script address
	cmp	eax, 0					; Checks the address is >= 0
	jl	intWriteB_error
	mov	ebx, [esi].code_len			; Checks the address is <= script length - 1
	dec	ebx					; (WriteByte does 8bits, so make sure don't try and read past end of script)
	cmp	eax, ebx
	jg	intWriteB_error

	push	edi
	mov	edi, [esi].code_ptr
	add	edi, eax				; EDI -> Address in code
	mov	eax, valNew				; EAX == New Value
	stosb
	pop	edi

	jmp	intWriteB_leave

intWriteB_error:
	push	crash_invalidaddr_len
	push	offset crash_invalidaddr
	call	internals_SetCrashMsg		; Address out of range error

intWriteB_leave:
	pop	ebx
	pop	esi
	ret
internals_WriteByte		endp

internals_Allocate		proc	STDCALL, ptrMachine:DWORD, lenAllocSize:DWORD
	push	esi
	push	ecx
	mov	esi, ptrMachine			; Gets machine
	mov	ecx, [esi].code_len
	add	ecx, lenAllocSize			; ECX == Script Length + new size

	cmp	ecx, [esi].code_len			; Check allocating a negative amount (or too large)
	jle	intAlloc_error

	push	ecx
	call	AllocFunc				; EAX -> Newly allocated space

	push	eax					; Temp save new script address

	push	[esi].code_len
	push	eax
	push	[esi].code_ptr
	call	MemCopy				; Copy script across

	push	[esi].code_ptr
	call	DeallocFunc				; Deallocate old script address

	pop	eax					; EAX == New script address
	mov	[esi].code_ptr, eax

	jmp	intAlloc_leave

intAlloc_error:
	mov	esi, ptrMachine			; Make sure machine is set
	push	crash_allocfail_len
	push	offset crash_allocfail
	call	internals_SetCrashMsg		; Address out of range error

intAlloc_leave:
	pop	ecx
	pop	esi
	ret
internals_Allocate		endp

internals_SetCrashMsg	proc	STDCALL, ptrCrashMessage:DWORD, lenCrashMessage:DWORD
	; ESI *MUST* point to machine
	push	edi
	push	ecx
	mov	[esi].state, VMSTATE_CRASH
	lea	edi, [esi].txt_crash
	mov	esi, ptrCrashMessage
	mov	ecx, lenCrashMessage
	rep	movsb
	pop	ecx
	pop	edi
	ret
internals_SetCrashMsg	endp

internals_CompareValues	proc	STDCALL, ptrMachine:DWORD, intLeftSide:DWORD, intRightSide:DWORD
;	push	esi
;	push	eax
;	push	ebx
;	mov	esi, ptrMachine
;	mov	bl, [esi].reg_flags
;
;	mov	eax, intLeftSide
;	cmp	eax, intRightSide
;	jz	cmpval_setz
;	and	bl, NOT VMFLAG_ZERO	
;	jmp	cmpval_chkedz
;cmpval_setz:
;	or	bl, VMFLAG_ZERO
;cmpval_chkedz:
;	jz	cmpval_setc
;	and	bl, NOT VMFLAG_BELOW
;	jmp	cmpval_chkedb
;cmpval_setc:
;	or	bl, VMFLAG_BELOW
;cmpval_chkedb:
;
;	mov	[esi].reg_flags, bl
;	pop	ebx
;	pop	eax
;	pop	esi

	push	eax
	mov	eax, intLeftSide
	sub	eax, intRightSide
	push	eax
	push	ptrMachine
	call	internals_SetFlags
	pop	eax

	ret
internals_CompareValues	endp

internals_SetFlags		proc	STDCALL, ptrMachine:DWORD, intToFlag:DWORD
	push	esi
	push	ebx
	push	eax
	mov	esi, ptrMachine
	mov	bl, [esi].reg_flags
	mov	eax, intToFlag

	or	eax, eax				; Check zero
	jz	setflags_setz
	and	bl, NOT VMFLAG_ZERO	
	jmp	setflags_finishedzero
setflags_setz:
	or	bl, VMFLAG_ZERO
setflags_finishedzero:

	cmp	eax, 0					; Check below zero
	jl	setflags_setb
	and	bl, NOT VMFLAG_BELOW	
	jmp	setflags_finishedbelow
setflags_setb:
	or	bl, VMFLAG_BELOW
setflags_finishedbelow:

	pop	eax
	pop	ebx
	pop	esi
	ret
internals_SetFlags		endp


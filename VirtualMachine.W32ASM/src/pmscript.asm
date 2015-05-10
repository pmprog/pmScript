	.386
	.model flat, STDCALL

UNICODE	equ	0
INCLUDE	..\Win32.INC
INCLUDELIB	..\Win32.LIB

public	LoadScript
public	LoadScriptFromFile
public	CreateVirtualMachine
public	RunScript
public	TakeStep
public ResetVirtualMachine
public PushVMStack
public PopVMStack

	.data?

randomSeed	dd	?

fileHnd	dd	?
mappingHnd	dd	?
viewHnd	dd	?
lastHnd	dd	?
machineHnd	dd	?

	.code

DLLMain		proc	STDCALL, hInst:DWORD, hReason:DWORD, hReserved:DWORD
	call	GetTickCount
	rol	eax, 10h
	mov	randomSeed, eax

	mov	eax, 1			;Return True
	ret
DLLMain		endp

LoadScript			proc	STDCALL, ptrPortableBinary:DWORD, lenPortableBinary:DWORD, ptrAPICallback:DWORD
	mov	esi, ptrPortableBinary
	mov	eax, dword ptr [esi]
	.IF eax == 00014D50h		; 'PM' and file version 1.0

		push	ptrAPICallback
		push	dword ptr [esi + 0Ch]	; Start IP
		push	dword ptr [esi + 10h]	; Stack Length
		push	dword ptr [esi + 08h]	; Code Length
		add	esi, [esi + 04h]		; ESI == Code Start
		push	esi
		call	CreateVirtualMachine		; EAX will return a machine handle

	.ELSE
		xor	eax, eax
	.ENDIF
	ret
LoadScript			endp

LoadScriptFromFile		proc	STDCALL, ptrFilename:DWORD, ptrAPICallback:DWORD
	mov	lastHnd, 0

	push	0
	push	FILE_ATTRIBUTE_NORMAL
	push	OPEN_EXISTING
	push	0
	push	FILE_SHARE_READWRITE
	push	GENERIC_READWRITE
	push	ptrFilename
	call	CreateFile
	mov	fileHnd, eax
	inc	eax
	jz	loadscriptfile_failed

	push	0
	push	0
	push	0
	push	PAGE_READONLY
	push	0
	push	fileHnd
	call	CreateFileMapping
	mov	mappingHnd, eax
	or	eax, eax
	jz	loadscriptfile_failedclosefile

	push	0
	push	0
	push	0
	push	FILE_MAP_READ
	push	eax
	call	MapViewOfFile
	mov	viewHnd, eax
	or	eax, eax
	jz	loadscriptfile_failedclosemap

	push	0
	push	fileHnd
	call	GetFileSize

	push	ptrAPICallback
	push	eax
	push	viewHnd
	call	LoadScript
	mov	lastHnd, eax

	push	viewHnd
	call	UnmapViewOfFile
	push	mappingHnd
	call	CloseHandle
	push	fileHnd
	call	CloseHandle

	mov	eax, lastHnd
	jmp	loadscriptfile_leave

loadscriptfile_failedclosemap:
	push	mappingHnd
	call	CloseHandle
loadscriptfile_failedclosefile:
	push	fileHnd
	call	CloseHandle
loadscriptfile_failed:
	xor	eax, eax
loadscriptfile_leave:
	ret
LoadScriptFromFile		endp

CreateVirtualMachine		proc	STDCALL, ptrCodeBlock:DWORD, lenCodeBlock:DWORD, lenStack:DWORD, intStartIP:DWORD, ptrAPICallback:DWORD

	push	size virtualmachine
	call	AllocFunc
	mov	machineHnd, eax
	mov	esi, eax

	mov	eax, lenCodeBlock
	mov	[esi].code_len, eax
	push	eax
	push	ptrCodeBlock
	call	CloneMemory
	mov	[esi].code_ptr, eax

	mov	eax, lenStack
	shl	eax, 2
	mov	[esi].stack_len, eax
	push	eax
	call	AllocFunc
	mov	[esi].stack_ptr, eax

	mov	eax, intStartIP
	mov	[esi].init_ip, eax
	mov	eax, ptrAPICallback
	mov	[esi].ptr_api, eax

	push	esi
	call	ResetVirtualMachine

	mov	eax, machineHnd
	ret
CreateVirtualMachine		endp

RunScript			proc	STDCALL, hndMachine:DWORD
	mov	esi, hndMachine
runscript_untilend:
	push	esi
	call	TakeStep
	cmp	eax, VMSTATE_RUNNING
	je	runscript_untilend
	cmp	eax, VMSTATE_READY
	je	runscript_untilend
	ret
RunScript			endp

TakeStep			proc	STDCALL, hndMachine:DWORD
	push	esi
	push	edi
	mov	esi, hndMachine
	mov	edi, [esi].reg_ip
	push	edi
	push	esi
	call	internals_ReadByte
	shl	edi, 2			; *4
	add	edi, offset OpCodeTable
	xchg	esi, edi
	lodsd
	push	edi
	push	edi
	call	eax
	pop	edi
	mov	eax, [edi].state
	pop	edi
	pop	esi
	ret					; Returns current machine state
TakeStep			endp

ResetVirtualMachine		proc	STDCALL, hndMachine:DWORD
	push	esi
	mov	esi, hndMachine

	mov	eax, [esi].init_ip
	mov	[esi].reg_ip, eax

	call	GetTickCount
	push	eax
	call	RandomNumber
	mov	[esi].reg_rnd, eax

	xor	eax, eax
	mov	[esi].reg_acc, eax
	mov	[esi].reg_cnt, eax
	mov	[esi].reg_dat, eax
	mov	[esi].reg_cps, eax
	mov	[esi].reg_cpd, eax
	mov	[esi].reg_sp, eax
	mov	[esi].reg_flags, al
	mov	[esi].state, VMSTATE_READY

	pop	esi
	ret
ResetVirtualMachine		endp

PushVMStack			proc	STDCALL, hndMachine:DWORD, pushValue:DWORD
	push	pushValue
	push	hndMachine
	call	internals_PushValue
	ret
PushVMStack			endp

PopVMStack			proc	STDCALL, hndMachine:DWORD
	push	hndMachine
	call	internals_PopValue
	ret
PopVMStack			endp

RandomNumber			proc STDCALL, SeedExtra:DWORD
	push	ebx
	call	GetTickCount
	mov	ebx, SeedExtra
	ror	eax, 0Ah
	xor	eax, ebx
	mov	ebx, randomSeed
	xor	eax, ebx
	rol	eax, 3h
	mov	randomSeed, eax
	pop	ebx
	ret
RandomNumber			endp

INCLUDE	memory.inc
INCLUDE	vmstruct.inc
INCLUDE	optable.inc

	end	DLLMain

	.486p
	.model flat, STDCALL

UNICODE	equ	0
INCLUDE	..\lib\win32.inc
INCLUDE	..\lib\pmScript.inc
INCLUDELIB	..\lib\win32.lib
INCLUDELIB	..\lib\msimg32.lib
INCLUDELIB	..\lib\pmScript.lib

	.data
myFrameworkTag	db	'Polymath Programming Script Debugger', 0
engine_tag		db	'pmDebug', 0

	.data?
randomSeed		dd	?

	.code
engineStart:

	push	0
	call	GetModuleHandle
	mov	engineInst, eax

	call	GetTickCount
	mov	randomSeed, eax

	call	LoadResources
	call	initWindow

engineMessageLoop:
	push	PM_REMOVE
	push	0 0 0
	push	offset engineMsg
	call	PeekMessage ; GetMessage
	or	eax, eax
	jz	engineNoMessages

	mov	eax, engineMsg.ms_message
	cmp	eax, WM_QUIT
	je	engineFinish

	push	offset engineMsg
	call	TranslateMessage

	push	offset engineMsg
	call	DispatchMessage

engineNoMessages:
	jmp	engineMessageLoop			; Handle all messages

engineFinish:
	call	ExitProcess


INCLUDE	gfxengine.inc
INCLUDE	resource.inc
INCLUDE	memory.inc
INCLUDE	textconvert.inc
INCLUDE	console.inc

	end	engineStart


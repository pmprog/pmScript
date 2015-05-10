
GRABMODE_NONE			equ	00h
GRABMODE_MOVE			equ	01h
GRABMODE_SIZELEFT		equ	02h
GRABMODE_SIZETOP		equ	04h
GRABMODE_SIZERIGHT		equ	08h
GRABMODE_SIZEBOTTOM		equ	10h

WIDGET_MIN_X			equ	32
WIDGET_MIN_Y			equ	24

GradientFill			PROCDESC	WINAPI

widgetGradFill		struct
	wdf_topleft		dd	?
	wdf_bottomright	dd	?
widgetGradFill		ends

widgetTriVertex		struct
	wtv_X			dd	?
	wtv_Y			dd	?
	wtv_red		dw	?
	wtv_green		dw	?
	wtv_blue		dw	?
	wtv_alpha		dw	?
widgetTriVertex		ends

	.data

appIconName			db	'AppIco', 0
appTitle			db	'pmScript Debugger', 0

menuAtX			dd			0
menuAtY			dd			0

grabMode			dd			GRABMODE_NONE	
grabbedWdgt			dd			0
grabLastX			dd			0
grabLastY			dd			0

	.data?

grabHndled			db			?

engineClass			WNDCLASS		?
engineMsg			MSG			?
enginePaint			PAINTSTRUCT		?
engineWnd			dd			?
engineInst			dd			?

engineDC			dd			?

bufferDC			dd			?
bufferBMP			dd			?

copierDC			dd			?
widgetDC			dd			?


clientRect			RECT			?

widgetGFill			widgetGradFill	?
widgetGVerts:
widgetGVertA			widgetTriVertex	?
widgetGVertB			widgetTriVertex	?

	.code

initWindow			proc	STDCALL	; Return: EAX = Window Handle


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Register Window Class
	push	0
	push	0
	push	0
	push	IMAGE_ICON
	push	offset appIconName
	push	engineInst
	call	LoadImage
	mov	engineClass.w_hIcon, eax

	push	IDC_ARROW
	push	0
	call	LoadCursor
	mov	engineClass.w_hCursor, eax

;	push	bmp_Background
;	call	CreatePatternBrush
	push	0
	call	CreateSolidBrush
	mov	engineClass.w_hbrBackground, eax

	mov	eax, engineInst
	mov	engineClass.w_hInstance, eax
	mov	engineClass.w_lpfnWndProc, offset windowMsgProc
	mov	engineClass.w_lpszMenuName, offset engine_tag
	mov	engineClass.w_lpszClassName, offset engine_tag

	push	offset engineClass
	call	RegisterClassA

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; Create Window
	push	0
	push	engineInst
	push	0
	push	0
	push	600
	push	800
	push	0
	push	0
	push	WS_VISIBLE + WS_SIZEBOX + WS_CAPTION + WS_SYSMENU + WS_MINIMIZEBOX + WS_MAXIMIZEBOX
	push	offset appTitle
	push	offset engine_tag
	push	0
	call	CreateWindowEx
	mov	engineWnd, eax

	push	eax
	call	GetDC
	mov	engineDC, eax

	push	eax
	call	CreateCompatibleDC
	mov	bufferDC, eax

	call	CreateBuffer

	push	engineDC
	call	CreateCompatibleDC
	mov	copierDC, eax

	push	engineDC
	call	CreateCompatibleDC
	mov	widgetDC, eax

	ret
initWindow			endp


windowMsgProc			proc	STDCALL, hwnd:DWORD, wmsg:DWORD, wparam:DWORD, lparam:DWORD
	mov	eax, wmsg

	.IF ax == WM_DESTROY
		push	0
		call	PostQuitMessage
		ret

	.ELSEIF ax == WM_WINDOWPOSCHANGED
		call	CreateBuffer
		call	DrawScreen

	.ELSEIF ax == WM_CHAR
		mov	ebx, wparam
		push	ebx
		call	HandleConsoleKey
		call	DrawScreen

	.ELSEIF ax == WM_PAINT
		push	offset enginePaint
		push	hwnd
		call	BeginPaint

		call	DrawScreen

		push	offset enginePaint
		push	hwnd
		call	EndPaint
	.ELSE
		push	lparam
		push	wparam
		push	wmsg
		push	hwnd
		call	DefWindowProc				; Fallback, standard windows handler
		ret
	.ENDIF
	xor	eax, eax
	ret
windowMsgProc			endp

CreateBuffer			proc	STDCALL

	push	offset clientRect
	push	engineWnd
	call	GetClientRect

	push	clientRect.rc_bottom
	push	clientRect.rc_right
	push	engineDC
	call	CreateCompatibleBitmap
	mov	bufferBMP, eax

	push	eax
	push	bufferDC
	call	SelectObject

	ret
CreateBuffer			endp

DrawScreen			proc	STDCALL

	push	offset clientRect
	push	engineWnd
	call	GetClientRect

	push	clientRect.rc_bottom
	push	clientRect.rc_right
	push	00996633h
	push	00C6A786h ; 00FFD8B0h
	push	bufferDC
	call	GradiFill

	push	bmp_pmprog
	push	copierDC
	call	SelectObject

	push	SRCCOPY
	push	0
	push	0
	push	copierDC
	push	31
	push	88
	mov	eax, clientRect.rc_bottom
	sub	eax, 38
	push	eax
	mov	eax, clientRect.rc_right
	sub	eax, 96
	push	eax
	push	bufferDC
	call	BitBlt


	call	DrawConsoleCommand

drawscreen_wndfinish:
	push	SRCCOPY
	push	0
	push	0
	push	bufferDC
	push	clientRect.rc_bottom
	push	clientRect.rc_right
	push	0
	push	0
	push	engineDC
	call	BitBlt

	ret
DrawScreen			endp

GradiFill			proc	STDCALL, dstDC:DWORD, topColour:DWORD, bottomColour:DWORD, dstWidth:DWORD, dstHeight:DWORD
	pusha

	mov	widgetGFill.wdf_topleft, 0
	mov	widgetGFill.wdf_bottomright, 1		; Set vert points

	xor	eax, eax
	mov	widgetGVertA.wtv_X, eax
	mov	widgetGVertA.wtv_Y, eax
	mov	widgetGVertA.wtv_alpha, ax
	mov	ebx, topColour
	mov	eax, ebx
	shl	eax, 8
	mov	widgetGVertA.wtv_red, ax
	mov	eax, ebx
	and	eax, 0000FF00h
	mov	widgetGVertA.wtv_green, ax
	mov	eax, ebx
	xor	ax, ax
	shr	eax, 8
	mov	widgetGVertA.wtv_blue, ax			; Define top colour

	mov	eax, dstWidth
	mov	widgetGVertB.wtv_X, eax
	mov	eax, dstHeight
	mov	widgetGVertB.wtv_Y, eax
	mov	widgetGVertB.wtv_alpha, 0
	mov	ebx, bottomColour
	mov	eax, ebx
	shl	eax, 8
	mov	widgetGVertB.wtv_red, ax
	mov	eax, ebx
	and	eax, 0000FF00h
	mov	widgetGVertB.wtv_green, ax
	mov	eax, ebx
	xor	ax, ax
	shr	eax, 8
	mov	widgetGVertB.wtv_blue, ax			; Define bottom colour

	push	1						; GRADIENT_FILL_RECT_V
	push	1
	push	offset widgetGFill
	push	2
	push	offset widgetGVerts
	push	dstDC
	call	GradientFill

	popa
	ret
GradiFill			endp


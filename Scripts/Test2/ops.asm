TESTCONST		equ	2

	.stack 70
	.start entry

entry:
	mov	cnt, 34h
	call	CopyString

	mov	cps, leavingnow
	push	cps
	jmp	TestHackedReturn

leavingnow:
	end


TestHackedReturn:
	mov	acc, 7
	mov	cnt, TESTCONST
	mul	cnt
	api	3
	ret

CopyString:
	push	cnt
	mov	acc, DstStringPtr
	cmp	acc, 0
	je	copystring_dontreallocate
	alloc	8
	mov	DstStringPtr, acc
copystring_dontreallocate:
	mov	acc, DstStringPtr
	mov	cpd, acc			; mov	cpd, DstStringPtr would set cpd pointing to var, not the value
	mov	cps, SrcString
	movs
	mov	cnt, 4
copystring_loop:
	movsb
	loop	copystring_loop
	pop	cnt
	ret

SrcString		str	'Copy Me'
DstStringPtr	var	0

	end
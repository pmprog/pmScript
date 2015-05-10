	.stack 70
	.start entry

	nop
	nop
entry:
	nop	
	push	7Dh + (23 * 2)
	push	TestVar
	push	acc
	push	cnt
	push	dat
	push	cps
	push	cpd
	pop	TestVar
	pop	acc
	pop	cnt
	pop	dat
	pop	cps
	pop	cpd
	mov	acc, 7Dh + (23 * 2)
	mov	cnt, 7Dh + (23 * 2)
	mov	dat, 7Dh + (23 * 2)
	mov	acc, cnt
	mov	acc, dat
	mov	acc, rnd
	mov	cnt, acc
	mov	cnt, dat
	mov	cnt, rnd
	mov	dat, acc
	mov	dat, cnt
	mov	dat, rnd
	mov	acc, TestVar
	mov	cnt, TestVar
	mov	dat, TestVar
	mov	cps, start
	mov	cpd, start
	mov	TestVar, 7Dh + (23 * 2)
	mov	TestVar, acc
	mov	TestVar, cnt
	mov	TestVar, dat
	mov	TestVar, rnd
	lods	
	stos	
	movs	
	cmp	acc, cnt
	cmp	acc, dat
	cmp	acc, 7Dh + (23 * 2)
	cmp	acc, TestVar
	cmp	cnt, acc
	cmp	cnt, dat
	cmp	cnt, 7Dh + (23 * 2)
	cmp	cnt, TestVar
	cmp	dat, acc
	cmp	dat, cnt
	cmp	dat, 7Dh + (23 * 2)
	cmp	dat, TestVar
	jmp	start
	je	start
	jne	start
	jb	start
	jbe	start
	loop	start
	call	start
	api	7Dh + (23 * 2)
	ret	
	end	
	add	acc, 7Dh + (23 * 2)
	add	acc, dat
	add	acc, rnd
	add	acc, TestVar
	add	cnt, 7Dh + (23 * 2)
	add	cnt, acc
	add	cnt, dat
	add	cnt, rnd
	add	cnt, TestVar
	add	dat, 7Dh + (23 * 2)
	add	dat, acc
	add	dat, rnd
	add	dat, TestVar
	sub	acc, 7Dh + (23 * 2)
	sub	acc, dat
	sub	acc, rnd
	sub	acc, TestVar
	sub	cnt, 7Dh + (23 * 2)
	sub	cnt, acc
	sub	cnt, dat
	sub	cnt, rnd
	sub	cnt, TestVar
	sub	dat, 7Dh + (23 * 2)
	sub	dat, acc
	sub	dat, rnd
	sub	dat, TestVar
	inc	acc
	inc	cnt
	inc	dat
	dec	acc
	dec	cnt
	dec	dat
	mul	7Dh + (23 * 2)
	mul	TestVar
	mul	cnt
	div	7Dh + (23 * 2)
	div	TestVar
	div	cnt
	and	acc, 7Dh + (23 * 2)
	and	acc, dat
	and	acc, TestVar
	and	dat, 7Dh + (23 * 2)
	and	dat, acc
	and	dat, TestVar
	or	acc, 7Dh + (23 * 2)
	or	acc, dat
	or	acc, TestVar
	or	dat, 7Dh + (23 * 2)
	or	dat, acc
	or	dat, TestVar
	xor	acc, 7Dh + (23 * 2)
	xor	acc, dat
	xor	acc, TestVar
	xor	dat, 7Dh + (23 * 2)
	xor	dat, acc
	xor	dat, TestVar
	not	acc
	not	dat
	neg	acc
	neg	dat
	sin	7Dh + (23 * 2)
	sin	cnt
	sin	TestVar
	cos	7Dh + (23 * 2)
	cos	cnt
	cos	TestVar
	tan	7Dh + (23 * 2)
	tan	cnt
	tan	TestVar
	rol	7Dh + (23 * 2)
	rol	cnt
	ror	7Dh + (23 * 2)
	ror	cnt
	shl	7Dh + (23 * 2)
	shl	cnt
	shr	7Dh + (23 * 2)
	shr	cnt
	xchg	acc, dat
	mod	7Dh + (23 * 2)
	mod	TestVar
	mod	cnt
	lodsb	
start:
	stosb	
	movsb	
	std	
	cld	
	xchg	acc, cnt
	and	cnt, 7Dh + (23 * 2)
	and	cnt, acc
	and	cnt, TestVar
	or	cnt, 7Dh + (23 * 2)
	or	cnt, acc
	or	cnt, TestVar
	xor	cnt, 7Dh + (23 * 2)
	xor	cnt, acc
	xor	cnt, TestVar
	and	acc, cnt
	or	acc, cnt
	xor	acc, cnt
	alloc	cnt
	alloc	7Dh + (23 * 2)
	mov	cps, acc
	mov	cpd, acc
	mov	acc, cps
	mov	acc, cpd
	mov	cps, dat
	mov	cpd, dat
	mov	dat, cps
	mov	dat, cpd
	mov	cps, cpd
	mov	cpd, cps
	alloc	acc


TestVar		var	347Dh

	end
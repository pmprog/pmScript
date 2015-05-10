include	api.inc

	.stack 30
	.start start

TEST_ACC	equ	TEST_LOOP + 3
TEST_LOOP	equ	5 + AddEventHandler
myApp		str	'Test App'
myVer		var	1
myCopy		str	'        '

start:	mov	cnt, TEST_LOOP * 0Dh
	mov	cps, myApp
	mov	cpd, myApp

loophere:
	mov	acc, TEST_ACC
	nop

	mov	cps, myApp
	mov	cpd, myCopy
	mov	cnt, 8
copyStr:
	movsb
	loop	copyStr

	api	MsgBox

	loop	loophere

	end


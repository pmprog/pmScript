
	.data

OpCodeTable:
	dd	offset vm_nop				; 00h
	dd	offset vm_pushimm			; 01h
	dd	offset vm_pushvar			; 02h
	dd	offset vm_pushacc			; 03h
	dd	offset vm_pushcnt			; 04h
	dd	offset vm_pushdat			; 05h
	dd	offset vm_pushcps			; 06h
	dd	offset vm_pushcpd			; 07h
	dd	offset vm_popvar			; 08h
	dd	offset vm_popacc			; 09h
	dd	offset vm_popcnt			; 0Ah
	dd	offset vm_popdat			; 0Bh
	dd	offset vm_popcps			; 0Ch
	dd	offset vm_popcpd			; 0Dh
	dd	offset vm_movaccimm			; 0Eh
	dd	offset vm_movcntimm			; 0Fh
	dd	offset vm_movdatimm			; 10h
	dd	offset vm_movacccnt			; 11h
	dd	offset vm_movaccdat			; 12h
	dd	offset vm_movaccrnd			; 13h
	dd	offset vm_movcntacc			; 14h
	dd	offset vm_movcntdat			; 15h
	dd	offset vm_movcntrnd			; 16h
	dd	offset vm_movdatacc			; 17h
	dd	offset vm_movdatcnt			; 18h
	dd	offset vm_movdatrnd			; 19h
	dd	offset vm_movaccvar			; 1Ah
	dd	offset vm_movcntvar			; 1Bh
	dd	offset vm_movdatvar			; 1Ch
	dd	offset vm_movcpsvar			; 1Dh
	dd	offset vm_movcpdvar			; 1Eh
	dd	offset vm_movvarimm			; 1Fh
	dd	offset vm_movvaracc			; 20h
	dd	offset vm_movvarcnt			; 21h
	dd	offset vm_movvardat			; 22h
	dd	offset vm_movvarrnd			; 23h
	dd	offset vm_lods			; 24h
	dd	offset vm_stos			; 25h
	dd	offset vm_movs			; 26h
	dd	offset vm_cmpacccnt			; 27h
	dd	offset vm_cmpaccdat			; 28h
	dd	offset vm_cmpaccimm			; 29h
	dd	offset vm_cmpaccvar			; 2Ah
	dd	offset vm_cmpcntacc			; 2Bh
	dd	offset vm_cmpcntdat			; 2Ch
	dd	offset vm_cmpcntimm			; 2Dh
	dd	offset vm_cmpcntvar			; 2Eh
	dd	offset vm_cmpdatacc			; 2Fh
	dd	offset vm_cmpdatcnt			; 30h
	dd	offset vm_cmpdatimm			; 31h
	dd	offset vm_cmpdatvar			; 32h
	dd	offset vm_jmp				; 33h
	dd	offset vm_je				; 34h
	dd	offset vm_jne				; 35h
	dd	offset vm_jb				; 36h
	dd	offset vm_jbe				; 37h
	dd	offset vm_loop			; 38h
	dd	offset vm_call			; 39h
	dd	offset vm_api				; 3Ah
	dd	offset vm_ret				; 3Bh
	dd	offset vm_end				; 3Ch
	dd	offset vm_addaccimm			; 3Dh
	dd	offset vm_addaccdat			; 3Eh
	dd	offset vm_addaccrnd			; 3Fh
	dd	offset vm_addaccvar			; 40h
	dd	offset vm_addcntimm			; 41h
	dd	offset vm_addcntacc			; 42h
	dd	offset vm_addcntdat			; 43h
	dd	offset vm_addcntrnd			; 44h
	dd	offset vm_addcntvar			; 45h
	dd	offset vm_adddatimm			; 46h
	dd	offset vm_adddatacc			; 47h
	dd	offset vm_adddatrnd			; 48h
	dd	offset vm_adddatvar			; 49h
	dd	offset vm_subaccimm			; 4Ah
	dd	offset vm_subaccdat			; 4Bh
	dd	offset vm_subaccrnd			; 4Ch
	dd	offset vm_subaccvar			; 4Dh
	dd	offset vm_subcntimm			; 4Eh
	dd	offset vm_subcntacc			; 4Fh
	dd	offset vm_subcntdat			; 50h
	dd	offset vm_subcntrnd			; 51h
	dd	offset vm_subcntvar			; 52h
	dd	offset vm_subdatimm			; 53h
	dd	offset vm_subdatacc			; 54h
	dd	offset vm_subdatrnd			; 55h
	dd	offset vm_subdatvar			; 56h
	dd	offset vm_incacc			; 57h
	dd	offset vm_inccnt			; 58h
	dd	offset vm_incdat			; 59h
	dd	offset vm_decacc			; 5Ah
	dd	offset vm_deccnt			; 5Bh
	dd	offset vm_decdat			; 5Ch
	dd	offset vm_mulimm			; 5Dh
	dd	offset vm_mulvar			; 5Eh
	dd	offset vm_mulcnt			; 5Fh
	dd	offset vm_divimm			; 60h
	dd	offset vm_divvar			; 61h
	dd	offset vm_divcnt			; 62h
	dd	offset vm_andaccimm			; 63h
	dd	offset vm_andaccdat			; 64h
	dd	offset vm_andaccvar			; 65h
	dd	offset vm_anddatimm			; 66h
	dd	offset vm_anddatacc			; 67h
	dd	offset vm_anddatvar			; 68h
	dd	offset vm_oraccimm			; 69h
	dd	offset vm_oraccdat			; 6Ah
	dd	offset vm_oraccvar			; 6Bh
	dd	offset vm_ordatimm			; 6Ch
	dd	offset vm_ordatacc			; 6Dh
	dd	offset vm_ordatvar			; 6Eh
	dd	offset vm_xoraccimm			; 6Fh
	dd	offset vm_xoraccdat			; 70h
	dd	offset vm_xoraccvar			; 71h
	dd	offset vm_xordatimm			; 72h
	dd	offset vm_xordatacc			; 73h
	dd	offset vm_xordatvar			; 74h
	dd	offset vm_notacc			; 75h
	dd	offset vm_notdat			; 76h
	dd	offset vm_negacc			; 77h
	dd	offset vm_negdat			; 78h
	dd	offset vm_sinimm			; 79h
	dd	offset vm_sincnt			; 7Ah
	dd	offset vm_sinvar			; 7Bh
	dd	offset vm_cosimm			; 7Ch
	dd	offset vm_coscnt			; 7Dh
	dd	offset vm_cosvar			; 7Eh
	dd	offset vm_tanimm			; 7Fh
	dd	offset vm_tancnt			; 80h
	dd	offset vm_tanvar			; 81h
	dd	offset vm_rolimm			; 82h
	dd	offset vm_rolcnt			; 83h
	dd	offset vm_rorimm			; 84h
	dd	offset vm_rorcnt			; 85h
	dd	offset vm_shlimm			; 86h
	dd	offset vm_shlcnt			; 87h
	dd	offset vm_shrimm			; 88h
	dd	offset vm_shrcnt			; 89h
	dd	offset vm_xchgaccdat			; 8Ah
	dd	offset vm_modimm			; 8Bh
	dd	offset vm_modvar			; 8Ch
	dd	offset vm_modcnt			; 8Dh
	dd	offset vm_lodsb			; 8Eh
	dd	offset vm_stosb			; 8Fh
	dd	offset vm_movsb			; 90h
	dd	offset vm_std				; 91h
	dd	offset vm_cld				; 92h
	dd	offset vm_xchgacccnt			; 93h
	dd	offset vm_andcntimm			; 94h
	dd	offset vm_andcntacc			; 95h
	dd	offset vm_andcntvar			; 96h
	dd	offset vm_orcntimm			; 97h
	dd	offset vm_orcntacc			; 98h
	dd	offset vm_orcntvar			; 99h
	dd	offset vm_xorcntimm			; 9Ah
	dd	offset vm_xorcntacc			; 9Bh
	dd	offset vm_xorcntvar			; 9Ch
	dd	offset vm_andacccnt			; 9Dh
	dd	offset vm_oracccnt			; 9Eh
	dd	offset vm_xoracccnt			; 9Fh
	dd	offset vm_alloccnt			; A0h
	dd	offset vm_allocimm			; A1h
	dd	offset vm_movcpsacc			; A2h
	dd	offset vm_movcpdacc			; A3h
	dd	offset vm_movacccps			; A4h
	dd	offset vm_movacccpd			; A5h
	dd	offset vm_movcpsdat			; A6h
	dd	offset vm_movcpddat			; A7h
	dd	offset vm_movdatcps			; A8h
	dd	offset vm_movdatcpd			; A9h
	dd	offset vm_movcpscpd			; AAh
	dd	offset vm_movcpdcps			; ABh
	dd	offset vm_allocacc			; ACh



	.code

vm_nop		proc	STDCALL, ptrMachine:DWORD
	ret
vm_nop		endp

INCLUDE	ops_pushpop.inc
INCLUDE	ops_mov.inc
INCLUDE	ops_copier.inc
INCLUDE	ops_cmp.inc
INCLUDE	ops_flow.inc
INCLUDE	ops_add.inc
INCLUDE	ops_sub.inc
INCLUDE	ops_incdec.inc
INCLUDE	ops_muldiv.inc
INCLUDE	ops_andor.inc
INCLUDE	ops_trig.inc
INCLUDE	ops_rotate.inc
INCLUDE	ops_alloc.inc



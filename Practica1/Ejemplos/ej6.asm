segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_m resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
	; -----------------------
	; PROCEDIMIENTO PRINCIPAL
	; -----------------------
main:
	mov dword [__esp], esp

	push dword 0
	pop dword eax
	mov [_m], eax
	push dword _m
	push dword 5
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_1
	push dword 0
	jmp fin_mayor_1
mayor_1:
	push dword 1
fin_mayor_1:
	pop dword eax
	cmp eax,0
	je ifthenelse_1
	push dword 2
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	jmp ifthenelse_fin_1
ifthenelse_1:
	push dword 3
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
call print_endofline
ifthenelse_fin_1:
	jmp fin
error_1:
	push dword mensaje_1
	call print_string
	add esp, 4
	jmp fin
error_2:
	push dword mensaje_2
	call print_string
	add esp, 4
	jmp fin
fin:
	mov dword esp, [__esp]
	ret

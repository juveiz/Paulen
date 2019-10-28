segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_x resd 1
_y resd 1
_z resd 1
_j resd 1
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

	push dword _x
	call scan_int
	add esp, 4
	push dword _z
	call scan_int
	add esp, 4
	push dword _x
	pop dword eax
	mov eax, [eax]
	neg eax
	push dword eax
	pop dword eax
	mov [_j], eax
	push dword _j
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	push dword _x
	push dword _z
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	sub eax, ebx
	push dword eax
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	push dword _x
	push dword 2
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cdq
	cmp ebx, 0
	je error_1
	idiv ebx
	push dword eax
	pop dword eax
	mov [_y], eax
	push dword _y
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	push dword _x
	push dword _y
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	imul ebx
	push dword eax
	pop dword eax
	push dword eax
	call print_int
	add esp, 4
call print_endofline
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

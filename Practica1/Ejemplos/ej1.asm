segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_x resd 1
_y resd 1
_z resd 1
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

	push dword 8
	pop dword eax
	mov [_x], eax
	push dword _y
	call scan_int
	add esp, 4
	push dword _x
	push dword _y
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov [_z], eax
	push dword _z
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	push dword 7
	push dword _y
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	add eax, ebx
	push dword eax
	pop dword eax
	mov [_z], eax
	push dword _z
	pop dword eax
	mov eax, [eax]
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

segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_b1 resd 1
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

	push dword _b1
	call scan_boolean
	add esp, 4
	push dword _b1
	pop dword eax
	mov eax, [eax]
	mov ebx, 0
	cmp eax, ebx
	jz cero_no_0
	mov eax, 0
	jmp fin_no_0
cero_no_0:
	mov eax, 1
fin_no_0:
	push dword eax
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _b1
	pop dword eax
	mov eax, [eax]
	mov ebx, 0
	cmp eax, ebx
	jz cero_no_1
	mov eax, 0
	jmp fin_no_1
cero_no_1:
	mov eax, 1
fin_no_1:
	push dword eax
	pop dword eax
	mov ebx, 0
	cmp eax, ebx
	jz cero_no_2
	mov eax, 0
	jmp fin_no_2
cero_no_2:
	mov eax, 1
fin_no_2:
	push dword eax
	pop dword eax
	push dword eax
	call print_boolean
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

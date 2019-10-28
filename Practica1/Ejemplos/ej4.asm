segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_b1 resd 1
_x resd 1
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
	push dword _x
	call scan_int
	add esp, 4
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_0
	push dword 0
	jmp fin_mayor_0
mayor_0:
	push dword 1
fin_mayor_0:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jge mayor_igual_1
	push dword 0
	jmp fin_mayor_igual_1
mayor_igual_1:
	push dword 1
fin_mayor_igual_1:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jl menor_2
	push dword 0
	jmp fin_menor_2
menor_2:
	push dword 1
fin_menor_2:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jle menor_igual_3
	push dword 0
	jmp fin_menor_igual_3
menor_igual_3:
	push dword 1
fin_menor_igual_3:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	je igual_4
	push dword 0
	jmp fin_igual_4
igual_4:
	push dword 1
fin_igual_4:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _x
	push dword 3
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jne distinto_5
	push dword 0
	jmp fin_distinto_5
distinto_5:
	push dword 1
fin_distinto_5:
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _b1
	push dword 0
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	and eax, ebx
	push dword eax
	pop dword eax
	push dword eax
	call print_boolean
	add esp, 4
call print_endofline
	push dword _b1
	push dword 1
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	or eax, ebx
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

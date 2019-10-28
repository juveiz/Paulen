segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_m resd 1
_v resd 4
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
while_1:
	push dword _m
	push dword 4
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jle menor_igual_1
	push dword 0
	jmp fin_menor_igual_1
menor_igual_1:
	push dword 1
fin_menor_igual_1:
	pop dword eax
	cmp eax,0
	je while_fin_1
	push dword _m
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
call print_endofline
	push dword _m
	push dword 10
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	imul ebx
	push dword eax
	push dword _m
	pop dword eax
	mov eax, [eax]
	cmp eax,0
	jl error_2
	cmp eax,4
	jge error_2
	mov dword edx, _v
	lea eax, [edx + eax*4]
	push dword eax
	push dword _m
	push dword 1
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	add eax, ebx
	push dword eax
	pop dword eax
	mov [_m], eax
	jmp while_1
while_fin_1:
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

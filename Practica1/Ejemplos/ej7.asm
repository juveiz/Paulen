segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
_z resd 1
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
_doble:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4*1
	lea eax, [ebp + 8]
	push dword eax
	lea eax, [ebp - 4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	mov dword [ebx], eax
	push dword 2
	lea eax, [ebp + 8]
	push dword eax
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	imul ebx
	push dword eax
	pop dword eax
	mov dword esp,ebp
	pop dword ebp
	ret
	; -----------------------
	; PROCEDIMIENTO PRINCIPAL
	; -----------------------
main:
	mov dword [__esp], esp

	push dword 2
	pop dword eax
	mov [_z], eax
	push dword _z
pop dword eax
mov eax, [eax]
push dword eax
call _doble
add esp, 4*1
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

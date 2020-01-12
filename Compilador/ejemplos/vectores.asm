;D:	main
segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
;D:	{
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	3
;D:	]
;R15	<clase_vector> ::= array <tipo> [<constante_entera>]
;R7:	<clase> ::= <clase_vector>
;D:	vector1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_vector1 resd 3
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	vector1
;R2:	<declaraciones> ::= <declaracion>
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
;R21:	<funciones> ::= 
	; -----------------------
	; PROCEDIMIENTO PRINCIPAL
	; -----------------------
main:
	mov dword [__esp], esp

;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 10
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 0
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	20
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 20
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 1
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector1
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 2
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	30
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 30
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 2
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	vector1
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 2
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	]
;R48:	<elemento_vector> ::= <identificador> [ <exp> ]
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector1
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
;D:	;
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= main { <declaraciones> <funciones> <sentencias> }
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

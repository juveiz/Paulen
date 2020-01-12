;D:	main
segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_x resd 1
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_y resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
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

;D:	x
;R54:	<lectura> ::= scanf <identificador>
	push dword _x
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
	pop dword eax
	mov [_y], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	while
;D:	(
while_0:
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
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
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je while_fin_0
;D:	y
;D:	=
;D:	x
;D:	*
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	y
;D:	;
;R80:	<exp> ::= <identificador>
	push dword _y
;R75:	<exp> ::= <exp> * <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	imul ebx
	push dword eax
;R43:	<asignacion> ::= <identificador> = <exp>
	pop dword eax
	mov [_y], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	x
;D:	=
;D:	x
;D:	-
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R73:	<exp> ::= <exp> - <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	sub eax, ebx
	push dword eax
;R43:	<asignacion> ::= <identificador> = <exp>
	pop dword eax
	mov [_x], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R52:	<bucle> ::= while ( <exp> ) { <sentencias> }
	jmp while_0
while_fin_0:
;R41:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	printf
;D:	y
;D:	;
;R80:	<exp> ::= <identificador>
	push dword _y
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

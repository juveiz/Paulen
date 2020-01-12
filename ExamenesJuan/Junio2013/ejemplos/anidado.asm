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
;D:	x1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_x1 resd 1
;D:	,
;D:	x2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_x2 resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	y1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_y1 resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
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

;D:	x1
;R54:	<lectura> ::= scanf <identificador>
	push dword _x1
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	x2
;R54:	<lectura> ::= scanf <identificador>
	push dword _x2
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	y1
;R54:	<lectura> ::= scanf <identificador>
	push dword _y1
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	(
;D:	x1
;D:	==
;R80:	<exp> ::= <identificador>
	push dword _x1
;D:	x2
;D:	)
;R80:	<exp> ::= <identificador>
	push dword _x2
;R93:	<comparacion> ::= <exp> == <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	je igual_0
	push dword 0
	jmp fin_igual_0
igual_0:
	push dword 1
fin_igual_0:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_1
;D:	if
;D:	(
;D:	y1
;D:	)
;R80:	<exp> ::= <identificador>
	push dword _y1
;D:	{
	pop dword eax
	mov eax, [eax]
	cmp eax,0
	je if_fin_2
;D:	printf
;D:	110
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 110
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
	jmp else_fin_2
if_fin_2:
;D:	{
;D:	printf
;D:	111
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 111
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
else_fin_2:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
	jmp else_fin_1
if_fin_1:
;D:	{
;D:	if
;D:	(
;D:	y1
;D:	)
;R80:	<exp> ::= <identificador>
	push dword _y1
;D:	{
	pop dword eax
	mov eax, [eax]
	cmp eax,0
	je if_fin_3
;D:	printf
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 10
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
	jmp else_fin_3
if_fin_3:
;D:	{
;D:	printf
;D:	11
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 11
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R56:	<escritura> ::= printf <exp>
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
else_fin_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
else_fin_1:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
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

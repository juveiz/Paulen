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
;D:	,
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_z resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
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
;D:	scanf
;D:	y
;R54:	<lectura> ::= scanf <identificador>
	push dword _y
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
;R54:	<lectura> ::= scanf <identificador>
	push dword _z
	call scan_int
	add esp, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	pop dword ebx
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
;D:	&&
;D:	(
;D:	y
;D:	==
;R80:	<exp> ::= <identificador>
	push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	je igual_1
	push dword 0
	jmp fin_igual_1
igual_1:
	push dword 1
fin_igual_1:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	&&
;D:	(
;D:	z
;D:	==
;R80:	<exp> ::= <identificador>
	push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	je igual_2
	push dword 0
	jmp fin_igual_2
igual_2:
	push dword 1
fin_igual_2:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_3
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
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
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_4
	push dword 0
	jmp fin_mayor_4
mayor_4:
	push dword 1
fin_mayor_4:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_5
	push dword 0
	jmp fin_mayor_5
mayor_5:
	push dword 1
fin_mayor_5:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_6
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_7
	push dword 0
	jmp fin_mayor_7
mayor_7:
	push dword 1
fin_mayor_7:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_8
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
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
	jmp else_fin_8
if_fin_8:
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 5
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
else_fin_8:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_6:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jl menor_9
	push dword 0
	jmp fin_menor_9
menor_9:
	push dword 1
fin_menor_9:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_10
	push dword 0
	jmp fin_mayor_10
mayor_10:
	push dword 1
fin_mayor_10:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_11
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_12
	push dword 0
	jmp fin_mayor_12
mayor_12:
	push dword 1
fin_mayor_12:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_13
;D:	printf
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 2
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
	jmp else_fin_13
if_fin_13:
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 6
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
else_fin_13:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_11:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jl menor_14
	push dword 0
	jmp fin_menor_14
menor_14:
	push dword 1
fin_menor_14:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
	push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jl menor_15
	push dword 0
	jmp fin_menor_15
menor_15:
	push dword 1
fin_menor_15:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_16
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_17
	push dword 0
	jmp fin_mayor_17
mayor_17:
	push dword 1
fin_mayor_17:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_18
;D:	printf
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 3
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
	jmp else_fin_18
if_fin_18:
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 7
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
else_fin_18:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_16:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_19
	push dword 0
	jmp fin_mayor_19
mayor_19:
	push dword 1
fin_mayor_19:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= <identificador>
	push dword _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jl menor_20
	push dword 0
	jmp fin_menor_20
menor_20:
	push dword 1
fin_menor_20:
;R83:	<exp> ::= ( <comparacion> )
;R77:	<exp> ::= <exp> && <exp>
	pop dword ebx
	pop dword eax
	and eax, ebx
	push dword eax
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_21
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= <identificador>
	push dword _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	cmp eax,ebx
	jg mayor_22
	push dword 0
	jmp fin_mayor_22
mayor_22:
	push dword 1
fin_mayor_22:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_23
;D:	printf
;D:	4
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 4
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
	jmp else_fin_23
if_fin_23:
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 8
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
else_fin_23:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	}
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_21:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
else_fin_3:
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

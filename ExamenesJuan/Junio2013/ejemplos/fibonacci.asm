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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	res2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_fibonacci:
	push dword ebp
	mov dword ebp, esp
	sub esp, 8
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 8]
	push dword eax
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
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_1
;D:	return
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 0
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
	pop dword eax
	mov dword esp,ebp
	pop dword ebp
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_1:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 8]
	push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
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
;D:	)
;D:	{
	pop dword eax
	cmp eax,0
	je if_fin_3
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
	pop dword eax
	mov dword esp,ebp
	pop dword ebp
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	res1
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
if_fin_3:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	=
;D:	fibonacci
;D:	(
;D:	num1
;D:	-
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 8]
	push dword eax
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 1
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	)
;R73:	<exp> ::= <exp> - <exp>
	pop dword ebx
	pop dword eax
	mov eax, [eax]
	sub eax, ebx
	push dword eax
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_e
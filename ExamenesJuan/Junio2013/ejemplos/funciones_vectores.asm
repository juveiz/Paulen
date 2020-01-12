;D:	main
segment .data
	mensaje_1 db "Division por cero",10,0
	mensaje_2 db "Indice incorrecto de vector",10,0
segment .bss
	__esp resd 1
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_resultado resd 1
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	array
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	[
;D:	3
;D:	]
;R15	<clase_vector> ::= array <tipo> [<constante_entera>]
;R7:	<clase> ::= <clase_vector>
;D:	vector
;R108:	<identificador> ::= TOK_IDENTIFICADOR
_vector resd 3
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
segment .text
	global main
	extern scan_int, print_int, scan_float, print_float, scan_boolean, print_boolean
	extern print_endofline, print_blank, print_string
	extern alfa_malloc, alfa_free, ld_float
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	or
;D:	(
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b1
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b2
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	b3
;R27:	<parametro_funcion> ::= <tipo> <identificador>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	a
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
_or:
	push dword ebp
	mov dword ebp, esp
	sub esp, 4
;D:	=
;D:	b1
;D:	||
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 16]
	push dword eax
;D:	b2
;D:	||
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 12]
	push dword eax
;R:78	<exp> ::= <exp> || <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	mov eax, [eax]
	or eax, ebx
	push dword eax
;D:	b3
;D:	;
;R80:	<exp> ::= <identificador>
	lea eax, [ebp + 8]
	push dword eax
;R:78	<exp> ::= <exp> || <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	or eax, ebx
	push dword eax
;R43:	<asignacion> ::= <identificador> = <exp>
	lea eax, [ebp - 4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	return
;D:	a
;D:	;
;R80:	<exp> ::= <identificador>
	lea eax, [ebp - 4]
	push dword eax
;R61:	<retorno_funcion> ::= return <exp>
	pop dword eax
	mov eax, [eax]
	mov dword esp,ebp
	pop dword ebp
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<function> ::= function <tipo> <identificador> (<parametro_funcion>) {<declaraciones_funcion> <sentencias>}
;D:	vector
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <function> <funciones>
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
	push dword 0
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 0
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	true
;R102:	<constante_logica> ::= true
	push dword 1
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 1
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
	push dword 0
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
	push dword 2
	pop dword eax
	cmp eax,0
	jl error_2
	cmp eax,3
	jge error_2
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
	pop dword ebx
	pop dword eax
	mov dword [ebx], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	or
;D:	(
;D:	vector
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
;D:	,
;D:	vector
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
;D:	,
;D:	vector
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
	mov dword edx, _vector
	lea eax, [edx + eax*4]
	push dword eax
;R85:	<exp> ::= <elemento_vector>
	pop dword eax
	mov eax, [eax]
	push dword eax
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <identificador> ( <lista_expresiones> )
	call _or
	add esp, 12
	push dword eax
;D:	;
;R43:	<asignacion> ::= <identificador> = <exp>
	pop dword eax
	mov [_resultado], eax
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= <identificador>
	push dword _resultado
;R56:	<escritura> ::= printf <exp>
	pop dword eax
	mov eax, [eax]
	push dword eax
	call print_boolean
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sent
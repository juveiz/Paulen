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
;D:	printf
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
	push dword 3
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
;D:	+
;D:	x1
;D:	+
;R80:	<exp> ::= <identificador>
	push dword _x1
;R72:	<exp> ::= <exp> + <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	add eax, ebx
	push dword eax
;D:	x2
;D:	;
;R80:	<exp> ::= <identificador>
	push dword _x2
;R72:	<exp> ::= <exp> + <exp>
	pop dword ebx
	mov ebx, [ebx]
	pop dword eax
	add eax, ebx
	push dword eax
;R56:	<escritura> ::= printf <exp>
	call print_int
	add esp, 4
	call print_endofline
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
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

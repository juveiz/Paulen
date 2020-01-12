/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

  #include <stdio.h>
  #include "alfa.h"
  #include "alfa.tab.h"
  #include "generacion.h"
  #include "tablasimbolos.h"
  extern FILE* out;
  extern void yyerror(const char * s);
  extern long nline;
  int yylex();
  tablaSimbolos *tabla;
  int ambito = GLOBAL;
  CATEGORIA_SIMBOLO cat_simbolo;
  TIPO tipo;
  CATEGORIA categoria;
  int valor;
  int longitud = 1;
  int num_parametros = 0;
  int num_var_locales = 0;
  int posicion = 0;
  int posicion_parametro = 0;
  int etiqueta = 0;
  int fn_return = 0;
  int llamando_funcion = 0;
  int pila_argumentos = 0;
  TIPO fn_tipo;

#line 94 "alfa.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "alfa.tab.h".  */
#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_IDENTIFICADOR = 258,
    TOK_CONSTANTE_ENTERA = 259,
    TOK_MAIN = 260,
    TOK_INT = 261,
    TOK_BOOLEAN = 262,
    TOK_ARRAY = 263,
    TOK_FUNCTION = 264,
    TOK_IF = 265,
    TOK_ELSE = 266,
    TOK_WHILE = 267,
    TOK_SCANF = 268,
    TOK_PRINTF = 269,
    TOK_RETURN = 270,
    TOK_PUNTOYCOMA = 271,
    TOK_COMA = 272,
    TOK_PARENTESISIZQUIERDO = 273,
    TOK_PARENTESISDERECHO = 274,
    TOK_CORCHETEIZQUIERDO = 275,
    TOK_CORCHETEDERECHO = 276,
    TOK_LLAVEIZQUIERDA = 277,
    TOK_LLAVEDERECHA = 278,
    TOK_ASIGNACION = 279,
    TOK_MAS = 280,
    TOK_MENOS = 281,
    TOK_DIVISION = 282,
    TOK_ASTERISCO = 283,
    TOK_AND = 284,
    TOK_OR = 285,
    TOK_NOT = 286,
    TOK_IGUAL = 287,
    TOK_DISTINTO = 288,
    TOK_MENORIGUAL = 289,
    TOK_MAYORIGUAL = 290,
    TOK_MENOR = 291,
    TOK_MAYOR = 292,
    TOK_TRUE = 293,
    TOK_FALSE = 294,
    TOK_ERROR = 295,
    TOK_MODULO = 296,
    TOK_LONGITUD = 297
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 29 "alfa.y" /* yacc.c:355  */

 tipo_atributos atributos;

#line 181 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "alfa.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   102,   112,   116,   120,   121,   123,   125,
     126,   128,   134,   135,   137,   146,   147,   149,   150,   152,
     176,   192,   234,   235,   237,   238,   240,   247,   282,   283,
     285,   286,   288,   289,   291,   292,   293,   294,   296,   297,
     299,   344,   378,   421,   426,   432,   438,   451,   457,   470,
     476,   499,   505,   522,   539,   551,   563,   575,   587,   599,
     611,   623,   636,   670,   719,   724,   729,   735,   742,   762,
     773,   779,   781,   787,   789,   802,   815,   828,   841,   854,
     868,   872,   874,   883,   893,   903
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL", "TOK_MAYORIGUAL",
  "TOK_MENOR", "TOK_MAYOR", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR",
  "TOK_MODULO", "TOK_LONGITUD", "$accept", "programa", "inicioTabla",
  "escritura_TS", "escritura_main", "declaraciones", "declaracion",
  "clase", "clase_escalar", "tipo", "clase_vector", "identificadores",
  "funciones", "funcion", "fn_declaracion", "fn_nombre",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "idpf", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "bloque", "asignacion", "elemento_vector",
  "condicional", "if_exp_sentencias", "if_exp", "bucle", "while_exp",
  "while", "lectura", "escritura", "retorno_funcion", "exp", "aux",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -46

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,   -37,    13,    -6,   -37,    37,   -37,   -37,    33,   -37,
      37,    34,   -37,   -37,   -37,    30,    46,   -37,   -37,    47,
      45,    67,    33,   -37,    46,    39,    55,   -37,    34,    53,
      72,    39,   -37,    -2,    58,    59,    77,    75,    75,    60,
      39,    65,   -37,   -37,    61,   -37,    73,    39,   -37,    39,
      75,   -37,   -37,   -37,    33,   -37,   -37,   -37,    69,    75,
      75,    75,   -37,   -37,    16,   -37,    75,    75,    75,   -37,
     -37,    91,   -37,   -21,    75,   -37,   -37,   -37,   -21,   -37,
     -37,   -37,    75,    76,    74,    79,   113,    92,    80,    87,
     -37,   140,   -21,   130,   -37,    93,    85,     0,    64,   -37,
      75,    75,    75,    75,    75,    75,    75,    31,    88,   -21,
      39,    97,   -37,    89,   -37,   -37,    94,    33,   -37,   -37,
     102,   -37,    75,    75,    75,    75,    75,    75,   -37,     0,
       0,    64,    64,    64,     0,   -21,    75,   -37,   -37,    86,
     -37,    37,    87,   -37,   -21,   -21,   -21,   -21,   -21,   -21,
      31,   -37,   -37,   -37,   -37,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,    12,    13,     0,     4,
       6,     0,     9,    11,    10,     0,    18,     7,    85,     0,
      15,     0,     0,     5,    18,     0,     0,     8,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,     0,     0,
      30,     0,    33,    34,     0,    38,     0,     0,    39,     0,
       0,    35,    36,    37,    23,    16,    14,    21,     0,     0,
       0,     0,    49,    50,    63,    84,     0,     0,     0,    82,
      83,     0,    67,    51,    71,    64,    80,    81,    52,    19,
      31,    32,     0,     0,     0,     0,     0,     0,     0,    25,
       2,     0,    40,     0,    69,     0,     0,    58,    61,    62,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    41,
       0,    43,    47,     0,    27,    26,     0,     0,    22,    42,
       0,    65,     0,     0,     0,     0,     0,     0,    66,    53,
      54,    56,    57,    59,    60,    55,     0,    70,    68,     0,
      48,    29,    25,    46,    74,    75,    76,    77,    78,    79,
      73,    44,    28,    20,    24,    72
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,   -37,   -37,   -37,   -10,   -37,   -37,   -37,    -7,
     -37,   105,   111,   -37,   -37,   -37,   -37,   -27,    19,   -37,
     -37,   -28,   -37,   -37,   -37,   -37,   -14,   -37,   -37,   -37,
     -37,   -37,   -37,   -37,   -37,   -37,   -36,   -37,   -37,   -13,
     -37,   -37,   -37,   -37,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    16,    31,     9,    10,    11,    12,    13,
      14,    19,    23,    24,    25,    26,    88,   118,    89,   115,
     153,    39,    40,    41,    42,    43,    72,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    73,    74,   108,   137,
      96,    75,    76,    77,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    15,    78,    58,   100,   101,   102,   103,   104,   105,
       1,    44,    80,     4,    86,    30,     5,    44,    59,    84,
     106,    85,    60,    91,    92,    93,    44,   102,   103,   104,
      95,    97,    98,    44,    94,    44,    59,    18,   107,     6,
       7,   106,    33,     6,     7,     8,   109,    87,   136,    34,
      21,    35,    36,    37,    38,    22,   100,   101,   102,   103,
     104,   105,    28,    27,   129,   130,   131,   132,   133,   134,
     135,    29,   106,    54,    56,    57,    61,    62,    64,    65,
      63,    81,   139,    79,    83,    82,   144,   145,   146,   147,
     148,   149,    90,    66,    99,   114,    44,   111,   110,   116,
     150,    67,   112,   117,   128,   106,    68,   138,   -45,   151,
      87,   140,   121,    69,    70,   154,   141,    71,   100,   101,
     102,   103,   104,   105,   143,   122,   123,   124,   125,   126,
     127,   152,   113,    55,   106,    32,   142,   155,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,   120,
       0,     0,     0,     0,   106,   100,   101,   102,   103,   104,
     105,   119,     0,     0,     0,   100,   101,   102,   103,   104,
     105,   106,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   106
};

static const yytype_int16 yycheck[] =
{
      10,     8,    38,    31,    25,    26,    27,    28,    29,    30,
       5,    25,    40,     0,    50,    22,    22,    31,    20,    47,
      41,    49,    24,    59,    60,    61,    40,    27,    28,    29,
      66,    67,    68,    47,    18,    49,    20,     3,    74,     6,
       7,    41,     3,     6,     7,     8,    82,    54,    17,    10,
      20,    12,    13,    14,    15,     9,    25,    26,    27,    28,
      29,    30,    17,    16,   100,   101,   102,   103,   104,   105,
     106,     4,    41,    18,    21,     3,    18,    18,     3,     4,
       3,    16,   110,    23,    11,    24,   122,   123,   124,   125,
     126,   127,    23,    18,     3,     3,   110,    23,    22,    19,
     136,    26,    23,    16,    19,    41,    31,    19,    11,    23,
     117,    22,    19,    38,    39,   142,    22,    42,    25,    26,
      27,    28,    29,    30,    22,    32,    33,    34,    35,    36,
      37,   141,    19,    28,    41,    24,   117,   150,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    41,    25,    26,    27,    28,    29,
      30,    21,    -1,    -1,    -1,    25,    26,    27,    28,    29,
      30,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    44,    45,     0,    22,     6,     7,     8,    48,
      49,    50,    51,    52,    53,    52,    46,    48,     3,    54,
      87,    20,     9,    55,    56,    57,    58,    16,    17,     4,
      52,    47,    55,     3,    10,    12,    13,    14,    15,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    18,    54,    21,     3,    64,    20,
      24,    18,    18,     3,     3,     4,    18,    26,    31,    38,
      39,    42,    69,    79,    80,    84,    85,    86,    79,    23,
      64,    16,    24,    11,    64,    64,    79,    52,    59,    61,
      23,    79,    79,    79,    18,    79,    83,    79,    79,     3,
      25,    26,    27,    28,    29,    30,    41,    79,    81,    79,
      22,    23,    23,    19,     3,    62,    19,    16,    60,    21,
      19,    19,    32,    33,    34,    35,    36,    37,    19,    79,
      79,    79,    79,    79,    79,    79,    17,    82,    19,    64,
      22,    22,    61,    22,    79,    79,    79,    79,    79,    79,
      79,    23,    48,    63,    60,    82
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    46,    47,    48,    48,    49,    50,
      50,    51,    52,    52,    53,    54,    54,    55,    55,    56,
      57,    58,    59,    59,    60,    60,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    66,    66,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    83,    83,
      84,    84,    85,    85,    86,    87
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     0,     0,     0,     1,     2,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     2,     0,     3,
       6,     3,     2,     0,     3,     0,     2,     1,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     3,     5,     3,     5,     3,     4,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     2,     3,
       3,     2,     2,     1,     1,     3,     3,     1,     3,     2,
       2,     0,     3,     0,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 98 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");
  escribir_fin(out);
  deleteTablaSimbolos(tabla);}
#line 1405 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 102 "alfa.y" /* yacc.c:1646  */
    {
  tabla = createTablaSimbolos();
  if (tabla == NULL){
    printf("Error en la tabla de simbolos: No se ha creado la tabla de simbolos\n");
    return -1;
  }
  escribir_subseccion_data(out);
  escribir_cabecera_bss(out);
}
#line 1419 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 112 "alfa.y" /* yacc.c:1646  */
    {
  escribir_segmento_codigo(out);
}
#line 1427 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 116 "alfa.y" /* yacc.c:1646  */
    {
  escribir_inicio_main(out);
}
#line 1435 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 120 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1441 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 121 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1447 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1453 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 125 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R5:\t<clase> ::= <clase_escalar>\n"); categoria = ESCALAR;}
#line 1459 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R7:\t<clase> ::= <clase_vector>\n"); categoria = VECTOR;}
#line 1465 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 129 "alfa.y" /* yacc.c:1646  */
    {
                 fprintf(out,";R9:\t<clase_escalar> ::= <tipo>\n");
                 longitud = 1;
              }
#line 1474 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 134 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R10:\t<tipo> ::= int\n"); tipo = ENTERO;}
#line 1480 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 135 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R11:\t<tipo> ::= boolean\n"); tipo = BOOLEANO;}
#line 1486 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R15\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");
                longitud = (yyvsp[-1].atributos).valor_entero;
                if(longitud < 1 ||longitud > MAX_TAMANIO_VECTOR){
                  printf("****Error semantico en lin %li: El tamanyo del vector excede los limites permitidos (1,64).\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }}
#line 1498 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 146 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1504 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 147 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1510 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 149 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R20:\t<funciones> ::= <function> <funciones>\n");}
#line 1516 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R21:\t<funciones> ::= \n");}
#line 1522 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 153 "alfa.y" /* yacc.c:1646  */
    {
           fprintf(out,";R22:\t<function> ::= function <tipo> <identificador> (<parametro_funcion>) {<declaraciones_funcion> <sentencias>}\n");
           if (fn_return < 1){
             printf("****Error semantico en lin %li: Funcion %s sin sentencia de retorno\n",nline,(yyvsp[-2].atributos).lexema);
             deleteTablaSimbolos(tabla);
             return -1;
           }
           limpiarAmbitoLocal(tabla);
           simboloTabla * simboloTabla;
           SIMBOLO * simbolo;
           if( (simboloTabla = buscarAmbitoGlobal(tabla,(yyvsp[-2].atributos).lexema)) == NULL) {
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
           }
           simbolo = getValor(simboloTabla);
           simbolo->num_parametros=num_parametros;
           ambito = GLOBAL;
           num_parametros = 0;
           num_var_locales = 0;
           posicion_parametro = 0;
        }
#line 1549 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 177 "alfa.y" /* yacc.c:1646  */
    {
                  simboloTabla * simboloTabla;
                  SIMBOLO * simbolo;
                  if((simboloTabla = buscarAmbitoLocal(tabla,(yyvsp[-5].atributos).lexema)) == NULL) {
                    printf("****Error en la tabla de simbolos\n");
                    deleteTablaSimbolos(tabla);
                    return -1;
                  }
                  simbolo = getValor(simboloTabla);
                  simbolo->num_parametros = num_parametros;
                  simbolo->num_var_locales = num_var_locales;
                  strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
                  declararFuncion(out, (yyvsp[-5].atributos).lexema, num_var_locales);
                }
#line 1568 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 193 "alfa.y" /* yacc.c:1646  */
    {
             if (buscarAmbitoGlobal(tabla,(yyvsp[0].atributos).lexema) == NULL){
             SIMBOLO *sim;
             sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
             if(sim == NULL){
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             }
             sim->identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
             if (sim->identificador == NULL){
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             }
             strcpy(sim->identificador,(yyvsp[0].atributos).lexema);
             strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);
             sim->cat_simbolo = FUNCION;
             sim->tipo = tipo;
             sim->num_parametros = 0;
             sim->num_var_locales = 0;
             posicion = 1;
             num_var_locales = 0;
             posicion_parametro = 0;
             num_parametros = 0;
             fn_return = 0;
             fn_tipo = tipo;
             ambito = LOCAL;
             if(aperturaAmbitoLocal(tabla, (yyvsp[0].atributos).lexema, sim) == -1) {
               printf("****Error en la tabla de simbolos\n");
               deleteTablaSimbolos(tabla);
               return -1;
             };
            }
             else {
               printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
               deleteTablaSimbolos(tabla);
               return -1;
             }
           }
#line 1613 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 234 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1619 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 235 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R24:\t<parametros_funcion> ::= \n");}
#line 1625 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 237 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1631 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 238 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1637 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 241 "alfa.y" /* yacc.c:1646  */
    {
                     fprintf(out,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
                     num_parametros++;
                     posicion_parametro++;
                  }
#line 1647 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 248 "alfa.y" /* yacc.c:1646  */
    {
        if (buscarAmbitoLocal(tabla,(yyvsp[0].atributos).lexema) == NULL){
          SIMBOLO *sim;
          sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
          if(sim == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          sim->identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
          if (sim->identificador == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          strcpy(sim->identificador,(yyvsp[0].atributos).lexema);
          sim->cat_simbolo = PARAMETRO;
          sim->tipo = tipo;
          sim->categoria = ESCALAR;
          sim->valor = valor;
          sim->longitud = longitud;
          sim->posicion = posicion_parametro;
          if (insertarAmbitoLocal(tabla, (yyvsp[0].atributos).lexema, sim) == -1){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
        }else{
          printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
    }
#line 1685 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1691 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 283 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1697 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 285 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1703 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 286 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1709 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 288 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1715 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 289 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1721 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 291 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1727 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 292 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1733 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1739 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 294 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1745 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 296 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R40:\t<bloque> ::= <condicional>\n");}
#line 1751 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 297 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R41:\t<bloque> ::= <condicional>\n");}
#line 1757 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 300 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
              simboloTabla *simbolo;
              SIMBOLO *sim_aux;
              if (ambito == GLOBAL){
                if((simbolo = buscarAmbitoGlobal(tabla,(yyvsp[-2].atributos).lexema)) == NULL){
                  printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[-2].atributos).lexema);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
              }else{
                if((simbolo = buscarAmbitoLocal(tabla,(yyvsp[-2].atributos).lexema)) == NULL){
                  printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[-2].atributos).lexema);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
              }
              sim_aux = getValor(simbolo);
              if(sim_aux == NULL){
                printf("****Error en la tabla de simbolos\n");
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->cat_simbolo == FUNCION){
                printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->categoria == VECTOR){
                printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(sim_aux->tipo != (yyvsp[0].atributos).tipo){
                printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
                deleteTablaSimbolos(tabla);
                return -1;
              }
              if(ambito == GLOBAL){
                asignar(out,(yyvsp[-2].atributos).lexema,(yyvsp[0].atributos).es_direccion);
              }else{
                escribirVariableLocal(out,sim_aux->posicion);
                asignarDestinoEnPila(out,(yyvsp[0].atributos).es_direccion);
              }
            }
#line 1806 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 345 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
            simboloTabla *simbolo;
            SIMBOLO *sim_aux;
            // Revisar
            if (ambito == GLOBAL){
              if((simbolo = buscarAmbitoGlobal(tabla,(yyvsp[-2].atributos).lexema)) == NULL){
                printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[-2].atributos).lexema);
                deleteTablaSimbolos(tabla);
                return -1;
              }
            }else{
              printf("****Error semantico en lin %li: Acceso a vector en ambito local (%s)\n",nline,(yyvsp[-2].atributos).lexema);
              deleteTablaSimbolos(tabla);
              return -1;
            }
            sim_aux = getValor(simbolo);
            if(sim_aux == NULL){
              printf("****Error en la tabla de simbolos\n");
              deleteTablaSimbolos(tabla);
              return -1;
            }
            if((yyvsp[-2].atributos).tipo != (yyvsp[0].atributos).tipo){
              printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
              deleteTablaSimbolos(tabla);
              return -1;
            }
            char valor[MAX_INT];
            sprintf(valor,"%d",(yyvsp[-2].atributos).valor_entero);
            escribir_operando(out,valor,0);
            escribir_elemento_vector(out,(yyvsp[-2].atributos).lexema,sim_aux->longitud,(yyvsp[0].atributos).es_direccion);
            asignarDestinoEnPila(out,(yyvsp[0].atributos).es_direccion);
          }
#line 1843 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 379 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
          simboloTabla *simbolo;
          SIMBOLO *sim_aux;
          if (ambito == GLOBAL){
            if((simbolo = buscarAmbitoGlobal(tabla,(yyvsp[-3].atributos).lexema)) == NULL){
              printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[-3].atributos).lexema);
              deleteTablaSimbolos(tabla);
              return -1;
            }
          }else{
            printf("****Error semantico en lin %li: Acceso a vector en ambito local (%s)\n",nline,(yyvsp[-3].atributos).lexema);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          sim_aux = getValor(simbolo);
          if(sim_aux == NULL){
            printf("****Error en la tabla de simbolos\n");
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if(sim_aux->cat_simbolo == FUNCION){
            printf("****Error semantico en lin %li: Intento de indexacion de una variable que no es de tipo vector\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if(sim_aux->categoria == ESCALAR){
            printf("****Error semantico en lin %li: Intento de indexacion de una variable que no es de tipo vector\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          if((yyvsp[-1].atributos).tipo != ENTERO){
            printf("****Error semantico en lin %li: El indice en una operacion de indexacion tiene que ser de tipo entero\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }
          // Pensar si queremos que dar un numero que no corresponde de Error
          (yyval.atributos).tipo = sim_aux->tipo;
          (yyval.atributos).es_direccion = 1;
          (yyval.atributos).valor_entero = (yyvsp[-1].atributos).valor_entero;
          escribir_elemento_vector(out,sim_aux->identificador,sim_aux->longitud,(yyvsp[-1].atributos).es_direccion);
        }
#line 1889 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 422 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
                ifthen_fin(out, (yyval.atributos).etiqueta);
            }
#line 1898 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 427 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
                ifthenelse_fin(out, (yyvsp[-4].atributos).etiqueta);
            }
#line 1907 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 433 "alfa.y" /* yacc.c:1646  */
    {
                     (yyval.atributos).etiqueta = (yyvsp[-2].atributos).etiqueta;
                     ifthenelse_fin_then(out, (yyval.atributos).etiqueta);
                   }
#line 1916 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 439 "alfa.y" /* yacc.c:1646  */
    {
          if((yyvsp[-2].atributos).tipo != BOOLEANO) {
            printf("****Error semantico en lin %li: Condicional con condicion de tipo int\n",nline);
            deleteTablaSimbolos(tabla);
            return -1;
          }

          (yyval.atributos).etiqueta = etiqueta++;

          ifthen_inicio(out,(yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
        }
#line 1932 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 452 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
        while_fin(out, (yyvsp[-2].atributos).etiqueta);
      }
#line 1941 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 458 "alfa.y" /* yacc.c:1646  */
    {
             if((yyvsp[-2].atributos).tipo != BOOLEANO) {
               printf("****Error semantico en lin %li: Bucle con condicion de tipo int\n",nline);
               deleteTablaSimbolos(tabla);
               return -1;
             }

             (yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;

             while_exp_pila(out, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
           }
#line 1957 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 471 "alfa.y" /* yacc.c:1646  */
    {
         (yyval.atributos).etiqueta = etiqueta++;
         while_inicio(out, (yyval.atributos).etiqueta);
       }
#line 1966 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 477 "alfa.y" /* yacc.c:1646  */
    {
  fprintf(out,";R54:\t<lectura> ::= scanf <identificador>\n");
  simboloTabla * simboloTabla;
  SIMBOLO * simbolo;
  if(ambito == GLOBAL) simboloTabla = buscarAmbitoGlobal(tabla, (yyvsp[0].atributos).lexema);
  else simboloTabla = buscarAmbitoLocal(tabla, (yyvsp[0].atributos).lexema);

  if(simboloTabla == NULL) {
    printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[0].atributos).lexema);
    deleteTablaSimbolos(tabla);
    return -1;
  }
  simbolo = getValor(simboloTabla);
  if(simbolo->cat_simbolo == FUNCION || simbolo->categoria == VECTOR){
    printf("****Error semantico en lin %li: Categoria o clase incorrecta de (%s)\n",nline,(yyvsp[0].atributos).lexema);
    deleteTablaSimbolos(tabla);
    return -1;
  }

  leer(out, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo);
  }
#line 1992 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 500 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R56:\t<escritura> ::= printf <exp>\n");
            operandoEnPilaAArgumento(out,(yyvsp[0].atributos).es_direccion);
            escribir(out,0,(yyvsp[0].atributos).tipo);
              }
#line 2001 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 506 "alfa.y" /* yacc.c:1646  */
    {
                   if(llamando_funcion == 1){
                     printf("****Error semantico en lin %li: Sentencia de retorno fuera del cuerpo de una funcion\n",nline);
                     deleteTablaSimbolos(tabla);
                     return -1;
                   }
                   fprintf(out,";R61:\t<retorno_funcion> ::= return <exp>\n");
                   if(fn_tipo != (yyvsp[0].atributos).tipo) {
                     printf("****Error semantico en lin %li: Tipo incorrecto en retorno\n",nline);
                     deleteTablaSimbolos(tabla);
                     return -1;
                   }
                   fn_return ++;
                   retornarFuncion(out,(yyvsp[0].atributos).es_direccion);
                }
#line 2021 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 523 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R72:\t<exp> ::= <exp> + <exp>\n");
        if(((yyvsp[-2].atributos).tipo == BOOLEANO) && ((yyvsp[0].atributos).tipo == BOOLEANO)) {
          o(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
          (yyval.atributos).tipo = BOOLEANO;
          (yyval.atributos).es_direccion = 0;
        }else if (((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)){
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }else{
        sumar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
      }
    }
#line 2042 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 540 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R73:\t<exp> ::= <exp> - <exp>\n");
        if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        restar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2058 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 552 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R73:\t<exp> ::= <exp> % <exp>\n");
        if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        modulo(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2074 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 564 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R74:\t<exp> ::= <exp> / <exp>\n");
        if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        dividir(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2090 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 576 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R75:\t<exp> ::= <exp> * <exp>\n");
        if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        multiplicar(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2106 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 588 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R76:\t<exp> ::= - <exp>\n");
        if((yyvsp[0].atributos).tipo == BOOLEANO) {
          printf("****Error semantico en lin %li: Operacion aritmetica con operandos boolean\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        cambiar_signo(out, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2122 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 600 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R77:\t<exp> ::= <exp> && <exp>\n");
        if(((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)) {
          printf("****Error semantico en lin %li: Operacion logica con operandos int\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        y(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2138 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 612 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R:78\t<exp> ::= <exp> || <exp>\n");
        if(((yyvsp[-2].atributos).tipo == ENTERO) || ((yyvsp[0].atributos).tipo == ENTERO)) {
          printf("****Error semantico en lin %li: Operacion logica con operandos int\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        o(out, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2154 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 624 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R79:\t<exp> ::= ! <exp>\n");
        if((yyvsp[0].atributos).tipo == ENTERO) {
          printf("****Error semantico en lin %li: Operacion logica con operandos int\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        no(out, (yyvsp[0].atributos).es_direccion, etiqueta);
        etiqueta++;
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
    }
#line 2171 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 637 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R4444:\t<exp> ::= ^<identificador>\n");
        simboloTabla *simbolo;
        SIMBOLO *sim_aux;
        if (ambito == GLOBAL){
          if((simbolo = buscarAmbitoGlobal(tabla,(yyvsp[0].atributos).lexema)) == NULL){
            printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[0].atributos).lexema);
            deleteTablaSimbolos(tabla);
            return -1;
          }
        }else{
          if((simbolo = buscarAmbitoLocal(tabla,(yyvsp[0].atributos).lexema)) == NULL){
            printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[0].atributos).lexema);
            deleteTablaSimbolos(tabla);
            return -1;
          }
        }
        sim_aux = getValor(simbolo);
        if(sim_aux == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        if(sim_aux->categoria != VECTOR){
          printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        char valor[MAX_INT];
        sprintf(valor,"%d",sim_aux->longitud);
        escribir_operando(out,valor,0);

    }
#line 2209 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 671 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R80:\t<exp> ::= <identificador>\n");
      simboloTabla *simbolo;
      SIMBOLO *sim_aux;
      if (ambito == GLOBAL){
        if((simbolo = buscarAmbitoGlobal(tabla,(yyvsp[0].atributos).lexema)) == NULL){
          printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[0].atributos).lexema);
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }else{
        if((simbolo = buscarAmbitoLocal(tabla,(yyvsp[0].atributos).lexema)) == NULL){
          printf("****Error semantico en lin %li: Acceso a variable no declarada (%s)\n",nline,(yyvsp[0].atributos).lexema);
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }
      sim_aux = getValor(simbolo);
      if(sim_aux == NULL){
        printf("****Error en la tabla de simbolos\n");
        deleteTablaSimbolos(tabla);
        return -1;
      }
      if(sim_aux->cat_simbolo == FUNCION){
        printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
      if(sim_aux->categoria == VECTOR){
        printf("****Error semantico en lin %li: Asignacion incompatible\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
      (yyval.atributos).tipo = sim_aux->tipo;
      (yyval.atributos).es_direccion = 1;
      if (sim_aux->cat_simbolo == PARAMETRO){
        escribirParametro(out,sim_aux->posicion,num_parametros);
      }else if (sim_aux->cat_simbolo == VARIABLE){
        if(ambito == LOCAL) {
          escribirVariableLocal(out,sim_aux->posicion);
        }
        else {
          escribir_operando(out,(yyvsp[0].atributos).lexema,1);
          if(llamando_funcion == 1) {
            operandoEnPilaAArgumento(out,1);
          }
        }
      }
    }
#line 2262 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 720 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R81:\t<exp> ::= <constante>\n");
      (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
      (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
    }
#line 2271 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 725 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R82:\t<exp> ::= ( <exp> )\n");
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
      (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
    }
#line 2280 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 730 "alfa.y" /* yacc.c:1646  */
    {
      fprintf(out,";R83:\t<exp> ::= ( <comparacion> )\n");
      (yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
      (yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;
    }
#line 2290 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 736 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(out,";R85:\t<exp> ::= <elemento_vector>\n");
        if(llamando_funcion == 1) {
          operandoEnPilaAArgumento(out,1);
        }
    }
#line 2301 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 743 "alfa.y" /* yacc.c:1646  */
    {
        simboloTabla * simboloTabla;
        SIMBOLO * simbolo;
        fprintf(out,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
        if((simboloTabla = buscarAmbitoGlobal(tabla, (yyvsp[-2].atributos).lexema)) == NULL) {
          printf("****Error semantico en lin %li: La funcion no existe\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        simbolo = getValor(simboloTabla);
        if(pila_argumentos != simbolo->num_parametros){
          printf("****Error semantico en lin %li: Numero incorrecto de parametros en llamada a funcion\n",nline);
        }
        (yyval.atributos).tipo = simbolo->tipo;
        llamarFuncion(out, (yyvsp[-2].atributos).lexema, simbolo->num_parametros);
        limpiarPila(out, simbolo->num_parametros);
        llamando_funcion = 0;
    }
#line 2324 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 762 "alfa.y" /* yacc.c:1646  */
    {
    if(llamando_funcion == 1){
      printf("****Error semantico en lin %li: No esta permitido el uso de llamadas a funciones como parametros de otras funciones\n",nline);
      deleteTablaSimbolos(tabla);
      return -1;
    }
    pila_argumentos = 0;
    strcpy((yyval.atributos).lexema, (yyvsp[-1].atributos).lexema);
    llamando_funcion = 1;
}
#line 2339 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 773 "alfa.y" /* yacc.c:1646  */
    {
                  fprintf(out,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                  if(llamando_funcion == 1) {
                    pila_argumentos++;
                  }
                }
#line 2350 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 779 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R90:\t<lista_expresiones> ::= \n");}
#line 2356 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 781 "alfa.y" /* yacc.c:1646  */
    {
                          fprintf(out,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");
                          if(llamando_funcion == 1) {
                            pila_argumentos++;
                          }
                        }
#line 2367 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 787 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 2373 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 790 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R93:\t<comparacion> ::= <exp> == <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                igual(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2390 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 803 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R94:\t<comparacion> ::= <exp> != <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                distinto(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2407 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 816 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R95:\t<comparacion> ::= <exp> <= <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                menor_igual(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2424 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 829 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R96:\t<comparacion> ::= <exp> >= <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                mayor_igual(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2441 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 842 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R97:\t<comparacion> ::= <exp> < <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                menor(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2458 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 855 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(out,";R98:\t<comparacion> ::= <exp> > <exp>\n");
                if(((yyvsp[-2].atributos).tipo == BOOLEANO) || ((yyvsp[0].atributos).tipo == BOOLEANO)) {
                  printf("****Error semantico en lin %li: Comparacion con operandos boolean\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }
                mayor(out, (yyvsp[-2].atributos).es_direccion , (yyvsp[0].atributos).es_direccion ,etiqueta);
                etiqueta ++;
                (yyval.atributos).tipo = BOOLEANO;
                (yyval.atributos).es_direccion = 0;
            }
#line 2475 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 869 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R99:\t<constante> ::= <constante_logica>\n");
            (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
            (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;}
#line 2483 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 872 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R100:\t<constante> ::= <constante_entera>\n");}
#line 2489 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 875 "alfa.y" /* yacc.c:1646  */
    {
                     fprintf(out,";R102:\t<constante_logica> ::= true\n");
                     (yyval.atributos).tipo = BOOLEANO;
                     (yyval.atributos).es_direccion = 0;
                     char valor[MAX_INT];
                     sprintf(valor,"1");
                     escribir_operando(out,valor,0);
                  }
#line 2502 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 884 "alfa.y" /* yacc.c:1646  */
    {
                     fprintf(out,";R103:\t<constante_logica> ::= false\n");
                     (yyval.atributos).tipo = BOOLEANO;
                     (yyval.atributos).es_direccion = 0;
                     char valor[MAX_INT];
                     sprintf(valor,"0");
                     escribir_operando(out,valor,0);
                  }
#line 2515 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 894 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
    (yyval.atributos).tipo = ENTERO;
    (yyval.atributos).es_direccion = 0;
    (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
    char valor[MAX_INT];
    sprintf(valor,"%d",(yyval.atributos).valor_entero);
    escribir_operando(out,valor,0);
    }
#line 2528 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 904 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    if (ambito == GLOBAL){
      if (buscarAmbitoGlobal(tabla,(yyvsp[0].atributos).lexema) == NULL){
        SIMBOLO *sim;
        sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
        if(sim == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        sim->identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
        if (sim->identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim->identificador,(yyvsp[0].atributos).lexema);
        sim->cat_simbolo = cat_simbolo;
        sim->tipo = tipo;
        sim->categoria = categoria;
        sim->valor = valor;
        sim->longitud = longitud;
        sim->num_parametros = num_parametros;
        sim->posicion = posicion;
        if (insertarAmbitoGlobal(tabla, (yyvsp[0].atributos).lexema, sim) == -1){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        declarar_variable(out,(yyvsp[0].atributos).lexema,sim->tipo,sim->longitud);
      }else{
        printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
    }else{
      if (buscarAmbitoLocal(tabla,(yyvsp[0].atributos).lexema) == NULL){
        SIMBOLO *sim;
        sim = (SIMBOLO*)malloc(sizeof(SIMBOLO));
        if(sim == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        sim->identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
        if (sim->identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        if (categoria != ESCALAR){
          printf("****Error semantico en lin %li: Variable local de tipo no escalar.\n",nline);
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim->identificador,(yyvsp[0].atributos).lexema);
        sim->cat_simbolo = cat_simbolo;
        sim->tipo = tipo;
        sim->categoria = categoria;
        sim->valor = valor;
        sim->longitud = longitud;
        sim->num_parametros = num_parametros;
        sim->posicion = posicion;
        num_var_locales++;
        sim->num_var_locales = num_var_locales;
        posicion++;
        if (insertarAmbitoLocal(tabla, (yyvsp[0].atributos).lexema, sim) == -1){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }else{
        printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
    }
  }
#line 2611 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 2615 "alfa.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}

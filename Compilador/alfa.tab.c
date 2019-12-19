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
  int longitud;
  int num_parametros;
  int posicion = 1;


#line 88 "alfa.tab.c" /* yacc.c:339  */

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
    TOK_ERROR = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "alfa.y" /* yacc.c:355  */

 tipo_atributos atributos;

#line 173 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "alfa.tab.c" /* yacc.c:358  */

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
#define YYLAST   167

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  145

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    74,    74,    77,    85,    91,    97,   101,   102,   104,
     106,   107,   109,   111,   112,   114,   123,   124,   126,   127,
     129,   132,   133,   135,   136,   138,   140,   141,   143,   144,
     146,   147,   149,   150,   151,   152,   154,   155,   157,   158,
     160,   162,   163,   166,   169,   171,   173,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   190,   191,   193,   194,   196,   197,   198,   199,   200,
     201,   203,   204,   206,   207,   209,   211
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
  "$accept", "programa", "inicioTabla", "escritura_TS", "escritura_main",
  "escribir_fin", "declaraciones", "declaracion", "clase", "clase_escalar",
  "tipo", "clase_vector", "identificadores", "funciones", "funcion",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador", YY_NULLPTR
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
     295
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -39,     5,    -9,   -39,    27,   -39,   -39,    24,   -39,
      27,    16,   -39,   -39,   -39,     1,    37,   -39,   -39,    20,
      30,    44,    24,   -39,    37,   -39,    16,    29,    16,   103,
     -39,   -39,   -39,    33,    34,    43,    16,     6,     6,    47,
     103,    46,   -39,   -39,    54,   -39,   -39,   -39,   -39,   -39,
     -13,    24,     6,     6,   -39,   -39,     6,     6,     6,   -39,
     -39,   -39,   137,   -39,   -39,   -39,    -4,   137,   -39,   -39,
     -39,     6,     6,     6,    16,    61,    63,   119,   131,   100,
      64,    11,   -39,     6,     6,     6,     6,     6,     6,     6,
     -39,   137,    39,   137,   -39,    62,    24,   -39,    73,    74,
     -39,     6,     6,     6,     6,     6,     6,   -39,    11,    11,
     -39,   -39,   -39,    11,    60,    79,   -39,    27,    63,   103,
     103,   137,   137,   137,   137,   137,   137,     6,   -39,   -39,
     -39,   103,   -39,    76,    77,    60,    78,    91,   -39,   -39,
     -39,    83,   103,    84,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     3,     0,     0,     1,     0,    13,    14,     0,     4,
       7,     0,    10,    12,    11,     0,    19,     8,    76,     0,
      16,     0,     0,     5,    19,     9,     0,     0,     0,     0,
      18,    17,    15,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    31,    32,     0,    36,    37,    33,    34,    35,
       0,    22,     0,     0,    44,    75,     0,     0,     0,    73,
      74,    59,    45,    56,    71,    72,    55,    46,     6,    29,
      30,     0,     0,     0,     0,     0,    24,     0,     0,     0,
       0,    51,    54,     0,     0,     0,     0,     0,     0,    62,
       2,    39,     0,    38,    25,     0,     0,    21,     0,     0,
      57,     0,     0,     0,     0,     0,     0,    58,    47,    48,
      49,    50,    52,    53,    64,     0,    40,    27,    24,     0,
       0,    65,    66,    67,    68,    69,    70,     0,    61,    60,
      26,     0,    23,     0,     0,    64,     0,    41,    43,    63,
      20,     0,     0,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -39,   -39,   -39,   -39,   -39,    -7,   -39,   -39,   -39,
      -2,   -39,    85,    88,   -39,   -39,     3,    26,   -39,   -38,
     -39,   -39,   -39,   -39,   -28,   -39,   -39,   -39,   -39,   -39,
     -30,   -39,   -12,   -39,   -39,   -39,   -39,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    16,    29,    90,     9,    10,    11,    12,
      13,    14,    19,    23,    24,    75,    97,    76,   131,    39,
      40,    41,    42,    43,    61,    45,    46,    47,    48,    49,
      62,   115,   128,    80,    63,    64,    65,    66
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      20,    44,    69,    17,     1,     4,    15,    72,    67,    18,
      55,    73,    44,     5,    89,    20,    72,    33,    50,    18,
      28,    21,    77,    78,    56,    54,    79,    81,    82,    50,
       6,     7,    57,     6,     7,     8,    25,    58,    85,    86,
      87,    91,    92,    93,    59,    60,    22,    26,    27,    74,
      32,    51,    52,   108,   109,   110,   111,   112,   113,   114,
     116,    53,    70,    94,    83,    84,    85,    86,    87,    88,
      68,   121,   122,   123,   124,   125,   126,   127,    71,    96,
      95,   133,   134,   107,   117,    83,    84,    85,    86,    87,
      88,    44,    44,   136,    74,   119,   120,   135,   129,   137,
     138,   140,   141,    44,   143,   142,    18,   144,    50,    50,
     130,    31,    30,    34,    44,    35,    36,    37,    38,   100,
      50,   132,   118,   139,     0,    83,    84,    85,    86,    87,
      88,    50,   101,   102,   103,   104,   105,   106,    98,     0,
       0,     0,     0,     0,    83,    84,    85,    86,    87,    88,
      99,     0,     0,     0,     0,     0,    83,    84,    85,    86,
      87,    88,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
      11,    29,    40,    10,     5,     0,     8,    20,    38,     3,
       4,    24,    40,    22,    18,    26,    20,    28,    29,     3,
      22,    20,    52,    53,    18,    36,    56,    57,    58,    40,
       6,     7,    26,     6,     7,     8,    16,    31,    27,    28,
      29,    71,    72,    73,    38,    39,     9,    17,     4,    51,
      21,    18,    18,    83,    84,    85,    86,    87,    88,    89,
      21,    18,    16,    74,    25,    26,    27,    28,    29,    30,
      23,   101,   102,   103,   104,   105,   106,    17,    24,    16,
      19,   119,   120,    19,    22,    25,    26,    27,    28,    29,
      30,   119,   120,   131,    96,    22,    22,   127,    19,    23,
      23,    23,    11,   131,   142,    22,     3,    23,   119,   120,
     117,    26,    24,    10,   142,    12,    13,    14,    15,    19,
     131,   118,    96,   135,    -1,    25,    26,    27,    28,    29,
      30,   142,    32,    33,    34,    35,    36,    37,    19,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      19,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    28,
      29,    30,    25,    26,    27,    28,    29,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    42,    43,     0,    22,     6,     7,     8,    47,
      48,    49,    50,    51,    52,    51,    44,    47,     3,    53,
      78,    20,     9,    54,    55,    16,    17,     4,    51,    45,
      54,    53,    21,    78,    10,    12,    13,    14,    15,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      78,    18,    18,    18,    78,     4,    18,    26,    31,    38,
      39,    65,    71,    75,    76,    77,    78,    71,    23,    60,
      16,    24,    20,    24,    51,    56,    58,    71,    71,    71,
      74,    71,    71,    25,    26,    27,    28,    29,    30,    18,
      46,    71,    71,    71,    78,    19,    16,    57,    19,    19,
      19,    32,    33,    34,    35,    36,    37,    19,    71,    71,
      71,    71,    71,    71,    71,    72,    21,    22,    58,    22,
      22,    71,    71,    71,    71,    71,    71,    17,    73,    19,
      47,    59,    57,    60,    60,    71,    60,    23,    23,    73,
      23,    11,    22,    60,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    44,    45,    46,    47,    47,    48,
      49,    49,    50,    51,    51,    52,    53,    53,    54,    54,
      55,    56,    56,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    62,    62,    62,    62,    63,    63,    64,    64,
      65,    66,    66,    67,    68,    69,    70,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    75,    75,    76,    76,    77,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     0,     0,     0,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     3,     2,     0,
      10,     2,     0,     3,     0,     2,     1,     0,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       4,     7,    11,     7,     2,     2,     2,     3,     3,     3,
       3,     2,     3,     3,     2,     1,     1,     3,     3,     1,
       4,     2,     0,     3,     0,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1
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
#line 75 "alfa.y" /* yacc.c:1646  */
    {fprintf(out, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");}
#line 1381 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 77 "alfa.y" /* yacc.c:1646  */
    {
  tabla = createTablaSimbolos();
  if (tabla == NULL){
    printf("Error en la tabla de simbolos: No se ha creado la tabla de simbolos\n");
    return -1;
  }
}
#line 1393 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 85 "alfa.y" /* yacc.c:1646  */
    {
  escribir_subseccion_data(out);
  escribir_cabecera_bss(out);
  // Faltan cosas como se cogen
}
#line 1403 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "alfa.y" /* yacc.c:1646  */
    {
  escribir_segmento_codigo(out);
  //creo faltan funciones
  escribir_inicio_main(out);
}
#line 1413 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "alfa.y" /* yacc.c:1646  */
    {
  escribir_fin(out);
  deleteTablaSimbolos(tabla);
}
#line 1422 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R2:\t<declaraciones> ::= <declaracion>\n");}
#line 1428 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 102 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");}
#line 1434 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 104 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");}
#line 1440 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R5:\t<clase> ::= <clase_escalar>\n"); categoria = ESCALAR;}
#line 1446 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R7:\t<clase> ::= <clase_vector>\n"); categoria = VECTOR;}
#line 1452 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R9:\t<clase_escalar> ::= <tipo>\n");}
#line 1458 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 111 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R10:\t<tipo> ::= int\n"); tipo = ENTERO;}
#line 1464 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R11:\t<tipo> ::= boolean\n"); tipo = BOOLEANO;}
#line 1470 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R15\t<clase_vector> ::= array <tipo> [<constante_entera>]\n");
                longitud = (yyvsp[-1].atributos).valor_entero;
                if(longitud < 1 ||longitud > MAX_TAMANIO_VECTOR){
                  printf("****Error semantico en lin %li: El tamanyo del vector excede los limites permitidos (1,64).\n",nline);
                  deleteTablaSimbolos(tabla);
                  return -1;
                }}
#line 1482 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R18:\t<identificadores> ::= <identificador>\n");}
#line 1488 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 124 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1494 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 126 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R20:\t<funciones> ::= <function> <funciones>\n");}
#line 1500 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 127 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R21:\t<funciones> ::= \n");}
#line 1506 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R22:\t<function> ::= function <tipo> <identificador> (<parametro_funcion>) {<declaraciones_funcion> <sentencias>}\n");}
#line 1512 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 132 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1518 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 133 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R24:\t<parametros_funcion> ::= \n");}
#line 1524 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 135 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1530 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 136 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R26:\t<resto_parametros_funcion> ::= \n");}
#line 1536 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 138 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");}
#line 1542 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 140 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");}
#line 1548 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 141 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R29:\t<declaraciones_funcion> ::= \n");}
#line 1554 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 143 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R30:\t<sentencias> ::= <sentencia>\n");}
#line 1560 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 144 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");}
#line 1566 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 146 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R32:\t<sentencia> ::= <sentencia_simple> ;\n");}
#line 1572 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 147 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R33:\t<sentencia> ::= <bloque>\n");}
#line 1578 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 149 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R34:\t<sentencia_simple> ::= <asignacion>\n");}
#line 1584 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 150 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R35:\t<sentencia_simple> ::= <lectura>\n");}
#line 1590 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 151 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R36:\t<sentencia_simple> ::= <escritura>\n");}
#line 1596 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 152 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");}
#line 1602 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 154 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R40:\t<bloque> ::= <condicional>\n");}
#line 1608 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 155 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R41:\t<bloque> ::= <condicional>\n");}
#line 1614 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 157 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R43:\t<asignacion> ::= <identificador> = <exp>\n");}
#line 1620 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 158 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");}
#line 1626 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 160 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");}
#line 1632 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 162 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");}
#line 1638 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 164 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");}
#line 1644 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 167 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");}
#line 1650 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 169 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R54:\t<lectura> ::= scanf <identificador>\n");}
#line 1656 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 171 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R56:\t<escritura> ::= printf <exp>\n");}
#line 1662 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 173 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R61:\t<retorno_funcion> ::= return <exp>\n");}
#line 1668 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 175 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R72:\t<exp> ::= <exp> + <exp>\n");}
#line 1674 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 176 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R73:\t<exp> ::= <exp> - <exp>\n");}
#line 1680 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 177 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R74:\t<exp> ::= <exp> / <exp>\n");}
#line 1686 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 178 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R75:\t<exp> ::= <exp> * <exp>\n");}
#line 1692 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 179 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R76:\t<exp> ::= - <exp>\n");}
#line 1698 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 180 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R77:\t<exp> ::= <exp> && <exp>\n");}
#line 1704 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 181 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R:78\t<exp> ::= <exp> || <exp>\n");}
#line 1710 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 182 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R79:\t<exp> ::= ! <exp>\n");}
#line 1716 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 183 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R80:\t<exp> ::= <identificador>\n");}
#line 1722 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 184 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R81:\t<exp> ::= <constante>\n");}
#line 1728 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 185 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R82:\t<exp> ::= ( <exp> )\n");}
#line 1734 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 186 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R83:\t<exp> ::= ( <comparacion> )\n");}
#line 1740 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 187 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R85:\t<exp> ::= <elemento_vector>\n");}
#line 1746 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 188 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 1752 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 190 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");}
#line 1758 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 191 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R90:\t<lista_expresiones> ::= \n");}
#line 1764 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 193 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");}
#line 1770 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 194 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R92:\t<resto_lista_expresiones> ::= \n");}
#line 1776 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 196 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R93:\t<comparacion> ::= <exp> == <exp>\n");}
#line 1782 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 197 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R94:\t<comparacion> ::= <exp> != <exp>\n");}
#line 1788 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 198 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R95:\t<comparacion> ::= <exp> <= <exp>\n");}
#line 1794 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 199 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R96:\t<comparacion> ::= <exp> >= <exp>\n");}
#line 1800 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 200 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R97:\t<comparacion> ::= <exp> < <exp>\n");}
#line 1806 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 201 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R98:\t<comparacion> ::= <exp> > <exp>\n");}
#line 1812 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 203 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R99:\t<constante> ::= <constante_logica>\n");}
#line 1818 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 204 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R100:\t<constante> ::= <constante_entera>\n");}
#line 1824 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 206 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R102:\t<constante_logica> ::= true\n");}
#line 1830 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 207 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R103:\t<constante_logica> ::= false\n");}
#line 1836 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 209 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");}
#line 1842 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 212 "alfa.y" /* yacc.c:1646  */
    {fprintf(out,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
    if (ambito == GLOBAL){
      if (buscarAmbitoGlobal(tabla,(yyvsp[0].atributos).lexema) == NULL){
        SIMBOLO sim;
        sim.identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
        if (sim.identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim.identificador,(yyvsp[0].atributos).lexema);
        sim.cat_simbolo = cat_simbolo;
        sim.tipo = tipo;
        sim.categoria = categoria;
        sim.valor = valor;
        sim.longitud = longitud;
        sim.num_parametros = num_parametros;
        sim.posicion = posicion;
        if (insertarAmbitoGlobal(tabla, (yyvsp[0].atributos).lexema,&sim) == -1){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
      }else{
        printf("****Error semantico en lin %li: Declaracion duplicada.\n",nline);
        deleteTablaSimbolos(tabla);
        return -1;
      }
    }else{
      if (buscarAmbitoLocal(tabla,(yyvsp[0].atributos).lexema) == NULL){
        if (categoria != ESCALAR){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        SIMBOLO sim;
        posicion ++;
        sim.identificador = (char*)malloc(sizeof(char)*(strlen((yyvsp[0].atributos).lexema) + 1));
        if (sim.identificador == NULL){
          printf("****Error en la tabla de simbolos\n");
          deleteTablaSimbolos(tabla);
          return -1;
        }
        strcpy(sim.identificador,(yyvsp[0].atributos).lexema);
        sim.cat_simbolo = cat_simbolo;
        sim.tipo = tipo;
        sim.categoria = categoria;
        sim.valor = valor;
        sim.longitud = longitud;
        // Revisar las dos siguientes
        sim.num_parametros = num_parametros;
        sim.posicion = posicion;
        if (insertarAmbitoLocal(tabla, (yyvsp[0].atributos).lexema,&sim) == -1){
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
#line 1911 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 1915 "alfa.tab.c" /* yacc.c:1646  */
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

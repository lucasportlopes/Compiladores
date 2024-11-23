/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

// LUCAS PORTELA LOPES - 00323986
// VINICIUS MATTE MEDEIROS - 00330087
int yylex(void);
void yyerror (char const *mensagem);
#include <stdio.h>
#include <string.h>
#include "symbol_stack.h"
extern int get_line_number();
extern void *arvore;
extern symbol_stack_t *stack;

#line 84 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_IF = 5,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 6,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 7,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 8,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 9,                   /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 10,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 11,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 12,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 13,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 14,                  /* TK_OC_OR  */
  YYSYMBOL_TK_IDENTIFICADOR = 15,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 16,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 17,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_ERRO = 18,                   /* TK_ERRO  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '>'  */
  YYSYMBOL_21_ = 21,                       /* '<'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '{'  */
  YYSYMBOL_24_ = 24,                       /* '}'  */
  YYSYMBOL_25_ = 25,                       /* ';'  */
  YYSYMBOL_26_ = 26,                       /* ','  */
  YYSYMBOL_27_ = 27,                       /* '('  */
  YYSYMBOL_28_ = 28,                       /* ')'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* '%'  */
  YYSYMBOL_33_ = 33,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_programa = 35,                  /* programa  */
  YYSYMBOL_lista_funcoes = 36,             /* lista_funcoes  */
  YYSYMBOL_funcao = 37,                    /* funcao  */
  YYSYMBOL_cabecalho_funcao = 38,          /* cabecalho_funcao  */
  YYSYMBOL_abre_escopo = 39,               /* abre_escopo  */
  YYSYMBOL_fecha_escopo = 40,              /* fecha_escopo  */
  YYSYMBOL_empty = 41,                     /* empty  */
  YYSYMBOL_tipo = 42,                      /* tipo  */
  YYSYMBOL_lista_parametros = 43,          /* lista_parametros  */
  YYSYMBOL_parametro = 44,                 /* parametro  */
  YYSYMBOL_bloco_comandos = 45,            /* bloco_comandos  */
  YYSYMBOL_comandos = 46,                  /* comandos  */
  YYSYMBOL_comando_simples = 47,           /* comando_simples  */
  YYSYMBOL_declaracao_variavel = 48,       /* declaracao_variavel  */
  YYSYMBOL_lista_variaveis = 49,           /* lista_variaveis  */
  YYSYMBOL_atribuicao = 50,                /* atribuicao  */
  YYSYMBOL_operacao_retorno = 51,          /* operacao_retorno  */
  YYSYMBOL_chamada_funcao = 52,            /* chamada_funcao  */
  YYSYMBOL_lista_argumentos = 53,          /* lista_argumentos  */
  YYSYMBOL_fluxo_controle = 54,            /* fluxo_controle  */
  YYSYMBOL_expressao = 55,                 /* expressao  */
  YYSYMBOL_expressao_precedencia_6 = 56,   /* expressao_precedencia_6  */
  YYSYMBOL_expressao_precedencia_5 = 57,   /* expressao_precedencia_5  */
  YYSYMBOL_expressao_precedencia_4 = 58,   /* expressao_precedencia_4  */
  YYSYMBOL_expressao_precedencia_3 = 59,   /* expressao_precedencia_3  */
  YYSYMBOL_expressao_precedencia_2 = 60,   /* expressao_precedencia_2  */
  YYSYMBOL_expressao_precedencia_1 = 61,   /* expressao_precedencia_1  */
  YYSYMBOL_literal = 62,                   /* literal  */
  YYSYMBOL_operandos_simples = 63          /* operandos_simples  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

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
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   273


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,     2,     2,    32,     2,     2,
      27,    28,    30,    29,    26,    22,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
      21,    19,    20,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,    24,     2,     2,     2,     2,
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
      15,    16,    17,    18
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    68,    68,    76,    77,    86,    95,   110,   112,   114,
     117,   117,   121,   122,   123,   127,   132,   136,   137,   164,
     165,   166,   167,   168,   169,   173,   178,   187,   188,   194,
     198,   214,   218,   245,   248,   255,   262,   272,   282,   283,
     292,   293,   302,   303,   309,   318,   319,   320,   326,   332,
     341,   342,   348,   357,   358,   364,   370,   378,   379,   380,
     381,   385,   386,   390,   391,   402
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_RETURN",
  "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_IDENTIFICADOR", "TK_LIT_INT", "TK_LIT_FLOAT", "TK_ERRO", "'='",
  "'>'", "'<'", "'-'", "'{'", "'}'", "';'", "','", "'('", "')'", "'+'",
  "'*'", "'/'", "'%'", "'!'", "$accept", "programa", "lista_funcoes",
  "funcao", "cabecalho_funcao", "abre_escopo", "fecha_escopo", "empty",
  "tipo", "lista_parametros", "parametro", "bloco_comandos", "comandos",
  "comando_simples", "declaracao_variavel", "lista_variaveis",
  "atribuicao", "operacao_retorno", "chamada_funcao", "lista_argumentos",
  "fluxo_controle", "expressao", "expressao_precedencia_6",
  "expressao_precedencia_5", "expressao_precedencia_4",
  "expressao_precedencia_3", "expressao_precedencia_2",
  "expressao_precedencia_1", "literal", "operandos_simples", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-88)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      12,    10,    48,   -88,    12,    31,   -88,   -88,   -88,   -88,
     -88,   -88,    45,     5,    47,   -88,    55,    62,   -88,   -88,
      50,    51,    -1,    34,   -88,    64,    56,   -88,     5,    57,
      58,    59,    60,    61,    65,    39,    45,    -1,    -1,    66,
     -88,   -88,    -1,    -1,    -1,   -88,    74,    67,    52,    29,
      33,    35,   -88,   -88,   -88,    -1,    -1,    15,   -88,   -88,
      68,   -88,   -88,   -88,   -88,   -88,   -88,    39,   -88,   -88,
      -3,    19,   -88,    23,   -88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    69,
      26,    53,    64,   -88,   -88,    31,    31,   -88,    67,    52,
      29,    29,    33,    33,    33,    33,    35,    35,   -88,   -88,
     -88,   -88,    -1,    63,   -88,    88,   -88,   -88,    64,    31,
     -88,   -88
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       9,     0,     0,     2,     9,     0,     3,     7,     1,     4,
       7,     5,     9,     9,     0,    12,     0,    14,    10,    11,
       0,     0,     0,     0,    17,     0,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,    64,
      61,    62,     0,     0,     0,    65,    31,    38,    40,    42,
      45,    50,    53,    63,    57,     0,     0,    29,    25,    23,
       0,    18,    19,    20,    22,    24,    21,     0,     6,    13,
       0,     0,    59,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
      33,     0,     0,    16,    15,     0,     0,    58,    39,    41,
      43,    44,    48,    49,    47,    46,    52,    51,    54,    55,
      56,    32,     0,    28,    27,    35,    37,    34,     0,     0,
      26,    36
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    91,   -88,   -88,    86,   -88,    -6,   -31,    70,
     -88,    -5,    71,   -88,   -88,   -87,   -88,   -88,     6,   -14,
     -88,   -20,    25,    27,    -4,   -23,   -12,   -41,    11,   -88
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     4,     5,    12,    60,     6,    25,    16,
      17,    26,    27,    28,    29,    58,    30,    31,    45,    89,
      33,    90,    47,    48,    49,    50,    51,    52,    53,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      11,    72,    46,    74,    68,   114,    15,    24,    18,    19,
      20,    75,    21,    22,    39,    40,    41,    70,    71,    32,
      23,    42,    24,    73,    91,    95,    43,     1,    10,     7,
      15,   120,    44,    75,    32,    88,    94,    75,    79,    80,
      75,    92,    18,    19,   108,   109,   110,    96,     8,    81,
      82,    97,   112,    55,    10,    83,   102,   103,   104,   105,
      14,    56,    84,    77,    78,    85,    86,    87,    34,    40,
      41,   106,   107,   100,   101,    35,    36,    37,    38,    57,
      76,    59,    62,    63,    64,    65,    66,    67,    75,   118,
     115,   116,    93,    56,   119,     9,    13,   111,   117,    61,
      98,     0,   113,    99,     0,     0,    69,     0,     0,     0,
       0,     0,     0,     0,   121
};

static const yytype_int8 yycheck[] =
{
       5,    42,    22,    44,    35,    92,    12,    13,     3,     4,
       5,    14,     7,     8,    15,    16,    17,    37,    38,    13,
      15,    22,    28,    43,     9,    28,    27,    15,    23,    19,
      36,   118,    33,    14,    28,    55,    67,    14,     9,    10,
      14,    26,     3,     4,    85,    86,    87,    28,     0,    20,
      21,    28,    26,    19,    23,    22,    79,    80,    81,    82,
      15,    27,    29,    11,    12,    30,    31,    32,    21,    16,
      17,    83,    84,    77,    78,    20,    14,    27,    27,    15,
      13,    25,    25,    25,    25,    25,    25,    22,    14,    26,
      95,    96,    24,    27,     6,     4,    10,    28,   112,    28,
      75,    -1,    91,    76,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   119
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    15,    35,    36,    37,    38,    41,    19,     0,    36,
      23,    45,    39,    39,    15,    41,    43,    44,     3,     4,
       5,     7,     8,    15,    41,    42,    45,    46,    47,    48,
      50,    51,    52,    54,    21,    20,    14,    27,    27,    15,
      16,    17,    22,    27,    33,    52,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    19,    27,    15,    49,    25,
      40,    46,    25,    25,    25,    25,    25,    22,    42,    43,
      55,    55,    61,    55,    61,    14,    13,    11,    12,     9,
      10,    20,    21,    22,    29,    30,    31,    32,    55,    53,
      55,     9,    26,    24,    42,    28,    28,    28,    56,    57,
      58,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      61,    28,    26,    62,    49,    45,    45,    53,    26,     6,
      49,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    38,    39,    40,    41,
      42,    42,    43,    43,    43,    44,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    48,    49,    49,    49,    49,
      50,    51,    52,    53,    53,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    60,    60,    60,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     0,     0,     0,
       1,     1,     1,     3,     1,     4,     5,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     5,     3,     3,     1,
       3,     2,     4,     1,     3,     5,     7,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     2,
       2,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* programa: lista_funcoes  */
#line 68 "parser.y"
                  { 
        symbol_table_t *escopo_global = symbol_table_create(NULL);
        stack = symbol_stack_create(escopo_global);
        (yyval.arvore_t) = (yyvsp[0].arvore_t); arvore = (yyval.arvore_t); 
    }
#line 1488 "parser.tab.c"
    break;

  case 3: /* lista_funcoes: empty  */
#line 76 "parser.y"
          { (yyval.arvore_t) = NULL; }
#line 1494 "parser.tab.c"
    break;

  case 4: /* lista_funcoes: funcao lista_funcoes  */
#line 77 "parser.y"
                           {
        (yyval.arvore_t) = (yyvsp[-1].arvore_t);
        if ((yyvsp[0].arvore_t) != NULL) {
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t));
        }
    }
#line 1505 "parser.tab.c"
    break;

  case 5: /* funcao: cabecalho_funcao bloco_comandos  */
#line 86 "parser.y"
                                    {
        (yyval.arvore_t) = (yyvsp[-1].arvore_t);
        if ((yyvsp[0].arvore_t) != NULL) {
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t));
        }
    }
#line 1516 "parser.tab.c"
    break;

  case 6: /* cabecalho_funcao: TK_IDENTIFICADOR '=' abre_escopo lista_parametros '>' tipo  */
#line 95 "parser.y"
                                                               { 
        // se tipo for TK_PR_INT, então o tipo é SYMBOL_TYPE_INT, caso contrário é SYMBOL_TYPE_FLOAT
        // symbol_table_type_t type;
        // if ($6 == TK_PR_INT) {
        //     type = SYMBOL_TYPE_INT;
        // } else {
        //     type = SYMBOL_TYPE_FLOAT;
        // }
        // $$ = asd_new($1.valor_token, type); 

        (yyval.arvore_t) = asd_new((yyvsp[-5].valor_lexico).valor_token, TODO_TYPE);
        // semantic_error(ERR_DECLARED, $1.valor_token , get_line_number());
        }
#line 1534 "parser.tab.c"
    break;

  case 7: /* abre_escopo: %empty  */
#line 110 "parser.y"
             { printf("\nabrindo escopo\n"); }
#line 1540 "parser.tab.c"
    break;

  case 8: /* fecha_escopo: %empty  */
#line 112 "parser.y"
              { printf("fechando escopo"); }
#line 1546 "parser.tab.c"
    break;

  case 12: /* lista_parametros: empty  */
#line 121 "parser.y"
          { (yyval.arvore_t) = NULL; }
#line 1552 "parser.tab.c"
    break;

  case 13: /* lista_parametros: parametro TK_OC_OR lista_parametros  */
#line 122 "parser.y"
                                          { (yyval.arvore_t) = NULL; }
#line 1558 "parser.tab.c"
    break;

  case 14: /* lista_parametros: parametro  */
#line 123 "parser.y"
                { (yyval.arvore_t) = NULL; }
#line 1564 "parser.tab.c"
    break;

  case 15: /* parametro: TK_IDENTIFICADOR '<' '-' tipo  */
#line 127 "parser.y"
                                  { (yyval.arvore_t) = NULL; }
#line 1570 "parser.tab.c"
    break;

  case 16: /* bloco_comandos: '{' abre_escopo comandos fecha_escopo '}'  */
#line 132 "parser.y"
                                              {  (yyval.arvore_t) = (yyvsp[-2].arvore_t); }
#line 1576 "parser.tab.c"
    break;

  case 17: /* comandos: empty  */
#line 136 "parser.y"
          { (yyval.arvore_t) = NULL; }
#line 1582 "parser.tab.c"
    break;

  case 18: /* comandos: comando_simples comandos  */
#line 137 "parser.y"
                               {
        // todo: tentar resolver o problema com mudança nas produções ao invés de usar find_last_declaration
        if ((yyvsp[-1].arvore_t) != NULL && (yyvsp[0].arvore_t) != NULL) {
            (yyval.arvore_t) = (yyvsp[-1].arvore_t);
            // se tiver alguma declaração na lista_variaveis, procura 
            // pelo último "<=" para usar como parent para o próximo node
            if (strcmp((yyvsp[-1].arvore_t)->label, "<=") == 0) {
                asd_tree_t *last_declaration = find_last_declaration((yyvsp[-1].arvore_t));

                if (last_declaration != NULL) {
                    asd_add_child(last_declaration, (yyvsp[0].arvore_t));
                }
            } else {
                // caso contrário a lista_variáveis não teve nenhuma inicialização, então apenas adiciona o filho
                asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t));
            }        
        } else if ((yyvsp[-1].arvore_t) != NULL) {
            (yyval.arvore_t) = (yyvsp[-1].arvore_t);
        } else if ((yyvsp[0].arvore_t) != NULL) {
            (yyval.arvore_t) = (yyvsp[0].arvore_t);
        } else {
            (yyval.arvore_t) = NULL;
        }
    }
#line 1611 "parser.tab.c"
    break;

  case 19: /* comando_simples: declaracao_variavel ';'  */
#line 164 "parser.y"
                            {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1617 "parser.tab.c"
    break;

  case 20: /* comando_simples: atribuicao ';'  */
#line 165 "parser.y"
                     {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1623 "parser.tab.c"
    break;

  case 21: /* comando_simples: fluxo_controle ';'  */
#line 166 "parser.y"
                         {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1629 "parser.tab.c"
    break;

  case 22: /* comando_simples: operacao_retorno ';'  */
#line 167 "parser.y"
                           {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1635 "parser.tab.c"
    break;

  case 23: /* comando_simples: bloco_comandos ';'  */
#line 168 "parser.y"
                         {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1641 "parser.tab.c"
    break;

  case 24: /* comando_simples: chamada_funcao ';'  */
#line 169 "parser.y"
                          {  (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1647 "parser.tab.c"
    break;

  case 25: /* declaracao_variavel: tipo lista_variaveis  */
#line 173 "parser.y"
                         { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1653 "parser.tab.c"
    break;

  case 26: /* lista_variaveis: TK_IDENTIFICADOR TK_OC_LE literal ',' lista_variaveis  */
#line 178 "parser.y"
                                                          {
        // todo: verificar se já foi declarado (apenas no escopo atual) -> ERR_DECLARED
        (yyval.arvore_t) = asd_new("<=", TODO_TYPE); 
        asd_add_child((yyval.arvore_t), asd_new((yyvsp[-4].valor_lexico).valor_token, TODO_TYPE)); 
        asd_add_child((yyval.arvore_t), asd_new((yyvsp[-2].arvore_t)->label, TODO_TYPE)); 
        if((yyvsp[0].arvore_t) != NULL) {
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t));
        }
    }
#line 1667 "parser.tab.c"
    break;

  case 27: /* lista_variaveis: TK_IDENTIFICADOR ',' lista_variaveis  */
#line 187 "parser.y"
                                           { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1673 "parser.tab.c"
    break;

  case 28: /* lista_variaveis: TK_IDENTIFICADOR TK_OC_LE literal  */
#line 188 "parser.y"
                                        {
        // todo: verificar se já foi declarado (apenas no escopo atual) -> ERR_DECLARED
        (yyval.arvore_t) = asd_new("<=", TODO_TYPE);
        asd_add_child((yyval.arvore_t), asd_new((yyvsp[-2].valor_lexico).valor_token, TODO_TYPE)); 
        asd_add_child((yyval.arvore_t), asd_new((yyvsp[0].arvore_t)->label, TODO_TYPE));
    }
#line 1684 "parser.tab.c"
    break;

  case 29: /* lista_variaveis: TK_IDENTIFICADOR  */
#line 194 "parser.y"
                       { (yyval.arvore_t) = NULL; }
#line 1690 "parser.tab.c"
    break;

  case 30: /* atribuicao: TK_IDENTIFICADOR '=' expressao  */
#line 198 "parser.y"
                                   { 
        symbol_table_content_t *content = symbol_stack_find(&stack, (yyvsp[-2].valor_lexico).valor_token);

        if (content == NULL) {
            semantic_error(ERR_UNDECLARED, (yyvsp[-2].valor_lexico).valor_token, get_line_number());
        } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
            semantic_error(ERR_FUNCTION, (yyvsp[-2].valor_lexico).valor_token, get_line_number());
        }

        (yyval.arvore_t) = asd_new("=", TODO_TYPE); 
        asd_add_child((yyval.arvore_t), asd_new((yyvsp[-2].valor_lexico).valor_token, TODO_TYPE)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t));
    }
#line 1708 "parser.tab.c"
    break;

  case 31: /* operacao_retorno: TK_PR_RETURN expressao  */
#line 214 "parser.y"
                           { (yyval.arvore_t) = asd_new("return", (yyvsp[0].arvore_t)->type); asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); }
#line 1714 "parser.tab.c"
    break;

  case 32: /* chamada_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')'  */
#line 218 "parser.y"
                                              {
        const char *CALL = "call";
        size_t size = strlen(CALL) + strlen((yyvsp[-3].valor_lexico).valor_token) + 2;
        char *function = (char *)malloc(size);

        if (function) {
            symbol_table_content_t *content = symbol_stack_find(&stack, (yyvsp[-3].valor_lexico).valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, (yyvsp[-3].valor_lexico).valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_VARIABLE) {
                semantic_error(ERR_VARIABLE, (yyvsp[-3].valor_lexico).valor_token, get_line_number());
            }

            sprintf(function, "%s %s", CALL, (yyvsp[-3].valor_lexico).valor_token); 

            (yyval.arvore_t) = asd_new(function, TODO_TYPE);
            asd_add_child((yyval.arvore_t), (yyvsp[-1].arvore_t));
            
            free(function);
        } else {
            fprintf(stderr, "Erro na alocacao de memoria! \n");
        }
    }
#line 1743 "parser.tab.c"
    break;

  case 33: /* lista_argumentos: expressao  */
#line 245 "parser.y"
              { 
        (yyval.arvore_t) = (yyvsp[0].arvore_t);
    }
#line 1751 "parser.tab.c"
    break;

  case 34: /* lista_argumentos: expressao ',' lista_argumentos  */
#line 248 "parser.y"
                                     { 
        (yyval.arvore_t) = (yyvsp[-2].arvore_t);
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1760 "parser.tab.c"
    break;

  case 35: /* fluxo_controle: TK_PR_IF '(' expressao ')' bloco_comandos  */
#line 255 "parser.y"
                                              {
        (yyval.arvore_t) = asd_new("if", (yyvsp[-2].arvore_t)->type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        if ((yyvsp[0].arvore_t) != NULL) { 
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
        } 
    }
#line 1772 "parser.tab.c"
    break;

  case 36: /* fluxo_controle: TK_PR_IF '(' expressao ')' bloco_comandos TK_PR_ELSE bloco_comandos  */
#line 262 "parser.y"
                                                                          { 
        (yyval.arvore_t) = asd_new("if", (yyvsp[-4].arvore_t)->type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-4].arvore_t)); 
        if ((yyvsp[-2].arvore_t) != NULL) { 
            asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        } 
        if ((yyvsp[0].arvore_t) != NULL) { 
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
        }  
    }
#line 1787 "parser.tab.c"
    break;

  case 37: /* fluxo_controle: TK_PR_WHILE '(' expressao ')' bloco_comandos  */
#line 272 "parser.y"
                                                   { 
        (yyval.arvore_t) = asd_new("while", (yyvsp[-2].arvore_t)->type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        if ((yyvsp[0].arvore_t) != NULL) { 
            asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
        } 
    }
#line 1799 "parser.tab.c"
    break;

  case 38: /* expressao: expressao_precedencia_6  */
#line 282 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1805 "parser.tab.c"
    break;

  case 39: /* expressao: expressao TK_OC_OR expressao_precedencia_6  */
#line 283 "parser.y"
                                                 { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("|", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1816 "parser.tab.c"
    break;

  case 40: /* expressao_precedencia_6: expressao_precedencia_5  */
#line 292 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1822 "parser.tab.c"
    break;

  case 41: /* expressao_precedencia_6: expressao_precedencia_6 TK_OC_AND expressao_precedencia_5  */
#line 293 "parser.y"
                                                                { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("&", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1833 "parser.tab.c"
    break;

  case 42: /* expressao_precedencia_5: expressao_precedencia_4  */
#line 302 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1839 "parser.tab.c"
    break;

  case 43: /* expressao_precedencia_5: expressao_precedencia_5 TK_OC_EQ expressao_precedencia_4  */
#line 303 "parser.y"
                                                               { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("==", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1850 "parser.tab.c"
    break;

  case 44: /* expressao_precedencia_5: expressao_precedencia_5 TK_OC_NE expressao_precedencia_4  */
#line 309 "parser.y"
                                                               { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("!=", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1861 "parser.tab.c"
    break;

  case 45: /* expressao_precedencia_4: expressao_precedencia_3  */
#line 318 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1867 "parser.tab.c"
    break;

  case 46: /* expressao_precedencia_4: expressao_precedencia_4 '<' expressao_precedencia_3  */
#line 319 "parser.y"
                                                          { (yyval.arvore_t) = asd_new("<", TODO_TYPE); asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); }
#line 1873 "parser.tab.c"
    break;

  case 47: /* expressao_precedencia_4: expressao_precedencia_4 '>' expressao_precedencia_3  */
#line 320 "parser.y"
                                                          { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new(">", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1884 "parser.tab.c"
    break;

  case 48: /* expressao_precedencia_4: expressao_precedencia_4 TK_OC_LE expressao_precedencia_3  */
#line 326 "parser.y"
                                                               { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("<=", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1895 "parser.tab.c"
    break;

  case 49: /* expressao_precedencia_4: expressao_precedencia_4 TK_OC_GE expressao_precedencia_3  */
#line 332 "parser.y"
                                                               { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new(">=", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1906 "parser.tab.c"
    break;

  case 50: /* expressao_precedencia_3: expressao_precedencia_2  */
#line 341 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1912 "parser.tab.c"
    break;

  case 51: /* expressao_precedencia_3: expressao_precedencia_3 '+' expressao_precedencia_2  */
#line 342 "parser.y"
                                                          { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("+", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1923 "parser.tab.c"
    break;

  case 52: /* expressao_precedencia_3: expressao_precedencia_3 '-' expressao_precedencia_2  */
#line 348 "parser.y"
                                                          { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("-", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1934 "parser.tab.c"
    break;

  case 53: /* expressao_precedencia_2: expressao_precedencia_1  */
#line 357 "parser.y"
                            { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1940 "parser.tab.c"
    break;

  case 54: /* expressao_precedencia_2: expressao_precedencia_2 '*' expressao_precedencia_1  */
#line 358 "parser.y"
                                                          {
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("*", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1951 "parser.tab.c"
    break;

  case 55: /* expressao_precedencia_2: expressao_precedencia_2 '/' expressao_precedencia_1  */
#line 364 "parser.y"
                                                          { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("/", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); 
    }
#line 1962 "parser.tab.c"
    break;

  case 56: /* expressao_precedencia_2: expressao_precedencia_2 '%' expressao_precedencia_1  */
#line 370 "parser.y"
                                                          { 
        symbol_table_type_t type = infer_type((yyvsp[-2].arvore_t)->type, (yyvsp[0].arvore_t)->type);
        (yyval.arvore_t) = asd_new("%", type); 
        asd_add_child((yyval.arvore_t), (yyvsp[-2].arvore_t)); 
        asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); }
#line 1972 "parser.tab.c"
    break;

  case 57: /* expressao_precedencia_1: operandos_simples  */
#line 378 "parser.y"
                      { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 1978 "parser.tab.c"
    break;

  case 58: /* expressao_precedencia_1: '(' expressao ')'  */
#line 379 "parser.y"
                        { (yyval.arvore_t) = (yyvsp[-1].arvore_t); }
#line 1984 "parser.tab.c"
    break;

  case 59: /* expressao_precedencia_1: '-' expressao_precedencia_1  */
#line 380 "parser.y"
                                  { (yyval.arvore_t) = asd_new("-", (yyvsp[0].arvore_t)->type); asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); }
#line 1990 "parser.tab.c"
    break;

  case 60: /* expressao_precedencia_1: '!' expressao_precedencia_1  */
#line 381 "parser.y"
                                  {(yyval.arvore_t) = asd_new("!", (yyvsp[0].arvore_t)->type); asd_add_child((yyval.arvore_t), (yyvsp[0].arvore_t)); }
#line 1996 "parser.tab.c"
    break;

  case 61: /* literal: TK_LIT_INT  */
#line 385 "parser.y"
               { (yyval.arvore_t) = asd_new((yyvsp[0].valor_lexico).valor_token, SYMBOL_TYPE_INT); }
#line 2002 "parser.tab.c"
    break;

  case 62: /* literal: TK_LIT_FLOAT  */
#line 386 "parser.y"
                   { (yyval.arvore_t) = asd_new((yyvsp[0].valor_lexico).valor_token, SYMBOL_TYPE_FLOAT); }
#line 2008 "parser.tab.c"
    break;

  case 63: /* operandos_simples: literal  */
#line 390 "parser.y"
                { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 2014 "parser.tab.c"
    break;

  case 64: /* operandos_simples: TK_IDENTIFICADOR  */
#line 391 "parser.y"
                         {
            symbol_table_content_t *content = symbol_stack_find(&stack, (yyvsp[0].valor_lexico).valor_token);

            if (content == NULL) {
                semantic_error(ERR_UNDECLARED, (yyvsp[0].valor_lexico).valor_token, get_line_number());
            } else if (content->nature == SYMBOL_NATURE_FUNCTION) {
                semantic_error(ERR_FUNCTION, (yyvsp[0].valor_lexico).valor_token, get_line_number());
            }

            (yyval.arvore_t) = asd_new((yyvsp[0].valor_lexico).valor_token, TODO_TYPE); 
        }
#line 2030 "parser.tab.c"
    break;

  case 65: /* operandos_simples: chamada_funcao  */
#line 402 "parser.y"
                       { (yyval.arvore_t) = (yyvsp[0].arvore_t); }
#line 2036 "parser.tab.c"
    break;


#line 2040 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 404 "parser.y"


void yyerror(const char *error) {
  fprintf(stderr, "Syntax error at line %d: %s\n", get_line_number(), error);
}

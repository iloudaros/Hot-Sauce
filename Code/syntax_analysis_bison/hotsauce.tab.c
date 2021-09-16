/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "hotsauce.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHECK_SIZE 200

//Declarations of flex derived tools

extern int yylex();
extern int yyparse();
extern FILE *yyin;
extern FILE *yyout;
extern int yylineno;
extern int  yywrap;

int yylex();
void yyerror(const char* s);

char decl_vars [CHECK_SIZE][30];
char decl_funcs [CHECK_SIZE][30];
char decl_structs [CHECK_SIZE][30];

int var_count = 0;
int fun_count = 0;
int struct_count = 0;

int found_flag = 0;



#line 103 "hotsauce.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


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
    KEY_PROGRAM = 258,
    KEY_FUNCTION = 259,
    KEY_RETURN = 260,
    KEY_ENDFUNCTION = 261,
    KEY_VARS = 262,
    KEY_CHAR = 263,
    KEY_INT = 264,
    KEY_MAIN = 265,
    KEY_ENDMAIN = 266,
    KEY_WHILE = 267,
    KEY_ENDWHILE = 268,
    KEY_FOR = 269,
    KEY_TO = 270,
    KEY_STEP = 271,
    KEY_ENDFOR = 272,
    KEY_IF = 273,
    KEY_ELSEIF = 274,
    KEY_ENDIF = 275,
    KEY_THEN = 276,
    KEY_ELSE = 277,
    KEY_SWITCH = 278,
    KEY_CASE = 279,
    KEY_DEFAULT = 280,
    KEY_ENDSWITCH = 281,
    KEY_PRINT = 282,
    KEY_BREAK = 283,
    KEY_ASSIGN = 284,
    KEY_BRACKETR = 285,
    KEY_BRACKETL = 286,
    KEY_PARR = 287,
    KEY_PARL = 288,
    KEY_COMMA = 289,
    KEY_SEMICOLON = 290,
    KEY_COLON = 291,
    KEY_CHARACTER = 292,
    KEY_NUM = 293,
    KEY_STRING = 294,
    KEY_IDENTIFIER = 295,
    KEY_AND = 296,
    KEY_OR = 297,
    KEY_GREATER = 298,
    KEY_LESSER = 299,
    KEY_EQUAL = 300,
    KEY_NOTEQUAL = 301,
    KEY_MUL = 302,
    KEY_DIV = 303,
    KEY_PLUS = 304,
    KEY_MIN = 305,
    KEY_TYPEDEF = 306,
    KEY_STRUCT = 307,
    KEY_ENDSTRUCT = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 37 "hotsauce.y"

  char* id;

#line 210 "hotsauce.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);





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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

#define YYUNDEFTOK  2
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    83,    83,    87,    90,    92,    96,    97,   100,   102,
     103,   104,   105,   109,   113,   117,   120,   123,   127,   131,
     135,   141,   145,   149,   150,   151,   152,   153,   157,   180,
     181,   184,   186,   190,   191,   195,   196,   197,   198,   199,
     203,   206,   207,   211,   230,   231,   235,   236,   240,   241,
     245,   246,   247,   248,   249,   250,   251,   270,   292,   311,
     333,   334,   353,   354,   355,   356,   357,   358,   359,   383,
     384,   385,   386,   390,   394,   398,   399,   403,   407,   413,
     414,   418,   422,   426,   427,   431,   435,   440,   441,   460,
     461,   462,   463,   464,   465,   466,   472,   476,   500,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KEY_PROGRAM", "KEY_FUNCTION",
  "KEY_RETURN", "KEY_ENDFUNCTION", "KEY_VARS", "KEY_CHAR", "KEY_INT",
  "KEY_MAIN", "KEY_ENDMAIN", "KEY_WHILE", "KEY_ENDWHILE", "KEY_FOR",
  "KEY_TO", "KEY_STEP", "KEY_ENDFOR", "KEY_IF", "KEY_ELSEIF", "KEY_ENDIF",
  "KEY_THEN", "KEY_ELSE", "KEY_SWITCH", "KEY_CASE", "KEY_DEFAULT",
  "KEY_ENDSWITCH", "KEY_PRINT", "KEY_BREAK", "KEY_ASSIGN", "KEY_BRACKETR",
  "KEY_BRACKETL", "KEY_PARR", "KEY_PARL", "KEY_COMMA", "KEY_SEMICOLON",
  "KEY_COLON", "KEY_CHARACTER", "KEY_NUM", "KEY_STRING", "KEY_IDENTIFIER",
  "KEY_AND", "KEY_OR", "KEY_GREATER", "KEY_LESSER", "KEY_EQUAL",
  "KEY_NOTEQUAL", "KEY_MUL", "KEY_DIV", "KEY_PLUS", "KEY_MIN",
  "KEY_TYPEDEF", "KEY_STRUCT", "KEY_ENDSTRUCT", "$accept", "program",
  "main", "vardeclaration", "variables_decl", "variable_decl", "int_decl",
  "char_decl", "int_array_decl", "char_array_decl", "int", "char",
  "int_array", "char_array", "struct_decl", "typedef_decl", "struct_decls",
  "struct_call", "functions", "function", "parameters", "parameter",
  "body", "return", "return_val", "identifier_list", "statements",
  "statement", "assignment", "expression", "if", "if_else", "if_elsif",
  "else_ifs", "else_if", "if_elsif_else", "switch", "switch_start",
  "cases_term", "cases", "case", "default", "condition", "while", "for",
  "print", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF (-175)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      15,   -18,    48,    57,  -175,    24,    58,  -175,  -175,     4,
      64,   115,    96,  -175,  -175,     2,  -175,   115,   117,    86,
     100,   115,  -175,  -175,   107,   104,   106,   117,  -175,  -175,
    -175,  -175,  -175,   119,   135,  -175,     5,   149,   154,   112,
     146,   144,   164,   144,  -175,  -175,  -175,   140,   176,   195,
    -175,  -175,  -175,  -175,  -175,    43,  -175,   163,   196,   184,
     204,   205,    63,   149,  -175,  -175,  -175,  -175,  -175,  -175,
    -175,   221,  -175,  -175,  -175,  -175,   193,   209,   208,   211,
     219,   220,  -175,   115,     5,    29,   216,    29,    29,   214,
     131,    31,  -175,   222,  -175,    40,  -175,  -175,   224,  -175,
     226,   223,   225,   252,  -175,    29,  -175,  -175,   141,   229,
     156,   162,   227,   -10,   230,  -175,   231,   -10,    -6,   232,
    -175,    59,    29,   233,  -175,  -175,  -175,   235,   236,   238,
     242,    80,   254,   177,   149,    29,    29,    29,    29,    29,
      29,   228,    93,  -175,    95,   -15,  -175,     5,  -175,  -175,
     -10,   -10,   -10,   -10,  -175,   239,   183,   149,  -175,  -175,
    -175,  -175,  -175,  -175,  -175,  -175,  -175,  -175,    -3,   168,
     147,   188,   188,   188,   188,   247,   240,   149,   130,  -175,
     237,  -175,  -175,   103,   125,   125,  -175,  -175,  -175,   243,
      76,  -175,   244,    29,    60,  -175,  -175,   245,   241,   149,
    -175,   262,   198,  -175,   149,    67,   248,  -175,    83,   246,
     260,   101,   149,   250,   251,   149,   149,  -175,   120,  -175,
    -175,   139,   149,  -175,  -175
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    27,     1,     0,     0,    23,    25,    31,
       0,     4,     0,    24,    26,     0,    29,     4,     8,     0,
       0,     4,     2,    30,     0,     0,     0,     5,     6,     9,
      10,    12,    11,     0,     0,    21,     0,     0,     0,     0,
      46,    18,    46,    17,     7,    13,    14,     0,     0,     0,
      35,    36,    37,    38,    39,     0,    33,     0,     0,     0,
       0,     0,     0,    40,    48,    50,    53,    70,    71,    72,
      54,     0,    51,    52,    55,     3,     0,     0,     0,     0,
      46,    46,    28,     4,     0,     0,     0,     0,     0,     0,
       0,     0,    49,     0,    79,     0,    83,    22,     0,    47,
       0,     0,     0,    41,    34,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,    60,    61,     0,     0,     0,
      46,     0,     0,     0,    82,    84,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    59,     0,    66,    58,
       0,     0,     0,     0,    57,     0,     0,     0,    16,    15,
      20,    19,    45,    44,    43,    42,    32,    95,     0,    93,
      94,    89,    90,    91,    92,     0,     0,     0,     0,    75,
       0,    98,    67,     0,    64,    65,    62,    63,    56,     0,
       0,    96,     0,     0,     0,    74,    76,     0,     0,     0,
      86,     0,     0,    69,     0,     0,     0,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,     0,    99,
      85,     0,    77,    78,    97
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -175,  -175,  -175,    28,  -175,   256,  -175,  -175,  -175,  -175,
     -11,    20,  -175,  -175,   278,   279,  -175,  -175,  -175,   274,
     143,   207,   210,  -175,  -175,   -21,  -131,   -63,  -175,   -92,
    -175,  -175,  -175,    98,  -174,  -175,  -175,  -175,  -175,  -175,
     199,  -175,   -86,  -175,  -175,  -175
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    22,    37,    27,    28,    29,    30,    31,    32,
      50,    51,    52,    53,     7,     8,     9,    54,    15,    16,
      55,    56,    38,   132,   165,    41,    63,    64,    65,   118,
      66,    67,    68,   178,   179,    69,    70,    71,    94,    95,
      96,   126,   108,    72,    73,    74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   110,   111,   168,   196,    43,    12,    33,    12,    57,
     191,    58,    21,    47,    48,    59,    33,   182,     1,   133,
      60,   145,     3,   113,    61,   148,   190,    43,   115,   149,
     116,   196,   150,   151,   152,   153,   156,    62,    34,    19,
     117,   150,   151,   152,   153,    24,   194,    34,     4,   169,
     170,   171,   172,   173,   174,     5,     6,    49,   184,   185,
     186,   187,   105,   119,    93,   123,   124,   106,   208,   107,
     121,   120,    57,   211,    58,    83,    10,    84,    59,   176,
     203,   218,   204,    60,   221,   222,   176,    61,    57,   212,
      58,   155,    90,    78,    59,    57,    91,    58,    11,    60,
      62,    59,   200,    61,    17,    92,    60,   202,     5,     6,
      61,   214,   176,    57,   177,    58,    62,   162,   163,    59,
     164,   217,    18,    62,    60,    25,    26,    92,    61,   180,
     181,    92,    57,    36,    58,   198,    20,    84,    59,    35,
     223,    62,    39,    60,    40,    92,    42,    61,    92,   176,
     195,    57,    76,    58,    45,    92,   224,    59,    92,    92,
      62,    57,    60,    58,   113,    75,    61,    59,   114,   115,
      46,   116,    60,   134,   152,   153,    61,    77,    78,    62,
      80,   117,   135,   136,   137,   138,   139,   140,   142,    62,
     137,   138,   139,   140,   143,    79,    85,   135,   136,   137,
     138,   139,   140,   135,   136,   137,   138,   139,   140,   167,
     136,   137,   138,   139,   140,   189,    81,    87,   135,   136,
     137,   138,   139,   140,   135,   136,   137,   138,   139,   140,
     210,    -1,    -1,    -1,    -1,    82,    86,    88,    89,   135,
     136,   137,   138,   139,   140,    93,    97,    98,    99,   100,
     101,   102,   109,   112,   127,   122,   128,   131,   141,   144,
     166,   129,   192,   130,   147,   146,   175,   154,   160,   157,
     158,   159,   161,   193,   188,   206,   207,   197,   209,   199,
     213,   216,   201,    44,   215,   219,   220,    13,    14,    23,
     183,   104,   205,   103,   125
};

static const yytype_uint8 yycheck[] =
{
      63,    87,    88,   134,   178,    26,     4,    18,     4,    12,
      13,    14,    10,     8,     9,    18,    27,    32,     3,   105,
      23,   113,    40,    33,    27,   117,   157,    48,    38,    35,
      40,   205,    47,    48,    49,    50,   122,    40,    18,    11,
      50,    47,    48,    49,    50,    17,   177,    27,     0,   135,
     136,   137,   138,   139,   140,    51,    52,    52,   150,   151,
     152,   153,    33,    32,    24,    25,    26,    38,   199,    40,
      91,    40,    12,   204,    14,    32,    52,    34,    18,    19,
      20,   212,    22,    23,   215,   216,    19,    27,    12,    22,
      14,    32,    29,    34,    18,    12,    33,    14,    40,    23,
      40,    18,    26,    27,    40,   168,    23,   193,    51,    52,
      27,    28,    19,    12,    21,    14,    40,    37,    38,    18,
      40,    20,     7,    40,    23,     8,     9,   190,    27,    34,
      35,   194,    12,    33,    14,    32,    40,    34,    18,    53,
      20,    40,    35,    23,    40,   208,    40,    27,   211,    19,
      20,    12,    40,    14,    35,   218,    17,    18,   221,   222,
      40,    12,    23,    14,    33,    11,    27,    18,    37,    38,
      35,    40,    23,    32,    49,    50,    27,    31,    34,    40,
      40,    50,    41,    42,    43,    44,    45,    46,    32,    40,
      43,    44,    45,    46,    32,    31,    33,    41,    42,    43,
      44,    45,    46,    41,    42,    43,    44,    45,    46,    32,
      42,    43,    44,    45,    46,    32,    40,    33,    41,    42,
      43,    44,    45,    46,    41,    42,    43,    44,    45,    46,
      32,    43,    44,    45,    46,    40,    40,    33,    33,    41,
      42,    43,    44,    45,    46,    24,    53,    38,    40,    38,
      31,    31,    36,    39,    30,    33,    30,     5,    29,    32,
       6,    38,    15,    38,    33,    35,    38,    35,    30,    36,
      35,    35,    30,    33,    35,    30,    35,    40,    16,    36,
      32,    21,    38,    27,    38,    35,    35,     9,     9,    15,
     147,    84,   194,    83,    95
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    55,    40,     0,    51,    52,    68,    69,    70,
      52,    40,     4,    68,    69,    72,    73,    40,     7,    57,
      40,    10,    56,    73,    57,     8,     9,    58,    59,    60,
      61,    62,    63,    64,    65,    53,    33,    57,    76,    35,
      40,    79,    40,    79,    59,    35,    35,     8,     9,    52,
      64,    65,    66,    67,    71,    74,    75,    12,    14,    18,
      23,    27,    40,    80,    81,    82,    84,    85,    86,    89,
      90,    91,    97,    98,    99,    11,    40,    31,    34,    31,
      40,    40,    40,    32,    34,    33,    40,    33,    33,    33,
      29,    33,    81,    24,    92,    93,    94,    53,    38,    40,
      38,    31,    31,    76,    75,    33,    38,    40,    96,    36,
      96,    96,    39,    33,    37,    38,    40,    50,    83,    32,
      40,    79,    33,    25,    26,    94,    95,    30,    30,    38,
      38,     5,    77,    96,    32,    41,    42,    43,    44,    45,
      46,    29,    32,    32,    32,    83,    35,    33,    83,    35,
      47,    48,    49,    50,    35,    32,    96,    36,    35,    35,
      30,    30,    37,    38,    40,    78,     6,    32,    80,    96,
      96,    96,    96,    96,    96,    38,    19,    21,    87,    88,
      34,    35,    32,    74,    83,    83,    83,    83,    35,    32,
      80,    13,    15,    33,    80,    20,    88,    40,    32,    36,
      26,    38,    96,    20,    22,    87,    30,    35,    80,    16,
      32,    80,    22,    32,    28,    38,    21,    20,    80,    35,
      35,    80,    80,    20,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    57,    57,    58,    58,    59,    59,
      59,    59,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    70,    70,    70,    70,    71,    72,
      72,    73,    73,    74,    74,    75,    75,    75,    75,    75,
      76,    77,    77,    78,    78,    78,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    84,
      84,    84,    84,    85,    86,    87,    87,    88,    89,    90,
      90,    91,    92,    93,    93,    94,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    98,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     2,     0,     1,
       1,     1,     1,     2,     2,     6,     6,     2,     2,     5,
       5,     4,     7,     1,     2,     1,     2,     0,     2,     1,
       2,     0,     8,     1,     3,     1,     1,     1,     1,     1,
       2,     0,     2,     1,     1,     1,     1,     3,     1,     2,
       1,     1,     1,     1,     1,     1,     5,     4,     4,     4,
       1,     1,     3,     3,     3,     3,     2,     3,     5,     7,
       1,     1,     1,     9,     6,     1,     2,     6,    10,     2,
       3,     4,     2,     1,     2,     8,     4,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     6,    11,     5,     9
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
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
  case 2:
#line 83 "hotsauce.y"
                                                         {printf("Parsed Successfully!🔥");}
#line 1559 "hotsauce.tab.c"
    break;

  case 15:
#line 117 "hotsauce.y"
                                                                          { strcpy(decl_vars[var_count], (yyvsp[-4].id)); var_count++; }
#line 1565 "hotsauce.tab.c"
    break;

  case 16:
#line 120 "hotsauce.y"
                                                                          { strcpy(decl_vars[var_count], (yyvsp[-4].id)); var_count++; }
#line 1571 "hotsauce.tab.c"
    break;

  case 19:
#line 131 "hotsauce.y"
                                                           { strcpy(decl_vars[var_count], (yyvsp[-3].id)); var_count++; }
#line 1577 "hotsauce.tab.c"
    break;

  case 20:
#line 135 "hotsauce.y"
                                                            { strcpy(decl_vars[var_count], (yyvsp[-3].id)); var_count++; }
#line 1583 "hotsauce.tab.c"
    break;

  case 21:
#line 141 "hotsauce.y"
                                                                 { strcpy(decl_structs[struct_count], (yyvsp[-2].id)); struct_count++; }
#line 1589 "hotsauce.tab.c"
    break;

  case 22:
#line 145 "hotsauce.y"
                                                                                                          { strcpy(decl_structs[struct_count], (yyvsp[-1].id)); struct_count++; }
#line 1595 "hotsauce.tab.c"
    break;

  case 28:
#line 157 "hotsauce.y"
                                    {
                                found_flag = 0;

                                for(int i=0; i<=CHECK_SIZE; i++)
                                {
                                  if(strcmp((yyvsp[0].id),decl_structs[i])==0)
                                  {
                                    found_flag = 1;
                                    break;
                                  }

                                  if(found_flag == 0)
                                  {
                                    printf("Struct %s in line %d not declared. \n",(yyvsp[0].id), yylineno);
                                  }

                                }
                              }
#line 1618 "hotsauce.tab.c"
    break;

  case 32:
#line 186 "hotsauce.y"
                                                                                         { strcpy(decl_funcs[fun_count], (yyvsp[-6].id)); fun_count++; }
#line 1624 "hotsauce.tab.c"
    break;

  case 43:
#line 211 "hotsauce.y"
                  {
                    found_flag = 0;

                    for(int i=0; i<=CHECK_SIZE; i++)
                    {
                      if(strcmp((yyvsp[0].id),decl_vars[i])==0)
                      {
                        found_flag = 1;
                        break;
                      }
                    }

                    if(found_flag == 0)
                    {
                      printf("Variable %s in line %d not declared. \n",(yyvsp[0].id), yylineno);
                      exit(1);
                    }

                  }
#line 1648 "hotsauce.tab.c"
    break;

  case 46:
#line 235 "hotsauce.y"
                 { strcpy(decl_vars[var_count], (yyvsp[0].id)); var_count++; }
#line 1654 "hotsauce.tab.c"
    break;

  case 47:
#line 236 "hotsauce.y"
                                             { strcpy(decl_vars[var_count], (yyvsp[0].id)); var_count++; }
#line 1660 "hotsauce.tab.c"
    break;

  case 56:
#line 251 "hotsauce.y"
                                                                   {
                                                                      found_flag = 0;

                                                                      for(int i=0; i<=CHECK_SIZE; i++)
                                                                      {
                                                                        if(strcmp((yyvsp[-4].id),decl_funcs[i])==0)
                                                                        {
                                                                          found_flag = 1;
                                                                          break;
                                                                        }
                                                                      }

                                                                      if(found_flag == 0)
                                                                      {
                                                                        printf("Function %s in line %d not declared. \n",(yyvsp[-4].id), yylineno);
                                                                        exit(1);
                                                                      }

                                                                    }
#line 1684 "hotsauce.tab.c"
    break;

  case 57:
#line 270 "hotsauce.y"
                                                   {
                                                      found_flag = 0;

                                                      for(int i=0; i<=CHECK_SIZE; i++)
                                                      {
                                                        if(strcmp((yyvsp[-3].id),decl_funcs[i])==0)
                                                        {
                                                          found_flag = 1;
                                                          break;
                                                        }
                                                      }

                                                      if(found_flag == 0)
                                                      {
                                                        printf("Function %s in line %d not declared. \n",(yyvsp[-3].id), yylineno);
                                                        exit(1);
                                                      }

                                                    }
#line 1708 "hotsauce.tab.c"
    break;

  case 58:
#line 292 "hotsauce.y"
                                                     {
                                                        found_flag = 0;

                                                        for(int i=0; i<=CHECK_SIZE; i++)
                                                        {
                                                          if(strcmp((yyvsp[-3].id),decl_vars[i])==0)
                                                          {
                                                            found_flag = 1;
                                                            break;
                                                          }
                                                        }

                                                        if(found_flag == 0)
                                                        {
                                                          printf("Variable %s in line %d not declared. \n",(yyvsp[-3].id), yylineno);
                                                          exit(1);
                                                        }

                                                      }
#line 1732 "hotsauce.tab.c"
    break;

  case 59:
#line 311 "hotsauce.y"
                                                          {
                                                            found_flag = 0;

                                                            for(int i=0; i<=CHECK_SIZE; i++)
                                                            {
                                                              if(strcmp((yyvsp[-3].id),decl_vars[i])==0)
                                                              {
                                                                found_flag = 1;
                                                                break;
                                                              }
                                                            }

                                                            if(found_flag == 0)
                                                            {
                                                              printf("Variable %s in line %d not declared. \n",(yyvsp[-3].id), yylineno);
                                                              exit(1);
                                                            }

                                                          }
#line 1756 "hotsauce.tab.c"
    break;

  case 61:
#line 334 "hotsauce.y"
                   {
                      found_flag = 0;

                      for(int i=0; i<=CHECK_SIZE; i++)
                      {
                        if(strcmp((yyvsp[0].id),decl_vars[i])==0)
                        {
                          found_flag = 1;
                          break;
                        }
                      }

                      if(found_flag == 0)
                      {
                        printf("Variable %s in line %d not declared. \n",(yyvsp[0].id), yylineno);
                        exit(1);
                      }

                    }
#line 1780 "hotsauce.tab.c"
    break;

  case 68:
#line 359 "hotsauce.y"
                                                              {
                                                                found_flag = 0;

                                                                for(int i=0; i<=CHECK_SIZE; i++)
                                                                {
                                                                  if(strcmp((yyvsp[-4].id),decl_funcs[i])==0)
                                                                  {
                                                                    found_flag = 1;
                                                                    break;
                                                                  }
                                                                }

                                                                if(found_flag == 0)
                                                                {
                                                                  printf("Function %s in line %d not declared. \n",(yyvsp[-4].id), yylineno);
                                                                  exit(1);
                                                                }

                                                              }
#line 1804 "hotsauce.tab.c"
    break;

  case 88:
#line 441 "hotsauce.y"
                   {
                      found_flag = 0;

                      for(int i=0; i<=CHECK_SIZE; i++)
                      {
                        if(strcmp((yyvsp[0].id),decl_vars[i])==0)
                        {
                          found_flag = 1;
                          break;
                        }
                      }

                      if(found_flag == 0)
                      {
                        printf("Variable %s in line %d not declared. \n",(yyvsp[0].id), yylineno);
                        exit(1);
                      }

                    }
#line 1828 "hotsauce.tab.c"
    break;

  case 97:
#line 476 "hotsauce.y"
                                                                                                                {
                                                                                                                  found_flag = 0;

                                                                                                                  for(int i=0; i<=CHECK_SIZE; i++)
                                                                                                                  {
                                                                                                                    if(strcmp((yyvsp[-9].id),decl_vars[i])==0)
                                                                                                                    {
                                                                                                                      found_flag = 1;
                                                                                                                      break;
                                                                                                                    }
                                                                                                                  }

                                                                                                                  if(found_flag == 0)
                                                                                                                  {
                                                                                                                    printf("Variable %s in line %d not declared. \n",(yyvsp[-9].id), yylineno);
                                                                                                                    exit(1);
                                                                                                                  }

                                                                                                                }
#line 1852 "hotsauce.tab.c"
    break;

  case 99:
#line 501 "hotsauce.y"
                                                                                                          {
                                                                                                            found_flag = 0;

                                                                                                            for(int i=0; i<=CHECK_SIZE; i++)
                                                                                                            {
                                                                                                              if(strcmp((yyvsp[-3].id),decl_vars[i])==0)
                                                                                                              {
                                                                                                                found_flag = 1;
                                                                                                                break;
                                                                                                              }
                                                                                                            }

                                                                                                            if(found_flag == 0)
                                                                                                            {
                                                                                                              printf("Variable %s in line %d not declared. \n",(yyvsp[-3].id), yylineno);
                                                                                                              exit(1);
                                                                                                            }

                                                                                                          }
#line 1876 "hotsauce.tab.c"
    break;


#line 1880 "hotsauce.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 524 "hotsauce.y"

/*** And finally, the parser in action ***/

void yyerror(const char* s)
  {
	fprintf(stderr, "Line: %d --> Parser error\n", yylineno);
	exit(1);
  }

int main ( int argc, char **argv  )
  {

  yyin = fopen( argv[1], "r" );
  yyparse ();

  return 0;
}

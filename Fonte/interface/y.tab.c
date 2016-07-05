/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#ifndef FMACROS
   #include "../macros.h"
#endif
#ifndef FTYPES
   #include "../types.h"
#endif
#ifndef FMISC
   #include "../misc.h"
#endif
#ifndef FDICTIONARY
   #include "../dictionary.h"
#endif
#ifndef FSQLCOMMANDS
   #include "../sqlcommands.h"
#endif
#ifndef FDATABASE
   #include "../database.h"
#endif
#ifndef FPARSER
   #include "parser.h"
#endif

extern char* yytext[];
extern FILE * yyin;
extern FILE* outFile_p;

int yywrap() {
    return 1;
}


#line 103 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    INSERT = 258,
    INTO = 259,
    VALUES = 260,
    SELECT = 261,
    FROM = 262,
    CREATE = 263,
    TABLE = 264,
    INTEGER = 265,
    VARCHAR = 266,
    DOUBLE = 267,
    CHAR = 268,
    PRIMARY = 269,
    KEY = 270,
    REFERENCES = 271,
    DATABASE = 272,
    DROP = 273,
    OBJECT = 274,
    NUMBER = 275,
    VALUE = 276,
    QUIT = 277,
    LIST_TABLES = 278,
    LIST_TABLE = 279,
    ALPHANUM = 280,
    CONNECT = 281,
    HELP = 282,
    LIST_DBASES = 283,
    CLEAR = 284,
    CONTR = 285,
    WHERE = 286,
    AND = 287,
    OR = 288,
    YEQ = 289,
    YLT = 290,
    YGT = 291,
    YNQ = 292,
    YGTQ = 293,
    YLTQ = 294
  };
#endif
/* Tokens.  */
#define INSERT 258
#define INTO 259
#define VALUES 260
#define SELECT 261
#define FROM 262
#define CREATE 263
#define TABLE 264
#define INTEGER 265
#define VARCHAR 266
#define DOUBLE 267
#define CHAR 268
#define PRIMARY 269
#define KEY 270
#define REFERENCES 271
#define DATABASE 272
#define DROP 273
#define OBJECT 274
#define NUMBER 275
#define VALUE 276
#define QUIT 277
#define LIST_TABLES 278
#define LIST_TABLE 279
#define ALPHANUM 280
#define CONNECT 281
#define HELP 282
#define LIST_DBASES 283
#define CLEAR 284
#define CONTR 285
#define WHERE 286
#define AND 287
#define OR 288
#define YEQ 289
#define YLT 290
#define YGT 291
#define YNQ 292
#define YGTQ 293
#define YLTQ 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "yacc.y" /* yacc.c:355  */

    int intval;
    double floatval;
    int subtok;
    char *strval;

#line 228 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  44
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   100

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156
=======
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135
>>>>>>> origin/master

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

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
      40,    41,    44,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    63,    64,    64,    64,    64,    64,    64,    65,
      65,    72,    74,    77,    79,    81,    83,    86,    96,   106,
     113,   116,   123,   123,   133,   135,   137,   137,   139,   139,
     141,   143,   143,   145,   146,   147,   150,   150,   156,   156,
     158,   159,   159,   160,   161,   163,   165,   166,   167,   169,
     171,   174,   174,   174,   177,   177,   177,   180,   180,   180,
<<<<<<< HEAD
     184,   184,   187,   189,   189,   189,   191,   196,   196,   196,
     198,   198,   198,   198,   198,   200,   200,   201,   201,   202,
     202,   203,   203,   204,   204,   205,   205,   207,   207,   207,
     207,   209,   209,   209,   209
=======
     184,   184,   186,   188,   188,   188,   190,   195,   195,   197,
     197,   197,   197,   197,   197,   197,   197,   199,   201,   201,
     201
>>>>>>> origin/master
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INSERT", "INTO", "VALUES", "SELECT",
  "FROM", "CREATE", "TABLE", "INTEGER", "VARCHAR", "DOUBLE", "CHAR",
  "PRIMARY", "KEY", "REFERENCES", "DATABASE", "DROP", "OBJECT", "NUMBER",
  "VALUE", "QUIT", "LIST_TABLES", "LIST_TABLE", "ALPHANUM", "CONNECT",
  "HELP", "LIST_DBASES", "CLEAR", "CONTR", "WHERE", "AND", "OR", "YEQ",
  "YLT", "YGT", "YNQ", "YGTQ", "YLTQ", "'('", "')'", "';'", "','", "'*'",
  "$accept", "start", "connection", "qualquer_coisa", "exit_program",
  "clear", "parentesis_open", "parentesis_close", "table_attr",
  "list_tables", "list_databases", "help_pls", "contributors", "insert",
  "$@1", "semicolon", "table", "opt_column_list", "column_list", "column",
  "value_list", "value", "create_table", "$@2", "table_column_attr",
  "type", "$@3", "column_create", "attribute", "table_fk", "column_fk",
  "drop_table", "$@4", "$@5", "create_database", "$@6", "$@7",
  "drop_database", "$@8", "$@9", "select", "$@10", "table_select",
  "columns_list", "projection", "condition_where", "$@11", "clause",
  "$@12", "$@13", "condition", "$@14", "$@15", "$@16", "$@17", "$@18",
  "$@19", "operatingL", "operatingR", YY_NULLPTR
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
      40,    41,    59,    44,    42
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
<<<<<<< HEAD
      15,    18,   -81,    -7,    -4,   -81,   -81,   -81,    -5,    13,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,    36,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -16,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,    21,   -81,   -81,    46,    32,
      21,    45,    57,    58,   -81,    38,    60,   -16,    38,   -81,
     -81,   -81,    62,    75,   -81,    51,   -81,    64,    42,    42,
      42,   -81,    44,    43,    38,   -81,    42,   -81,    44,    61,
     -81,   -81,   -81,   -81,    62,    -9,    10,   -81,    42,   -81,
     -81,   -81,   -81,     3,   -81,   -81,   -81,   -81,    44,    47,
     -81,   -81,   -81,   -81,    -8,   -81,    24,   -81,    38,    72,
      69,    48,    42,    -9,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,    73,   -81,   -81,    49,    64,   -81,   -81,    10,
      10,    27,    27,    27,    27,    27,    27,    44,    76,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,    53,   -81
=======
       8,    14,   -72,    -7,     0,   -72,   -72,   -72,     5,    28,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    29,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -11,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,    36,   -72,   -72,    45,    18,
      36,    43,    44,    46,   -72,    26,    48,   -11,    26,   -72,
     -72,   -72,    49,    64,   -72,    40,   -72,    51,    30,    30,
      30,   -72,    32,    31,    26,    56,    30,   -72,    32,    10,
     -72,   -72,   -72,   -72,    49,    33,   -72,     7,   -72,    30,
     -72,   -72,   -72,   -72,    -1,   -72,   -72,   -72,   -72,    32,
      34,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    39,
     -72,    26,    61,    59,    37,    30,    33,   -72,   -72,   -72,
     -72,    62,   -72,   -72,    41,    51,   -72,   -72,    32,    60,
     -72,   -72,   -72,    42,   -72
>>>>>>> origin/master
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,     0,    70,     0,     0,    22,    23,    28,     0,     0,
      30,    29,    24,    31,    25,    26,    34,     0,    10,    19,
      11,    17,    13,    14,     8,     9,    16,    15,    18,     2,
      12,     4,     6,     5,     7,     3,    32,     0,    46,    64,
      61,    67,    27,    21,     1,     0,    76,    73,     0,    74,
       0,     0,     0,     0,    35,    36,     0,     0,     0,    65,
      62,    68,     0,     0,    72,    77,    75,     0,     0,     0,
<<<<<<< HEAD
       0,    40,     0,    38,     0,    78,     0,    55,     0,     0,
      66,    63,    69,    37,     0,     0,     0,    71,     0,    50,
      51,    53,    54,    56,    39,    44,    43,    45,     0,    41,
      97,    99,    98,   100,    79,    80,     0,    47,     0,     0,
       0,    48,     0,     0,    83,    81,    85,    87,    89,    91,
      93,    95,     0,    57,    59,     0,     0,    33,    42,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      84,    82,   101,   103,   102,   104,    86,    88,    90,    92,
      94,    96,    52,    60,     0,    58
=======
       0,    40,     0,    38,     0,     0,     0,    55,     0,     0,
      66,    63,    69,    37,     0,     0,    87,     0,    71,     0,
      50,    51,    53,    54,    56,    39,    44,    43,    45,     0,
      41,    79,    80,    81,    82,    83,    84,    85,    86,     0,
      47,     0,     0,     0,    48,     0,     0,    90,    89,    88,
      78,     0,    57,    59,     0,     0,    33,    42,     0,     0,
      49,    52,    60,     0,    58
>>>>>>> origin/master
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
<<<<<<< HEAD
     -81,   -81,   -81,   -81,   -81,   -81,   -54,   -72,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -61,    50,   -81,     8,   -81,
     -17,   -81,   -81,   -81,   -29,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,    41,   -81,   -81,   -81,   -81,   -81,   -81,
     -80,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -66
=======
     -72,   -72,   -72,   -72,   -72,   -72,   -55,   -71,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -64,    35,   -72,     2,   -72,
     -32,   -72,   -72,   -72,   -38,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    38,   -72,   -72,   -72,   -72,   -72
>>>>>>> origin/master
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    45,    30,    55,    63,    72,    73,
<<<<<<< HEAD
      98,    99,    31,    50,    78,    93,   108,    79,   111,   125,
     154,    32,    52,    69,    33,    51,    68,    34,    53,    70,
      35,    37,    65,    48,    49,    76,    86,   104,   130,   129,
     105,   131,   132,   133,   134,   135,   136,   106,   146
=======
      99,   100,    31,    50,    78,    94,   111,    79,   114,   124,
     133,    32,    52,    69,    33,    51,    68,    34,    53,    70,
      35,    37,    65,    48,    49,    76,   109,    87,   120
>>>>>>> origin/master
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      83,    62,    38,    46,    67,    40,    88,    80,    81,    82,
      39,    95,    96,    41,    42,    87,    97,   109,     1,   110,
      85,     2,    36,     3,   114,   115,   112,   107,    47,   100,
     101,   102,    43,     4,     5,   103,    44,     6,     7,     8,
      54,     9,    10,    11,    12,    13,   142,   143,   144,   140,
     141,   127,   145,    56,   122,    14,    15,    16,   116,   117,
     118,   119,   120,   121,    59,   152,   147,   148,   149,   150,
     151,    89,    90,    91,    92,    57,    60,    61,    14,    64,
      74,    71,    75,    77,    16,    15,    84,   123,   124,   138,
     113,   126,    94,   137,   155,   153,   128,   139,    66,     0,
      58
=======
      62,    83,    38,    67,    80,    81,    82,    89,    46,    40,
      39,     1,    88,   112,     2,   113,     3,    41,    36,    85,
      90,    91,    92,    93,    42,   110,     4,     5,   115,    44,
       6,     7,     8,    47,     9,    10,    11,    12,    13,   101,
     102,   103,   104,   105,   106,   107,   108,    43,    14,    15,
      16,   126,    56,    96,    97,    54,   121,   131,    98,   117,
     118,    57,    59,    60,   119,    61,    14,    64,    71,    74,
      77,    75,    16,    15,    84,    86,   122,   116,   123,   132,
     125,   129,   128,   134,   127,    58,    95,   130,     0,     0,
       0,     0,     0,     0,     0,    66
>>>>>>> origin/master
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
      72,    55,     9,    19,    58,     9,    78,    68,    69,    70,
      17,    20,    21,    17,    19,    76,    25,    14,     3,    16,
      74,     6,     4,     8,    32,    33,    98,    88,    44,    19,
      20,    21,    19,    18,    19,    25,     0,    22,    23,    24,
      19,    26,    27,    28,    29,    30,    19,    20,    21,   129,
     130,   112,    25,     7,   108,    40,    41,    42,    34,    35,
      36,    37,    38,    39,    19,   137,   132,   133,   134,   135,
     136,    10,    11,    12,    13,    43,    19,    19,    40,    19,
       5,    19,    31,    19,    42,    41,    43,    15,    19,    40,
      43,    43,    84,    20,    41,    19,   113,   126,    57,    -1,
      50
=======
      55,    72,     9,    58,    68,    69,    70,    78,    19,     9,
      17,     3,    76,    14,     6,    16,     8,    17,     4,    74,
      10,    11,    12,    13,    19,    89,    18,    19,    99,     0,
      22,    23,    24,    44,    26,    27,    28,    29,    30,    32,
      33,    34,    35,    36,    37,    38,    39,    19,    40,    41,
      42,   115,     7,    20,    21,    19,   111,   128,    25,    20,
      21,    43,    19,    19,    25,    19,    40,    19,    19,     5,
      19,    31,    42,    41,    43,    19,    15,    43,    19,    19,
      43,    40,    20,    41,   116,    50,    84,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57
>>>>>>> origin/master
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     6,     8,    18,    19,    22,    23,    24,    26,
      27,    28,    29,    30,    40,    41,    42,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      60,    67,    76,    79,    82,    85,     4,    86,     9,    17,
       9,    17,    19,    19,     0,    59,    19,    44,    88,    89,
      68,    80,    77,    83,    19,    61,     7,    43,    61,    19,
      19,    19,    51,    62,    19,    87,    88,    51,    81,    78,
      84,    19,    63,    64,     5,    31,    90,    19,    69,    72,
<<<<<<< HEAD
      60,    60,    60,    52,    43,    51,    91,    60,    52,    10,
      11,    12,    13,    70,    63,    20,    21,    25,    65,    66,
      19,    20,    21,    25,    92,    95,   102,    60,    71,    14,
      16,    73,    52,    43,    32,    33,    34,    35,    36,    37,
      38,    39,    51,    15,    19,    74,    43,    60,    65,    94,
      93,    96,    97,    98,    99,   100,   101,    20,    40,    69,
      95,    95,    19,    20,    21,    25,   103,   103,   103,   103,
     103,   103,    52,    19,    75,    41
=======
      60,    60,    60,    52,    43,    51,    19,    92,    60,    52,
      10,    11,    12,    13,    70,    63,    20,    21,    25,    65,
      66,    32,    33,    34,    35,    36,    37,    38,    39,    91,
      60,    71,    14,    16,    73,    52,    43,    20,    21,    25,
      93,    51,    15,    19,    74,    43,    60,    65,    20,    40,
      69,    52,    19,    75,    41
>>>>>>> origin/master
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    59,    58,    60,    61,    62,    62,    63,    63,
      64,    65,    65,    66,    66,    66,    68,    67,    69,    69,
      70,    71,    70,    70,    70,    72,    73,    73,    73,    74,
      75,    77,    78,    76,    80,    81,    79,    83,    84,    82,
<<<<<<< HEAD
      86,    85,    87,    88,    88,    88,    89,    90,    91,    90,
      92,    93,    92,    94,    92,    96,    95,    97,    95,    98,
      95,    99,    95,   100,    95,   101,    95,   102,   102,   102,
     102,   103,   103,   103,   103
=======
      86,    85,    87,    88,    88,    88,    89,    90,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    93,    93,
      93
>>>>>>> origin/master
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     0,    10,     1,     1,     0,     3,     1,     3,
       1,     1,     3,     1,     1,     1,     0,     8,     3,     5,
       1,     0,     5,     1,     1,     1,     0,     2,     5,     1,
       1,     0,     0,     6,     0,     0,     6,     0,     0,     6,
<<<<<<< HEAD
       0,     7,     1,     1,     1,     3,     1,     0,     0,     3,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     1,     1,     1,
       1,     1,     1,     1,     1
=======
       0,     7,     1,     1,     1,     3,     1,     0,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
>>>>>>> origin/master
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
        case 12:
#line 63 "yacc.y" /* yacc.c:1646  */
    {GLOBAL_PARSER.consoleFlag = 1; return 0;}
<<<<<<< HEAD
#line 1436 "y.tab.c" /* yacc.c:1646  */
=======
#line 1423 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 21:
#line 72 "yacc.y" /* yacc.c:1646  */
    {connect(*yytext); GLOBAL_PARSER.consoleFlag = 1; return 0;}
<<<<<<< HEAD
#line 1442 "y.tab.c" /* yacc.c:1646  */
=======
#line 1429 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 22:
#line 74 "yacc.y" /* yacc.c:1646  */
    {GLOBAL_PARSER.consoleFlag = 1; GLOBAL_PARSER.noerror = 0; return 0;}
<<<<<<< HEAD
#line 1448 "y.tab.c" /* yacc.c:1646  */
=======
#line 1435 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 23:
#line 77 "yacc.y" /* yacc.c:1646  */
    {exit(0);}
<<<<<<< HEAD
#line 1454 "y.tab.c" /* yacc.c:1646  */
=======
#line 1441 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 24:
#line 79 "yacc.y" /* yacc.c:1646  */
    {clear(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
<<<<<<< HEAD
#line 1460 "y.tab.c" /* yacc.c:1646  */
=======
#line 1447 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 25:
#line 81 "yacc.y" /* yacc.c:1646  */
    {GLOBAL_PARSER.parentesis++;}
<<<<<<< HEAD
#line 1466 "y.tab.c" /* yacc.c:1646  */
=======
#line 1453 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 26:
#line 83 "yacc.y" /* yacc.c:1646  */
    {GLOBAL_PARSER.parentesis--;}
<<<<<<< HEAD
#line 1472 "y.tab.c" /* yacc.c:1646  */
=======
#line 1459 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 27:
#line 86 "yacc.y" /* yacc.c:1646  */
    {
    if(connected.conn_active) {
        printTable(yylval.strval);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
<<<<<<< HEAD
#line 1485 "y.tab.c" /* yacc.c:1646  */
=======
#line 1472 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 28:
#line 96 "yacc.y" /* yacc.c:1646  */
    {
    if(connected.conn_active) {
        printTable(NULL);
        GLOBAL_PARSER.consoleFlag = 1;
    } else
        notConnected();
    return 0;
}
<<<<<<< HEAD
#line 1498 "y.tab.c" /* yacc.c:1646  */
=======
#line 1485 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 29:
#line 106 "yacc.y" /* yacc.c:1646  */
    {
    showDB();
    GLOBAL_PARSER.consoleFlag = 1;
    return 0;
}
<<<<<<< HEAD
#line 1508 "y.tab.c" /* yacc.c:1646  */
=======
#line 1495 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 30:
#line 113 "yacc.y" /* yacc.c:1646  */
    {help(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
<<<<<<< HEAD
#line 1514 "y.tab.c" /* yacc.c:1646  */
=======
#line 1501 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 31:
#line 116 "yacc.y" /* yacc.c:1646  */
    {contr(); GLOBAL_PARSER.consoleFlag = 1; return 0;}
<<<<<<< HEAD
#line 1520 "y.tab.c" /* yacc.c:1646  */
=======
#line 1507 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 32:
#line 123 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_INSERT);}
<<<<<<< HEAD
#line 1526 "y.tab.c" /* yacc.c:1646  */
=======
#line 1513 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 33:
#line 123 "yacc.y" /* yacc.c:1646  */
    {
    if (GLOBAL_PARSER.col_count == GLOBAL_PARSER.val_count || GLOBAL_DATA.columnName == NULL)
        GLOBAL_DATA.N = GLOBAL_PARSER.val_count;
    else {
        printf("ERROR: The column counter doesn't match the value counter.\n");
        GLOBAL_PARSER.noerror=0;
    }
    return 0;
}
<<<<<<< HEAD
#line 1540 "y.tab.c" /* yacc.c:1646  */
=======
#line 1527 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 35:
#line 135 "yacc.y" /* yacc.c:1646  */
    {setObjName(yytext);}
<<<<<<< HEAD
#line 1546 "y.tab.c" /* yacc.c:1646  */
=======
#line 1533 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 40:
#line 141 "yacc.y" /* yacc.c:1646  */
    {setColumnInsert(yytext);}
<<<<<<< HEAD
#line 1552 "y.tab.c" /* yacc.c:1646  */
=======
#line 1539 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 43:
#line 145 "yacc.y" /* yacc.c:1646  */
    {setValueInsert(yylval.strval, 'D');}
<<<<<<< HEAD
#line 1558 "y.tab.c" /* yacc.c:1646  */
=======
#line 1545 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 44:
#line 146 "yacc.y" /* yacc.c:1646  */
    {setValueInsert(yylval.strval, 'I');}
<<<<<<< HEAD
#line 1564 "y.tab.c" /* yacc.c:1646  */
=======
#line 1551 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 45:
#line 147 "yacc.y" /* yacc.c:1646  */
    {setValueInsert(yylval.strval, 'S');}
<<<<<<< HEAD
#line 1570 "y.tab.c" /* yacc.c:1646  */
=======
#line 1557 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 46:
#line 150 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_CREATE_TABLE);}
<<<<<<< HEAD
#line 1576 "y.tab.c" /* yacc.c:1646  */
=======
#line 1563 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 47:
#line 150 "yacc.y" /* yacc.c:1646  */
    {
    GLOBAL_DATA.N = GLOBAL_PARSER.col_count;

    return 0;
}
<<<<<<< HEAD
#line 1586 "y.tab.c" /* yacc.c:1646  */
=======
#line 1573 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 50:
#line 158 "yacc.y" /* yacc.c:1646  */
    {setColumnTypeCreate('I');}
<<<<<<< HEAD
#line 1592 "y.tab.c" /* yacc.c:1646  */
=======
#line 1579 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 51:
#line 159 "yacc.y" /* yacc.c:1646  */
    {setColumnTypeCreate('S');}
<<<<<<< HEAD
#line 1598 "y.tab.c" /* yacc.c:1646  */
=======
#line 1585 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 52:
#line 159 "yacc.y" /* yacc.c:1646  */
    {setColumnSizeCreate(yylval.strval);}
<<<<<<< HEAD
#line 1604 "y.tab.c" /* yacc.c:1646  */
=======
#line 1591 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 53:
#line 160 "yacc.y" /* yacc.c:1646  */
    {setColumnTypeCreate('D');}
<<<<<<< HEAD
#line 1610 "y.tab.c" /* yacc.c:1646  */
=======
#line 1597 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 54:
#line 161 "yacc.y" /* yacc.c:1646  */
    {setColumnTypeCreate('C');}
<<<<<<< HEAD
#line 1616 "y.tab.c" /* yacc.c:1646  */
=======
#line 1603 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 55:
#line 163 "yacc.y" /* yacc.c:1646  */
    {setColumnCreate(yytext);}
<<<<<<< HEAD
#line 1622 "y.tab.c" /* yacc.c:1646  */
=======
#line 1609 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 57:
#line 166 "yacc.y" /* yacc.c:1646  */
    {setColumnPKCreate();}
<<<<<<< HEAD
#line 1628 "y.tab.c" /* yacc.c:1646  */
=======
#line 1615 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 59:
#line 169 "yacc.y" /* yacc.c:1646  */
    {setColumnFKTableCreate(yytext);}
<<<<<<< HEAD
#line 1634 "y.tab.c" /* yacc.c:1646  */
=======
#line 1621 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 60:
#line 171 "yacc.y" /* yacc.c:1646  */
    {setColumnFKColumnCreate(yytext);}
<<<<<<< HEAD
#line 1640 "y.tab.c" /* yacc.c:1646  */
=======
#line 1627 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 61:
#line 174 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_DROP_TABLE);}
<<<<<<< HEAD
#line 1646 "y.tab.c" /* yacc.c:1646  */
=======
#line 1633 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 62:
#line 174 "yacc.y" /* yacc.c:1646  */
    {setObjName(yytext);}
<<<<<<< HEAD
#line 1652 "y.tab.c" /* yacc.c:1646  */
=======
#line 1639 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 63:
#line 174 "yacc.y" /* yacc.c:1646  */
    {return 0;}
<<<<<<< HEAD
#line 1658 "y.tab.c" /* yacc.c:1646  */
=======
#line 1645 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 64:
#line 177 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_CREATE_DATABASE);}
<<<<<<< HEAD
#line 1664 "y.tab.c" /* yacc.c:1646  */
=======
#line 1651 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 65:
#line 177 "yacc.y" /* yacc.c:1646  */
    {setObjName(yytext);}
<<<<<<< HEAD
#line 1670 "y.tab.c" /* yacc.c:1646  */
=======
#line 1657 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 66:
#line 177 "yacc.y" /* yacc.c:1646  */
    {return 0;}
<<<<<<< HEAD
#line 1676 "y.tab.c" /* yacc.c:1646  */
=======
#line 1663 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 67:
#line 180 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_DROP_DATABASE);}
<<<<<<< HEAD
#line 1682 "y.tab.c" /* yacc.c:1646  */
=======
#line 1669 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 68:
#line 180 "yacc.y" /* yacc.c:1646  */
    {setObjName(yytext);}
<<<<<<< HEAD
#line 1688 "y.tab.c" /* yacc.c:1646  */
=======
#line 1675 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 69:
#line 180 "yacc.y" /* yacc.c:1646  */
    {return 0;}
<<<<<<< HEAD
#line 1694 "y.tab.c" /* yacc.c:1646  */
=======
#line 1681 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 70:
#line 184 "yacc.y" /* yacc.c:1646  */
    {setMode(OP_SELECT_ALL);}
<<<<<<< HEAD
#line 1700 "y.tab.c" /* yacc.c:1646  */
=======
#line 1687 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 71:
#line 184 "yacc.y" /* yacc.c:1646  */
    {return 0;}
<<<<<<< HEAD
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 187 "yacc.y" /* yacc.c:1646  */
    {setObjNameSelect(yytext);}
#line 1712 "y.tab.c" /* yacc.c:1646  */
=======
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 186 "yacc.y" /* yacc.c:1646  */
    {setObjName(yytext);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 76:
#line 191 "yacc.y" /* yacc.c:1646  */
    {setColumnProjection(yytext);}
<<<<<<< HEAD
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 196 "yacc.y" /* yacc.c:1646  */
    {setWhere(NONE);}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 198 "yacc.y" /* yacc.c:1646  */
    {setWhere(logic_OR);}
#line 1730 "y.tab.c" /* yacc.c:1646  */
=======
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 199 "yacc.y" /* yacc.c:1646  */
    {setColumnTest(yytext);}
#line 1711 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 83:
#line 198 "yacc.y" /* yacc.c:1646  */
    {setWhere(logic_AND);}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 200 "yacc.y" /* yacc.c:1646  */
    {setCompWhereOp(EQ);}
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 201 "yacc.y" /* yacc.c:1646  */
<<<<<<< HEAD
    {setCompWhereOp(LT);}
#line 1748 "y.tab.c" /* yacc.c:1646  */
=======
    {addTypeValue(ALPHANUM_TYPE);addValueTest(*yytext);}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 201 "yacc.y" /* yacc.c:1646  */
    {addTypeValue(NUMBER_TYPE);addValueTest(*yytext);}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 201 "yacc.y" /* yacc.c:1646  */
    {addTypeValue(INT_TYPE);addValueTest(*yytext);}
#line 1729 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
    break;

  case 89:
#line 202 "yacc.y" /* yacc.c:1646  */
    {setCompWhereOp(GT);}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

<<<<<<< HEAD
  case 91:
#line 203 "yacc.y" /* yacc.c:1646  */
    {setCompWhereOp(NQ);}
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 204 "yacc.y" /* yacc.c:1646  */
    {setCompWhereOp(GTQ);}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 205 "yacc.y" /* yacc.c:1646  */
    {setCompWhereOp(LTQ);}
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 207 "yacc.y" /* yacc.c:1646  */
    {setCompWhereLeft(yytext, 'C');}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 207 "yacc.y" /* yacc.c:1646  */
    {setCompWhereLeft(yytext, 'D');}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 207 "yacc.y" /* yacc.c:1646  */
    {setCompWhereLeft(yytext, 'I');}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 207 "yacc.y" /* yacc.c:1646  */
    {setCompWhereLeft(yytext, 'S');}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 209 "yacc.y" /* yacc.c:1646  */
    {setCompWhereRight(yytext, 'C');}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 209 "yacc.y" /* yacc.c:1646  */
    {setCompWhereRight(yytext, 'D');}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 209 "yacc.y" /* yacc.c:1646  */
    {setCompWhereRight(yytext, 'I');}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 209 "yacc.y" /* yacc.c:1646  */
    {setCompWhereRight(yytext, 'S');}
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1824 "y.tab.c" /* yacc.c:1646  */
=======
#line 1733 "y.tab.c" /* yacc.c:1646  */
>>>>>>> origin/master
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
#line 212 "yacc.y" /* yacc.c:1906  */


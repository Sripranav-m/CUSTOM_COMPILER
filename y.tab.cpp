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
#line 1 "yacc.y"

	#include "main.h"
	int yylex();
	void yyerror(string);
	char mytext[10000]; // get from lex file.

	TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
	int Num_variables=0;
	map<pair<string,string>, int> symbol_table;
	map<string,int> list_size;
	map<string,pair<int,int>> matrix;
	vector<map<string,string>> all_scopes_variable_types;
	map<string,string> variable_types;

	vector<map<pair<string,string>, int>> all_scopes_symbol_tables;

	map<string,int> function_scope_definer;

	map<string,int> function_args; 
	void dotraversal(TreeNode* head);
	vector<string> text;
	vector<string> data;
	vector<string> bss; // 
	vector<string> printint; // To include the print subroutine
	vector<string> printList;
	vector<string> printNewLine;
	map<string,vector<string>> function_arguments;
	map<string,int> Num_variablesF;
	void CodeGenerator(TreeNode* root);
	void putx86inafile();
	void set_integer_print_subroutine();
	void set_data_segment();
	void set_scanner_integer();
	void string_to_number_subroutine();
	void set_list_print_subroutine();
	void set_go_to_new_line_subroutine();
	int load_into_register(string);
	void makenulls();
	int count_loops=0;
	int num_scans=0;
	int matrix_size=0;

	string scope="";
	

#line 116 "y.tab.cpp"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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
    INT = 258,
    STRING = 259,
    CHARACTER = 260,
    FLOAT = 261,
    LIST = 262,
    MATRIX = 263,
    IDENTIFIER = 264,
    CHAR = 265,
    STR = 266,
    FUNCTION_IDENTIFIER = 267,
    N_NUMBER = 268,
    NON_N_NUMBER = 269,
    FLOATING = 270,
    COMMA = 271,
    SEMICOLON = 272,
    OFB = 273,
    CFB = 274,
    ONB = 275,
    CNB = 276,
    PLUS = 277,
    MINUS = 278,
    MULTIPLY = 279,
    DIVIDE = 280,
    IF = 281,
    ELSE = 282,
    ELIF = 283,
    WHILE = 284,
    FOR = 285,
    PRINT = 286,
    SCAN = 287,
    OR = 288,
    AND = 289,
    NOT = 290,
    EQUALTO = 291,
    LT = 292,
    GT = 293,
    LE = 294,
    GE = 295,
    EE = 296,
    NEQ = 297,
    INC = 298,
    DEC = 299,
    IC = 300,
    BAND = 301,
    BOR = 302,
    BXOR = 303,
    OSB = 304,
    CSB = 305,
    ATSIZE = 306,
    AATSIZE = 307,
    RETURN = 308
  };
#endif
/* Tokens.  */
#define INT 258
#define STRING 259
#define CHARACTER 260
#define FLOAT 261
#define LIST 262
#define MATRIX 263
#define IDENTIFIER 264
#define CHAR 265
#define STR 266
#define FUNCTION_IDENTIFIER 267
#define N_NUMBER 268
#define NON_N_NUMBER 269
#define FLOATING 270
#define COMMA 271
#define SEMICOLON 272
#define OFB 273
#define CFB 274
#define ONB 275
#define CNB 276
#define PLUS 277
#define MINUS 278
#define MULTIPLY 279
#define DIVIDE 280
#define IF 281
#define ELSE 282
#define ELIF 283
#define WHILE 284
#define FOR 285
#define PRINT 286
#define SCAN 287
#define OR 288
#define AND 289
#define NOT 290
#define EQUALTO 291
#define LT 292
#define GT 293
#define LE 294
#define GE 295
#define EE 296
#define NEQ 297
#define INC 298
#define DEC 299
#define IC 300
#define BAND 301
#define BOR 302
#define BXOR 303
#define OSB 304
#define CSB 305
#define ATSIZE 306
#define AATSIZE 307
#define RETURN 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "yacc.y"

	class TreeNode* node;

#line 278 "y.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */



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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  202

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
       0,    70,    70,    76,    80,    86,    91,    98,   113,   131,
     155,   162,   169,   212,   216,   224,   229,   236,   247,   254,
     258,   265,   269,   274,   278,   283,   288,   292,   296,   300,
     304,   309,   315,   323,   335,   346,   354,   361,   372,   383,
     394,   401,   410,   416,   421,   426,   435,   449,   464,   488,
     498,   502,   508,   514,   520,   526,   532,   538,   544,   550,
     556,   562,   568,   574,   580,   584,   590,   596,   604,   610,
     617,   622,   629,   634,   642,   647,   653,   660,   664,   668,
     673,   678,   684,   690,   694,   700,   707,   714,   721,   737,
     745,   752,   758,   763,   771
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "CHARACTER", "FLOAT",
  "LIST", "MATRIX", "IDENTIFIER", "CHAR", "STR", "FUNCTION_IDENTIFIER",
  "N_NUMBER", "NON_N_NUMBER", "FLOATING", "COMMA", "SEMICOLON", "OFB",
  "CFB", "ONB", "CNB", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "IF", "ELSE",
  "ELIF", "WHILE", "FOR", "PRINT", "SCAN", "OR", "AND", "NOT", "EQUALTO",
  "LT", "GT", "LE", "GE", "EE", "NEQ", "INC", "DEC", "IC", "BAND", "BOR",
  "BXOR", "OSB", "CSB", "ATSIZE", "AATSIZE", "RETURN", "$accept",
  "PROGRAM", "DECLARATION_LIST", "DECLARATION", "VARIABLE_DECLARATION",
  "LIST_TYPE", "MATRIX_TYPE", "FUNCTION_DECLARATION", "PARAMS",
  "PARAM_LIST_NT", "PARAM", "STATEMENT_LIST", "STATEMENT",
  "RETURN_STATEMENT", "PRINT_STATEMENT", "SCAN_STATEMENT",
  "COMPOUND_STATEMENT", "IF_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT",
  "INCDEC_STATEMENT", "VARIABLE_TYPE", "LOCAL_DECLARATION",
  "ASSIGNMENT_STATEMENT", "EXPRESSION", "SIZE_EXPRESSION", "LIST_ELEMENT",
  "MATRIX_ELEMENT", "MATVAR_NT", "PEXPRESSION", "PRINT_SCAN_ITEM",
  "INTEGER_NT", "FLOAT_NT", "CHARACTER_NT", "IDENTIFIER_NT",
  "FUNCTION_IDENTIFIER_NT", YY_NULLPTR
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

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     185,   -59,   -59,   -59,   -59,   -59,   -59,    10,   185,   -59,
     -59,    22,    22,   -59,    66,   -59,   -59,   -59,   -28,    -6,
     -59,     3,    33,   211,   234,   -59,   234,   104,   -59,    15,
      29,    86,   -59,    -8,    70,    44,   -59,    22,    52,    89,
     -59,   -59,   101,    93,   104,    52,   -59,    69,   176,   -59,
     -59,   110,   117,   122,   136,   138,   145,   234,    22,    22,
     143,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
      22,   -59,   -59,    27,   -59,   108,   108,    22,    22,    22,
     113,    12,   118,   127,   -59,   -59,    13,   108,   149,   154,
     -59,   -59,   108,   108,   101,    22,    22,     2,   -59,   175,
     -59,   -59,   -59,   146,   157,    65,   108,   -22,   165,    52,
     180,   -59,   -59,   234,   234,   -59,    17,   -59,   -59,    91,
     105,    -9,     4,   128,   186,    52,    52,   176,   108,   108,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,   234,   104,   176,    40,   187,   192,   160,
       6,   -59,   -59,   -59,   194,   -59,   137,   -59,   101,   -59,
     -59,   191,   105,   105,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   169,   114,   205,
     -59,    22,   -59,   -59,   210,   101,   -59,   -59,   -59,   176,
     179,   195,   -59,   224,    39,   -59,   196,   -59,   176,   232,
     -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    42,    43,    44,    45,    10,    11,     0,     2,     4,
       5,     0,     0,     6,     0,     1,     3,    91,     0,     0,
      94,     0,     0,     0,     0,     7,     0,    14,    88,     0,
       0,     0,    87,     0,     0,    13,    16,     0,    18,     0,
      92,    93,     0,     0,     0,    17,     8,     0,     0,    12,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    30,    28,    29,    22,    23,    24,    25,    26,
       0,    27,    21,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    35,    19,     0,     0,     0,     0,
      90,    89,     0,     0,     0,     0,     0,     0,    64,    50,
      77,    83,    85,    78,     0,     0,     0,     0,     0,    86,
       0,    32,    31,     0,     0,    46,     0,    40,    41,     0,
      67,     0,     0,     0,    75,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,    49,    81,    82,     0,    84,     0,    75,     0,    73,
      71,    36,    66,    65,    51,    52,    53,    54,    61,    60,
      59,    58,    62,    63,    55,    57,    56,     0,     0,     0,
      38,     0,    33,    34,    92,     0,    70,    72,    74,     0,
      79,    80,    76,     0,     0,    47,     0,    37,     0,     0,
      39,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   242,   -59,    24,    64,   -59,   107,   -59,
     208,   -59,   -58,   -59,   -59,   -59,   212,   -59,   -59,   -59,
      72,    11,   -59,   177,   -48,   -59,   -59,   -59,   134,   100,
     178,   -17,   -59,   -59,   -11,   244
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    58,    59,    13,    34,    35,
      36,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    97,    98,   121,   122,   123,    99,
     108,   100,   101,   102,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    19,    85,    21,    28,    32,    30,    33,    42,    30,
      15,    14,    31,    31,    87,    31,    38,    28,    32,    14,
      25,    23,   185,   127,    11,    47,    45,    26,   105,   112,
     115,    17,    11,    38,   151,   128,   129,    73,    37,   116,
      80,   153,    40,    24,   119,   120,    81,    82,    83,    73,
     128,   129,    26,    27,   155,    37,    40,   181,   146,    86,
      44,    26,    26,    87,    12,    39,   107,   109,   109,   161,
      88,    89,    12,   128,   129,    17,    26,   124,    20,    40,
     162,   163,    88,    89,   125,   126,   145,   180,    26,    17,
      90,    43,    20,    28,    32,    91,   149,   150,   128,   129,
      92,    26,    31,    31,   154,   157,    46,     1,     2,     3,
       4,    48,   152,    17,    28,    32,    73,    17,    90,    51,
      20,    28,    32,    91,   128,   129,   177,    74,    92,    94,
     111,   197,   178,    38,    73,    26,    41,    75,   128,   129,
     200,   188,    76,    93,   158,   159,     1,     2,     3,     4,
       5,     6,    17,   158,   187,    37,    77,    94,    78,    95,
      96,    48,    84,    26,   191,    79,   117,   113,   196,    52,
     194,   118,    53,    54,    55,    56,   114,   144,    73,     1,
       2,     3,     4,     5,     6,    17,   147,    73,     1,     2,
       3,     4,     5,     6,    48,   143,    57,   130,   131,   132,
     133,   148,    52,   160,   182,    53,    54,    55,    56,   183,
     184,   186,   134,   135,   136,   137,   138,   139,   189,   190,
      17,   140,   141,   142,    28,    29,   192,   195,   -92,    57,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,    17,   -93,   198,   199,    28,    32,   201,
      16,   179,    50,   193,   106,    49,   156,   110,    22
};

static const yytype_uint8 yycheck[] =
{
      11,    12,    60,    14,    13,    14,    23,    24,    16,    26,
       0,     0,    23,    24,    36,    26,    27,    13,    14,     8,
      17,    49,    16,    21,     0,    42,    37,    49,    76,    17,
      17,     9,     8,    44,    17,    33,    34,    48,    27,    87,
      57,    50,    50,    49,    92,    93,    57,    58,    59,    60,
      33,    34,    49,    20,    50,    44,    50,    17,   106,    70,
      16,    49,    49,    36,     0,    50,    77,    78,    79,   127,
      43,    44,     8,    33,    34,     9,    49,    94,    12,    50,
     128,   129,    43,    44,    95,    96,    21,   145,    49,     9,
      10,    21,    12,    13,    14,    15,   113,   114,    33,    34,
      20,    49,   113,   114,   121,   122,    17,     3,     4,     5,
       6,    18,    21,     9,    13,    14,   127,     9,    10,    50,
      12,    13,    14,    15,    33,    34,   143,    17,    20,    49,
      17,   189,   143,   144,   145,    49,    50,    20,    33,    34,
     198,   158,    20,    35,    16,    17,     3,     4,     5,     6,
       7,     8,     9,    16,    17,   144,    20,    49,    20,    51,
      52,    18,    19,    49,    50,    20,    17,    49,   185,    26,
     181,    17,    29,    30,    31,    32,    49,    20,   189,     3,
       4,     5,     6,     7,     8,     9,    21,   198,     3,     4,
       5,     6,     7,     8,    18,    49,    53,    22,    23,    24,
      25,    21,    26,    17,    17,    29,    30,    31,    32,    17,
      50,    17,    37,    38,    39,    40,    41,    42,    27,    50,
       9,    46,    47,    48,    13,    14,    21,    17,    49,    53,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,     9,    49,    21,    50,    13,    14,    17,
       8,   144,    44,   181,    77,    43,   122,    79,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    55,    56,    57,
      58,    59,    60,    61,    75,     0,    57,     9,    88,    88,
      12,    88,    89,    49,    49,    17,    49,    20,    13,    14,
      85,    88,    14,    85,    62,    63,    64,    75,    88,    50,
      50,    50,    16,    21,    16,    88,    17,    85,    18,    70,
      64,    50,    26,    29,    30,    31,    32,    53,    59,    60,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    88,    17,    20,    20,    20,    20,    20,
      85,    88,    88,    88,    19,    66,    88,    36,    43,    44,
      10,    15,    20,    35,    49,    51,    52,    78,    79,    83,
      85,    86,    87,    88,    89,    78,    77,    88,    84,    88,
      84,    17,    17,    49,    49,    17,    78,    17,    17,    78,
      78,    80,    81,    82,    85,    88,    88,    21,    33,    34,
      22,    23,    24,    25,    37,    38,    39,    40,    41,    42,
      46,    47,    48,    49,    20,    21,    78,    21,    21,    85,
      85,    17,    21,    50,    85,    50,    82,    85,    16,    17,
      17,    66,    78,    78,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    85,    88,    62,
      66,    17,    17,    17,    50,    16,    17,    17,    85,    27,
      50,    50,    21,    74,    88,    17,    85,    66,    21,    50,
      66,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      59,    60,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    67,    67,    68,    69,    70,    71,    71,    72,    73,
      74,    74,    75,    75,    75,    75,    76,    76,    76,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    84,    85,    85,    86,
      87,    88,    88,    88,    89
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     8,
       1,     1,     6,     1,     0,     3,     1,     2,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     5,     3,     5,     7,     5,     8,
       3,     3,     1,     1,     1,     1,     3,     6,     8,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     2,     2,     2,
       3,     2,     3,     2,     3,     1,     4,     1,     1,     4,
       4,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     1
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
#line 70 "yacc.y"
                          {
							vector<TreeNode*> v={(yyvsp[0].node)};
							(yyval.node)=new TreeNode("PROGRAM",v);
							Abstract_Syntax_Tree=(yyval.node);
							}
#line 1612 "y.tab.cpp"
    break;

  case 3:
#line 76 "yacc.y"
                                              {
												vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node)=new TreeNode("DECLARATION_LIST",v);
												}
#line 1621 "y.tab.cpp"
    break;

  case 4:
#line 80 "yacc.y"
                                              {
								vector<TreeNode*> v={(yyvsp[0].node)};
								(yyval.node)=new TreeNode("DECLARATION_LIST",v);
							}
#line 1630 "y.tab.cpp"
    break;

  case 5:
#line 86 "yacc.y"
                                        {

			vector<TreeNode*> v={(yyvsp[0].node)};
			(yyval.node)=new TreeNode("DECLARATION",v);
			}
#line 1640 "y.tab.cpp"
    break;

  case 6:
#line 91 "yacc.y"
                                               {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("DECLARATION",v);
			}
#line 1649 "y.tab.cpp"
    break;

  case 7:
#line 98 "yacc.y"
                                                             {
															(yyvsp[0].node)=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        					(yyval.node) = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															if(variable_types.find((yyvsp[-1].node)->lex_val)==variable_types.end()){
																string var_type=(yyvsp[-2].node)->children[0]->NodeName;
																symbol_table[{(yyvsp[-1].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
																
																variable_types[(yyvsp[-1].node)->lex_val]=var_type;
															}
															else{
																// error
															}
						}
#line 1669 "y.tab.cpp"
    break;

  case 8:
#line 113 "yacc.y"
                                                                                                         {
							(yyvsp[-3].node)=new TreeNode("OSB");
							(yyvsp[-1].node)=new TreeNode("CSB");
							(yyvsp[0].node)=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node) = new TreeNode("VARIABLE_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[(yyvsp[-4].node)->lex_val]=atoi(mytext);
							if(variable_types.find((yyvsp[-4].node)->lex_val)==variable_types.end()){
								string var_type=(yyvsp[-5].node)->children[0]->NodeName;
								symbol_table[{(yyvsp[-4].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
								
								variable_types[(yyvsp[-4].node)->lex_val]=var_type;
							}
							else{
								// error
							}
						}
#line 1692 "y.tab.cpp"
    break;

  case 9:
#line 131 "yacc.y"
                                                                                                                         {
							(yyvsp[-5].node)=new TreeNode("OSB");
							(yyvsp[-3].node)=new TreeNode("COMMA");
							(yyvsp[-1].node)=new TreeNode("CSB");
							(yyvsp[0].node)=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node) = new TreeNode("VARIABLE_DECLARATION", v);
							matrix_size=stoi((yyvsp[-4].node)->lex_val)*stoi((yyvsp[-2].node)->lex_val);
							Num_variables+=matrix_size;
							
							matrix[(yyvsp[-6].node)->lex_val]={stoi((yyvsp[-4].node)->lex_val),stoi((yyvsp[-2].node)->lex_val)};

							if(variable_types.find((yyvsp[-6].node)->lex_val)==variable_types.end()){
								string var_type=(yyvsp[-7].node)->children[0]->NodeName;
								symbol_table[{(yyvsp[-6].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
								
								variable_types[(yyvsp[-6].node)->lex_val]=var_type;
							}
							else{
								// error
							}
						}
#line 1719 "y.tab.cpp"
    break;

  case 10:
#line 155 "yacc.y"
                 {
				(yyvsp[0].node) = new TreeNode("LIST");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("LIST_TYPE",v);
				}
#line 1729 "y.tab.cpp"
    break;

  case 11:
#line 162 "yacc.y"
                     {
				(yyvsp[0].node) = new TreeNode("MATRIX");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("MATRIX_TYPE",v);
			}
#line 1739 "y.tab.cpp"
    break;

  case 12:
#line 169 "yacc.y"
                                                                                             {
																								(yyvsp[-3].node) = new TreeNode("ONB"); 
																								(yyvsp[-1].node) = new TreeNode("CNB");
																								vector<TreeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
																								(yyval.node) = new TreeNode("FUNCTION_DECLARATION", v);
																								function_args[(yyvsp[-4].node)->lex_val]=0;

																								int tot_num_fun=function_scope_definer.size();
																								function_scope_definer[(yyvsp[-4].node)->lex_val]=tot_num_fun;
																								scope=(yyvsp[-4].node)->lex_val;
																								all_scopes_symbol_tables.push_back(symbol_table);
																								all_scopes_variable_types.push_back(variable_types);
																								
																								vector<string> arguments;
																								
																								TreeNode* params=(yyvsp[-2].node);
																								if(params->children.size()!=0 && params->children[0]->NodeName!="EPSILON"){
																									TreeNode* paramsnt=params->children[0];
																									int ch=0;

																									while(paramsnt->children.size()>2){
																										//cout<<paramsnt->NodeName<<endl;
																										//cout<<symbol_table[{paramsnt->children[2]->children[1]->lex_val,"INT"}]<<endl;
																										arguments.push_back(to_string(symbol_table[{paramsnt->children[2]->children[1]->lex_val,"INT"}]));
																										ch++;
																										paramsnt=paramsnt->children[0];
																									}
																									ch++;
																									//cout<<paramsnt->NodeName<<"=="<<endl;
																									//cout<<symbol_table[{paramsnt->children[0]->children[1]->lex_val,"INT"}]<<endl;
																									arguments.push_back(to_string(symbol_table[{paramsnt->children[0]->children[1]->lex_val,"INT"}]));
																									function_args[(yyvsp[-4].node)->lex_val]=ch;
																								}
																								Num_variablesF[(yyvsp[-4].node)->lex_val]=Num_variables;
																								Num_variables=0;
																								reverse(arguments.begin(),arguments.end());
																								function_arguments[(yyvsp[-4].node)->lex_val]=arguments;
																								symbol_table.clear();
																								variable_types.clear();
																							}
#line 1784 "y.tab.cpp"
    break;

  case 13:
#line 212 "yacc.y"
                      {
						vector<TreeNode*> v = {(yyvsp[0].node)};
						(yyval.node) = new TreeNode("PARAMS",v);
					}
#line 1793 "y.tab.cpp"
    break;

  case 14:
#line 216 "yacc.y"
                  {
			auto eps= new TreeNode("EPSILON");
			vector<TreeNode*> v = {eps};
			(yyval.node) = new TreeNode("PARAMS",v);
		}
#line 1803 "y.tab.cpp"
    break;

  case 15:
#line 224 "yacc.y"
                                         {
										(yyvsp[-1].node) = new TreeNode("COMMA");
										vector<TreeNode*> v = {(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
										(yyval.node) = new TreeNode("PARAM_LIST_NT",v);
									}
#line 1813 "y.tab.cpp"
    break;

  case 16:
#line 229 "yacc.y"
                                        {
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("PARAM_LIST_NT",v);
				}
#line 1822 "y.tab.cpp"
    break;

  case 17:
#line 236 "yacc.y"
                                  {
									Num_variables++;
									string var_type=(yyvsp[-1].node)->children[0]->NodeName;
									if(var_type!="INT"){
										yyerror("You can pass only Integer arguments...");
									}
									symbol_table[{(yyvsp[0].node)->lex_val,var_type}]=Num_variables*-8;
									variable_types[(yyvsp[0].node)->lex_val]=var_type;
									vector<TreeNode*> v = {(yyvsp[-1].node),(yyvsp[0].node)};
									(yyval.node) = new TreeNode("PARAM",v);
								}
#line 1838 "y.tab.cpp"
    break;

  case 18:
#line 247 "yacc.y"
                               {
			vector<TreeNode*> v = {(yyvsp[0].node)};
			(yyval.node) = new TreeNode("PARAM",v);
		}
#line 1847 "y.tab.cpp"
    break;

  case 19:
#line 254 "yacc.y"
                                         {
										vector<TreeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new TreeNode("STATEMENT_LIST", v); 
										}
#line 1856 "y.tab.cpp"
    break;

  case 20:
#line 258 "yacc.y"
                                            {
							vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("STATEMENT_LIST", v); 
							}
#line 1865 "y.tab.cpp"
    break;

  case 21:
#line 265 "yacc.y"
                                {
								vector<TreeNode*> v = {(yyvsp[0].node)};
                        		(yyval.node) = new TreeNode("STATEMENT", v);
								}
#line 1874 "y.tab.cpp"
    break;

  case 22:
#line 269 "yacc.y"
                                             {
				vector<TreeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new TreeNode("STATEMENT", v);
			}
#line 1883 "y.tab.cpp"
    break;

  case 23:
#line 274 "yacc.y"
                                       {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1892 "y.tab.cpp"
    break;

  case 24:
#line 278 "yacc.y"
                                          {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1901 "y.tab.cpp"
    break;

  case 25:
#line 283 "yacc.y"
                                         {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1910 "y.tab.cpp"
    break;

  case 26:
#line 288 "yacc.y"
                                           {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1919 "y.tab.cpp"
    break;

  case 27:
#line 292 "yacc.y"
                                            {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1928 "y.tab.cpp"
    break;

  case 28:
#line 296 "yacc.y"
                                         {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1937 "y.tab.cpp"
    break;

  case 29:
#line 300 "yacc.y"
                                        {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1946 "y.tab.cpp"
    break;

  case 30:
#line 304 "yacc.y"
                                          {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1955 "y.tab.cpp"
    break;

  case 31:
#line 309 "yacc.y"
                                                 {
						(yyvsp[-2].node)=new TreeNode("RETURN");
						(yyvsp[0].node)=new TreeNode("SEMICOLON");
						vector<TreeNode*> v = {(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
						(yyval.node) = new TreeNode("RETURN_STATEMENT",v);
					}
#line 1966 "y.tab.cpp"
    break;

  case 32:
#line 315 "yacc.y"
                                                                     {
						(yyvsp[-2].node)=new TreeNode("RETURN");
						(yyvsp[0].node)=new TreeNode("SEMICOLON");
						vector<TreeNode*> v = {(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
						(yyval.node) = new TreeNode("RETURN_STATEMENT",v);
					}
#line 1977 "y.tab.cpp"
    break;

  case 33:
#line 323 "yacc.y"
                                                          {
												(yyvsp[-4].node) = new TreeNode("PRINT");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												(yyvsp[0].node)=new TreeNode("SEMICOLON");
												//Num_variables++;
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("PRINT_STATEMENT",v);
												
											}
#line 1992 "y.tab.cpp"
    break;

  case 34:
#line 335 "yacc.y"
                                                        {
												(yyvsp[-4].node) = new TreeNode("SCAN");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												(yyvsp[0].node)=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("SCAN_STATEMENT",v);
				}
#line 2005 "y.tab.cpp"
    break;

  case 35:
#line 346 "yacc.y"
                                              {
                                                    (yyvsp[-2].node) = new TreeNode("OFB"); (yyvsp[0].node) = new TreeNode("CFB");
                                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new TreeNode("COMPOUND_STATEMENT", v);
                                                }
#line 2015 "y.tab.cpp"
    break;

  case 36:
#line 354 "yacc.y"
                                              {
												(yyvsp[-4].node) = new TreeNode("IF");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("IF_STATEMENT",v);
											}
#line 2027 "y.tab.cpp"
    break;

  case 37:
#line 361 "yacc.y"
                                                                                {
					(yyvsp[-6].node) = new TreeNode("IF");
					(yyvsp[-5].node) = new TreeNode("ONB");
					(yyvsp[-3].node) = new TreeNode("CNB");
					(yyvsp[-1].node) = new TreeNode("STATEMENT");
					vector<TreeNode*> v = {(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
					(yyval.node) = new TreeNode("IF_STATEMENT",v);
				}
#line 2040 "y.tab.cpp"
    break;

  case 38:
#line 372 "yacc.y"
                                                    {
													(yyvsp[-4].node) = new TreeNode("WHILE_STATEMENT");
													(yyvsp[-3].node) = new TreeNode("ONB");
													(yyvsp[-1].node) = new TreeNode("CNB");
													vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
													(yyval.node) = new TreeNode("WHILE_STATEMENT",v);
												}
#line 2052 "y.tab.cpp"
    break;

  case 39:
#line 383 "yacc.y"
                                                                                                {
												(yyvsp[-7].node) = new TreeNode("FOR");
												(yyvsp[-6].node) = new TreeNode("ONB");
												(yyvsp[-3].node) = new TreeNode("SEMICOLON");
												(yyvsp[-1].node) = new TreeNode("CNB");
												vector<TreeNode*> v = {(yyvsp[-7].node),(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("FOR_STATEMENT",v);				
										}
#line 2065 "y.tab.cpp"
    break;

  case 40:
#line 394 "yacc.y"
                                                {
                                    (yyvsp[0].node) = new TreeNode("SEMICOLON");
                                    (yyvsp[-1].node) = new TreeNode("INC");
                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new TreeNode("INCDEC_STATEMENT", v);
                                }
#line 2076 "y.tab.cpp"
    break;

  case 41:
#line 401 "yacc.y"
                                                            {
                                    (yyvsp[0].node) = new TreeNode("SEMICOLON");
                                    (yyvsp[-1].node) = new TreeNode("DEC");
                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new TreeNode("INCDEC_STATEMENT", v);
                }
#line 2087 "y.tab.cpp"
    break;

  case 42:
#line 410 "yacc.y"
                   {
					(yyvsp[0].node) = new TreeNode("INT");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);

				}
#line 2098 "y.tab.cpp"
    break;

  case 43:
#line 416 "yacc.y"
                                        {
					(yyvsp[0].node) = new TreeNode("STRING");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);
				}
#line 2108 "y.tab.cpp"
    break;

  case 44:
#line 421 "yacc.y"
                                            {
					(yyvsp[0].node) = new TreeNode("CHARACTER");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);
				}
#line 2118 "y.tab.cpp"
    break;

  case 45:
#line 426 "yacc.y"
                                        {
					(yyvsp[0].node) = new TreeNode("FLOAT");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);
				}
#line 2128 "y.tab.cpp"
    break;

  case 46:
#line 435 "yacc.y"
                                                         {
															
															(yyvsp[0].node)=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        					(yyval.node) = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;
															
															if(variable_types.find((yyvsp[-1].node)->lex_val)==variable_types.end()){
																string var_type=(yyvsp[-2].node)->children[0]->NodeName;
																symbol_table[{(yyvsp[-1].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
												
																variable_types[(yyvsp[-1].node)->lex_val]=var_type;
															}
					}
#line 2147 "y.tab.cpp"
    break;

  case 47:
#line 449 "yacc.y"
                                                                                               {
							(yyvsp[-3].node)=new TreeNode("OSB");
							(yyvsp[-1].node)=new TreeNode("CSB");
							(yyvsp[0].node)=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node) = new TreeNode("LOCAL_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[(yyvsp[-4].node)->lex_val]=atoi(mytext);
							if(variable_types.find((yyvsp[-4].node)->lex_val)==variable_types.end()){
								string var_type=(yyvsp[-5].node)->children[0]->NodeName;
								symbol_table[{(yyvsp[-4].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
								
								variable_types[(yyvsp[-4].node)->lex_val]=var_type;
							}
						}
#line 2167 "y.tab.cpp"
    break;

  case 48:
#line 464 "yacc.y"
                                                                                                                         {
							(yyvsp[-5].node)=new TreeNode("OSB");
							(yyvsp[-3].node)=new TreeNode("COMMA");
							(yyvsp[-1].node)=new TreeNode("CSB");
							(yyvsp[0].node)=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {(yyvsp[-7].node), (yyvsp[-6].node), (yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node) = new TreeNode("LOCAL_DECLARATION", v);
							matrix_size=stoi((yyvsp[-4].node)->lex_val)*stoi((yyvsp[-2].node)->lex_val);
							Num_variables+=matrix_size;
							
							matrix[(yyvsp[-6].node)->lex_val]={stoi((yyvsp[-4].node)->lex_val),stoi((yyvsp[-2].node)->lex_val)};
							if(variable_types.find((yyvsp[-6].node)->lex_val)==variable_types.end()){
								string var_type=(yyvsp[-7].node)->children[0]->NodeName;
								symbol_table[{(yyvsp[-6].node)->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.

								variable_types[(yyvsp[-6].node)->lex_val]=var_type;
							}
							else{
								// error
							}
						}
#line 2193 "y.tab.cpp"
    break;

  case 49:
#line 488 "yacc.y"
                                                                 {									// Identifier and Expression are given as children to EQUAL TO OPERATOR IN SYNTAX TREE.
																vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-1].node)};
																(yyvsp[-2].node)=new TreeNode("EQUALTO",v);
																(yyvsp[0].node)=new TreeNode("SEMICOLON");
																vector<TreeNode*> u={(yyvsp[-2].node),(yyvsp[0].node)};
																(yyval.node)=new TreeNode("ASSIGNMENT_STATEMENT",u);
																}
#line 2205 "y.tab.cpp"
    break;

  case 50:
#line 498 "yacc.y"
                        {	
						vector<TreeNode*> v={(yyvsp[0].node)};
						(yyval.node)=new TreeNode("EXPRESSION",v);
			}
#line 2214 "y.tab.cpp"
    break;

  case 51:
#line 502 "yacc.y"
                                            {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("PLUS",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2225 "y.tab.cpp"
    break;

  case 52:
#line 508 "yacc.y"
                                            {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("MINUS",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2236 "y.tab.cpp"
    break;

  case 53:
#line 514 "yacc.y"
                                               {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("MULTIPLY",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2247 "y.tab.cpp"
    break;

  case 54:
#line 520 "yacc.y"
                                                         {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("DIVIDE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2258 "y.tab.cpp"
    break;

  case 55:
#line 526 "yacc.y"
                                                       {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BAND",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2269 "y.tab.cpp"
    break;

  case 56:
#line 532 "yacc.y"
                                                       {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BXOR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2280 "y.tab.cpp"
    break;

  case 57:
#line 538 "yacc.y"
                                                      {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BOR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 2291 "y.tab.cpp"
    break;

  case 58:
#line 544 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("GE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2302 "y.tab.cpp"
    break;

  case 59:
#line 550 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("LE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2313 "y.tab.cpp"
    break;

  case 60:
#line 556 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("GT",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2324 "y.tab.cpp"
    break;

  case 61:
#line 562 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("LT",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2335 "y.tab.cpp"
    break;

  case 62:
#line 568 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("EE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2346 "y.tab.cpp"
    break;

  case 63:
#line 574 "yacc.y"
                                                     {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("NEQ",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2357 "y.tab.cpp"
    break;

  case 64:
#line 580 "yacc.y"
                                         {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("EXPRESSION",v);
			}
#line 2366 "y.tab.cpp"
    break;

  case 65:
#line 584 "yacc.y"
                                                   {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("AND",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2377 "y.tab.cpp"
    break;

  case 66:
#line 590 "yacc.y"
                                                  {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("OR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2388 "y.tab.cpp"
    break;

  case 67:
#line 596 "yacc.y"
                                        {
				vector<TreeNode*> v={(yyvsp[0].node)};
                (yyvsp[0].node)=new TreeNode("OR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2399 "y.tab.cpp"
    break;

  case 68:
#line 604 "yacc.y"
                                      {
						(yyvsp[-1].node)=new TreeNode("ATSIZE");
						vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
						(yyval.node) = new TreeNode("SIZE_EXPRESSION",v);
					}
#line 2409 "y.tab.cpp"
    break;

  case 69:
#line 610 "yacc.y"
                                                             {
						(yyvsp[-1].node)=new TreeNode("AATSIZE");
						vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
						(yyval.node) = new TreeNode("SIZE_EXPRESSION",v);
					}
#line 2419 "y.tab.cpp"
    break;

  case 70:
#line 617 "yacc.y"
                                                 {
					(yyvsp[0].node)=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
					(yyval.node)=new TreeNode("LIST_ELEMENT",v);
				}
#line 2429 "y.tab.cpp"
    break;

  case 71:
#line 622 "yacc.y"
                                                       {
					(yyvsp[0].node)=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
					(yyval.node)=new TreeNode("LIST_ELEMENT",v);
				}
#line 2439 "y.tab.cpp"
    break;

  case 72:
#line 629 "yacc.y"
                                                   {
					(yyvsp[0].node)=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
					(yyval.node)=new TreeNode("MATRIX_ELEMENT",v);
				}
#line 2449 "y.tab.cpp"
    break;

  case 73:
#line 634 "yacc.y"
                                                     {
					(yyvsp[0].node)=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
					(yyval.node)=new TreeNode("MATRIX_ELEMENT",v);
				}
#line 2459 "y.tab.cpp"
    break;

  case 74:
#line 642 "yacc.y"
                                      {
				(yyvsp[-1].node)=new TreeNode("COMMA");
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("MATVAR_NT",v);	
				}
#line 2469 "y.tab.cpp"
    break;

  case 75:
#line 647 "yacc.y"
                                            {
					vector<TreeNode*> v={(yyvsp[0].node)};
					(yyval.node)=new TreeNode("MATVAR_NT",v);
				}
#line 2478 "y.tab.cpp"
    break;

  case 76:
#line 653 "yacc.y"
                                                  {
				//cout<<"YYYYYY\n";
				(yyvsp[-2].node) = new TreeNode("ONB");
				(yyvsp[0].node) = new TreeNode("CNB");
				vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2490 "y.tab.cpp"
    break;

  case 77:
#line 660 "yacc.y"
                                     {	
					vector<TreeNode*> v={(yyvsp[0].node)};
					(yyval.node)=new TreeNode("PEXPRESSION",v);
					}
#line 2499 "y.tab.cpp"
    break;

  case 78:
#line 664 "yacc.y"
                                        {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2508 "y.tab.cpp"
    break;

  case 79:
#line 668 "yacc.y"
                                                          {
				(yyvsp[-2].node) = new TreeNode("OSB"); (yyvsp[0].node) = new TreeNode("CSB");
				vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2518 "y.tab.cpp"
    break;

  case 80:
#line 673 "yacc.y"
                                                             {
				(yyvsp[-2].node) = new TreeNode("OSB"); (yyvsp[0].node) = new TreeNode("CSB");
				vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2528 "y.tab.cpp"
    break;

  case 81:
#line 678 "yacc.y"
                                             {
				(yyvsp[-2].node) = new TreeNode("ONB"); (yyvsp[0].node) = new TreeNode("CNB");
                vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                (yyval.node) = new TreeNode("PEXPRESSION", v);
			
			}
#line 2539 "y.tab.cpp"
    break;

  case 82:
#line 684 "yacc.y"
                                                {
				(yyvsp[-2].node) = new TreeNode("OSB");
				(yyvsp[0].node) = new TreeNode("CSB");
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2550 "y.tab.cpp"
    break;

  case 83:
#line 690 "yacc.y"
                                  {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2559 "y.tab.cpp"
    break;

  case 84:
#line 694 "yacc.y"
                                                {
				(yyvsp[-2].node) = new TreeNode("OSB");
				(yyvsp[0].node) = new TreeNode("CSB");
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2570 "y.tab.cpp"
    break;

  case 85:
#line 700 "yacc.y"
                                      {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2579 "y.tab.cpp"
    break;

  case 86:
#line 707 "yacc.y"
                                {
				vector<TreeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new TreeNode("PRINT_SCAN_ITEM", v);
				(yyval.node)->lex_val=(yyvsp[0].node)->lex_val;
			}
#line 2589 "y.tab.cpp"
    break;

  case 87:
#line 714 "yacc.y"
                        {
				//cout<<"&\n";
				(yyvsp[0].node) = new TreeNode("NON_N_NUMBER");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("INTEGER_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2601 "y.tab.cpp"
    break;

  case 88:
#line 721 "yacc.y"
                                   {
				//cout<<"!\n";
				(yyvsp[0].node) = new TreeNode("N_NUMBER");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("INTEGER_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2613 "y.tab.cpp"
    break;

  case 89:
#line 737 "yacc.y"
                   {
				(yyvsp[0].node) = new TreeNode("FLOATING");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("FLOAT_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2624 "y.tab.cpp"
    break;

  case 90:
#line 745 "yacc.y"
                    {
				(yyvsp[0].node) = new TreeNode("CHAR");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("CHARACTER_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2635 "y.tab.cpp"
    break;

  case 91:
#line 752 "yacc.y"
                          {
							(yyvsp[0].node) = new TreeNode("IDENTIFIER");
                            vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("IDENTIFIER_NT", v);
                            (yyval.node)->lex_val = mytext;
				}
#line 2646 "y.tab.cpp"
    break;

  case 92:
#line 758 "yacc.y"
                                                                  {
							(yyvsp[-2].node) = new TreeNode("OSB"); (yyvsp[0].node) = new TreeNode("CSB");
							vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node)=new TreeNode("IDENTIFIER_NT",v);
				}
#line 2656 "y.tab.cpp"
    break;

  case 93:
#line 763 "yacc.y"
                                                                     {
							(yyvsp[-2].node) = new TreeNode("OSB"); (yyvsp[0].node) = new TreeNode("CSB");
							vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
							(yyval.node)=new TreeNode("IDENTIFIER_NT",v);
				}
#line 2666 "y.tab.cpp"
    break;

  case 94:
#line 771 "yacc.y"
                                             {
							(yyvsp[0].node) = new TreeNode("FUNCTION_IDENTIFIER");
                            vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("FUNCTION_IDENTIFIER_NT", v);
                            (yyval.node)->lex_val = mytext;
						}
#line 2677 "y.tab.cpp"
    break;


#line 2681 "y.tab.cpp"

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
#line 778 "yacc.y"


/* Rules Section ends here */

extern FILE *yyin;




int main(){
	yyparse();
	//dotraversal(Abstract_Syntax_Tree);
	CodeGenerator(Abstract_Syntax_Tree);
	putx86inafile();
	return 0;
}

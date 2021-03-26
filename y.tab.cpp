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

	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *);
	char mytext[10000]; // get from lex file.
	class TreeNode {
        public:
            vector<TreeNode*> children;   // children
            string NodeName;              // name of the node
            string lex_val;              // lexical value, name of identifier etc.
            int level;	                  // for printing
            TreeNode(string NodeName, vector<TreeNode*> children) {
                this->NodeName = NodeName;
                this->children = children;
				this->lex_val="";
            }
            TreeNode(string NodeName) {  // for leaf nodes(No children nodes)
                this->NodeName = NodeName;
                children.assign(0, NULL);
				this->lex_val="";
            }
    };
	TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
	int Num_variables=0;
	map<pair<string,string>, int> symbol_table;
	void dotraversal(TreeNode* head);
	vector<string> text;
	vector<string> data;
	vector<string> bss; // 
	vector<string> printint; // To include the print subroutine
	void CodeGenerator(TreeNode* root);
	void putx86inafile();
	void set_integer_print_subroutine();
	void set_integer_scan_subroutine();
	void string_to_number_subroutine();
	int count_loops=0;

#line 109 "y.tab.cpp"

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
    IDENTIFIER = 261,
    CHAR = 262,
    STR = 263,
    FUNCTION_IDENTIFIER = 264,
    NUMBER = 265,
    COMMA = 266,
    SEMICOLON = 267,
    OFB = 268,
    CFB = 269,
    ONB = 270,
    CNB = 271,
    PLUS = 272,
    MINUS = 273,
    MULTIPLY = 274,
    IF = 275,
    ELSE = 276,
    ELIF = 277,
    WHILE = 278,
    FOR = 279,
    PRINT = 280,
    SCAN = 281,
    OR = 282,
    AND = 283,
    NOT = 284,
    EQUALTO = 285,
    LT = 286,
    GT = 287,
    LE = 288,
    GE = 289,
    EE = 290,
    NEQ = 291,
    INC = 292,
    DEC = 293,
    IC = 294,
    BAND = 295,
    BOR = 296,
    BXOR = 297
  };
#endif
/* Tokens.  */
#define INT 258
#define STRING 259
#define CHARACTER 260
#define IDENTIFIER 261
#define CHAR 262
#define STR 263
#define FUNCTION_IDENTIFIER 264
#define NUMBER 265
#define COMMA 266
#define SEMICOLON 267
#define OFB 268
#define CFB 269
#define ONB 270
#define CNB 271
#define PLUS 272
#define MINUS 273
#define MULTIPLY 274
#define IF 275
#define ELSE 276
#define ELIF 277
#define WHILE 278
#define FOR 279
#define PRINT 280
#define SCAN 281
#define OR 282
#define AND 283
#define NOT 284
#define EQUALTO 285
#define LT 286
#define GT 287
#define LE 288
#define GE 289
#define EE 290
#define NEQ 291
#define INC 292
#define DEC 293
#define IC 294
#define BAND 295
#define BOR 296
#define BXOR 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "yacc.y"

	class TreeNode* node;

#line 249 "y.tab.cpp"

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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   120

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

#define YYUNDEFTOK  2
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    61,    61,    67,    71,    77,    82,    89,    99,   107,
     111,   119,   124,   131,   138,   142,   149,   153,   158,   162,
     167,   172,   176,   180,   184,   191,   201,   212,   220,   230,
     240,   251,   258,   267,   273,   278,   286,   297,   307,   311,
     317,   323,   329,   335,   341,   347,   353,   359,   365,   371,
     377,   383,   390,   394,   398,   405,   409,   415,   422,   429,
     436,   443,   452
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "STRING", "CHARACTER",
  "IDENTIFIER", "CHAR", "STR", "FUNCTION_IDENTIFIER", "NUMBER", "COMMA",
  "SEMICOLON", "OFB", "CFB", "ONB", "CNB", "PLUS", "MINUS", "MULTIPLY",
  "IF", "ELSE", "ELIF", "WHILE", "FOR", "PRINT", "SCAN", "OR", "AND",
  "NOT", "EQUALTO", "LT", "GT", "LE", "GE", "EE", "NEQ", "INC", "DEC",
  "IC", "BAND", "BOR", "BXOR", "$accept", "PROGRAM", "DECLARATION_LIST",
  "DECLARATION", "VARIABLE_DECLARATION", "FUNCTION_DECLARATION", "PARAMS",
  "PARAM_LIST_NT", "PARAM", "STATEMENT_LIST", "STATEMENT",
  "PRINT_STATEMENT", "SCAN_STATEMENT", "COMPOUND_STATEMENT",
  "IF_STATEMENT", "WHILE_STATEMENT", "FOR_STATEMENT", "INCDEC_STATEMENT",
  "VARIABLE_TYPE", "LOCAL_DECLARATION", "ASSIGNMENT_STATEMENT",
  "EXPRESSION", "PEXPRESSION", "PEXPRESSION_S", "PRINT_SCAN_ITEM",
  "INTEGER_NT", "STRING_NT", "CHARACTER_NT", "IDENTIFIER_NT",
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
     295,   296,   297
};
# endif

#define YYPACT_NINF (-33)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,   -33,   -33,   -33,    25,    10,   -33,   -33,   -33,    43,
     -33,   -33,   -33,   -33,    18,    16,   -33,    10,    22,    21,
     -33,    36,    30,    10,   -33,    68,   -33,   -33,    33,    35,
      46,    48,    49,    31,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,    36,   -33,   -33,   -28,    69,    69,    36,    36,
      36,   -33,   -33,    53,    69,    54,    57,   -33,   -33,   -33,
      69,    62,   -14,   -33,   -33,   -33,   -33,   -33,    64,    69,
      56,    66,   -33,    71,   -33,    77,   -33,   -33,    74,    68,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    68,    83,    84,    85,   -33,   -33,   -33,   -33,
     -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,   -33,
     -33,   -33,    36,   -33,   -33,    82,   -30,    68,   -33
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    33,    34,    35,     0,     2,     4,     5,     6,     0,
       1,     3,    61,    62,     0,     0,     7,    10,     0,     9,
      12,     0,     0,     0,    13,     0,     8,    11,     0,     0,
       0,     0,     0,     0,    15,    23,    24,    17,    18,    19,
      20,    21,     0,    22,    16,     0,     0,     0,     0,     0,
       0,    27,    14,     0,     0,     0,     0,    60,    59,    58,
       0,     0,    38,    51,    52,    55,    56,    53,     0,     0,
       0,     0,    57,     0,    36,     0,    31,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,    54,    28,    39,
      40,    41,    48,    47,    46,    45,    49,    50,    42,    44,
      43,    29,     0,    25,    26,     0,     0,     0,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -33,   -33,   -33,    94,   -33,   -33,   -33,   -33,    78,   -33,
     -32,   -33,   -33,    80,   -33,   -33,   -33,   -12,     6,   -33,
      58,    -1,    29,   -33,    55,   -33,   -33,   -33,    -9,   -33
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    18,    19,    20,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    61,    62,    63,    71,    64,    65,    66,    67,    15
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      14,    52,    54,    80,    81,    82,     9,    55,    56,    55,
      56,     9,    24,     1,     2,     3,    45,    83,    84,    85,
      86,    87,    88,    21,    45,    10,    89,    90,    91,    21,
      16,    17,    23,    53,     1,     2,     3,    12,    22,    70,
      72,    72,    12,    25,    25,    51,    68,    98,    46,    12,
      47,    28,    13,    75,    29,    30,    31,    32,    12,    78,
     111,    48,    59,    49,    50,    74,    76,    60,    93,    77,
      45,     1,     2,     3,    12,    12,    57,    58,    79,    59,
      92,    25,    94,    45,    60,   118,    54,    95,    28,    96,
      97,    29,    30,    31,    32,   112,   113,   114,   117,    11,
     115,    27,    26,   116,     0,    73,    69,     0,    45,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110
};

static const yytype_int8 yycheck[] =
{
       9,    33,    30,    17,    18,    19,     0,    37,    38,    37,
      38,     5,    21,     3,     4,     5,    25,    31,    32,    33,
      34,    35,    36,    17,    33,     0,    40,    41,    42,    23,
      12,    15,    11,    42,     3,     4,     5,     6,    16,    48,
      49,    50,     6,    13,    13,    14,    47,    79,    15,     6,
      15,    20,     9,    54,    23,    24,    25,    26,     6,    60,
      92,    15,    10,    15,    15,    12,    12,    15,    69,    12,
      79,     3,     4,     5,     6,     6,     7,     8,    16,    10,
      16,    13,    16,    92,    15,   117,    30,    16,    20,    12,
      16,    23,    24,    25,    26,    12,    12,    12,    16,     5,
     112,    23,    22,   112,    -1,    50,    48,    -1,   117,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    44,    45,    46,    47,    48,    61,
       0,    46,     6,     9,    71,    72,    12,    15,    49,    50,
      51,    61,    16,    11,    71,    13,    56,    51,    20,    23,
      24,    25,    26,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    71,    15,    15,    15,    15,
      15,    14,    53,    71,    30,    37,    38,     7,     8,    10,
      15,    64,    65,    66,    68,    69,    70,    71,    64,    63,
      71,    67,    71,    67,    12,    64,    12,    12,    64,    16,
      17,    18,    19,    31,    32,    33,    34,    35,    36,    40,
      41,    42,    16,    64,    16,    16,    12,    16,    53,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    53,    12,    12,    12,    60,    71,    16,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    47,    48,    49,
      49,    50,    50,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    55,    56,    57,    58,
      59,    60,    60,    61,    61,    61,    62,    63,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    65,    65,    65,    66,    66,    67,    68,    69,
      70,    71,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       0,     3,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     3,     5,     5,
       8,     3,     3,     1,     1,     1,     3,     4,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 61 "yacc.y"
                          {
							vector<TreeNode*> v={(yyvsp[0].node)};
							(yyval.node)=new TreeNode("PROGRAM",v);
							Abstract_Syntax_Tree=(yyval.node);
							}
#line 1514 "y.tab.cpp"
    break;

  case 3:
#line 67 "yacc.y"
                                              {
												vector<TreeNode*> v={(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node)=new TreeNode("DECLARATION_LIST",v);
												}
#line 1523 "y.tab.cpp"
    break;

  case 4:
#line 71 "yacc.y"
                                              {
								vector<TreeNode*> v={(yyvsp[0].node)};
								(yyval.node)=new TreeNode("DECLARATION_LIST",v);
							}
#line 1532 "y.tab.cpp"
    break;

  case 5:
#line 77 "yacc.y"
                                        {

			vector<TreeNode*> v={(yyvsp[0].node)};
			(yyval.node)=new TreeNode("DECLARATION",v);
			}
#line 1542 "y.tab.cpp"
    break;

  case 6:
#line 82 "yacc.y"
                                               {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("DECLARATION",v);
			}
#line 1551 "y.tab.cpp"
    break;

  case 7:
#line 89 "yacc.y"
                                                            {
															(yyvsp[0].node)=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        					(yyval.node) = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															symbol_table[{(yyvsp[-1].node)->lex_val,"int"}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															}
#line 1563 "y.tab.cpp"
    break;

  case 8:
#line 99 "yacc.y"
                                                                                             {
																								(yyvsp[-3].node) = new TreeNode("ONB"); (yyvsp[-1].node) = new TreeNode("CNB");
																								vector<TreeNode*> v = {(yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
																								(yyval.node) = new TreeNode("FUNCTION_DECLARATION", v);
																							}
#line 1573 "y.tab.cpp"
    break;

  case 9:
#line 107 "yacc.y"
                      {
						vector<TreeNode*> v = {(yyvsp[0].node)};
						(yyval.node) = new TreeNode("PARAMS",v);
					}
#line 1582 "y.tab.cpp"
    break;

  case 10:
#line 111 "yacc.y"
                  {
			auto eps= new TreeNode("EPSILON");
			vector<TreeNode*> v = {eps};
			(yyval.node) = new TreeNode("PARAMS",v);
		}
#line 1592 "y.tab.cpp"
    break;

  case 11:
#line 119 "yacc.y"
                                         {
										(yyvsp[-1].node) = new TreeNode("COMMA");
										vector<TreeNode*> v = {(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
										(yyval.node) = new TreeNode("PARAM_LIST_NT",v);
									}
#line 1602 "y.tab.cpp"
    break;

  case 12:
#line 124 "yacc.y"
                                        {
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("PARAM_LIST_NT",v);
				}
#line 1611 "y.tab.cpp"
    break;

  case 13:
#line 131 "yacc.y"
                                  {
									vector<TreeNode*> v = {(yyvsp[-1].node),(yyvsp[0].node)};
									(yyval.node) = new TreeNode("PARAM",v);
								}
#line 1620 "y.tab.cpp"
    break;

  case 14:
#line 138 "yacc.y"
                                         {
										vector<TreeNode*> v = {(yyvsp[-1].node), (yyvsp[0].node)};
                                        (yyval.node) = new TreeNode("STATEMENT_LIST", v); 
										}
#line 1629 "y.tab.cpp"
    break;

  case 15:
#line 142 "yacc.y"
                                            {
							vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("STATEMENT_LIST", v); 
							}
#line 1638 "y.tab.cpp"
    break;

  case 16:
#line 149 "yacc.y"
                                {
								vector<TreeNode*> v = {(yyvsp[0].node)};
                        		(yyval.node) = new TreeNode("STATEMENT", v);
								}
#line 1647 "y.tab.cpp"
    break;

  case 17:
#line 153 "yacc.y"
                                             {
				vector<TreeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new TreeNode("STATEMENT", v);
			}
#line 1656 "y.tab.cpp"
    break;

  case 18:
#line 158 "yacc.y"
                                       {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1665 "y.tab.cpp"
    break;

  case 19:
#line 162 "yacc.y"
                                          {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1674 "y.tab.cpp"
    break;

  case 20:
#line 167 "yacc.y"
                                         {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1683 "y.tab.cpp"
    break;

  case 21:
#line 172 "yacc.y"
                                           {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1692 "y.tab.cpp"
    break;

  case 22:
#line 176 "yacc.y"
                                            {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1701 "y.tab.cpp"
    break;

  case 23:
#line 180 "yacc.y"
                                         {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1710 "y.tab.cpp"
    break;

  case 24:
#line 184 "yacc.y"
                                        {
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STATEMENT",v);
			}
#line 1719 "y.tab.cpp"
    break;

  case 25:
#line 191 "yacc.y"
                                                          {
												(yyvsp[-4].node) = new TreeNode("PRINT");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												(yyvsp[0].node)=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("PRINT_STATEMENT",v);
											}
#line 1732 "y.tab.cpp"
    break;

  case 26:
#line 201 "yacc.y"
                                                        {
												(yyvsp[-4].node) = new TreeNode("SCAN");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												(yyvsp[0].node)=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("SCAN_STATEMENT",v);
											}
#line 1745 "y.tab.cpp"
    break;

  case 27:
#line 212 "yacc.y"
                                              {
                                                    (yyvsp[-2].node) = new TreeNode("OFB"); (yyvsp[0].node) = new TreeNode("CFB");
                                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                                    (yyval.node) = new TreeNode("COMPOUND_STATEMENT", v);
                                                }
#line 1755 "y.tab.cpp"
    break;

  case 28:
#line 220 "yacc.y"
                                              {
												(yyvsp[-4].node) = new TreeNode("IF");
												(yyvsp[-3].node) = new TreeNode("ONB");
												(yyvsp[-1].node) = new TreeNode("CNB");
												vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("IF_STATEMENT",v);
											}
#line 1767 "y.tab.cpp"
    break;

  case 29:
#line 230 "yacc.y"
                                                    {
													(yyvsp[-4].node) = new TreeNode("WHILE_STATEMENT");
													(yyvsp[-3].node) = new TreeNode("ONB");
													(yyvsp[-1].node) = new TreeNode("CNB");
													vector<TreeNode*> v = {(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
													(yyval.node) = new TreeNode("WHILE_STATEMENT",v);
												}
#line 1779 "y.tab.cpp"
    break;

  case 30:
#line 240 "yacc.y"
                                                                                                {
												(yyvsp[-7].node) = new TreeNode("FOR");
												(yyvsp[-6].node) = new TreeNode("ONB");
												(yyvsp[-3].node) = new TreeNode("SEMICOLON");
												(yyvsp[-1].node) = new TreeNode("CNB");
												vector<TreeNode*> v = {(yyvsp[-7].node),(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)};
												(yyval.node) = new TreeNode("FOR_STATEMENT",v);				
										}
#line 1792 "y.tab.cpp"
    break;

  case 31:
#line 251 "yacc.y"
                                                {
                                    (yyvsp[0].node) = new TreeNode("SEMICOLON");
                                    (yyvsp[-1].node) = new TreeNode("INC");
                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new TreeNode("INCDEC_STATEMENT", v);
                                }
#line 1803 "y.tab.cpp"
    break;

  case 32:
#line 258 "yacc.y"
                                                            {
                                    (yyvsp[0].node) = new TreeNode("SEMICOLON");
                                    (yyvsp[-1].node) = new TreeNode("DEC");
                                    vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                    (yyval.node) = new TreeNode("INCDEC_STATEMENT", v);
                }
#line 1814 "y.tab.cpp"
    break;

  case 33:
#line 267 "yacc.y"
                   {
					(yyvsp[0].node) = new TreeNode("INT");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);

				}
#line 1825 "y.tab.cpp"
    break;

  case 34:
#line 273 "yacc.y"
                                        {
					(yyvsp[0].node) = new TreeNode("STRING");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);
				}
#line 1835 "y.tab.cpp"
    break;

  case 35:
#line 278 "yacc.y"
                                            {
					(yyvsp[0].node) = new TreeNode("CHARACTER");
					vector<TreeNode*> v = {(yyvsp[0].node)};
					(yyval.node) = new TreeNode("VARIABLE_TYPE",v);
				}
#line 1845 "y.tab.cpp"
    break;

  case 36:
#line 286 "yacc.y"
                                                         {
															(yyvsp[0].node)=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                                        					(yyval.node) = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;

															symbol_table[{(yyvsp[-1].node)->lex_val,"int"}]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															}
#line 1858 "y.tab.cpp"
    break;

  case 37:
#line 297 "yacc.y"
                                                                 {									// Identifier and Expression are given as children to EQUAL TO OPERATOR IN SYNTAX TREE.
																vector<TreeNode*> v={(yyvsp[-3].node),(yyvsp[-1].node)};
																(yyvsp[-2].node)=new TreeNode("EQUALTO",v);
																(yyvsp[0].node)=new TreeNode("SEMICOLON");
																vector<TreeNode*> u={(yyvsp[-2].node),(yyvsp[0].node)};
																(yyval.node)=new TreeNode("ASSIGNMENT_STATEMENT",u);
																}
#line 1870 "y.tab.cpp"
    break;

  case 38:
#line 307 "yacc.y"
                        {	
						vector<TreeNode*> v={(yyvsp[0].node)};
						(yyval.node)=new TreeNode("EXPRESSION",v);
			}
#line 1879 "y.tab.cpp"
    break;

  case 39:
#line 311 "yacc.y"
                                            {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("PLUS",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1890 "y.tab.cpp"
    break;

  case 40:
#line 317 "yacc.y"
                                            {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("MINUS",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1901 "y.tab.cpp"
    break;

  case 41:
#line 323 "yacc.y"
                                               {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("MULTIPLY",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1912 "y.tab.cpp"
    break;

  case 42:
#line 329 "yacc.y"
                                                       {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BAND",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1923 "y.tab.cpp"
    break;

  case 43:
#line 335 "yacc.y"
                                                       {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BXOR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1934 "y.tab.cpp"
    break;

  case 44:
#line 341 "yacc.y"
                                                      {
                vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("BOR",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
            }
#line 1945 "y.tab.cpp"
    break;

  case 45:
#line 347 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("GE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 1956 "y.tab.cpp"
    break;

  case 46:
#line 353 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("LE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 1967 "y.tab.cpp"
    break;

  case 47:
#line 359 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("GT",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 1978 "y.tab.cpp"
    break;

  case 48:
#line 365 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("LT",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 1989 "y.tab.cpp"
    break;

  case 49:
#line 371 "yacc.y"
                                                    {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("EE",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2000 "y.tab.cpp"
    break;

  case 50:
#line 377 "yacc.y"
                                                     {
				vector<TreeNode*> v={(yyvsp[-2].node),(yyvsp[0].node)};
                (yyvsp[-1].node)=new TreeNode("NEQ",v);
                vector<TreeNode*> u={(yyvsp[-1].node)};
                (yyval.node)=new TreeNode("EXPRESSION",u);
			}
#line 2011 "y.tab.cpp"
    break;

  case 51:
#line 383 "yacc.y"
                                        {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("EXPRESSION",v);
			}
#line 2020 "y.tab.cpp"
    break;

  case 52:
#line 390 "yacc.y"
                        {	
					vector<TreeNode*> v={(yyvsp[0].node)};
					(yyval.node)=new TreeNode("PEXPRESSION",v);
					}
#line 2029 "y.tab.cpp"
    break;

  case 53:
#line 394 "yacc.y"
                                        {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2038 "y.tab.cpp"
    break;

  case 54:
#line 398 "yacc.y"
                                             {
				(yyvsp[-2].node) = new TreeNode("ONB"); (yyvsp[0].node) = new TreeNode("CNB");
                vector<TreeNode*> v = {(yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node)};
                (yyval.node) = new TreeNode("PEXPRESSION", v);
			
			}
#line 2049 "y.tab.cpp"
    break;

  case 55:
#line 405 "yacc.y"
                          {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2058 "y.tab.cpp"
    break;

  case 56:
#line 409 "yacc.y"
                                       {
				vector<TreeNode*> v={(yyvsp[0].node)};
				(yyval.node)=new TreeNode("PEXPRESSION",v);
			}
#line 2067 "y.tab.cpp"
    break;

  case 57:
#line 415 "yacc.y"
                                {
				vector<TreeNode*> v = {(yyvsp[0].node)};
                (yyval.node) = new TreeNode("PRINT_SCAN_ITEM", v);
				(yyval.node)->lex_val=(yyvsp[0].node)->lex_val;
			}
#line 2077 "y.tab.cpp"
    break;

  case 58:
#line 422 "yacc.y"
                   {
				(yyvsp[0].node) = new TreeNode("NUMBER");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("INTEGER_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2088 "y.tab.cpp"
    break;

  case 59:
#line 429 "yacc.y"
               {
				(yyvsp[0].node) = new TreeNode("STR");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("STRING_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2099 "y.tab.cpp"
    break;

  case 60:
#line 436 "yacc.y"
                    {
				(yyvsp[0].node) = new TreeNode("CHAR");
				vector<TreeNode*> v = {(yyvsp[0].node)};
				(yyval.node) = new TreeNode("CHARACTER_NT", v);
				(yyval.node)->lex_val = mytext;
			}
#line 2110 "y.tab.cpp"
    break;

  case 61:
#line 443 "yacc.y"
                          {
							(yyvsp[0].node) = new TreeNode("IDENTIFIER");
                            vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("IDENTIFIER_NT", v);
                            (yyval.node)->lex_val = mytext;
						}
#line 2121 "y.tab.cpp"
    break;

  case 62:
#line 452 "yacc.y"
                                             {
							(yyvsp[0].node) = new TreeNode("FUNCTION_IDENTIFIER");
                            vector<TreeNode*> v = {(yyvsp[0].node)};
                            (yyval.node) = new TreeNode("FUNCTION_IDENTIFIER_NT", v);
                            (yyval.node)->lex_val = mytext;
						}
#line 2132 "y.tab.cpp"
    break;


#line 2136 "y.tab.cpp"

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
#line 459 "yacc.y"


/* Rules Section ends here */

extern FILE *yyin;




int main(){
	yyparse();
	//dotraversal(Abstract_Syntax_Tree);
	CodeGenerator(Abstract_Syntax_Tree);
	text.push_back("mov rax , 60");
	text.push_back("mov rdi , 0");
	text.push_back("syscall");
	putx86inafile();
	return 0;
}
// HEAD -> (N CHILDREN) -> EACH CHILDREN = N CHLDREN ->RECURSIVE
// Basically,this is to check whether the Abstract syntax tree is correct or not
// Doing a traversal on the tree that we generated
void dotraversal(TreeNode* head){
	cout<<"NodeName: "<<head->NodeName<<"   ";
	cout<<"Lexval: "<<head->lex_val<<endl;
	vector<TreeNode*> children=head->children;
	for(int i=0;i<children.size();i++){
		dotraversal(children[i]);
	}
	return;
}
// This code generates the X86 code for our abstract syntax tree constructed.
void CodeGenerator(TreeNode* root){
	if(root->NodeName=="PROGRAM"){
		text.push_back("section	.text");
		text.push_back("global _start ");
		text.push_back("_start:");
		text.push_back("push rbp");
		text.push_back("mov rbp , rsp");
		set_integer_print_subroutine();
		set_integer_scan_subroutine();
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="DECLARATION_LIST"){
		CodeGenerator(root->children[0]);
		if(root->children.size()>1){
			CodeGenerator(root->children[1]);
		}
	}
	else if(root->NodeName=="DECLARATION"){
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="VARIABLE_DECLARATION"){
		return;
	}
	else if(root->NodeName=="FUNCTION_DECLARATION"){
		CodeGenerator(root->children[5]);
	}
	else if(root->NodeName=="COMPOUND_STATEMENT"){
		CodeGenerator(root->children[1]);
	}
	else if(root->NodeName=="STATEMENT_LIST"){
		CodeGenerator(root->children[0]);
		if(root->children.size()>1){
			CodeGenerator(root->children[1]);
		}
	}
	else if(root->NodeName=="STATEMENT"){
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="LOCAL_DECLARATION"){
		text.push_back("sub rsp , 8");
	}
	else if(root->NodeName=="PRINT_STATEMENT"){
		text.push_back("mov rbx , rbp");
		
		text.push_back("add rbx , "+to_string(symbol_table[{root->children[2]->lex_val,"int"}]));
		text.push_back("mov rax , [rbx]");
		text.push_back("call _printRAX");
	}
	else if(root->NodeName=="SCAN_STATEMENT"){
		text.push_back("mov rax , 0");
		text.push_back("mov rdi , 0");
		text.push_back("mov rsi , scanned");
		text.push_back("mov rdx , 16");
		text.push_back("syscall");
		string_to_number_subroutine();
		text.push_back("mov rcx , rbp");
		text.push_back("add rcx , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"int"}]));
		text.push_back("mov [rcx] , rax");

	}
	else if(root->NodeName=="ASSIGNMENT_STATEMENT"){ 
		if(root->children[0]->children.size()==2){
			if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION"){
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="INTEGER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"int"}]));
					text.push_back("mov rax , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
				}
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"int"}]));
					text.push_back("mov rdx , rbp");
					text.push_back("add rdx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->children[0]->lex_val,"int"}]));
					text.push_back("mov [rcx] , [rdx]");
				}
			}
			else { 	// PLUS/MINUS/MULTIPLY/BAND/BOR/BXOR NAMES
				CodeGenerator(root->children[0]->children[1]);
                text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"int"}]));
				text.push_back("mov [rcx] , rax");
            }
		}
	}
	else if(root->NodeName=="INCDEC_STATEMENT"){
		if(root->children[1]->NodeName=="INC"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->lex_val,"int"}]));
			text.push_back("mov rax , [rcx]");
			text.push_back("add rax , 1");
			text.push_back("mov [rcx] , rax");
		}
		else if(root->children[1]->NodeName=="DEC"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->lex_val,"int"}]));
			text.push_back("mov rax , [rcx]");
			text.push_back("add rax , -1");
			text.push_back("mov [rcx] , rax");
		}
	}
	else if(root->NodeName=="IF_STATEMENT"){
		count_loops++;
		string LabelIf="LabelIf"+to_string(count_loops);
		string EndIf="EndIf"+to_string(count_loops);
		text.push_back(LabelIf+":");
		if(root->children[2]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[2]);
			text.push_back("jl "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[2]);
			text.push_back("jg "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[2]);
			text.push_back("jle "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[2]);
			text.push_back("jge "+EndIf);

		}
		if(root->children[2]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[2]);
			text.push_back("jne "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[2]);
			text.push_back("je "+EndIf);
		}
		CodeGenerator(root->children[4]);
		/* text.push_back("jmp "+LabelIf); */
		text.push_back(EndIf+":");
	}
	else if(root->NodeName=="FOR_STATEMENT"){
		count_loops++;
		CodeGenerator(root->children[2]);
		string LabelFor="LabelFor"+to_string(count_loops);
		string EndFor="EndFor"+to_string(count_loops);
		text.push_back(LabelFor+":");
		if(root->children[3]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[3]);
			text.push_back("je "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[3]);
			text.push_back("jl "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[3]);
			text.push_back("jle "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[3]);
			text.push_back("jge "+EndFor);

		}
		if(root->children[3]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[3]);
			text.push_back("jg "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[3]);
			text.push_back("jne "+EndFor);
		}
		CodeGenerator(root->children[7]);
		CodeGenerator(root->children[5]);
		text.push_back("jmp "+LabelFor);
		text.push_back(EndFor+":");
	}
	else if(root->NodeName=="WHILE_STATEMENT"){
		count_loops++;
		string LabelWhile="LabelWhile"+to_string(count_loops);
		string EndWhile="EndWhile"+to_string(count_loops);
		text.push_back(LabelWhile+":");
		if(root->children[2]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[2]);
			text.push_back("je "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[2]);
			text.push_back("jl "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[2]);
			text.push_back("jle "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[2]);
			text.push_back("jge "+EndWhile);

		}
		if(root->children[2]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[2]);
			text.push_back("jg "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[2]);
			text.push_back("jne "+EndWhile);
		}
		CodeGenerator(root->children[4]);
		text.push_back("jmp "+LabelWhile);
		text.push_back(EndWhile+":");
	}
	else if(root->NodeName=="EXPRESSION"){ // EXPRESSION CODE GEN  // storing everythin in rax
		if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"int"}]));
			text.push_back("mov rax , [rcx]");
		}
		else if(root->children[0]->children[0]->children[0]->NodeName=="INTEGER_NT"){
			text.push_back("mov rcx , "+root->children[0]->children[0]->children[0]->lex_val);
			text.push_back("mov rax , rcx");
		}
		if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"int"}]));
			text.push_back("mov rbx , [rcx]");
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="INTEGER_NT"){
			text.push_back("mov rcx , "+root->children[0]->children[1]->children[0]->lex_val);
			text.push_back("mov rbx , rcx");
		}
		string typ=root->children[0]->NodeName;
		if(typ=="PLUS"){
			text.push_back("add rax , rbx");
		}
		else if(typ=="MINUS"){
			text.push_back("sub rax , rbx");
		}
		else if(typ=="MULTIPLY"){
			text.push_back("mul rbx");
		}
		else if(typ=="BAND"){
			text.push_back("and rbx");
		}
		else if(typ=="BOR"){
			text.push_back("or rbx");
		}
		else if(typ=="BXOR"){
			text.push_back("xor rbx");
		}
		else if(typ=="GE" || typ=="LE" || typ=="GT" || typ=="LT" || typ=="EE" || typ=="NEQ"){
			text.push_back("cmp rax , rbx");
		}
	}
}
void putx86inafile(){
	ofstream MyFile("gen.asm");
	for(int i=0;i<bss.size();i++){
		MyFile<<bss[i]<<endl;
	}
	for(int i=0;i<data.size();i++){
		MyFile<<data[i]<<endl;
	}
	for(int i=0;i<text.size();i++){
		MyFile<<text[i]<<endl;
	}
	for(int i=0;i<printint.size();i++){
		MyFile<<printint[i]<<endl;
	}
	MyFile.close();
}


void yyerror(char* temp){
	cout<<"Parsing Terminated...Syntax Error:("<<endl;
	exit(0);
}

void set_integer_print_subroutine(){ // prints the string in the rax register , custom made subroutine by me
	printint.push_back("_printRAX:");
	printint.push_back("mov rcx, digitSpace");
	printint.push_back("mov rbx, 10");
	printint.push_back("mov [rcx], rbx");
	printint.push_back("inc rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("_printRAXLoop:");
	printint.push_back("mov rdx, 0");
	printint.push_back("mov rbx, 10");
	printint.push_back("div rbx");
	printint.push_back("push rax");
	printint.push_back("add rdx, 48");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("mov [rcx], dl");
	printint.push_back("inc rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("pop rax");
	printint.push_back("cmp rax, 0");
	printint.push_back("jne _printRAXLoop");
	printint.push_back("_printRAXLoop2:");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("mov rax, 1");
	printint.push_back("mov rdi, 1");
	printint.push_back("mov rsi, rcx");
	printint.push_back("mov rdx, 1");
	printint.push_back("syscall");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("dec rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("cmp rcx, digitSpace");
	printint.push_back("jge _printRAXLoop2");
	printint.push_back("ret");
	bss.push_back("section .bss");
	bss.push_back("digitSpace resb 100");
	bss.push_back("digitSpacePos resb 8");
}

void set_integer_scan_subroutine(){
	bss.push_back("scanned resb 16");
}

void string_to_number_subroutine(){ // takes the string inside the scanned in bss and returns output inside rax register , custom made subroutine by me
	
    text.push_back("xor rax, rax");
	text.push_back("mov rdx , scanned");
	text.push_back("top:");
	text.push_back("movzx rcx , byte [rdx]");
	text.push_back("add rdx , 1");
	text.push_back("cmp rcx , '0' ");
	text.push_back("jl done");
	text.push_back("cmp rcx , '9' ");
	text.push_back("jg done");
	text.push_back("sub rcx , '0'");
	text.push_back("imul rax , 10");
	text.push_back("add rax , rcx");
	text.push_back("jmp top");
	text.push_back("done:");
}

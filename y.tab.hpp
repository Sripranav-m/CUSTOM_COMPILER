/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 167 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

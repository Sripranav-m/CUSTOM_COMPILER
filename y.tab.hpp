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
    IDENTIFIER = 259,
    FUNCTION_IDENTIFIER = 260,
    NUMBER = 261,
    COMMA = 262,
    SEMICOLON = 263,
    OFB = 264,
    CFB = 265,
    ONB = 266,
    CNB = 267,
    PLUS = 268,
    MINUS = 269,
    MULTIPLY = 270,
    IF = 271,
    ELSE = 272,
    ELIF = 273,
    WHILE = 274,
    FOR = 275,
    PRINT = 276,
    SCAN = 277,
    OR = 278,
    AND = 279,
    NOT = 280,
    EQUALTO = 281,
    LT = 282,
    GT = 283,
    LE = 284,
    GE = 285,
    EE = 286,
    NEQ = 287,
    INC = 288,
    DEC = 289
  };
#endif
/* Tokens.  */
#define INT 258
#define IDENTIFIER 259
#define FUNCTION_IDENTIFIER 260
#define NUMBER 261
#define COMMA 262
#define SEMICOLON 263
#define OFB 264
#define CFB 265
#define ONB 266
#define CNB 267
#define PLUS 268
#define MINUS 269
#define MULTIPLY 270
#define IF 271
#define ELSE 272
#define ELIF 273
#define WHILE 274
#define FOR 275
#define PRINT 276
#define SCAN 277
#define OR 278
#define AND 279
#define NOT 280
#define EQUALTO 281
#define LT 282
#define GT 283
#define LE 284
#define GE 285
#define EE 286
#define NEQ 287
#define INC 288
#define DEC 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "yacc.y"

	class TreeNode* node;

#line 129 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

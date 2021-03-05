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
    NUMBER = 260,
    COMMA = 261,
    SEMICOLON = 262,
    OFB = 263,
    CFB = 264,
    ONB = 265,
    CNB = 266,
    PLUS = 267,
    MINUS = 268,
    MULTIPLY = 269,
    EQUALTO = 270,
    IF = 271,
    ELSE = 272,
    ELIF = 273,
    WHILE = 274,
    FUNCTION_IDENTIFIER = 275,
    FOR = 276,
    INC = 277,
    DEC = 278,
    PRINT = 279,
    SCAN = 280,
    OR = 281,
    AND = 282,
    NOT = 283,
    LT = 284,
    GT = 285,
    LE = 286,
    GE = 287,
    EE = 288
  };
#endif
/* Tokens.  */
#define INT 258
#define IDENTIFIER 259
#define NUMBER 260
#define COMMA 261
#define SEMICOLON 262
#define OFB 263
#define CFB 264
#define ONB 265
#define CNB 266
#define PLUS 267
#define MINUS 268
#define MULTIPLY 269
#define EQUALTO 270
#define IF 271
#define ELSE 272
#define ELIF 273
#define WHILE 274
#define FUNCTION_IDENTIFIER 275
#define FOR 276
#define INC 277
#define DEC 278
#define PRINT 279
#define SCAN 280
#define OR 281
#define AND 282
#define NOT 283
#define LT 284
#define GT 285
#define LE 286
#define GE 287
#define EE 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 75 "yacc.y"

	class TreeNode* node;

#line 127 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

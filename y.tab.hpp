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

#line 145 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

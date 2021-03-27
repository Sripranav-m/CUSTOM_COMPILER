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
    IDENTIFIER = 263,
    CHAR = 264,
    STR = 265,
    FUNCTION_IDENTIFIER = 266,
    NUMBER = 267,
    FLOATING = 268,
    COMMA = 269,
    SEMICOLON = 270,
    OFB = 271,
    CFB = 272,
    ONB = 273,
    CNB = 274,
    PLUS = 275,
    MINUS = 276,
    MULTIPLY = 277,
    IF = 278,
    ELSE = 279,
    ELIF = 280,
    WHILE = 281,
    FOR = 282,
    PRINT = 283,
    SCAN = 284,
    OR = 285,
    AND = 286,
    NOT = 287,
    EQUALTO = 288,
    LT = 289,
    GT = 290,
    LE = 291,
    GE = 292,
    EE = 293,
    NEQ = 294,
    INC = 295,
    DEC = 296,
    IC = 297,
    BAND = 298,
    BOR = 299,
    BXOR = 300,
    OSB = 301,
    CSB = 302
  };
#endif
/* Tokens.  */
#define INT 258
#define STRING 259
#define CHARACTER 260
#define FLOAT 261
#define LIST 262
#define IDENTIFIER 263
#define CHAR 264
#define STR 265
#define FUNCTION_IDENTIFIER 266
#define NUMBER 267
#define FLOATING 268
#define COMMA 269
#define SEMICOLON 270
#define OFB 271
#define CFB 272
#define ONB 273
#define CNB 274
#define PLUS 275
#define MINUS 276
#define MULTIPLY 277
#define IF 278
#define ELSE 279
#define ELIF 280
#define WHILE 281
#define FOR 282
#define PRINT 283
#define SCAN 284
#define OR 285
#define AND 286
#define NOT 287
#define EQUALTO 288
#define LT 289
#define GT 290
#define LE 291
#define GE 292
#define EE 293
#define NEQ 294
#define INC 295
#define DEC 296
#define IC 297
#define BAND 298
#define BOR 299
#define BXOR 300
#define OSB 301
#define CSB 302

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "yacc.y"

	class TreeNode* node;

#line 155 "y.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

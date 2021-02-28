/*Auxiliary declarations start here*/

/* The auxiliary declarations are copied as such by LEX to the output lex.yy.c file. */
/* This C code consists of instructions to the C compiler and are not processed by the LEX tool. */
/* The auxiliary declarations (which are optional) are written in C language and are enclosed within ' %{ ' and ' %} '. */
/* It is generally used to declare functions, include header files, or define global variables and constants. */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}



/*Regular definitions */

delim [ \t\n]*
letter [A-Za-z]
underscore [_]
digit [0-9]
int int
plus [+]
minus [-]
equal [=]
multiply [*]
if [if]
else [else]
elif [elif]
or [or]
and [and]
not [not]
lt [<]
gt [>]
le [<=]
ge [>=]
ee [==]
while [while]



/* TRANSITION RULES */
%%

"#".*                                   {}  // This is a single line comment. Ignore the comments.

{int}			                        {return INT;}
{plus}                                  {return PLUS;}
{minus}                                 {return MINUS;}
{multiply}                              {return MULTIPLY;}
{equal}                                 {return EQUALTO;}
{if}                                    {return IF;}
{elif}                                  {return ELIF;}
{else}                                  {return ELSE;}
{or}                                    {return OR;}
{and}                                   {return AND;}
{not}                                   {return NOT;}
{lt}                                    {return LT;}
{gt}                                    {return GT;}
{le}                                    {return LE;}
{ge}                                    {return GE;}
{ee}                                    {return EE;}
{while}                                 {return WHILE;}

{letter}+{digit}?                       {strcpy(yylval.string, yytext);return IDENTIFIER;}
({plus}|{minus})?{digit}+				{strcpy(yylval.string, yytext);return NUMBER;}



","										{return COMMA;}
";"										{return SEMICOLON;}
"{"										{return OFB;}
"}"										{return CFB;}
"("                                     {return ONB;}
")"                                     {return CNB;}
[ \t\r\n]	                                        ;
.                                                   ;

%%


/* AUXILIARY FUNCTIONS */



/* If yywrap() returns zero (indicating false) yylex() assumes there is more input and it continues scanning from the location pointed to by yyin. */
/* If yywrap() returns a non-zero value (indicating true), yylex() terminates the scanning process and returns 0 (i.e. “wraps up”). */
/* If the programmer wishes to scan more than one input file using the generated lexical analyzer, it can be simply done by setting yyin to a new input file in yywrap() and return 0. */


// int yywrap(){
//     return 1;
// }
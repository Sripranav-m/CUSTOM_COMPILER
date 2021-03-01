/*Auxiliary declarations start here*/

/* The auxiliary declarations are copied as such by LEX to the output lex.yy.c file. */
/* This C code consists of instructions to the C compiler and are not processed by the LEX tool. */
/* The auxiliary declarations (which are optional) are written in C language and are enclosed within ' %{ ' and ' %} '. */
/* It is generally used to declare functions, include header files, or define global variables and constants. */
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.hpp"
extern char mytext[10000];
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
for [for]



/* TRANSITION RULES */
%%

"#".*                                   {}  // This is a single line comment. Ignore the comments.

integer			                        {return INT;}
"+"                                     {return PLUS;}
"-"                                 {return MINUS;}
"*"                              {return MULTIPLY;}
"="                                 {return EQUALTO;}
if                                    {return IF;}
elif                                  {return ELIF;}
else                                 {return ELSE;}
"||"                                    {return OR;}
"&&"                                   {return AND;}
"!"                                   {return NOT;}
"<"                                    {return LT;}
">"                                    {return GT;}
"<="                                    {return LE;}
">="                                    {return GE;}
"=="                                    {return EE;}








for {
    return FOR;
}

while {
    return WHILE;
}

break {
    return BREAK;
}

continue {
    return CONTINUE;
}

return {
    return RETURN;
}

print {
    return PRINT;
}

scan {
    return SCAN;
}

{letter}+{digit}?                       {strcpy(mytext, yytext);return IDENTIFIER;}
{underscore}{letter}+{digit}?           {strcpy(mytext, yytext);return IDENTIFIER;}
({plus}|{minus})?{digit}+				{strcpy(mytext, yytext);return NUMBER;}


","										{return COMMA;}
";"										{return SEMICOLON;}
"{"										{return OFB;}
"}"										{return CFB;}
"("                                     {return ONB;}
")"                                     {return CNB;}
"["                                     {return OSQB;}
"]"                                     {return CSQB;}
":"                                     {return COLON;}
"++"                                    {return INC;}
"--"                                    {return DEC;}
[ \t\r\n]	                                        ;
.                                                   ;

%%


/* AUXILIARY FUNCTIONS */



/* If yywrap() returns zero (indicating false) yylex() assumes there is more input and it continues scanning from the location pointed to by yyin. */
/* If yywrap() returns a non-zero value (indicating true), yylex() terminates the scanning process and returns 0 (i.e. “wraps up”). */
/* If the programmer wishes to scan more than one input file using the generated lexical analyzer, it can be simply done by setting yyin to a new input file in yywrap() and return 0. */


int yywrap(void){
    return 1;
}
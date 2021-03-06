%{
#include <bits/stdc++.h>
#include "y.tab.hpp"
extern char mytext[10000];
%}

letter [A-Za-z]
underscore [_]
digit [0-9]
ic ["]


%%

"#".*                                   {}  // This is a single line comment. Ignore the comments.

"int"			                        {return INT;}
"for"                                     {return FOR;}
"while"                                   {return WHILE;}
"print"                                   {return PRINT;}
"scan"                                    {return SCAN;}

"=="|"<="|">="|">"|"<"|"!=" {
    if(strcmp(yytext, "==") == 0) {
        return EE;
    }
    else if(strcmp(yytext, ">=") == 0) {
        return GE;
    }
    else if(strcmp(yytext, "<=") == 0) {
        return LE;
    }
    else if(strcmp(yytext, ">") == 0) {
        return GT;
    }
    else if(strcmp(yytext, "<") == 0) {
        return LT;
    }
    else if(strcmp(yytext, "!=") == 0) {
        return NEQ;
    } 
}

"if"                                  {return IF;}
"elif"                                  {return ELIF;}
"else"                                {return ELSE;}
"||"                                    {return OR;}
"&&"                                   {return AND;}
"!"                                   {return NOT;}

","										{return COMMA;}
";"										{return SEMICOLON;}

"{"										{return OFB;}
"}"										{return CFB;}
"("                                     {return ONB;}
")"                                     {return CNB;}

"++"                                    {return INC;}
"--"                                    {return DEC;}

"+"                                     {return PLUS;}
"-"                                     {return MINUS;}
"*"                                     {return MULTIPLY;}
"="                                     {return EQUALTO;}

{ic}                                    {return IC;}
({letter}+{digit}?)                     {strcpy(mytext, yytext);return IDENTIFIER;}
{underscore}{letter}+{digit}?           {strcpy(mytext, yytext);return FUNCTION_IDENTIFIER;}
("+"|"-")?{digit}+				        {strcpy(mytext, yytext);return NUMBER;}

[ \t\r\n]	                                        ;
.                                                   ;

%%

int yywrap(void){
    return 1;
}
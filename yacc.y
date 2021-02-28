/* Beginning of Declarations part */

/* Beginning of C declarations */
%{
	#include <stdio.h>
	#include <string.h>
	int yylex();
	int yyerror(char *);
	char st[100][100];
	int top=0;
	char temp[2]="t";
	char temp_num=0;
	void codegen_assign_unary_minus();
	void codegen();
	void push();
	void codegen_assign();
	void append(char* s, char c);
%}
/* End of C declarations */

/* Beginning of YACC declarations  */

%token INT 
%token IDENTIFIER
%token NUMBER
%token COMMA
%token SEMICOLON
%token OFB
%token CFB
%token ONB
%token CNB
%token PLUS
%token MINUS
%token MULTIPLY
%token EQUALTO
%token IF
%token ELSE
%token ELIF
%token OR
%token AND
%token NOT
%token LT
%token GT
%token LE
%token GE
%token EE
%token WHILE;

%left PLUS
%left MULTIPLY
%left MINUS
%right EQUALTO

%union{
	char string[100];
}

%type<string> NUMBER
%type<string> IDENTIFIER

/* End of YACC declarations */

/* End of Declarations Part */

/* Rules Section begins here */

%%


PROGRAM : OFB STATEMENT CFB ;

STATEMENT 	: LINE 
			| LINE STATEMENT ;

LINE 	: IDENTIFIER{push($1);} EQUALTO{push("=");} AE  {codegen_assign();} SEMICOLON;  // AE is Arithmetic Expression
		| IF ONB BE CNB OFB STATEMENT CFB ELSE STATEMENT SEMICOLON ;
		| WHILE ONB BE CNB OFB STATEMENT CFB SEMICOLON;

BE 	: BE OR BE ;
	| BE AND BE ;
	| NOT BE ;
	| ONB BE CNB ;
	| AE RELOP AE ;

RELOP 	: LE;
		| GE;
		| LT;
		| GT;
		| EE;


AE 	: AE PLUS{push("+");} T  {codegen();}
	| AE MINUS{push("-");} T  {codegen();}
	| T ;

T 	: T MULTIPLY{push("*");} F {codegen();} 
	| F;

F 	: ONB AE CNB 
	| MINUS{push("-");} F  {codegen_assign_unary_minus();} 
	| IDENTIFIER{push($1);} 
	| NUMBER{push($1);} ;

BE : AE;

%%
/* Rules Section ends here */

extern FILE *yyin;

int main(int argc,char** argv){
	yyin = fopen(argv[1],"r");  
	while(!feof(yyin)){
		yyparse();
	}
	fclose(yyin);
	return 0;
}

void push(char* string){
	strcpy(st[++top],string);
}

void codegen(){
	strcpy(temp,"t");
	sprintf(temp, "%s%d", temp, temp_num);
	temp_num++;
	printf("%s = %s %s %s\n",temp,st[top-2],st[top-1],st[top]);
	top-=2;
	strcpy(st[top],temp);
}

void codegen_assign(){
	printf("%s %s %s\n",st[top-2],st[top-1],st[top]);
	top-=2;
}

void codegen_assign_unary_minus(){
	strcpy(temp,"t");
	sprintf(temp, "%s%d", temp, temp_num);
	temp_num++;
	printf("%s = -%s\n",temp,st[top]);
	top--;
	strcpy(st[top],temp);
}

int yyerror(char* temp){
	return 0;
}
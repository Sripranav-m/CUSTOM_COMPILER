/* Beginning of Declarations part */

/* Beginning of C declarations */
%{
	#include <stdio.h>
	#include <string.h>
	int yylex();
	int yyerror(char *);
	char mytext[10000]; // get from lex file.
	class TreeNode {
        public:
            vector<TreeNode*> children;   // children
            string NodeName;              // name of the node
            string lex_val;               // lexical value, name of identifier etc.
            int level;	                  // for printing
            TreeNode(string NodeName, vector<TreeNode*> children) {
                this->NodeName = NodeName;
                this->children = children;
            }
            TreeNode(string NodeName) {  // for leaf nodes(No children nodes)
                this->NodeName = NodeName;
                children.assign(0, NULL);
            }
    };
	TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
	int Num_variables=0;
	map<string, int> stck;
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
	class TreeNode* node;
}

%type<node> PROGRAM
%type<node> DECLARATION_LIST
%type<node> DECLARATION
%type<node> VARIABLE_DECLARATION
%type<node> VARIABLE_TYPE
%type<node> SEMICOLON

/* End of YACC declarations */

/* End of Declarations Part */

/* Rules Section begins here */

%%

PROGRAM : DECLARATION_LIST {
							vector<TreeNode*> v={$1};
							$$=new TreeNode("PROGRAM",v);
							Abstract_Syntax_Tree=$$;
							};


DECLARATION_LIST : DECLARATION_LIST DECLARATION{
												vector<TreeNode*> v={$1,$2};
												$$=new TreeNode("DECLARATION_LIST",v);
												}
				| DECLARATION {
								vector<TreeNode*> v={$1};
								$$=new TreeNode("DECLARATION",v);
							} ;


DECLARATION : VARIABLE_DECLARATION	{
									vector<TreeNode*> v={$1};
									$$=new TreeNode("VARIABLE_DECLARATION",v);
									};

								
VARIABLE_DECLARATION : VARIABLE_TYPE IDENTIFIER SEMICOLON {
															vector<treeNode*> v = {$1, $2, $3};
                                        					$$ = new treeNode("var_decl", v); 
															Num_variables++;
															stck[$2->NodeName]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															}

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



int yyerror(char* temp){
	return 0;
}
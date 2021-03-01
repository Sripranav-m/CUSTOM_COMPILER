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
%token WHILE
%token FUNCTION_IDENTIFIER;

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
%type<node> STATEMENT_LIST
%type<node> STATEMENT
%type<node> ASSIGNMENT_STATEMENT
%type<node> IDENTIFIER_NT
%type<node> EXPRESSION
%type<node> PEXPRESSION
%type<node> INTEGER
%type<node> FUNCTION_DECLARATION
%type<node> FUNCTION_IDENTIFIER_NT;
%type<node> COMPOUND_STATEMENT
%type<node> LOCAL_DECLARATION_LIST
%type<node> LOCAL_DECLARATION

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
									$$=new TreeNode("DECLARATION",v);
									}
			| FUNCTION_DECLARATION {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("DECLARATION",v);
			};

								
VARIABLE_DECLARATION : VARIABLE_TYPE IDENTIFIER SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															stck[$2->NodeName]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															};


FUNCTION_DECLARATION : VARIABLE_TYPE FUNCTION_IDENTIFIER_NT ONB PARAMS CNB COMPOUND_STATEMENT {
																								$3 = new TreeNode("ONB"); $5 = new TreeNode("CNB");
																								vector<TreeNode*> v = {$1, $2, $3, $4, $5, $6};
																								$$ = new TreeNode("FUNCTION_DECLARATION", v);
																							}


STATEMENT_LIST : STATEMENT_LIST STATEMENT {
										vector<TreeNode*> v = {$1, $2};
                                        $$ = new TreeNode("STATEMENT_LIST", v); 
										}
				| STATEMENT {
							vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("STATEMENT_LIST", v); 
							} ;


STATEMENT : ASSIGNMENT_STATEMENT {
								vector<TreeNode*> v = {$1};
                        		$$ = new TreeNode("STATEMENT", v);
								}
			| COMPOUND_STATEMENT {
				vector<TreeNode*> v = {$1};
                $$ = new TreeNode("STATEMENT", v);
			}


COMPOUND_STATEMENT: OFB LOCAL_DECLARATION_LIST STATEMENT_LIST CFB    {
                                                    $1 = new TreeNode("OFB"); $4 = new TreeNode("CFB");
                                                    vector<TreeNode*> v = {$1, $2, $3, $4};
                                                    $$ = new TreeNode("COMPOUND_STATEMENT", v);
                                                };


LOCAL_DECLARATION_LIST : LOCAL_DECLARATION_LIST LOCAL_DECLARATION {
																vector<TreeNode*> v = {$1, $2};
                                        						$$ = new TreeNode("LOCAL_DECLARATION_LIST", v);
																}
						| 	{
							TreeNode* x = new TreeNode("EPSILON");
							vector<TreeNode*> v = {x};
							$$ = new TreeNode("LOCAL_DECLARATION_LIST", v);
						};


LOCAL_DECLARATION : VARIABLE_TYPE IDENTIFIER SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;
															stck[$2->NodeName]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															};



ASSIGNMENT_STATEMENT : IDENTIFIER_NT EQUALTO EXPRESSION SEMICOLON {									// Identifier and Expression are given as children to EQUAL TO OPERATOR IN SYNTAX TREE.
																vector<TreeNode*> v={$1,$3};
																$2=new TreeNode("EQUALTO",v);
																$4=new TreeNode("SEMICOLON");
																vector<TreeNode*> u={$2,$4};
																$$=new TreeNode("ASSIGNMENT_STATEMENT",u);
																};


EXPRESSION : PEXPRESSION {	
						vector<TreeNode*> v={$1};
						$$=new TreeNode("EXPRESSION",v);
						};


PEXPRESSION : INTEGER {	
					vector<TreeNode*> v={$1};
					$$=new TreeNode("PEXPRESSION",v);
					}
			| IDENTIFIER_NT {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("PEXPRESSION",v);
			| ONB EXPRESSION CNB {
				$1 = new TreeNode("ONB"); $3 = new TreeNode("CNB");
                vector<TreeNode*> v = {$1, $2, $3};
                $$ = new TreeNode("PEXPRESSION", v);
			}
			};


INTEGER : NUMBER {
				$1 = new TreeNode("NUMBER");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("INTEGER", v);
				$$->lexValue = mytext;
				};


IDENTIFIER_NT : IDENTIFIER {
							$1 = new TreeNode("IDENTIFIER");
                            vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("IDENTIFIER_NT", v);
                            $$->lexValue = mytext;
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
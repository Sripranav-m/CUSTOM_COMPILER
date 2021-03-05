/* Beginning of Declarations part */

/* Beginning of C declarations */
%{
	// #include <stdio.h>
	// #include <string.h>
	#include<bits/stdc++.h>
	using namespace std;
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
%token WHILE
%token FUNCTION_IDENTIFIER
%token FOR
%token INC
%token DEC
%token PRINT
%token SCAN
%token OR
%token AND
%token NOT
%token LT
%token GT
%token LE
%token GE
%token EE

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
%type<node> INTEGER_NT
%type<node> FUNCTION_DECLARATION
// %type<node> FUNCTION_IDENTIFIER_NT
%type<node> COMPOUND_STATEMENT
%type<node> LOCAL_DECLARATION_LIST
%type<node> LOCAL_DECLARATION



%type<node>IF_STATEMENT
%type<node>ELSE_STATEMENT
%type<node>ELIF_STATEMENT
%type<node>WHILE_STATEMENT
%type<node>FOR_STATEMENT
// %type<node>RETURN_STATEMENT
// %type<node>BREAK_STATEMENT
// %type<node>CONTINUE_STATEMENT
// %type<node>PRINT_STATEMENT
// %type<node>SCAN_STATEMENT
%type<node>INCREMENT_STATEMENT
%type<node>DECREMENT_STATEMENT



%type<node>PARAM
%type<node> PARAMS
%type<node>PARAM_LIST_NT

%type<node> INT 
%type<node> IDENTIFIER
%type<node> NUMBER
%type<node> COMMA
%type<node> SEMICOLON
%type<node> OFB
%type<node> CFB
%type<node> ONB
%type<node> CNB
%type<node> PLUS
%type<node> MINUS
%type<node> MULTIPLY
%type<node> EQUALTO
%type<node> IF
%type<node> ELSE
%type<node> ELIF
%type<node> OR
%type<node> AND
%type<node> NOT
%type<node> LT
%type<node> GT
%type<node> LE
%type<node> GE
%type<node> EE
%type<node> WHILE
%type<node> FUNCTION_IDENTIFIER
%type<node> COLON
%type<node> FOR
%type<node> INC
%type<node> DEC
%type<node> PRINT
%type<node> BREAK
%type<node> CONTINUE
%type<node> SCAN
%type<node> RETURN





/* End of YACC declarations */

/* End of Declarations Part */

/* Rules Section begins here */

%%
PROGRAM: DECLARATION_LIST {
							vector<TreeNode*> v={$1};
							$$=new TreeNode("PROGRAM",v);
							Abstract_Syntax_Tree=$$;
							};


DECLARATION_LIST: DECLARATION_LIST DECLARATION{
												vector<TreeNode*> v={$1,$2};
												$$=new TreeNode("DECLARATION_LIST",v);
												}
				| DECLARATION {
								vector<TreeNode*> v={$1};
								$$=new TreeNode("DECLARATION",v);
							} ;


DECLARATION: VARIABLE_DECLARATION	{

			vector<TreeNode*> v={$1};
			$$=new TreeNode("DECLARATION",v);
			
									}
			| FUNCTION_DECLARATION {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("DECLARATION",v);
			};


								
VARIABLE_DECLARATION: VARIABLE_TYPE IDENTIFIER SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															stck[$2->NodeName]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															};
					


FUNCTION_DECLARATION: VARIABLE_TYPE IDENTIFIER_NT ONB PARAMS CNB COMPOUND_STATEMENT {
																								$3 = new TreeNode("ONB"); $5 = new TreeNode("CNB");
																								vector<TreeNode*> v = {$1, $2, $3, $4, $5, $6};
																								$$ = new TreeNode("FUNCTION_DECLARATION", v);
																							};



PARAMS: PARAM_LIST_NT {
						vector<TreeNode*> v = {$1};
						$$ = new TreeNode("PARAMS",v);
					}								
		| {
			auto eps= new TreeNode("EPSILON");
			vector<TreeNode*> v = {eps};
			$$ = new TreeNode("PARAMS",v);
		};



PARAM_LIST_NT: PARAM_LIST_NT COMMA PARAM {
										$2 = new TreeNode("COMMA");
										vector<TreeNode*> v = {$1,$2,$3};
										$$ = new TreeNode("PARAM_LIST_NT",v);
									} 
				| PARAM {
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("PARAM_LIST_NT",v);
				};



PARAM: VARIABLE_TYPE IDENTIFIER_NT{
									vector<TreeNode*> v = {$1,$2};
									$$ = new TreeNode("PARAM",v);
								};



STATEMENT_LIST: STATEMENT_LIST STATEMENT {
										vector<TreeNode*> v = {$1, $2};
                                        $$ = new TreeNode("STATEMENT_LIST", v); 
										}
				| STATEMENT {
							vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("STATEMENT_LIST", v); 
							} ;



STATEMENT: ASSIGNMENT_STATEMENT {
								vector<TreeNode*> v = {$1};
                        		$$ = new TreeNode("STATEMENT", v);
								}
			| COMPOUND_STATEMENT {
				vector<TreeNode*> v = {$1};
                $$ = new TreeNode("STATEMENT", v);
			} 

			| IF_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}
			| WHILE_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}

			|  FOR_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}

			| INCREMENT_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}

			| DECREMENT_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			};


IF_STATEMENT: IF ONB EXPRESSION CNB STATEMENT {
												$1 = new TreeNode("IF");
												$2 = new TreeNode("ONB");
												$4 = new TreeNode("CNB");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5};
												$$ = new TreeNode("IF_STATEMENT",v);
											}
			  | IF ONB EXPRESSION CNB STATEMENT ELSE_STATEMENT {
				  										$1 = new TreeNode("IF");
														$2 = new TreeNode("ONB");
														$4 = new TreeNode("CNB");
														
														vector<TreeNode*> v = {$1,$2,$3,$4,$5,$6};
														$$ = new TreeNode("IF_STATEMENT",v);
			  										};



WHILE_STATEMENT: WHILE ONB EXPRESSION CNB STATEMENT {
													$1 = new TreeNode("WHILE_STATEMENT");
													$2 = new TreeNode("ONB");
													$4 = new TreeNode("CNB");
													vector<TreeNode*> v = {$1,$2,$3,$4,$5};
													$$ = new TreeNode("WHILE_STATEMENT",v);
												};



FOR_STATEMENT: FOR ONB VARIABLE_TYPE EXPRESSION SEMICOLON EXPRESSION SEMICOLON INCREMENT_STATEMENT CNB STATEMENT {
												$1 = new TreeNode("FOR");
												$2 = new TreeNode("ONB");
												$5 = new TreeNode("SEMICOLON");
												$7 = new TreeNode("SEMICOLON");
												$9 = new TreeNode("CNB");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5,$6,$7,$8,$9,$10};
												$$ = new TreeNode("FOR_STATEMENT",v);				
										};



INCREMENT_STATEMENT: IDENTIFIER_NT INC SEMICOLON   {
                                    $3 = new TreeNode("SEMICOLON");
                                    $2 = new TreeNode("INC");
                                    vector<TreeNode*> v = {$1, $2, $3};
                                    $$ = new TreeNode("INCREMENT_STATEMENT", v);
                                };



DECREMENT_STATEMENT: IDENTIFIER_NT DEC SEMICOLON   {
                                    $3 = new TreeNode("SEMICOLON");
                                    $2 = new TreeNode("DEC");
                                    vector<TreeNode*> v = {$1, $2, $3};
                                    $$ = new TreeNode("DECREMENT_STATEMENT", v);
                                };



VARIABLE_TYPE: INT {
					$1 = new TreeNode("INT");
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("VARIABLE_TYPE",v);

				};


COMPOUND_STATEMENT: OFB LOCAL_DECLARATION_LIST STATEMENT_LIST CFB    {
                                                    $1 = new TreeNode("OFB"); $4 = new TreeNode("CFB");
                                                    vector<TreeNode*> v = {$1, $2, $3, $4};
                                                    $$ = new TreeNode("COMPOUND_STATEMENT", v);
                                                };



LOCAL_DECLARATION_LIST: LOCAL_DECLARATION_LIST LOCAL_DECLARATION {
																vector<TreeNode*> v = {$1, $2};
                                        						$$ = new TreeNode("LOCAL_DECLARATION_LIST", v);
																}
						| 	{
							TreeNode* x = new TreeNode("EPSILON");
							vector<TreeNode*> v = {x};
							$$ = new TreeNode("LOCAL_DECLARATION_LIST", v);
						};


LOCAL_DECLARATION: VARIABLE_TYPE IDENTIFIER SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;
															stck[$2->NodeName]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															};



ASSIGNMENT_STATEMENT: IDENTIFIER_NT EQUALTO EXPRESSION SEMICOLON {									// Identifier and Expression are given as children to EQUAL TO OPERATOR IN SYNTAX TREE.
																vector<TreeNode*> v={$1,$3};
																$2=new TreeNode("EQUALTO",v);
																$4=new TreeNode("SEMICOLON");
																vector<TreeNode*> u={$2,$4};
																$$=new TreeNode("ASSIGNMENT_STATEMENT",u);
																};



EXPRESSION: PEXPRESSION {	
						vector<TreeNode*> v={$1};
						$$=new TreeNode("EXPRESSION",v);
						};



PEXPRESSION: INTEGER_NT {	
					vector<TreeNode*> v={$1};
					$$=new TreeNode("PEXPRESSION",v);
					}
			| IDENTIFIER_NT {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("PEXPRESSION",v);
			}
			| ONB EXPRESSION CNB {
				$1 = new TreeNode("ONB"); $3 = new TreeNode("CNB");
                vector<TreeNode*> v = {$1, $2, $3};
                $$ = new TreeNode("PEXPRESSION", v);
			
			};



INTEGER_NT: NUMBER {
				$1 = new TreeNode("NUMBER");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("INTEGER_NT", v);
				$$->lex_val = mytext;
			};



IDENTIFIER_NT: IDENTIFIER {
							$1 = new TreeNode("IDENTIFIER");
                            vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("IDENTIFIER_NT", v);
                            $$->lex_val = mytext;
						};


%%

/* Rules Section ends here */

extern FILE *yyin;

int main(int argc,char** argv){
	yyin = fopen(argv[1],"r");  
	while(!feof(yyin)){
		yyparse();
	}
	fclose(yyin);
	doinorder(Abstract_Syntax_Tree);
	return 0;
}

void doinorder(){

}


int yyerror(char* temp){
	printf("ERROR in code:(\n");
	return 0;
}
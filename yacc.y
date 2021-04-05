%{
	#include "main.h"
	int yylex();
	void yyerror(char *);
	char mytext[10000]; // get from lex file.

	TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
	int Num_variables=0;
	map<pair<string,string>, int> symbol_table;
	map<string,int> list_size;
	map<string,string> variable_types; 
	void dotraversal(TreeNode* head);
	vector<string> text;
	vector<string> data;
	vector<string> bss; // 
	vector<string> printint; // To include the print subroutine
	vector<string> printList;
	vector<string> printNewLine;
	void CodeGenerator(TreeNode* root);
	void putx86inafile();
	void set_integer_print_subroutine();
	void set_data_segment();
	void set_scanner_integer();
	void string_to_number_subroutine();
	void set_list_print_subroutine();
	void set_go_to_new_line_subroutine();
	int count_loops=0;
	int num_scans=0;
%}

%union{
	class TreeNode* node;
}
 
%token 	INT STRING CHARACTER FLOAT LIST IDENTIFIER CHAR STR FUNCTION_IDENTIFIER N_NUMBER NON_N_NUMBER FLOATING COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY DIVIDE
%token  IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC IC BAND BOR BXOR OSB CSB ATSIZE

%left PLUS
%left MULTIPLY
%left MINUS
%left DIVIDE
%right EQUALTO

%type<node> PROGRAM DECLARATION_LIST DECLARATION VARIABLE_DECLARATION VARIABLE_TYPE 
%type<node> STATEMENT_LIST STATEMENT ASSIGNMENT_STATEMENT IDENTIFIER_NT FUNCTION_IDENTIFIER_NT 
%type<node> EXPRESSION PEXPRESSION PEXPRESSION_S PEXPRESSION_F PEXPRESSION_L LIST_ELEMENT INTEGER_NT STRING_NT CHARACTER_NT FLOAT_NT FUNCTION_DECLARATION COMPOUND_STATEMENT 
%type<node> LOCAL_DECLARATION_LIST LOCAL_DECLARATION PRINT_STATEMENT SCAN_STATEMENT PRINT_SCAN_ITEM
%type<node> IF_STATEMENT WHILE_STATEMENT FOR_STATEMENT INCDEC_STATEMENT PARAM PARAMS PARAM_LIST_NT
%type<node> INT STRING CHARACTER FLOAT LIST IC IDENTIFIER FUNCTION_IDENTIFIER N_NUMBER NON_N_NUMBER STR CHAR FLOATING COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY DIVIDE
%type<node> IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC BAND BOR BXOR OSB CSB LIST_TYPE ATSIZE SIZE_EXPRESSION

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
								$$=new TreeNode("DECLARATION_LIST",v);
							} ;


DECLARATION: VARIABLE_DECLARATION	{

			vector<TreeNode*> v={$1};
			$$=new TreeNode("DECLARATION",v);
			}
			| FUNCTION_DECLARATION {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("DECLARATION",v);
			};


								
VARIABLE_DECLARATION:  VARIABLE_TYPE IDENTIFIER_NT SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															if(variable_types.find($2->lex_val)==variable_types.end()){
																string var_type=$1->children[0]->NodeName;
																symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
																variable_types[$2->lex_val]=var_type;
															}
															else{
																// error
															}
						}
						| LIST_TYPE IDENTIFIER_NT OSB NON_N_NUMBER CSB SEMICOLON {
							$3=new TreeNode("OSB");
							$5=new TreeNode("CSB");
							$6=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {$1, $2, $3,$4,$5,$6};
							$$ = new TreeNode("VARIABLE_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[$2->lex_val]=atoi(mytext);
							if(variable_types.find($2->lex_val)==variable_types.end()){
								string var_type=$1->children[0]->NodeName;
								symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
								variable_types[$2->lex_val]=var_type;
							}
							else{
								// error
							}
						}
						
						;

LIST_TYPE : LIST {
				$1 = new TreeNode("LIST");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("LIST_TYPE",v);
				};
					


FUNCTION_DECLARATION: VARIABLE_TYPE FUNCTION_IDENTIFIER_NT ONB PARAMS CNB COMPOUND_STATEMENT {
																								$3 = new TreeNode("ONB"); 
																								$5 = new TreeNode("CNB");
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

			| INCDEC_STATEMENT {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}
			| LOCAL_DECLARATION {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}
			| PRINT_STATEMENT{
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}
			| SCAN_STATEMENT{
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			};



PRINT_STATEMENT : PRINT ONB PRINT_SCAN_ITEM CNB SEMICOLON {
												$1 = new TreeNode("PRINT");
												$2 = new TreeNode("ONB");
												$4 = new TreeNode("CNB");
												$5=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5};
												$$ = new TreeNode("PRINT_STATEMENT",v);
											} ;


SCAN_STATEMENT : SCAN ONB PRINT_SCAN_ITEM CNB SEMICOLON {
												$1 = new TreeNode("SCAN");
												$2 = new TreeNode("ONB");
												$4 = new TreeNode("CNB");
												$5=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5};
												$$ = new TreeNode("SCAN_STATEMENT",v);
											} ;



COMPOUND_STATEMENT: OFB STATEMENT_LIST CFB    {
                                                    $1 = new TreeNode("OFB"); $3 = new TreeNode("CFB");
                                                    vector<TreeNode*> v = {$1, $2, $3};
                                                    $$ = new TreeNode("COMPOUND_STATEMENT", v);
                                                };



IF_STATEMENT: IF ONB EXPRESSION CNB STATEMENT {
												$1 = new TreeNode("IF");
												$2 = new TreeNode("ONB");
												$4 = new TreeNode("CNB");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5};
												$$ = new TreeNode("IF_STATEMENT",v);
											};



WHILE_STATEMENT: WHILE ONB EXPRESSION CNB STATEMENT {
													$1 = new TreeNode("WHILE_STATEMENT");
													$2 = new TreeNode("ONB");
													$4 = new TreeNode("CNB");
													vector<TreeNode*> v = {$1,$2,$3,$4,$5};
													$$ = new TreeNode("WHILE_STATEMENT",v);
												};




FOR_STATEMENT: FOR ONB ASSIGNMENT_STATEMENT EXPRESSION SEMICOLON INCDEC_STATEMENT CNB STATEMENT {
												$1 = new TreeNode("FOR");
												$2 = new TreeNode("ONB");
												$5 = new TreeNode("SEMICOLON");
												$7 = new TreeNode("CNB");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5,$6,$7,$8};
												$$ = new TreeNode("FOR_STATEMENT",v);				
										};



INCDEC_STATEMENT: IDENTIFIER_NT INC SEMICOLON   {
                                    $3 = new TreeNode("SEMICOLON");
                                    $2 = new TreeNode("INC");
                                    vector<TreeNode*> v = {$1, $2, $3};
                                    $$ = new TreeNode("INCDEC_STATEMENT", v);
                                }
				|
				IDENTIFIER_NT DEC SEMICOLON {
                                    $3 = new TreeNode("SEMICOLON");
                                    $2 = new TreeNode("DEC");
                                    vector<TreeNode*> v = {$1, $2, $3};
                                    $$ = new TreeNode("INCDEC_STATEMENT", v);
                };



VARIABLE_TYPE: INT {
					$1 = new TreeNode("INT");
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("VARIABLE_TYPE",v);

				}
				| STRING{
					$1 = new TreeNode("STRING");
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("VARIABLE_TYPE",v);
				}
				| CHARACTER {
					$1 = new TreeNode("CHARACTER");
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("VARIABLE_TYPE",v);
				}
				| FLOAT {
					$1 = new TreeNode("FLOAT");
					vector<TreeNode*> v = {$1};
					$$ = new TreeNode("VARIABLE_TYPE",v);
				};




LOCAL_DECLARATION: VARIABLE_TYPE IDENTIFIER_NT SEMICOLON {
															
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;
															if(variable_types.find($2->lex_val)==variable_types.end()){
																string var_type=$1->children[0]->NodeName;
																symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
																variable_types[$2->lex_val]=var_type;
															}
					}
					| LIST_TYPE IDENTIFIER_NT OSB INTEGER_NT CSB SEMICOLON {
							$3=new TreeNode("OSB");
							$5=new TreeNode("CSB");
							$6=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {$1, $2, $3,$4,$5,$6};
							$$ = new TreeNode("LOCAL_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[$2->lex_val]=atoi(mytext);
							if(variable_types.find($2->lex_val)==variable_types.end()){
								string var_type=$1->children[0]->NodeName;
								symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
								variable_types[$2->lex_val]=var_type;
							}
						} ;



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
			}
            |  PEXPRESSION PLUS PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("PLUS",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
            | PEXPRESSION MINUS PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("MINUS",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
            | PEXPRESSION MULTIPLY PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("MULTIPLY",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
			| PEXPRESSION DIVIDE PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("DIVIDE",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
			| PEXPRESSION BAND PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("BAND",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
			| PEXPRESSION BXOR PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("BXOR",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
			| PEXPRESSION BOR PEXPRESSION {
                vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("BOR",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
            }
			| PEXPRESSION GE PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("GE",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION LE PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("LE",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION GT PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("GT",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION LT PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("LT",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION EE PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("EE",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION NEQ PEXPRESSION{
				vector<TreeNode*> v={$1,$3};
                $2=new TreeNode("NEQ",v);
                vector<TreeNode*> u={$2};
                $$=new TreeNode("EXPRESSION",u);
			}
			| PEXPRESSION_S {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("EXPRESSION",v);
			}
			| PEXPRESSION_F{
				vector<TreeNode*> v={$1};
				$$=new TreeNode("EXPRESSION",v);
			}
			| SIZE_EXPRESSION{
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			};


SIZE_EXPRESSION : ATSIZE IDENTIFIER{
						$1=new TreeNode("ATSIZE");
						vector<TreeNode*> v={$1,$2};
						$$ = new TreeNode("SIZE_EXPRESSION",v);
					};


LIST_ELEMENT : LIST_ELEMENT INTEGER_NT SEMICOLON {
					$3=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={$1,$2,$3};
					$$=new TreeNode("LIST_ELEMENT",v);
				} 
				| INTEGER_NT SEMICOLON {
					$2=new TreeNode("SEMICOLON");
					vector<TreeNode*> v={$1,$2};
					$$=new TreeNode("LIST_ELEMENT",v);
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
			
			}
			| OSB LIST_ELEMENT  CSB {
				$1 = new TreeNode("OSB");
				$3 = new TreeNode("CSB");
				vector<TreeNode*> v={$1,$2,$3};
				$$=new TreeNode("PEXPRESSION",v);
			}
			| FLOAT_NT{
				vector<TreeNode*> v={$1};
				$$=new TreeNode("PEXPRESSION",v);
			};

PEXPRESSION_S : STRING_NT {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("PEXPRESSION",v);
			}
			| CHARACTER_NT {
				vector<TreeNode*> v={$1};
				$$=new TreeNode("PEXPRESSION",v);
			}


PEXPRESSION_F : FLOAT_NT {
					vector<TreeNode*> v={$1};
					$$=new TreeNode("PEXPRESSION",v);
				};


PRINT_SCAN_ITEM : IDENTIFIER_NT {
				vector<TreeNode*> v = {$1};
                $$ = new TreeNode("PRINT_SCAN_ITEM", v);
				$$->lex_val=$1->lex_val;
			};


INTEGER_NT: NON_N_NUMBER{
				//cout<<"&\n";
				$1 = new TreeNode("NON_N_NUMBER");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("INTEGER_NT", v);
				$$->lex_val = mytext;
			}
			| N_NUMBER {
				//cout<<"!\n";
				$1 = new TreeNode("N_NUMBER");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("INTEGER_NT", v);
				$$->lex_val = mytext;
			} ;

STRING_NT : STR{
				$1 = new TreeNode("STR");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STRING_NT", v);
				$$->lex_val = mytext;
			};


FLOAT_NT : FLOATING{
				$1 = new TreeNode("FLOATING");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("FLOAT_NT", v);
				$$->lex_val = mytext;
			};


CHARACTER_NT : CHAR {
				$1 = new TreeNode("CHAR");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("CHARACTER_NT", v);
				$$->lex_val = mytext;
			};

IDENTIFIER_NT: IDENTIFIER {
							$1 = new TreeNode("IDENTIFIER");
                            vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("IDENTIFIER_NT", v);
                            $$->lex_val = mytext;
						};



FUNCTION_IDENTIFIER_NT : FUNCTION_IDENTIFIER {
							$1 = new TreeNode("FUNCTION_IDENTIFIER");
                            vector<TreeNode*> v = {$1};
                            $$ = new TreeNode("FUNCTION_IDENTIFIER_NT", v);
                            $$->lex_val = mytext;
						};

%%

/* Rules Section ends here */

extern FILE *yyin;




int main(){
	yyparse();
	//dotraversal(Abstract_Syntax_Tree);
	CodeGenerator(Abstract_Syntax_Tree);
	text.push_back("mov rax , 60");
	text.push_back("mov rdi , 0");
	text.push_back("syscall");
	putx86inafile();
	return 0;
}


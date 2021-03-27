%{
	#include<bits/stdc++.h>
	using namespace std;
	int yylex();
	void yyerror(char *);
	char mytext[10000]; // get from lex file.
	class TreeNode {
        public:
            vector<TreeNode*> children;   // children
            string NodeName;              // name of the node
            string lex_val;              // lexical value, name of identifier etc.
            int level;	                  // for printing
            TreeNode(string NodeName, vector<TreeNode*> children) {
                this->NodeName = NodeName;
                this->children = children;
				this->lex_val="";
            }
            TreeNode(string NodeName) {  // for leaf nodes(No children nodes)
                this->NodeName = NodeName;
                children.assign(0, NULL);
				this->lex_val="";
            }
    };
	TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
	int Num_variables=0;
	map<pair<string,string>, int> symbol_table;
	map<string,int> list_size;
	void dotraversal(TreeNode* head);
	vector<string> text;
	vector<string> data;
	vector<string> bss; // 
	vector<string> printint; // To include the print subroutine
	void CodeGenerator(TreeNode* root);
	void putx86inafile();
	void set_integer_print_subroutine();
	void set_integer_scan_subroutine();
	void string_to_number_subroutine();
	int count_loops=0;
	int num_scans=0;
%}
%union{
	class TreeNode* node;
}

%token 	INT STRING CHARACTER FLOAT LIST IDENTIFIER CHAR STR FUNCTION_IDENTIFIER NUMBER FLOATING COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY
%token  IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC IC BAND BOR BXOR OSB CSB 

%left PLUS
%left MULTIPLY
%left MINUS
%right EQUALTO

%type<node> PROGRAM DECLARATION_LIST DECLARATION VARIABLE_DECLARATION VARIABLE_TYPE 
%type<node> STATEMENT_LIST STATEMENT ASSIGNMENT_STATEMENT IDENTIFIER_NT FUNCTION_IDENTIFIER_NT 
%type<node> EXPRESSION PEXPRESSION PEXPRESSION_S PEXPRESSION_F PEXPRESSION_L LIST_ELEMENT INTEGER_NT STRING_NT CHARACTER_NT FLOAT_NT FUNCTION_DECLARATION COMPOUND_STATEMENT 
%type<node> LOCAL_DECLARATION_LIST LOCAL_DECLARATION PRINT_STATEMENT SCAN_STATEMENT PRINT_SCAN_ITEM
%type<node> IF_STATEMENT WHILE_STATEMENT FOR_STATEMENT INCDEC_STATEMENT PARAM PARAMS PARAM_LIST_NT
%type<node> INT STRING CHARACTER FLOAT LIST IC IDENTIFIER FUNCTION_IDENTIFIER NUMBER STR CHAR FLOATING COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY
%type<node> IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC BAND BOR BXOR OSB CSB LIST_TYPE

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
															string var_type=$1->children[0]->NodeName;
															symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;  // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
						}
						| LIST_TYPE IDENTIFIER_NT OSB NUMBER CSB SEMICOLON {
							$3=new TreeNode("OSB");
							$5=new TreeNode("CSB");
							$6=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {$1, $2, $3,$4,$5,$6};
							$$ = new TreeNode("VARIABLE_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[$2->lex_val]=atoi(mytext);
							string var_type=$1->children[0]->NodeName;
							symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;
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
															string var_type=$1->children[0]->NodeName;
															symbol_table[{$2->lex_val,var_type}]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
					}
					| LIST_TYPE IDENTIFIER_NT OSB INTEGER_NT CSB SEMICOLON {
							$3=new TreeNode("OSB");
							$5=new TreeNode("CSB");
							$6=new TreeNode("SEMICOLON");
							vector<TreeNode*> v = {$1, $2, $3,$4,$5,$6};
							$$ = new TreeNode("LOCAL_DECLARATION", v);
							Num_variables+=atoi(mytext);
							list_size[$2->lex_val]=atoi(mytext);
							string var_type=$1->children[0]->NodeName;
							symbol_table[{$2->lex_val,var_type}]=Num_variables*-8;
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
			| PEXPRESSION_L{
				vector<TreeNode*> v={$1};
				$$=new TreeNode("EXPRESSION",v);
			};



PEXPRESSION_L : OSB LIST_ELEMENT  CSB {
				$1 = new TreeNode("OSB");
				$3 = new TreeNode("CSB");
				vector<TreeNode*> v={$1,$2,$3};
				$$=new TreeNode("PEXPRESSION_L",v);
			}
			| IDENTIFIER_NT{
					vector<TreeNode*> v={$1};
					$$=new TreeNode("PEXPRESSION_L",v);
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


INTEGER_NT: NUMBER {
				$1 = new TreeNode("NUMBER");
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("INTEGER_NT", v);
				$$->lex_val = mytext;
			};

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
// HEAD -> (N CHILDREN) -> EACH CHILDREN = N CHLDREN ->RECURSIVE
// Basically,this is to check whether the Abstract syntax tree is correct or not
// Doing a traversal on the tree that we generated
void dotraversal(TreeNode* head){
	cout<<"NodeName: "<<head->NodeName<<"   ";
	cout<<"Lexval: "<<head->lex_val<<endl;
	vector<TreeNode*> children=head->children;
	for(int i=0;i<children.size();i++){
		dotraversal(children[i]);
	}
	return;
}
// This code generates the X86 code for our abstract syntax tree constructed.
void CodeGenerator(TreeNode* root){
	if(root->NodeName=="PROGRAM"){
		text.push_back("section	.text");
		text.push_back("global _start ");
		text.push_back("_start:");
		text.push_back("push rbp");
		text.push_back("mov rbp , rsp");
		set_integer_print_subroutine();
		set_integer_scan_subroutine();
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="DECLARATION_LIST"){
		CodeGenerator(root->children[0]);
		if(root->children.size()>1){
			CodeGenerator(root->children[1]);
		}
	}
	else if(root->NodeName=="DECLARATION"){
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="VARIABLE_DECLARATION"){
		return;
	}
	else if(root->NodeName=="FUNCTION_DECLARATION"){
		CodeGenerator(root->children[5]);
	}
	else if(root->NodeName=="COMPOUND_STATEMENT"){
		CodeGenerator(root->children[1]);
	}
	else if(root->NodeName=="STATEMENT_LIST"){
		CodeGenerator(root->children[0]);
		if(root->children.size()>1){
			CodeGenerator(root->children[1]);
		}
	}
	else if(root->NodeName=="STATEMENT"){
		CodeGenerator(root->children[0]);
	}
	else if(root->NodeName=="LOCAL_DECLARATION"){
		if(root->children[0]->NodeName=="VARIABLE_TYPE"){
			text.push_back("sub rsp , 8");
		}
		else if(root->children[0]->NodeName=="LIST_TYPE"){
			int x=8*stoi(root->children[3]->lex_val);
			text.push_back("sub rsp , "+to_string(x));
		}
	}
	else if(root->NodeName=="PRINT_STATEMENT"){
		if(symbol_table.find({root->children[2]->lex_val,"INT"})!=symbol_table.end()){
			text.push_back("mov rbx , rbp");
			text.push_back("add rbx , "+to_string(symbol_table[{root->children[2]->lex_val,"INT"}]));
			text.push_back("mov rax , [rbx]");
			text.push_back("call _printRAX");
		}
		else if(symbol_table.find({root->children[2]->lex_val,"LIST"})!=symbol_table.end()){
			int list_location=symbol_table[{root->children[2]->lex_val,"LIST"}];
			int number_of_times=list_size[{root->children[2]->lex_val}];
			list_location+=8*number_of_times;
			//cout<<list_location<<endl<<number_of_times<<endl;
			while(number_of_times>0){
				list_location-=8;
				number_of_times-=1;
				text.push_back("mov rbx , rbp");
				text.push_back("add rbx , "+to_string(list_location));
				text.push_back("mov rax , [rbx]");
				text.push_back("call _printRAX");
			}
		}
	}
	else if(root->NodeName=="SCAN_STATEMENT"){
		num_scans++;
		text.push_back("mov rax , 0");
		text.push_back("mov rdi , 0");
		text.push_back("mov rsi , scanned");
		text.push_back("mov rdx , 16");
		text.push_back("syscall");
		string_to_number_subroutine();
		text.push_back("mov rcx , rbp");
		text.push_back("add rcx , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"INT"}]));
		text.push_back("mov [rcx] , rax");
	}
	else if(root->NodeName=="ASSIGNMENT_STATEMENT"){
		if(root->children[0]->children.size()==2){
			if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION"){
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="INTEGER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
					text.push_back("mov rax , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
				}
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
					text.push_back("mov rdx , rbp");
					text.push_back("add rdx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->children[0]->lex_val,"INT"}]));
					text.push_back("mov [rcx] , [rdx]");
				}
			}
			else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION_L"){
				if(root->children[0]->NodeName=="IDENTIFIER_NT"){

				}
				else{
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"LIST"}]));
					//cout<<symbol_table[{root->children[0]->children[0]->lex_val,"LIST"}]<<endl;
					TreeNode* elements=root->children[0]->children[1]->children[0]->children[1];
					while(elements->children.size()>2){
						string val_from_end=elements->children[1]->lex_val;
						//cout<<val_from_end<<endl;
						text.push_back("mov rax , "+elements->children[1]->lex_val);
						text.push_back("mov [rcx] , rax");
						text.push_back("add rcx , 8");
						elements=elements->children[0];
					}
					string val_from_end=elements->children[0]->lex_val;
					//cout<<val_from_end<<endl;
					text.push_back("mov rax , "+elements->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
				}
			}
			else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION_F"){
				
			}
			else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION_S"){
				
			}
			else { 	// PLUS/MINUS/MULTIPLY/BAND/BOR/BXOR NAMES
				CodeGenerator(root->children[0]->children[1]);
                text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov [rcx] , rax");
            }
		}
	}
	else if(root->NodeName=="INCDEC_STATEMENT"){
		if(root->children[1]->NodeName=="INC"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->lex_val,"INT"}]));
			text.push_back("mov rax , [rcx]");
			text.push_back("add rax , 1");
			text.push_back("mov [rcx] , rax");
		}
		else if(root->children[1]->NodeName=="DEC"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->lex_val,"INT"}]));
			text.push_back("mov rax , [rcx]");
			text.push_back("add rax , -1");
			text.push_back("mov [rcx] , rax");
		}
	}
	else if(root->NodeName=="IF_STATEMENT"){
		count_loops++;
		string LabelIf="LabelIf"+to_string(count_loops);
		string EndIf="EndIf"+to_string(count_loops);
		text.push_back(LabelIf+":");
		if(root->children[2]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[2]);
			text.push_back("jl "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[2]);
			text.push_back("jg "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[2]);
			text.push_back("jle "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[2]);
			text.push_back("jge "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[2]);
			text.push_back("jne "+EndIf);
		}
		if(root->children[2]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[2]);
			text.push_back("je "+EndIf);
		}
		CodeGenerator(root->children[4]);
		/* text.push_back("jmp "+LabelIf); */
		text.push_back(EndIf+":");
	}
	else if(root->NodeName=="FOR_STATEMENT"){
		count_loops++;
		CodeGenerator(root->children[2]);
		string LabelFor="LabelFor"+to_string(count_loops);
		string EndFor="EndFor"+to_string(count_loops);
		text.push_back(LabelFor+":");
		if(root->children[3]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[3]);
			text.push_back("je "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[3]);
			text.push_back("jl "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[3]);
			text.push_back("jle "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[3]);
			text.push_back("jge "+EndFor);

		}
		if(root->children[3]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[3]);
			text.push_back("jg "+EndFor);
		}
		if(root->children[3]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[3]);
			text.push_back("jne "+EndFor);
		}
		CodeGenerator(root->children[7]);
		CodeGenerator(root->children[5]);
		text.push_back("jmp "+LabelFor);
		text.push_back(EndFor+":");
	}
	else if(root->NodeName=="WHILE_STATEMENT"){
		count_loops++;
		string LabelWhile="LabelWhile"+to_string(count_loops);
		string EndWhile="EndWhile"+to_string(count_loops);
		text.push_back(LabelWhile+":");
		if(root->children[2]->children[0]->NodeName=="NEQ"){
			CodeGenerator(root->children[2]);
			text.push_back("je "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="GE"){
			CodeGenerator(root->children[2]);
			text.push_back("jl "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="GT"){
			CodeGenerator(root->children[2]);
			text.push_back("jle "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="LT"){
			CodeGenerator(root->children[2]);
			text.push_back("jge "+EndWhile);

		}
		if(root->children[2]->children[0]->NodeName=="LE"){
			CodeGenerator(root->children[2]);
			text.push_back("jg "+EndWhile);
		}
		if(root->children[2]->children[0]->NodeName=="EE"){
			CodeGenerator(root->children[2]);
			text.push_back("jne "+EndWhile);
		}
		CodeGenerator(root->children[4]);
		text.push_back("jmp "+LabelWhile);
		text.push_back(EndWhile+":");
	}
	else if(root->NodeName=="EXPRESSION"){ // EXPRESSION CODE GEN  // storing everythin in rax
		if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"INT"}]));
			text.push_back("mov rax , [rcx]");
		}
		else if(root->children[0]->children[0]->children[0]->NodeName=="INTEGER_NT"){
			text.push_back("mov rcx , "+root->children[0]->children[0]->children[0]->lex_val);
			text.push_back("mov rax , rcx");
		}
		if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"INT"}]));
			text.push_back("mov rbx , [rcx]");
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="INTEGER_NT"){
			text.push_back("mov rcx , "+root->children[0]->children[1]->children[0]->lex_val);
			text.push_back("mov rbx , rcx");
		}
		string typ=root->children[0]->NodeName;
		if(typ=="PLUS"){
			text.push_back("add rax , rbx");
		}
		else if(typ=="MINUS"){
			text.push_back("sub rax , rbx");
		}
		else if(typ=="MULTIPLY"){
			text.push_back("mul rbx");
		}
		else if(typ=="BAND"){
			text.push_back("and rax , rbx");
		}
		else if(typ=="BOR"){
			text.push_back("or rax , rbx");
		}
		else if(typ=="BXOR"){
			text.push_back("xor rax , rbx");
		}
		else if(typ=="GE" || typ=="LE" || typ=="GT" || typ=="LT" || typ=="EE" || typ=="NEQ"){
			text.push_back("cmp rax , rbx");
		}
	}
}
void putx86inafile(){
	ofstream MyFile("gen.asm");
	for(int i=0;i<bss.size();i++){
		MyFile<<bss[i]<<endl;
	}
	for(int i=0;i<data.size();i++){
		MyFile<<data[i]<<endl;
	}
	for(int i=0;i<text.size();i++){
		MyFile<<text[i]<<endl;
	}
	for(int i=0;i<printint.size();i++){
		MyFile<<printint[i]<<endl;
	}
	MyFile.close();
}


void yyerror(char* temp){
	cout<<"Parsing Terminated...Syntax Error:("<<endl;
	exit(0);
}

void set_integer_print_subroutine(){ // prints the string in the rax register , custom made subroutine by me
	printint.push_back("_printRAX:");
	printint.push_back("mov rcx, digitSpace");
	printint.push_back("mov rbx, 10");
	printint.push_back("mov [rcx], rbx");
	printint.push_back("inc rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("_printRAXLoop:");
	printint.push_back("mov rdx, 0");
	printint.push_back("mov rbx, 10");
	printint.push_back("div rbx");
	printint.push_back("push rax");
	printint.push_back("add rdx, 48");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("mov [rcx], dl");
	printint.push_back("inc rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("pop rax");
	printint.push_back("cmp rax, 0");
	printint.push_back("jne _printRAXLoop");
	printint.push_back("_printRAXLoop2:");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("mov rax, 1");
	printint.push_back("mov rdi, 1");
	printint.push_back("mov rsi, rcx");
	printint.push_back("mov rdx, 1");
	printint.push_back("syscall");
	printint.push_back("mov rcx, [digitSpacePos]");
	printint.push_back("dec rcx");
	printint.push_back("mov [digitSpacePos], rcx");
	printint.push_back("cmp rcx, digitSpace");
	printint.push_back("jge _printRAXLoop2");
	printint.push_back("ret");
	bss.push_back("section .bss");
	bss.push_back("digitSpace resb 100");
	bss.push_back("digitSpacePos resb 8");
}

void set_integer_scan_subroutine(){
	bss.push_back("scanned resb 16");
}

void string_to_number_subroutine(){ // takes the string inside the scanned in bss and returns output inside rax register , custom made subroutine by me
	
    text.push_back("xor rax, rax");
	text.push_back("mov rdx , scanned");
	text.push_back("top"+to_string(num_scans)+":");
	text.push_back("movzx rcx , byte [rdx]");
	text.push_back("add rdx , 1");
	text.push_back("cmp rcx , '0' ");
	text.push_back("jl done"+to_string(num_scans));
	text.push_back("cmp rcx , '9' ");
	text.push_back("jg done"+to_string(num_scans));
	text.push_back("sub rcx , '0'");
	text.push_back("imul rax , 10");
	text.push_back("add rax , rcx");
	text.push_back("jmp top"+to_string(num_scans));
	text.push_back("done"+to_string(num_scans)+":");
}
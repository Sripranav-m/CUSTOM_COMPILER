%{
	// #include <stdio.h>
	// #include <string.h>
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
	map<string, int> stck;   // Symbol Table
	void dotraversal(TreeNode* head);
	vector<string> text;
	vector<string> data;
	vector<string> bss;
	vector<string> printint;
	void CodeGenerator(TreeNode* root);
	void putx86inafile();
%}
%union{
	class TreeNode* node;
}

%token 	INT IDENTIFIER FUNCTION_IDENTIFIER NUMBER COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY
%token  IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC IC

%left PLUS
%left MULTIPLY
%left MINUS
%right EQUALTO

%type<node> PROGRAM DECLARATION_LIST DECLARATION VARIABLE_DECLARATION VARIABLE_TYPE 
%type<node> STATEMENT_LIST STATEMENT ASSIGNMENT_STATEMENT IDENTIFIER_NT FUNCTION_IDENTIFIER_NT 
%type<node> EXPRESSION PEXPRESSION INTEGER_NT FUNCTION_DECLARATION COMPOUND_STATEMENT 
%type<node> LOCAL_DECLARATION_LIST LOCAL_DECLARATION PRINT_STATEMENT PRINT_ITEM
%type<node> IF_STATEMENT WHILE_STATEMENT FOR_STATEMENT INCREMENT_STATEMENT DECREMENT_STATEMENT PARAM PARAMS PARAM_LIST_NT
%type<node> INT IC IDENTIFIER FUNCTION_IDENTIFIER NUMBER COMMA SEMICOLON OFB CFB ONB CNB PLUS MINUS MULTIPLY
%type<node> IF ELSE ELIF WHILE FOR PRINT SCAN OR AND NOT EQUALTO LT GT LE GE EE NEQ INC DEC 

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


								
VARIABLE_DECLARATION: VARIABLE_TYPE IDENTIFIER_NT SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("VARIABLE_DECLARATION", v);
															Num_variables++;
															stck[$2->lex_val]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
															};
					


FUNCTION_DECLARATION: VARIABLE_TYPE FUNCTION_IDENTIFIER_NT ONB PARAMS CNB COMPOUND_STATEMENT {
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
			}
			| LOCAL_DECLARATION {
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			}
			| PRINT_STATEMENT{
				vector<TreeNode*> v = {$1};
				$$ = new TreeNode("STATEMENT",v);
			};


PRINT_STATEMENT : PRINT ONB PRINT_ITEM CNB SEMICOLON {
												$1 = new TreeNode("PRINT");
												$2 = new TreeNode("ONB");
												$4 = new TreeNode("CNB");
												$5=new TreeNode("SEMICOLON");
												vector<TreeNode*> v = {$1,$2,$3,$4,$5};
												$$ = new TreeNode("PRINT_STATEMENT",v);
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



LOCAL_DECLARATION: VARIABLE_TYPE IDENTIFIER_NT SEMICOLON {
															$3=new TreeNode("SEMICOLON");
															vector<TreeNode*> v = {$1, $2, $3};
                                        					$$ = new TreeNode("LOCAL_DECLARATION", v);
															Num_variables++;
															stck[$2->lex_val]=Num_variables*-8; // Store the variables in a Map.Key is the name of variable.Value is the address in stack.
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


PRINT_ITEM : IDENTIFIER_NT {
				vector<TreeNode*> v = {$1};
                $$ = new TreeNode("PRINT_ITEM", v);
				$$->lex_val=$1->lex_val;
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
		printint.push_back("_printRAX:");printint.push_back("mov rcx, digitSpace");printint.push_back("mov rbx, 10");
		printint.push_back("mov [rcx], rbx");printint.push_back("inc rcx");printint.push_back("mov [digitSpacePos], rcx");
		printint.push_back("_printRAXLoop:");printint.push_back("mov rdx, 0");printint.push_back("mov rbx, 10");
		printint.push_back("div rbx");printint.push_back("push rax");printint.push_back("add rdx, 48");
		printint.push_back("mov rcx, [digitSpacePos]");printint.push_back("mov [rcx], dl");printint.push_back("inc rcx");
		printint.push_back("mov [digitSpacePos], rcx");printint.push_back("pop rax");printint.push_back("cmp rax, 0");
		printint.push_back("jne _printRAXLoop");printint.push_back("_printRAXLoop2:");printint.push_back("mov rcx, [digitSpacePos]");
		printint.push_back("mov rax, 1");printint.push_back("mov rdi, 1");printint.push_back("mov rsi, rcx");
		printint.push_back("mov rdx, 1");printint.push_back("syscall");printint.push_back("mov rcx, [digitSpacePos]");
		printint.push_back("dec rcx");printint.push_back("mov [digitSpacePos], rcx");printint.push_back("cmp rcx, digitSpace");
		printint.push_back("jge _printRAXLoop2");printint.push_back("ret");
		bss.push_back("section .bss");bss.push_back("digitSpace resb 100");bss.push_back("digitSpacePos resb 8");
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
		text.push_back("sub rsp , 8");
	}
	else if(root->NodeName=="PRINT_STATEMENT"){
		text.push_back("mov rbx , rbp");
		text.push_back("add rbx , "+to_string(stck[root->children[2]->lex_val]));
		text.push_back("mov rax , [rbx]");
		text.push_back("call _printRAX");
	}
	else if(root->NodeName=="ASSIGNMENT_STATEMENT"){
		if(root->children[0]->children.size()==2){
			if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION"){
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="INTEGER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(stck[root->children[0]->children[0]->lex_val]));
					text.push_back("mov rax , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
				}
				if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(stck[root->children[0]->children[0]->lex_val]));
					text.push_back("mov rdx , rbp");
					text.push_back("add rdx , "+to_string(stck[root->children[0]->children[1]->children[0]->children[0]->lex_val]));
					text.push_back("mov [rcx] , [rdx]");
				}
			}
			else { // PLUS/MINUS/MULTIPLY NONE NAMES
				CodeGenerator(root->children[0]->children[1]);
                text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(stck[root->children[0]->children[0]->lex_val]));
				text.push_back("mov [rcx] , rax");
            }
		}
	}
	else if(root->NodeName=="EXPRESSION"){ // EXPRESSION CODE GEN  // storing everythin in rax
		if(root->children[0]->NodeName=="PLUS" || root->children[0]->NodeName=="MINUS" || root->children[0]->NodeName=="MULTIPLY"){
			if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(stck[root->children[0]->children[0]->children[0]->lex_val]));
				text.push_back("mov rax , [rcx]");
			}
			else if(root->children[0]->children[0]->children[0]->NodeName=="INTEGER_NT"){
				text.push_back("mov rcx , "+root->children[0]->children[0]->children[0]->lex_val);
				text.push_back("mov rax , rcx");
			}
			if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(stck[root->children[0]->children[1]->children[0]->lex_val]));
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
		}
		else{
			return;
		}
	}
}
void putx86inafile(){
	ofstream MyFile("NASM_FILES/gen.asm");
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
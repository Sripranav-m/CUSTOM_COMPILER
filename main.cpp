#include "main.h"

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

string function_scope="";

int x,y;
int check_reg=0;

void CodeGenerator(TreeNode* root){
	if(root->NodeName=="PROGRAM"){
		registers.push_back("rax");
		registers.push_back("rbx");
		registers.push_back("rcx");
		registers.push_back("rdx");
		registers.push_back("r8");
		registers.push_back("r9");
		registers.push_back("r10");
		registers.push_back("r11");
		registers.push_back("r12");
		registers.push_back("r13");
		registers.push_back("r14");
		registers.push_back("r15");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		regs_replacement.push_back("");
		text.push_back("section	.text");
		text.push_back("global main ");
		data.push_back("extern printf , scanf");
		set_data_segment();
		set_scanner_integer();
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
		string fun_name=root->children[1]->lex_val;
		fun_name=fun_name.substr(1,fun_name.length());
		if(fun_name=="main"){
			text.push_back("main:");
			text.push_back("push rbp");
			text.push_back("mov rbp , rsp");
			function_scope="_main";
			symbol_table=all_scopes_symbol_tables[function_scope_definer[function_scope]];
			CodeGenerator(root->children[5]);
			text.push_back("mov  rsp, rbp");
			text.push_back("pop  rbp");
			text.push_back("mov rax , 60");
			text.push_back("mov rdi , 0");
			text.push_back("syscall");
		}
		else{
			fun_name="_"+fun_name;
			text.push_back(""+fun_name+":");
			text.push_back("push rbp");
			text.push_back("mov rbp , rsp");
			function_scope=fun_name;
			CodeGenerator(root->children[5]);
			text.push_back("mov  rsp, rbp");
			text.push_back("pop  rbp");
			text.push_back("ret");
		}
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
		//cout<<root->children[0]->NodeName<<"***************\n";
		if(root->children[0]->NodeName=="VARIABLE_TYPE"){
			text.push_back("sub rsp , 8");
			if(root->children[0]->children[0]->NodeName=="INT"){
				// text.push_back("mov "+registers[2]+" , rbp");
				// text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				// text.push_back("mov "+registers[0]+" , 0");
				// text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}
			else if(root->children[0]->children[0]->NodeName=="FLOAT"){
				// text.push_back("mov "+registers[2]+" , rbp");
				// text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				// text.push_back("mov dword["+registers[2]+"] , __float32__(0.0)");
			}
		}
		else if(root->children[0]->NodeName=="LIST_TYPE"){
			int x=8*stoi(root->children[3]->lex_val);
			text.push_back("sub rsp , "+to_string(x));
		}
		else if(root->children[0]->NodeName=="MATRIX_TYPE"){
			int x=stoi(root->children[3]->lex_val)*stoi(root->children[5]->lex_val);
			x*=8;
			text.push_back("sub rsp , "+to_string(x));
		}
	}
	else if(root->NodeName=="PRINT_STATEMENT"){
		check_reg=-1;
		if(symbol_table.find({root->children[2]->lex_val,"INT"})!=symbol_table.end()){
            text.push_back("");
			string ident=to_string(symbol_table[{root->children[2]->lex_val,"INT"}]);
			text.push_back("mov "+registers[1]+" , rbp");
			text.push_back("add "+registers[1]+" , "+ident);
			text.push_back("mov "+registers[1]+" , ["+registers[1]+"]");
			text.push_back("mov rsi , "+registers[1]+"");
			text.push_back("mov rdi , intf");
			text.push_back("mov "+registers[0]+" , 0");
			text.push_back("call printf");
            text.push_back("");
		}
		else if(symbol_table.find({root->children[2]->lex_val,"FLOAT"})!=symbol_table.end()){
            text.push_back("");
			text.push_back("mov "+registers[1]+" , rbp");
			text.push_back("add "+registers[1]+" , "+to_string(symbol_table[{root->children[2]->lex_val,"FLOAT"}]));
			text.push_back("add rsp , -8");
			text.push_back("fld dword["+registers[1]+"]");
			text.push_back("fstp qword[temp]");
			text.push_back("mov rdi , fmtf");
			text.push_back("movq xmm0 , qword[temp]");
			text.push_back("mov "+registers[0]+" , 1");
			text.push_back("call printf");
			text.push_back("add rsp , 8");
            text.push_back("");
			
		}
		else if(symbol_table.find({root->children[2]->lex_val,"LIST"})!=symbol_table.end()){
            text.push_back("");
			int list_location=symbol_table[{root->children[2]->lex_val,"LIST"}];
			int number_of_times=list_size[{root->children[2]->lex_val}];
			list_location+=8*number_of_times;
			int s=0;
			////cout<<list_location<<endl<<number_of_times<<endl;
			while(number_of_times>0){
				list_location-=8;
				number_of_times-=1;
				text.push_back("mov "+registers[1]+" , rbp");
				text.push_back("add "+registers[1]+" , "+to_string(list_location));
				text.push_back("mov "+registers[0]+" , ["+registers[1]+"]");
				text.push_back("mov rsi , "+registers[0]+"");
				if(s==0){
					text.push_back("mov rdi , lisfs");
					s++;
				}
				else if(number_of_times==0){
					text.push_back("mov rdi , lisfe");
				}
				else{
					text.push_back("mov rdi , lisf");
				}
				text.push_back("mov "+registers[0]+" , 0");
				text.push_back("call printf");
			}
            text.push_back("");
		}
		else if(symbol_table.find({root->children[2]->lex_val,"MATRIX"})!=symbol_table.end()){
			text.push_back("");
			int mat_location=symbol_table[{root->children[2]->lex_val,"MATRIX"}];
			int x=matrix[root->children[2]->lex_val].first;
			int y=matrix[root->children[2]->lex_val].second;
			mat_location+=8*(x*y);
			//cout<< x<<" "<<y<<" "<<mat_location<<endl;
			int t=y;
			int f=0;
			while(x>0){
				while(t>0){
					mat_location-=8;
					t--;
					text.push_back("mov "+registers[1]+" , rbp");
					//cout<<mat_location<<"<";
					text.push_back("add "+registers[1]+" , "+to_string(mat_location));
					text.push_back("mov "+registers[0]+" , ["+registers[1]+"]");
					text.push_back("mov rsi , "+registers[0]+"");
					if(t==y-1 && f==0){
						f=1;
						text.push_back("mov rdi , lisfs");
					}
					else if(t==0 && x==1){
						text.push_back("mov rdi , lisfe");
					}
					else if(t==0){
						text.push_back("mov rdi , intf");
					}
					else{
						text.push_back("mov rdi , lisf");
					}
					text.push_back("mov "+registers[0]+" , 0");
					text.push_back("call printf");
				}
				t=y;
				x--;
			}
			text.push_back("");
		}
	}
	else if(root->NodeName=="SCAN_STATEMENT"){
		check_reg=-1;
		num_scans++;
		if(variable_types[root->children[2]->children[0]->lex_val]=="INT"){
			text.push_back("mov "+registers[2]+" , rbp");
			text.push_back("add rsp , -8");
			text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"INT"}]));
			text.push_back("lea rsi , ["+registers[2]+"]");
			text.push_back("mov rdi , intin");
			text.push_back("xor "+registers[0]+" , "+registers[0]+"");
			text.push_back("call scanf");
			text.push_back("add rsp , 8");
		}
		else if(variable_types[root->children[2]->children[0]->lex_val]=="FLOAT"){
			text.push_back("mov "+registers[2]+" , rbp");
			text.push_back("add rsp , -8");
			text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"FLOAT"}]));
			text.push_back("mov rsi , temp");
			text.push_back("mov rdi , floatin");
			text.push_back("xor "+registers[0]+" , "+registers[0]+"");
			text.push_back("call scanf");
			text.push_back("fld dword[temp]");
			text.push_back("fstp dword["+registers[2]+"]");
			text.push_back("add rsp , 8");
		}
		// text.push_back("mov "+registers[0]+" , 0");
		// text.push_back("mov rdi , 0");
		// text.push_back("mov rsi , scanned");
		// text.push_back("mov "+registers[3]+" , 16");
		// text.push_back("syscall");
		// string_to_number_subroutine();
		// text.push_back("mov "+registers[2]+" , rbp");
		// text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"INT"}]));
		// text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
	// 	data.push_back("intin: db \"%ld\",0");
	// data.push_back("integer:times 4 db 0");
	}
	else if(root->NodeName=="RETURN_STATEMENT"){
		if(root->children[1]->NodeName=="IDENTIFIER_NT"){
			if(variable_types[root->children[1]->lex_val]=="INT"){
				text.push_back("mov "+registers[1]+" , rbp");
				text.push_back("add "+registers[1]+" , "+to_string(symbol_table[{root->children[1]->lex_val,"INT"}]));
				text.push_back("mov rax , ["+registers[1]+"]");
			}
			else{
				string err="Incorect return type...";
				yyerror(err);
			}
		}
		else if(root->children[1]->NodeName=="INTEGER_NT"){
			text.push_back("mov rax , "+root->children[1]->lex_val);
		}
		else{
			string err="Error at function return statement";
			yyerror(err);
		}

	}
	else if(root->NodeName=="ASSIGNMENT_STATEMENT"){
				
		if(root->children[0]->children[1]->children[0]->NodeName=="SIZE_EXPRESSION"){
			if(variable_types[root->children[0]->children[0]->lex_val]=="INT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}
			else{
				//
			}
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION"){
			////cout<<root->children[0]->children[1]->children[0]->children[0]->NodeName<<endl;
			if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="INTEGER_NT"){
				//cout<<"INTEGER_NT\n";
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov "+registers[0]+" , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
				text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}	
			else if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="FLOAT_NT"){
				//cout<<"FLOAT_NT\n";
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				text.push_back("mov qword["+registers[2]+"] , __float32__("+root->children[0]->children[1]->children[0]->children[0]->lex_val+")");
			}
			else if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
				//cout<<"IDENTIFIER_NT\n";
				string node_type=variable_types[root->children[0]->children[1]->children[0]->children[0]->lex_val];
				if(node_type=="INT"){
					text.push_back("mov "+registers[2]+" , rbp");
					text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
					string ident =to_string(symbol_table[{root->children[0]->children[1]->children[0]->children[0]->lex_val,"INT"}]);
					int loaded_into=load_into_register(ident);
					text.push_back("mov ["+registers[2]+"] , "+registers[loaded_into]+" ");
				}
				else if(node_type=="LIST"){
					TreeNode* right_list=root->children[0]->children[1]->children[0]->children[0];
					TreeNode* left_list=root->children[0]->children[0];
					int right_list_size=list_size[right_list->lex_val];
					int left_list_size=list_size[left_list->lex_val];
					if(right_list_size==left_list_size){
						text.push_back("mov "+registers[2]+" , rbp");
						text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{right_list->lex_val,"LIST"}]));
						text.push_back("mov "+registers[0]+" , rbp");
						text.push_back("add "+registers[0]+" , "+to_string(symbol_table[{left_list->lex_val,"LIST"}]));
						////cout<<to_string(symbol_table[{right_list->lex_val,"LIST"}])<<endl;
						int numer_of_elements=left_list_size;
						while(numer_of_elements>0){
							text.push_back("mov "+registers[3]+" , ["+registers[2]+"]");
							text.push_back("mov ["+registers[0]+"] , "+registers[3]+"");
							text.push_back("add "+registers[0]+" , 8");
							text.push_back("add "+registers[2]+" , 8");
							numer_of_elements--;
						}
					}
					else{
						//
					}
				}
				else{
					//
				}
			}
			else if(variable_types[root->children[0]->children[0]->lex_val]=="LIST"){
				//cout<<"LIST\n";
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"LIST"}]));
				//cout<<symbol_table[{root->children[0]->children[0]->lex_val,"LIST"}]<<endl;

				TreeNode* elements=root->children[0]->children[1]->children[0]->children[1];
				while(elements->children.size()>2){
					string val_from_end=elements->children[1]->lex_val;
					//cout<<val_from_end<<endl;	
					text.push_back("mov "+registers[0]+" , "+elements->children[1]->lex_val);
					text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
					text.push_back("add "+registers[2]+" , 8");
					elements=elements->children[0];
				}
				string val_from_end=elements->children[0]->lex_val;
				//cout<<val_from_end<<endl;
				text.push_back("mov "+registers[0]+" , "+elements->children[0]->lex_val);
				text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}
			else if(variable_types[root->children[0]->children[0]->lex_val]=="MATRIX"){
				//cout<<"MATRIX\n";
				int x=matrix[root->children[0]->children[0]->lex_val].first;
				int y=matrix[root->children[0]->children[0]->lex_val].second;
				//cout<<x<<" "<<y<<endl;
				TreeNode* level1=root->children[0]->children[1]->children[0]->children[1];
				TreeNode* level2;
				int startloc=symbol_table[{root->children[0]->children[0]->lex_val,"MATRIX"}];
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(startloc));
				//cout<<to_string(symbol_table[{root->children[0]->children[0]->lex_val,"MATRIX"}])<<endl;

				while(level1->children.size()>2){
					level2=level1->children[1];
					while(level2->children.size()>2){
						//cout<<level2->children[2]->lex_val<<" ";
						text.push_back("mov "+registers[0]+" , "+level2->children[2]->lex_val);
						text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
						text.push_back("add "+registers[2]+" , 8");
						//cout<<"x\n";
						level2=level2->children[0];
					}
					//cout<<level2->children[0]->lex_val<<" ";
					text.push_back("mov "+registers[0]+" , "+level2->children[0]->lex_val);
					text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
					text.push_back("add "+registers[2]+" , 8");
					//cout<<"x\n";
					level1=level1->children[0];
				}
				level2=level1->children[0];
				while(level2->children.size()>2){
					//cout<<level2->children[2]->lex_val<<" ";
					text.push_back("mov "+registers[0]+" , "+level2->children[2]->lex_val);
					text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
					text.push_back("add "+registers[2]+" , 8");
					//cout<<"x\n";
					level2=level2->children[0];
				}
				//cout<<level2->children[0]->lex_val<<"\n";
				text.push_back("mov "+registers[0]+" , "+level2->children[0]->lex_val);
				text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
				text.push_back("add "+registers[2]+" , 8");
				//cout<<"x\n";
				level1=level1->children[0];

			}
			// FUNCTION CALLING
			else if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="FUNCTION_IDENTIFIER_NT"){
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				TreeNode* pexp=root->children[0]->children[1]->children[0];
				if(function_args.find(pexp->children[0]->lex_val)!=function_args.end()){
					int ch=0;
					TreeNode* params=pexp->children[2];
					if(params->children[0]->NodeName=="EPSILON"){
						ch=0;
					}
					else{
						TreeNode* paramsnt=params->children[0];

						while(paramsnt->children.size()>1){
							ch++;
							text.push_back("add rsp , -8");
							string ident_name=paramsnt->children[2]->children[0]->lex_val;
							string ident =to_string(symbol_table[{paramsnt->children[2]->children[0]->lex_val,"INT"}]);
							cout<<ident<<" ";
							int loaded_into=load_into_register(ident);
							text.push_back("mov [rsp],"+registers[loaded_into]);
							paramsnt=paramsnt->children[0];

						}
						text.push_back("add rsp , -8");
						string ident_name=paramsnt->children[0]->children[0]->lex_val;
						string ident =to_string(symbol_table[{paramsnt->children[0]->children[0]->lex_val,"INT"}]);
						cout<<ident<<" ";
						int loaded_into=load_into_register(ident);
						text.push_back("mov [rsp],"+registers[loaded_into]);

						ch++;

					}
					if(ch==function_args[pexp->children[0]->lex_val]){
						text.push_back("mov "+registers[0]+" , "+to_string(ch));
						map<pair<string,string>, int> symbol_table_T=symbol_table;
						symbol_table=all_scopes_symbol_tables[function_scope_definer[pexp->children[0]->lex_val]];
						check_reg=-1;
						text.push_back("call "+pexp->children[0]->lex_val);
						symbol_table=symbol_table_T;
						text.push_back("add rsp ,"+to_string(8*ch));
					}

					else{
						string err="Incorrect number of arguments passed to the function...";
						yyerror(err);
					}
				}
				else{
					string err="Function Doesn't Exist...";
					yyerror(err);
				}
				// text.push_back("mov "+registers[0]+" , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
				// text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}
			else{
				string err="Error Occured...";
				yyerror(err);
			}
		}
		
		else { 	// PLUS/MINUS/MULTIPLY/BAND/BOR/BXOR NAMES
			string node_type=variable_types[root->children[0]->children[1]->children[0]->children[0]->children[0]->lex_val];
			string node_type2=root->children[0]->children[1]->children[0]->children[0]->children[0]->NodeName;
			////cout<<node_type<<"  "<<node_type2<<endl;
			if(node_type=="LIST"){
				CodeGenerator(root->children[0]->children[1]);
				int top_of_stack=Num_variables;
				top_of_stack++;
				top_of_stack*=-8;
				TreeNode* left_list=root->children[0]->children[0];
				int left_list_size=list_size[left_list->lex_val];
				int left_list_loc=symbol_table[{left_list->lex_val,"LIST"}];
				int number_of_times=left_list_size;
				text.push_back("mov "+registers[3]+" , rbp");
				text.push_back("add "+registers[3]+" , "+to_string(left_list_loc));
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(top_of_stack));
				while(number_of_times>0){
					text.push_back("mov "+registers[0]+" , ["+registers[2]+"]");
					text.push_back("mov ["+registers[3]+"] , "+registers[0]+"");
					text.push_back("add "+registers[3]+" , 8");
					text.push_back("add "+registers[2]+" , -8");
					number_of_times--;
				}
			}
			else if(node_type=="MATRIX"){
				CodeGenerator(root->children[0]->children[1]);
				int top_of_stack=Num_variables;
				top_of_stack++;
				top_of_stack*=-8;
				TreeNode* left_matrix=root->children[0]->children[0];
				int left_matrix_size_x=matrix[left_matrix->lex_val].first;
				int left_matrix_size_y=matrix[left_matrix->lex_val].second;
				int left_matrix_loc=symbol_table[{left_matrix->lex_val,"MATRIX"}];
				int number_of_times=left_matrix_size_x*left_matrix_size_y;
				text.push_back("mov "+registers[3]+" , rbp");
				text.push_back("add "+registers[3]+" , "+to_string(left_matrix_loc));
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(top_of_stack));
				while(number_of_times>0){
					text.push_back("mov "+registers[0]+" , ["+registers[2]+"]");
					text.push_back("mov ["+registers[3]+"] , "+registers[0]+"");
					text.push_back("add "+registers[3]+" , 8");
					text.push_back("add "+registers[2]+" , -8");
					number_of_times--;
				}
			}
			else if(node_type2=="INTEGER_NT" || node_type=="INT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov "+registers[2]+" , rbp");
				text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
			}
			else if(node_type2=="FLOAT_NT" || node_type=="FLOAT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov "+registers[0]+" , rbp");
				text.push_back("add "+registers[0]+" , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				text.push_back("fstp dword["+registers[0]+"]");
                text.push_back("add rsp , 16");
			}
		}
	}
	else if(root->NodeName=="INCDEC_STATEMENT"){
		if(root->children[1]->NodeName=="INC"){
			text.push_back("mov "+registers[2]+" , rbp");
			text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->lex_val,"INT"}]));
			text.push_back("mov "+registers[0]+" , ["+registers[2]+"]");
			text.push_back("add "+registers[0]+" , 1");
			text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
		}
		else if(root->children[1]->NodeName=="DEC"){
			text.push_back("mov "+registers[2]+" , rbp");
			text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->lex_val,"INT"}]));
			text.push_back("mov "+registers[0]+" , ["+registers[2]+"]");
			text.push_back("add "+registers[0]+" , -1");
			text.push_back("mov ["+registers[2]+"] , "+registers[0]+"");
		}
	}
	else if(root->NodeName=="IF_STATEMENT"){
		count_loops++;
		string LabelIf="LabelIf"+to_string(count_loops);
		string EndIf="EndIf"+to_string(count_loops);
		string NextSkip="NextSkip"+to_string(count_loops);
		text.push_back(LabelIf+":");
		TreeNode* left_expr=root->children[2]->children[0]->children[0];
		string x,y,xx;
		string a,b;
		a=left_expr->children[0]->NodeName;
		if(a=="NEQ"){
			x="je";
			xx="jne";
		}
		if(a=="GE"){
			x="jl";
			xx="jge";
		}
		if(a=="LE"){
			x="jg";
			xx="jle";
		}
		if(a=="GT"){
			x="jle";
			xx="jg";
		}
		if(a=="LT"){
			x="jge";
			xx="jl";
		}
		if(a=="EE"){
			x="jne";
			xx="je";
		}
		if(root->children[2]->children[0]->NodeName=="NOT"){
			CodeGenerator(root->children[2]);
			text.push_back(xx+" "+EndIf);
			CodeGenerator(root->children[4]);
			/* text.push_back("jmp "+LabelIf); */
			text.push_back(EndIf+":");
			return;
		}
		TreeNode* right_expr=root->children[2]->children[0]->children[1];
		b=right_expr->children[0]->NodeName;
		if(b=="NEQ"){
			y="je";
		}
		if(b=="GE"){
			y="jl";
		}
		if(b=="LE"){
			y="jg";
		}
		if(b=="GT"){
			y="jle";
		}
		if(b=="LT"){
			y="jge";
		}
		if(b=="EE"){
			y="jne";
		}
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;
			
			if(typ=="AND"){
				CodeGenerator(left_expr);
				text.push_back(x+" "+EndIf);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndIf);
			}
			else if(typ=="OR"){
				CodeGenerator(left_expr);
				text.push_back(xx+" "+NextSkip);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndIf);
				text.push_back(NextSkip+":");
			}
			else{
				//
			}
			CodeGenerator(root->children[4]);
			/* text.push_back("jmp "+LabelIf); */
			text.push_back(EndIf+":");
			return;
		}
		else{
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
		string NextSkip="NextSkip"+to_string(count_loops);
		text.push_back(LabelFor+":");
		TreeNode* left_expr=root->children[2]->children[0]->children[0];
		string x,y,xx;
		string a,b;
		a=left_expr->children[0]->NodeName;
		if(a=="NEQ"){
			x="je";
			xx="jne";
		}
		if(a=="GE"){
			x="jl";
			xx="jge";
		}
		if(a=="LE"){
			x="jg";
			xx="jle";
		}
		if(a=="GT"){
			x="jle";
			xx="jg";
		}
		if(a=="LT"){
			x="jge";
			xx="jl";
		}
		if(a=="EE"){
			x="jne";
			xx="je";
		}
		if(root->children[2]->children[0]->NodeName=="NOT"){
			CodeGenerator(root->children[2]);
			text.push_back(xx+" "+EndFor);
			CodeGenerator(root->children[7]);
			CodeGenerator(root->children[5]);
			text.push_back("jmp "+LabelFor);
			text.push_back(EndFor+":");
			return ;
		}

		TreeNode* right_expr=root->children[2]->children[0]->children[1];
		b=right_expr->children[0]->NodeName;
		if(b=="NEQ"){
			y="je";
		}
		if(b=="GE"){
			y="jl";
		}
		if(b=="LE"){
			y="jg";
		}
		if(b=="GT"){
			y="jle";
		}
		if(b=="LT"){
			y="jge";
		}
		if(b=="EE"){
			y="jne";
		}
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;

			if(typ=="AND"){
				CodeGenerator(left_expr);
				text.push_back(x+" "+EndFor);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndFor);
			}
			else if(typ=="OR"){
				CodeGenerator(left_expr);
				text.push_back(xx+" "+NextSkip);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndFor);
				text.push_back(NextSkip+":");
			}
			else{
				//
			}
			CodeGenerator(root->children[7]);
			CodeGenerator(root->children[5]);
			text.push_back("jmp "+LabelFor);
			text.push_back(EndFor+":");
			return ;
		}
		else{
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
		string NextSkip="NextSkip"+to_string(count_loops);
		text.push_back(LabelWhile+":");
		TreeNode* left_expr=root->children[2]->children[0]->children[0];
		string x,y,xx;
		string a,b;
		a=left_expr->children[0]->NodeName;
		if(a=="NEQ"){
			x="je";
			xx="jne";
		}
		if(a=="GE"){
			x="jl";
			xx="jge";
		}
		if(a=="LE"){
			x="jg";
			xx="jle";
		}
		if(a=="GT"){
			x="jle";
			xx="jg";
		}
		if(a=="LT"){
			x="jge";
			xx="jl";
		}
		if(a=="EE"){
			x="jne";
			xx="je";
		}
		// NOT
		if(root->children[2]->children[0]->NodeName=="NOT"){
			CodeGenerator(root->children[2]);
			text.push_back(xx+" "+EndWhile);
			CodeGenerator(root->children[4]);
			text.push_back("jmp "+LabelWhile);
			text.push_back(EndWhile+":");
			return;
		}

		TreeNode* right_expr=root->children[2]->children[0]->children[1];
		b=right_expr->children[0]->NodeName;
		if(b=="NEQ"){
			y="je";
		}
		if(b=="GE"){
			y="jl";
		}
		if(b=="LE"){
			y="jg";
		}
		if(b=="GT"){
			y="jle";
		}
		if(b=="LT"){
			y="jge";
		}
		if(b=="EE"){
			y="jne";
		}
		// AND OR
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;
			if(typ=="AND"){
				CodeGenerator(left_expr);
				text.push_back(x+" "+EndWhile);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndWhile);
			}
			else if(typ=="OR"){
				CodeGenerator(left_expr);
				text.push_back(xx+" "+NextSkip);
				CodeGenerator(right_expr);
				text.push_back(y+" "+EndWhile);
				text.push_back(NextSkip+":");
			}
			else{
				//
			}
			CodeGenerator(root->children[4]);
			text.push_back("jmp "+LabelWhile);
			text.push_back(EndWhile+":");
			return;
		}
		else{
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
		}
		CodeGenerator(root->children[4]);
		text.push_back("jmp "+LabelWhile);
		text.push_back(EndWhile+":");
	}
	// Only Addition and Subtraction on Lists
	else if(root->NodeName=="EXPRESSION"){ // EXPRESSION CODE GEN  // storing everythin in "+registers[0]+"
		////cout<<root->children[0]->children[0]->NodeName;
		if(root->children[0]->children[0]->NodeName=="EXPRESSION"){
			// string typ=root->children[0]->NodeName;
			// if(typ=="AND"){
			// 	CodeGenerator(root->children[0]->children[0]);
			// 	text.push_back("");
			// }
			// else if(typ=="OR"){
				
			// }
		}
		else if(root->children[0]->children[0]->NodeName=="ATSIZE"){
			string ident=root->children[0]->children[1]->lex_val;
			if(symbol_table.find({ident,"LIST"})!=symbol_table.end()){
				int siz=list_size[ident];
				text.push_back("mov "+registers[0]+" , "+to_string(siz));
			}
			else if(symbol_table.find({ident,"MATRIX"})!=symbol_table.end()){
				int siz=matrix[ident].first;
				text.push_back("mov "+registers[0]+" , "+to_string(siz));
			}
			else{
				// 
			}
			return;
		}
		else if(root->children[0]->children[0]->NodeName=="AATSIZE"){
			string ident=root->children[0]->children[1]->lex_val;
			if(symbol_table.find({ident,"MATRIX"})!=symbol_table.end()){
				int siz=matrix[ident].second;
				text.push_back("mov "+registers[0]+" , "+to_string(siz));
			}
			else{
				//
			}
			return;
		}
		string node_type=variable_types[root->children[0]->children[0]->children[0]->lex_val];
		string node_ident=root->children[0]->children[0]->children[0]->NodeName;
		if(node_type=="LIST"){
			string typ=root->children[0]->NodeName;
			TreeNode* right_list=root->children[0]->children[1]->children[0];
			TreeNode* left_list=root->children[0]->children[0]->children[0];
			if(right_list->NodeName=="IDENTIFIER_NT" && left_list->NodeName=="IDENTIFIER_NT"){
				string left_type=variable_types[left_list->lex_val];
				string right_type=variable_types[right_list->lex_val];
				if(left_type=="LIST" && right_type=="LIST"){
					if(typ=="PLUS"){		
						int top_of_stack=Num_variables;
						top_of_stack++;
						top_of_stack*=-8;
						int left_list_loc=symbol_table[{left_list->lex_val,"LIST"}];
						int right_list_loc=symbol_table[{right_list->lex_val,"LIST"}];
						int left_list_size=list_size[left_list->lex_val];
						int right_list_size=list_size[right_list->lex_val];
						if(left_list_size==right_list_size){
							int number_of_times=left_list_size;
							int top_expanding=top_of_stack;
							while(number_of_times>0){
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(left_list_loc));
								text.push_back("mov "+registers[2]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(right_list_loc));
								text.push_back("mov "+registers[1]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[0]+" , rbp");
								text.push_back("add "+registers[0]+" , "+to_string(top_expanding));
								text.push_back("add "+registers[2]+" , "+registers[1]+"");
								text.push_back("mov ["+registers[0]+"] , "+registers[2]+"");
								left_list_loc+=8;
								right_list_loc+=8;
								top_expanding-=8;
								number_of_times--;
							}
						}
						else{
							// error
						}
					}
					if(typ=="MINUS"){		
						int top_of_stack=Num_variables;
						top_of_stack++;
						top_of_stack*=-8;
						int left_list_loc=symbol_table[{left_list->lex_val,"LIST"}];
						int right_list_loc=symbol_table[{right_list->lex_val,"LIST"}];
						int left_list_size=list_size[left_list->lex_val];
						int right_list_size=list_size[right_list->lex_val];
						if(left_list_size==right_list_size){
							int number_of_times=left_list_size;
							int top_expanding=top_of_stack;
							while(number_of_times>0){
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(left_list_loc));
								text.push_back("mov "+registers[2]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(right_list_loc));
								text.push_back("mov "+registers[1]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[0]+" , rbp");
								text.push_back("add "+registers[0]+" , "+to_string(top_expanding));
								text.push_back("sub "+registers[2]+" , "+registers[1]+"");
								text.push_back("mov ["+registers[0]+"] , "+registers[2]+"");
								left_list_loc+=8;
								right_list_loc+=8;
								top_expanding-=8;
								number_of_times--;
							}
						}
						else{
							// error
						}
					}
				}
				
			}
			else{
				//
			}
		}
		else if(node_type=="MATRIX"){
			string typ=root->children[0]->NodeName;
			TreeNode* right_matrix=root->children[0]->children[1]->children[0];
			TreeNode* left_matrix=root->children[0]->children[0]->children[0];
			if(right_matrix->NodeName=="IDENTIFIER_NT" && left_matrix->NodeName=="IDENTIFIER_NT"){
				string left_type=variable_types[left_matrix->lex_val];
				string right_type=variable_types[right_matrix->lex_val];
				if(left_type=="MATRIX" && right_type=="MATRIX"){
					if(typ=="PLUS"){		
						int top_of_stack=Num_variables;
						top_of_stack++;
						top_of_stack*=-8;
						int left_matrix_loc=symbol_table[{left_matrix->lex_val,"MATRIX"}];
						int right_matrix_loc=symbol_table[{right_matrix->lex_val,"MATRIX"}];
						int left_matrix_size_x=matrix[left_matrix->lex_val].first;
						int left_matrix_size_y=matrix[left_matrix->lex_val].second;
						int right_matrix_size_x=matrix[right_matrix->lex_val].first;
						int right_matrix_size_y=matrix[right_matrix->lex_val].second;
						if(left_matrix_size_x==right_matrix_size_x && left_matrix_size_y==right_matrix_size_y ){
							x=left_matrix_size_x;
							y=left_matrix_size_y;
							int number_of_times=left_matrix_size_x*left_matrix_size_y;
							int top_expanding=top_of_stack;
							while(number_of_times>0){
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(left_matrix_loc));
								text.push_back("mov "+registers[2]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(right_matrix_loc));
								text.push_back("mov "+registers[1]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[0]+" , rbp");
								text.push_back("add "+registers[0]+" , "+to_string(top_expanding));
								text.push_back("add "+registers[2]+" , "+registers[1]+"");
								text.push_back("mov ["+registers[0]+"] , "+registers[2]+"");
								left_matrix_loc+=8;
								right_matrix_loc+=8;
								top_expanding-=8;
								number_of_times--;
							}
						}
					}
					else if(typ=="MINUS"){		
						int top_of_stack=Num_variables;
						top_of_stack++;
						top_of_stack*=-8;
						int left_matrix_loc=symbol_table[{left_matrix->lex_val,"MATRIX"}];
						int right_matrix_loc=symbol_table[{right_matrix->lex_val,"MATRIX"}];
						int left_matrix_size_x=matrix[left_matrix->lex_val].first;
						int left_matrix_size_y=matrix[left_matrix->lex_val].second;
						int right_matrix_size_x=matrix[right_matrix->lex_val].first;
						int right_matrix_size_y=matrix[right_matrix->lex_val].second;
						if(left_matrix_size_x==right_matrix_size_x && left_matrix_size_y==right_matrix_size_y ){
							x=left_matrix_size_x;
							y=left_matrix_size_y;
							int number_of_times=left_matrix_size_x*left_matrix_size_y;
							int top_expanding=top_of_stack;
							while(number_of_times>0){
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(left_matrix_loc));
								text.push_back("mov "+registers[2]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[3]+" , rbp");
								text.push_back("add "+registers[3]+" , "+to_string(right_matrix_loc));
								text.push_back("mov "+registers[1]+" , ["+registers[3]+"]");
								text.push_back("mov "+registers[0]+" , rbp");
								text.push_back("add "+registers[0]+" , "+to_string(top_expanding));
								text.push_back("sub "+registers[2]+" , "+registers[1]+"");
								text.push_back("mov ["+registers[0]+"] , "+registers[2]+"");
								left_matrix_loc+=8;
								right_matrix_loc+=8;
								top_expanding-=8;
								number_of_times--;
							}
						}
					}
				}
			}
		}
		else if(node_type=="INT" || node_ident=="INTEGER_NT"){  // NUMBER OR INT IDENTIFIER
			if(root->children[0]->children[0]->NodeName=="PEXPRESSION"){
				if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
					

					string ident =to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"INT"}]);
					int loaded_into=load_into_register(ident);
					text.push_back("mov "+registers[0]+" ,"+registers[loaded_into]);
				}
				else if(root->children[0]->children[0]->children[0]->NodeName=="INTEGER_NT"){
					////cout<<root->children[0]->children[0]->children[0]->lex_val<<endl;
					text.push_back("mov "+registers[2]+" , "+root->children[0]->children[0]->children[0]->lex_val);
					text.push_back("mov "+registers[0]+" , "+registers[2]+"");
				}
				if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
					

					string ident =to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"INT"}]);
					int loaded_into=load_into_register(ident);
					text.push_back("mov "+registers[1]+" ,"+registers[loaded_into]);
				}
				else if(root->children[0]->children[1]->children[0]->NodeName=="INTEGER_NT"){
					////cout<<root->children[0]->children[1]->children[0]->lex_val<<endl;
					text.push_back("mov "+registers[2]+" , "+root->children[0]->children[1]->children[0]->lex_val);
					text.push_back("mov "+registers[1]+" , "+registers[2]+"");
				}
				string typ=root->children[0]->NodeName;
				if(typ=="PLUS"){
					text.push_back("add "+registers[0]+" , "+registers[1]+"");
				}
				else if(typ=="MINUS"){
					text.push_back("sub "+registers[0]+" , "+registers[1]+"");
				}
				else if(typ=="MULTIPLY"){
					text.push_back("mul "+registers[1]+"");
				}
				else if(typ=="BAND"){
					text.push_back("and "+registers[0]+" , "+registers[1]+"");
				}
				else if(typ=="BOR"){
					text.push_back("or "+registers[0]+" , "+registers[1]+"");
				}
				else if(typ=="BXOR"){
					text.push_back("xor "+registers[0]+" , "+registers[1]+"");
				}
				else if(typ=="GE" || typ=="LE" || typ=="GT" || typ=="LT" || typ=="EE" || typ=="NEQ"){
					text.push_back("cmp "+registers[0]+" , "+registers[1]+"");
				}
			}
		}
		else if(node_type=="FLOAT" || node_ident=="FLOAT_NT"){ // FLOAT OR FLOAT IDENTIFIER 
            if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
				////cout<<root->children[0]->children[0]->children[0]->lex_val<<endl;
                text.push_back("mov "+registers[1]+" , rbp");
                text.push_back("add "+registers[1]+" , "+to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"FLOAT"}]));
                text.push_back("add rsp , -8");
                text.push_back("fld dword["+registers[1]+"]");
			    text.push_back("fstp dword[temp]");
                text.push_back("add rsp ,8");
			}
			else if(root->children[0]->children[0]->children[0]->NodeName=="FLOAT_NT"){
                text.push_back("mov dword[temp] , __float32__("+root->children[0]->children[0]->children[0]->lex_val+")");
            }
			if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
				////cout<<root->children[0]->children[1]->children[0]->lex_val<<endl;
                text.push_back("mov "+registers[2]+" , rbp");
                text.push_back("add "+registers[2]+" , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"FLOAT"}]));
                text.push_back("add rsp , -8");
                text.push_back("fld dword["+registers[2]+"]");
			    text.push_back("fstp dword[temq]");
                text.push_back("add rsp ,8");
			}
			else if(root->children[0]->children[1]->children[0]->NodeName=="FLOAT_NT"){
                text.push_back("mov dword[temq] , __float32__("+root->children[0]->children[1]->children[0]->lex_val+")");
                
            }
			string typ=root->children[0]->NodeName;
			if(typ=="PLUS"){
                text.push_back("finit");
                text.push_back("add rsp , -8");
                text.push_back("add rsp , -8");
                text.push_back("fld dword[temp]");
                text.push_back("fld dword[temq]");
                text.push_back("fadd");
			}
			else if(typ=="MINUS"){
                text.push_back("finit");
                text.push_back("add rsp , -8");
                text.push_back("add rsp , -8");
                text.push_back("fld dword[temp]");
                text.push_back("fld dword[temq]");
                text.push_back("fsub");
			}
			else if(typ=="MULTIPLY"){
                text.push_back("finit");
                text.push_back("add rsp , -8");
                text.push_back("add rsp , -8");
                text.push_back("fld dword[temp]");
                text.push_back("fld dword[temq]");
                text.push_back("fmul");
			}
            else if(typ=="DIVIDE"){
                text.push_back("finit");
                text.push_back("add rsp , -8");
                text.push_back("add rsp , -8");
                text.push_back("fld dword[temp]");
                text.push_back("fld dword[temq]");
                text.push_back("fdiv");
            }
			// else if(typ=="GE" || typ=="LE" || typ=="GT" || typ=="LT" || typ=="EE" || typ=="NEQ"){
            //     text.push_back("finit");
            //     text.push_back("add rsp , -8");
            //     text.push_back("add rsp , -8");
            //     text.push_back("fld dword[temp]");
            //     text.push_back("fld dword[temq]");
            //     text.push_back("fcom");
			// }
		}
		
	}
	if(check_reg==-1){
		for(int i=0;i<=11;i++){
			regs_replacement[i]="";
		}
		u0=0;u1=0;
		u2=0;u3=0;
		u4=0;u5=0;
		u6=0;u7=0;
		u8=0;u9=0;
		u10=0;u11=0;
		check_reg=0;
	}
}

void putx86inafile(){
	ofstream MyFile("gen.asm");
	for(int i=0;i<text.size();i++){
		MyFile<<text[i]<<endl;
	}
	MyFile<<endl<<endl;
	for(int i=0;i<data.size();i++){
		MyFile<<data[i]<<endl;
	}
	MyFile<<endl<<endl;
	for(int i=0;i<bss.size();i++){
		MyFile<<bss[i]<<endl;
	}
	MyFile<<endl;
	/* for(int i=0;i<printint.size();i++){
		MyFile<<printint[i]<<endl;
	} */
	/* for(int i=0;i<printList.size();i++){
		MyFile<<printList[i]<<endl;
	}
	for(int i=0;i<printNewLine.size();i++){
		MyFile<<printNewLine[i]<<endl;
	} */
	MyFile.close();
}


void yyerror(string temp){
	cout<<endl<<temp<<endl;
	cout<<"Parsing Terminated...Syntax Error:("<<endl;
	exit(0);
}
void set_go_to_new_line_subroutine(){
	printNewLine.push_back("_printNewLine:");
	printNewLine.push_back("mov "+registers[0]+" , 1");
	printNewLine.push_back("mov rdi , 1");
	printNewLine.push_back("mov rsi , newline");
	printNewLine.push_back("mov "+registers[3]+" , 1");
	printNewLine.push_back("syscall");
	printNewLine.push_back("ret");
}
void set_list_print_subroutine(){ // // prints the string in the "+registers[0]+" register , custom made subroutine by me but doesnt go to new line
	printList.push_back("_print_R_A_X_L:");
	printList.push_back("mov "+registers[2]+", digitSpace_L");
	printList.push_back("mov "+registers[1]+", 32");
	printList.push_back("mov ["+registers[2]+"], "+registers[1]+"");
	printList.push_back("inc "+registers[2]+"");
	printList.push_back("mov [digitSpace_LPos], "+registers[2]+"");
	printList.push_back("_print_R_A_X_LLoop:");
	printList.push_back("mov "+registers[3]+", 0");
	printList.push_back("mov "+registers[1]+", 10");
	printList.push_back("div "+registers[1]+"");
	printList.push_back("push "+registers[0]+"");
	printList.push_back("add "+registers[3]+", 48");
	printList.push_back("mov "+registers[2]+", [digitSpace_LPos]");
	printList.push_back("mov ["+registers[2]+"], dl");
	printList.push_back("inc "+registers[2]+"");
	printList.push_back("mov [digitSpace_LPos], "+registers[2]+"");
	printList.push_back("pop "+registers[0]+"");
	printList.push_back("cmp "+registers[0]+", 0");
	printList.push_back("jne _print_R_A_X_LLoop");
	printList.push_back("_print_R_A_X_LLoop2:");
	printList.push_back("mov "+registers[2]+", [digitSpace_LPos]");
	printList.push_back("mov "+registers[0]+", 1");
	printList.push_back("mov rdi, 1");
	printList.push_back("mov rsi, "+registers[2]+"");
	printList.push_back("mov "+registers[3]+", 1");
	printList.push_back("syscall");
	printList.push_back("mov "+registers[2]+", [digitSpace_LPos]");
	printList.push_back("dec "+registers[2]+"");
	printList.push_back("mov [digitSpace_LPos], "+registers[2]+"");
	printList.push_back("cmp "+registers[2]+", digitSpace_L");
	printList.push_back("jge _print_R_A_X_LLoop2");
	printList.push_back("ret");
	bss.push_back("section .bss");
	bss.push_back("digitSpace_L resb 100");
	bss.push_back("digitSpace_LPos resb 8");
}
void set_integer_print_subroutine(){ // prints the string in the "+registers[0]+" register , custom made subroutine by me
	printint.push_back("_print_R_A_X:");
	printint.push_back("mov "+registers[2]+", digitSpace");
	printint.push_back("mov "+registers[1]+", 10");
	printint.push_back("mov ["+registers[2]+"], "+registers[1]+"");
	printint.push_back("inc "+registers[2]+"");
	printint.push_back("mov [digitSpacePos], "+registers[2]+"");
	printint.push_back("_print_R_A_XLoop:");
	printint.push_back("mov "+registers[3]+", 0");
	printint.push_back("mov "+registers[1]+", 10");
	printint.push_back("div "+registers[1]+"");
	printint.push_back("push "+registers[0]+"");
	printint.push_back("add "+registers[3]+", 48");
	printint.push_back("mov "+registers[2]+", [digitSpacePos]");
	printint.push_back("mov ["+registers[2]+"], dl");
	printint.push_back("inc "+registers[2]+"");
	printint.push_back("mov [digitSpacePos], "+registers[2]+"");
	printint.push_back("pop "+registers[0]+"");
	printint.push_back("cmp "+registers[0]+", 0");
	printint.push_back("jne _print_R_A_XLoop");
	printint.push_back("_print_R_A_XLoop2:");
	printint.push_back("mov "+registers[2]+", [digitSpacePos]");
	printint.push_back("mov "+registers[0]+", 1");
	printint.push_back("mov rdi, 1");
	printint.push_back("mov rsi, "+registers[2]+"");
	printint.push_back("mov "+registers[3]+", 1");
	printint.push_back("syscall");
	printint.push_back("mov "+registers[2]+", [digitSpacePos]");
	printint.push_back("dec "+registers[2]+"");
	printint.push_back("mov [digitSpacePos], "+registers[2]+"");
	printint.push_back("cmp "+registers[2]+", digitSpace");
	printint.push_back("jge _print_R_A_XLoop2");
	printint.push_back("ret");
	bss.push_back("section .bss");
	bss.push_back("digitSpace resb 100");
	bss.push_back("digitSpacePos resb 8");
}

void set_scanner_integer(){
	bss.push_back("section .bss");
	bss.push_back("scanned resb 16");
	bss.push_back("temp : resq 1");
    bss.push_back("temq : resq 1");
}

void string_to_number_subroutine(){ // takes the string inside the scanned in bss and returns output inside "+registers[0]+" register , custom made subroutine by me
	
    text.push_back("xor "+registers[0]+", "+registers[0]+"");
	text.push_back("mov "+registers[3]+" , scanned");
	text.push_back("top"+to_string(num_scans)+":");
	text.push_back("movzx "+registers[2]+" , byte ["+registers[3]+"]");
	text.push_back("add "+registers[3]+" , 1");
	text.push_back("cmp "+registers[2]+" , '0' ");
	text.push_back("jl done"+to_string(num_scans));
	text.push_back("cmp "+registers[2]+" , '9' ");
	text.push_back("jg done"+to_string(num_scans));
	text.push_back("sub "+registers[2]+" , '0'");
	text.push_back("imul "+registers[0]+" , 10");
	text.push_back("add "+registers[0]+" , "+registers[2]+"");
	text.push_back("jmp top"+to_string(num_scans));
	text.push_back("done"+to_string(num_scans)+":");
}

void set_data_segment(){
	data.push_back("section .data");
	data.push_back("intf: db \"%ld\",10,0 ");
	data.push_back("lisfs: dq \"[%ld \",32,0 ");
	data.push_back("lisf: dq \"%ld \",32,0 ");
	data.push_back("lisfe: db \"%ld]\",10,0 ");
	data.push_back("fmtf: db \"%lf\",10,0 ");
	data.push_back("intin: db \"%ld\",0");
	data.push_back("floatin: db \"%lf\",0");
	data.push_back("integer:times 4 db 0");
}
#include "main.h"
int cc=0;
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
void CodeGenerator(TreeNode* root){
	if(root->NodeName=="PROGRAM"){
		text.push_back("section	.text");
		text.push_back("global main ");
		text.push_back("main:");
		text.push_back("push rbp");
		text.push_back("mov rbp , rsp");
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
			if(root->children[0]->children[0]->NodeName=="INT"){
				// text.push_back("mov rcx , rbp");
				// text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				// text.push_back("mov rax , 0");
				// text.push_back("mov [rcx] , rax");
			}
			else if(root->children[0]->children[0]->NodeName=="FLOAT"){
				// text.push_back("mov rcx , rbp");
				// text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				// text.push_back("mov dword[rcx] , __float32__(0.0)");
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
		if(symbol_table.find({root->children[2]->lex_val,"INT"})!=symbol_table.end()){
            text.push_back("");
			text.push_back("mov rbx , rbp");
			text.push_back("add rbx , "+to_string(symbol_table[{root->children[2]->lex_val,"INT"}]));
			text.push_back("mov rax , [rbx]");
			text.push_back("mov rsi , rax");
			text.push_back("mov rdi , intf");
			text.push_back("mov rax , 0");
			text.push_back("call printf");
            text.push_back("");
		}
		if(symbol_table.find({root->children[2]->lex_val,"FLOAT"})!=symbol_table.end()){
			cc=1;
            text.push_back("");
			text.push_back("mov rbx , rbp");
			text.push_back("add rbx , "+to_string(symbol_table[{root->children[2]->lex_val,"FLOAT"}]));
			text.push_back("add rsp , -8");
			text.push_back("fld dword[rbx]");
			text.push_back("fstp qword[temp]");
			text.push_back("mov rdi , fmtf");
			text.push_back("movq xmm0 , qword[temp]");
			text.push_back("mov rax , 1");
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
			//cout<<list_location<<endl<<number_of_times<<endl;
			while(number_of_times>0){
				list_location-=8;
				number_of_times-=1;
				text.push_back("mov rbx , rbp");
				text.push_back("add rbx , "+to_string(list_location));
				text.push_back("mov rax , [rbx]");
				text.push_back("mov rsi , rax");
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
				text.push_back("mov rax , 0");
				text.push_back("call printf");
			}
            text.push_back("");
		}
	}
	else if(root->NodeName=="SCAN_STATEMENT"){
		num_scans++;
		if(variable_types[root->children[2]->children[0]->lex_val]=="INT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rsp , -8");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"INT"}]));
			text.push_back("lea rsi , [rcx]");
			text.push_back("mov rdi , intin");
			text.push_back("xor rax , rax");
			text.push_back("call scanf");
			text.push_back("add rsp , 8");
		}
		else if(variable_types[root->children[2]->children[0]->lex_val]=="FLOAT"){
			text.push_back("mov rcx , rbp");
			text.push_back("add rsp , -8");
			text.push_back("add rcx , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"FLOAT"}]));
			text.push_back("mov rsi , temp");
			text.push_back("mov rdi , floatin");
			text.push_back("xor rax , rax");
			text.push_back("call scanf");
			text.push_back("fld dword[temp]");
			text.push_back("fstp dword[rcx]");
			text.push_back("add rsp , 8");
		}
		// text.push_back("mov rax , 0");
		// text.push_back("mov rdi , 0");
		// text.push_back("mov rsi , scanned");
		// text.push_back("mov rdx , 16");
		// text.push_back("syscall");
		// string_to_number_subroutine();
		// text.push_back("mov rcx , rbp");
		// text.push_back("add rcx , "+to_string(symbol_table[{root->children[2]->children[0]->lex_val,"INT"}]));
		// text.push_back("mov [rcx] , rax");
	// 	data.push_back("intin: db \"%ld\",0");
	// data.push_back("integer:times 4 db 0");
	}
	else if(root->NodeName=="ASSIGNMENT_STATEMENT"){		
		if(root->children[0]->children[1]->children[0]->NodeName=="SIZE_EXPRESSION"){
			if(variable_types[root->children[0]->children[0]->lex_val]=="INT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov [rcx] , rax");
			}
			else{
				//
			}
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION"){
			//cout<<root->children[0]->children[1]->children[0]->children[0]->NodeName<<endl;
			if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="INTEGER_NT"){
				if(root->children[0]->children[0]->children.size()==4){
					TreeNode* ident=root->children[0]->children[0]->children[0];
					int req_pos=stoi(root->children[0]->children[0]->children[2]->lex_val);
					int siz=list_size[ident->lex_val];
					cout<<symbol_table[{ident->lex_val,"LIST"}]<<endl;
					if(root->children[0]->children[0]->children[2]->NodeName=="INTEGER_NT"){
						if(req_pos>=0 && req_pos<siz){
							req_pos=siz-req_pos-1;
							text.push_back("mov rcx , rbp");
							text.push_back("add rcx , "+to_string(symbol_table[{ident->lex_val,"LIST"}]));
							text.push_back("add rcx , "+to_string((req_pos)*8));
							text.push_back("mov rax , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
							text.push_back("mov [rcx] , rax");
						}
						else{
							//
						}
					}
					else{
						//
					}
				}
				else{
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
					text.push_back("mov rax , "+root->children[0]->children[1]->children[0]->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
				}
			}	
			else if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="FLOAT_NT"){
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				text.push_back("mov qword[rcx] , __float32__("+root->children[0]->children[1]->children[0]->children[0]->lex_val+")");
			}
			else if(root->children[0]->children[1]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
				string node_type=variable_types[root->children[0]->children[1]->children[0]->children[0]->lex_val];
				if(node_type=="INT"){
					if(root->children[0]->children[0]->children.size()==4){
						TreeNode* ident=root->children[0]->children[0]->children[0];
						int req_pos=stoi(root->children[0]->children[0]->children[2]->lex_val);
						int siz=list_size[ident->lex_val];
						cout<<symbol_table[{ident->lex_val,"LIST"}]<<endl;
						if(root->children[0]->children[0]->children[2]->NodeName=="INTEGER_NT"){
							if(req_pos>=0 && req_pos<siz){
								req_pos=siz-req_pos-1;
								text.push_back("mov rcx , rbp");
								text.push_back("add rcx , "+to_string(symbol_table[{ident->lex_val,"LIST"}]));
								text.push_back("add rcx , "+to_string((req_pos)*8));
								text.push_back("mov rdx , rbp");
								text.push_back("add rdx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->children[0]->lex_val,"INT"}]));
								text.push_back("mov rax , [rdx]");
								text.push_back("mov [rcx] , rax");
							}
							else{
								//
							}
						}
						else{
							//
						}
					}
					else{
						
						text.push_back("mov rcx , rbp");
						text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
						text.push_back("mov rdx , rbp");
						text.push_back("add rdx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->children[0]->lex_val,"INT"}]));
						text.push_back("mov rax , [rdx]");
						text.push_back("mov [rcx] , rax");
					}	
				}
				else if(node_type=="LIST"){
					TreeNode* right_list=root->children[0]->children[1]->children[0]->children[0];
					TreeNode* left_list=root->children[0]->children[0];
					int right_list_size=list_size[right_list->lex_val];
					int left_list_size=list_size[left_list->lex_val];
					if(right_list_size==left_list_size){
						text.push_back("mov rcx , rbp");
						text.push_back("add rcx , "+to_string(symbol_table[{right_list->lex_val,"LIST"}]));
						text.push_back("mov rax , rbp");
						text.push_back("add rax , "+to_string(symbol_table[{left_list->lex_val,"LIST"}]));
						//cout<<to_string(symbol_table[{right_list->lex_val,"LIST"}])<<endl;
						int numer_of_elements=left_list_size;
						while(numer_of_elements>0){
							text.push_back("mov rdx , [rcx]");
							text.push_back("mov [rax] , rdx");
							text.push_back("add rax , 8");
							text.push_back("add rcx , 8");
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
			else if(variable_types[root->children[0]->children[0]->lex_val]=="MATRIX"){
				cout<<"MATRIX TYPE\n";
				int x=matrix[root->children[0]->children[0]->lex_val].first;
				int y=matrix[root->children[0]->children[0]->lex_val].second;
				cout<<x<<" "<<y<<endl;
				TreeNode* level1=root->children[0]->children[1]->children[0]->children[1];
				TreeNode* level2;
				while(level1->children.size()>2){
					level2=level1->children[1];
					while(level2->children.size()>2){
						//cout<<level2->children[2]->lex_val<<" ";
						text.push_back("mov rax , "+level2->children[2]->lex_val);
						text.push_back("mov [rcx] , rax");
						text.push_back("add rcx , 8");
						level2=level2->children[0];
					}
					//cout<<level2->children[0]->lex_val<<" ";
					text.push_back("mov rax , "+level2->children[0]->lex_val);
					text.push_back("mov [rcx] , rax");
					level1=level1->children[0];
				}
				level2=level1->children[0];
				while(level2->children.size()>2){
					//cout<<level2->children[2]->lex_val<<" ";
					text.push_back("mov rax , "+level2->children[2]->lex_val);
					text.push_back("mov [rcx] , rax");
					text.push_back("add rcx , 8");
					level2=level2->children[0];
				}
				//cout<<level2->children[0]->lex_val<<" ";
				text.push_back("mov rax , "+level2->children[0]->lex_val);
				text.push_back("mov [rcx] , rax");
				level1=level1->children[0];

			}
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION_F"){
			//
		}
		else if(root->children[0]->children[1]->children[0]->NodeName=="PEXPRESSION_S"){
			//
		}
		else { 	// PLUS/MINUS/MULTIPLY/BAND/BOR/BXOR NAMES
			string node_type=variable_types[root->children[0]->children[1]->children[0]->children[0]->children[0]->lex_val];
			string node_type2=root->children[0]->children[1]->children[0]->children[0]->children[0]->NodeName;
			//cout<<node_type<<"  "<<node_type2<<endl;
			if(node_type=="LIST"){
				CodeGenerator(root->children[0]->children[1]);
				int top_of_stack=Num_variables;
				top_of_stack++;
				top_of_stack*=-8;
				TreeNode* left_list=root->children[0]->children[0];
				int left_list_size=list_size[left_list->lex_val];
				int left_list_loc=symbol_table[{left_list->lex_val,"LIST"}];
				int number_of_times=left_list_size;
				text.push_back("mov rdx , rbp");
				text.push_back("add rdx , "+to_string(left_list_loc));
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(top_of_stack));
				while(number_of_times>0){
					text.push_back("mov rax , [rcx]");
					text.push_back("mov [rdx] , rax");
					text.push_back("add rdx , 8");
					text.push_back("add rcx , -8");
					number_of_times--;
				}
			}
			else if(node_type2=="INTEGER_NT" || node_type=="INT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov rcx , rbp");
				text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"INT"}]));
				text.push_back("mov [rcx] , rax");
			}
			else if(node_type2=="FLOAT_NT" || node_type=="FLOAT"){
				CodeGenerator(root->children[0]->children[1]);
				text.push_back("mov rax , rbp");
				text.push_back("add rax , "+to_string(symbol_table[{root->children[0]->children[0]->lex_val,"FLOAT"}]));
				text.push_back("fstp dword[rax]");
                text.push_back("add rsp , 16");
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
		string NextSkip="NextSkip"+to_string(count_loops);
		text.push_back(LabelIf+":");
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;
			TreeNode* left_expr=root->children[2]->children[0]->children[0];
			TreeNode* right_expr=root->children[2]->children[0]->children[1];
			string x,y,xx;
			string a,b;
			a=left_expr->children[0]->NodeName;
			b=right_expr->children[0]->NodeName;

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
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;
			TreeNode* left_expr=root->children[2]->children[0]->children[0];
			TreeNode* right_expr=root->children[2]->children[0]->children[1];
			string x,y,xx;
			string a,b;
			a=left_expr->children[0]->NodeName;
			b=right_expr->children[0]->NodeName;

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
		if(root->children[2]->children[0]->NodeName=="AND" ||root->children[2]->children[0]->NodeName=="OR"){
			string typ=root->children[2]->children[0]->NodeName;
			TreeNode* left_expr=root->children[2]->children[0]->children[0];
			TreeNode* right_expr=root->children[2]->children[0]->children[1];
			string x,y,xx;
			string a,b;
			a=left_expr->children[0]->NodeName;
			b=right_expr->children[0]->NodeName;

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
	else if(root->NodeName=="EXPRESSION"){ // EXPRESSION CODE GEN  // storing everythin in rax
		//cout<<root->children[0]->children[0]->NodeName;
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
				text.push_back("mov rax , "+to_string(siz));
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
								text.push_back("mov rdx , rbp");
								text.push_back("add rdx , "+to_string(left_list_loc));
								text.push_back("mov rcx , [rdx]");
								text.push_back("mov rdx , rbp");
								text.push_back("add rdx , "+to_string(right_list_loc));
								text.push_back("mov rbx , [rdx]");
								text.push_back("mov rax , rbp");
								text.push_back("add rax , "+to_string(top_expanding));
								text.push_back("add rcx , rbx");
								text.push_back("mov [rax] , rcx");
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
		else if(node_type=="INT" || node_ident=="INTEGER_NT"){  // NUMBER OR INT IDENTIFIER
			if(root->children[0]->children[0]->NodeName=="PEXPRESSION"){
				if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"INT"}]));
					text.push_back("mov rax , [rcx]");
				}
				else if(root->children[0]->children[0]->children[0]->NodeName=="INTEGER_NT"){
					//cout<<root->children[0]->children[0]->children[0]->lex_val<<endl;
					text.push_back("mov rcx , "+root->children[0]->children[0]->children[0]->lex_val);
					text.push_back("mov rax , rcx");
				}
				if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
					text.push_back("mov rcx , rbp");
					text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"INT"}]));
					text.push_back("mov rbx , [rcx]");
				}
				else if(root->children[0]->children[1]->children[0]->NodeName=="INTEGER_NT"){
					//cout<<root->children[0]->children[1]->children[0]->lex_val<<endl;
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
		else if(node_type=="FLOAT" || node_ident=="FLOAT_NT"){ // FLOAT OR FLOAT IDENTIFIER 
            if(root->children[0]->children[0]->children[0]->NodeName=="IDENTIFIER_NT"){
				//cout<<root->children[0]->children[0]->children[0]->lex_val<<endl;
                text.push_back("mov rbx , rbp");
                text.push_back("add rbx , "+to_string(symbol_table[{root->children[0]->children[0]->children[0]->lex_val,"FLOAT"}]));
                text.push_back("add rsp , -8");
                text.push_back("fld dword[rbx]");
			    text.push_back("fstp dword[temp]");
                text.push_back("add rsp ,8");
			}
			else if(root->children[0]->children[0]->children[0]->NodeName=="FLOAT_NT"){
                text.push_back("mov dword[temp] , __float32__("+root->children[0]->children[0]->children[0]->lex_val+")");
            }
			if(root->children[0]->children[1]->children[0]->NodeName=="IDENTIFIER_NT"){
				//cout<<root->children[0]->children[1]->children[0]->lex_val<<endl;
                text.push_back("mov rcx , rbp");
                text.push_back("add rcx , "+to_string(symbol_table[{root->children[0]->children[1]->children[0]->lex_val,"FLOAT"}]));
                text.push_back("add rsp , -8");
                text.push_back("fld dword[rcx]");
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


void yyerror(char* temp){
	cout<<"Parsing Terminated...Syntax Error:("<<endl;
	exit(0);
}
void set_go_to_new_line_subroutine(){
	printNewLine.push_back("_printNewLine:");
	printNewLine.push_back("mov rax , 1");
	printNewLine.push_back("mov rdi , 1");
	printNewLine.push_back("mov rsi , newline");
	printNewLine.push_back("mov rdx , 1");
	printNewLine.push_back("syscall");
	printNewLine.push_back("ret");
}
void set_list_print_subroutine(){ // // prints the string in the rax register , custom made subroutine by me but doesnt go to new line
	printList.push_back("_printRAX_L:");
	printList.push_back("mov rcx, digitSpace_L");
	printList.push_back("mov rbx, 32");
	printList.push_back("mov [rcx], rbx");
	printList.push_back("inc rcx");
	printList.push_back("mov [digitSpace_LPos], rcx");
	printList.push_back("_printRAX_LLoop:");
	printList.push_back("mov rdx, 0");
	printList.push_back("mov rbx, 10");
	printList.push_back("div rbx");
	printList.push_back("push rax");
	printList.push_back("add rdx, 48");
	printList.push_back("mov rcx, [digitSpace_LPos]");
	printList.push_back("mov [rcx], dl");
	printList.push_back("inc rcx");
	printList.push_back("mov [digitSpace_LPos], rcx");
	printList.push_back("pop rax");
	printList.push_back("cmp rax, 0");
	printList.push_back("jne _printRAX_LLoop");
	printList.push_back("_printRAX_LLoop2:");
	printList.push_back("mov rcx, [digitSpace_LPos]");
	printList.push_back("mov rax, 1");
	printList.push_back("mov rdi, 1");
	printList.push_back("mov rsi, rcx");
	printList.push_back("mov rdx, 1");
	printList.push_back("syscall");
	printList.push_back("mov rcx, [digitSpace_LPos]");
	printList.push_back("dec rcx");
	printList.push_back("mov [digitSpace_LPos], rcx");
	printList.push_back("cmp rcx, digitSpace_L");
	printList.push_back("jge _printRAX_LLoop2");
	printList.push_back("ret");
	bss.push_back("section .bss");
	bss.push_back("digitSpace_L resb 100");
	bss.push_back("digitSpace_LPos resb 8");
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

void set_scanner_integer(){
	bss.push_back("section .bss");
	bss.push_back("scanned resb 16");
	bss.push_back("temp : resq 1");
    bss.push_back("temq : resq 1");
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
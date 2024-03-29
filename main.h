#include<bits/stdc++.h>
using namespace std;

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

extern vector<map<pair<string,string>, int>> all_scopes_symbol_tables;
extern map<string,int> function_scope_definer;
extern map<string,vector<string>> function_arguments;
extern map<string,int> Num_variablesF;
extern vector<map<string,string>> all_scopes_variable_types;
extern TreeNode* Abstract_Syntax_Tree;  // Pointer to the Absract Syntax Tree
extern int Num_variables;
extern map<string,pair<int,int>> matrix;
extern map<pair<string,string>, int> symbol_table;
extern map<string,int> list_size;
extern map<string,string> variable_types; 
extern void dotraversal(TreeNode* head);
extern vector<string> text;
extern vector<string> data;
extern vector<string> bss; // 
extern vector<string> printint; // To include the print subroutine
extern vector<string> printList;
extern vector<string> printNewLine;
extern int count_loops;
extern int num_scans;
extern vector<int> u;
extern int store_into_register(string ident);


extern vector<string> registers;

extern int check_reg;
extern int time_lru;
extern int check;
extern vector<string> regs_replacement;
extern map<string,int> function_args; 



void CodeGenerator(TreeNode* root);
void yyerror(string temp);
void set_go_to_new_line_subroutine();
void set_list_print_subroutine();
void set_integer_print_subroutine();
void set_scanner_integer();
void string_to_number_subroutine();
void set_data_segment();
int load_into_register(string);
void makenulls();
int least_recently_used();


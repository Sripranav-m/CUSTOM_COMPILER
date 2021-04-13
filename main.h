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

extern vector<string> registers;
extern int u0;
extern int u1;
extern int u2;
extern int u3;

extern int u4;
extern int u5;
extern int u6;
extern int u7;
extern int u8;
extern int u9;
extern int u10;
extern int u11;
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


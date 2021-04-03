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


void CodeGenerator(TreeNode* root);
void yyerror(char* temp);
void set_go_to_new_line_subroutine();
void set_list_print_subroutine();
void set_integer_print_subroutine();
void set_scanner_integer();
void string_to_number_subroutine();
void set_data_segment();
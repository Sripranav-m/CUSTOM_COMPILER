#include "main.h"
vector<string> registers;

vector<int> u(12,0);
int time_lru=0;
vector<string> regs_replacement;

int least_recently_used(){
    return min(u[4],min(u[5],min(u[6],min(u[7],min(u[8],min(u[9],min(u[10],u[11])))))));
}

// int least_recently_used(){
//     return min(u2,min(u3,min(u4,min(u5,min(u6,u7)))));
// }

int load_into_register(string ident){ // load into register. If it is already there , then directly return , if full , replace with lru;
	time_lru++;
	for(int i=4;i<=11;i++){
		if(regs_replacement[i]==ident){
            //cout<<time_lru<<" "<<i<<" "<<regs_replacement[i]<<"$"<<endl;
			u[i]=time_lru;
			return i;
		}
	}
	if(u[4]==0 || u[5]==0 || u[6]==0 || u[7]==0 || u[8]==0 || u[9]==0 || u[10]==0 || u[11]==0){
		text.push_back("mov "+registers[3]+" , rbp");
		text.push_back("add "+registers[3]+" , "+ident);
		int i,j;
		for(int j=4;j<12;j++){
			if(u[j]==0){
				i=j;
				break;
			}
		}
		u[i]=time_lru;
		text.push_back("mov "+registers[i]+", ["+registers[3]+"]");
		regs_replacement[i]=ident;
		return i;
	}
	else{
		text.push_back("mov "+registers[2]+" , rbp");
		text.push_back("add "+registers[2]+" , "+ident);
		for(int i=4;i<12;i++){
			if(u[i]==least_recently_used()){
				u[i]=time_lru;
				text.push_back("mov "+registers[i]+", ["+registers[2]+"]");
				regs_replacement[i]=ident;
				return i;
			}
		}
	}
}

int store_into_register(string ident){
	time_lru++;
	for(int i=4;i<=11;i++){
		if(regs_replacement[i]==ident){
            text.push_back("mov "+registers[2]+" , rbp");
			text.push_back("add "+registers[2]+" , "+ident);
			text.push_back("mov "+registers[i]+", ["+registers[2]+"]");
			u[i]=time_lru;
			return i;
		}
	}
	if(u[4]==0 || u[5]==0 || u[6]==0 || u[7]==0 || u[8]==0 || u[9]==0 || u[10]==0 || u[11]==0){
		text.push_back("mov "+registers[3]+" , rbp");
		text.push_back("add "+registers[3]+" , "+ident);
		int i,j;
		for(int j=4;j<12;j++){
			if(u[j]==0){
				i=j;
				break;
			}
		}
		u[i]=time_lru;
		text.push_back("mov "+registers[i]+", ["+registers[3]+"]");
		regs_replacement[i]=ident;
		return i;
	}
	else{
		text.push_back("mov "+registers[2]+" , rbp");
		text.push_back("add "+registers[2]+" , "+ident);
		for(int i=4;i<12;i++){
			if(u[i]==least_recently_used()){
				u[i]=time_lru;
				text.push_back("mov "+registers[i]+", ["+registers[2]+"]");
				regs_replacement[i]=ident;
				return i;
			}
		}
	}
}


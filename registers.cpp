#include "main.h"
vector<string> registers;
int u0=0;
int u1=0;
int u2=0;     
int u3=0;

int u4=0;
int u5=0;
int u6=0;
int u7=0;
int u8=0;
int u9=0;
int u10=0;
int u11=0;
int time_lru=0;
vector<string> regs_replacement;

int least_recently_used(){
    return min(u4,min(u5,min(u6,min(u7,min(u8,min(u9,min(u10,u11)))))));
}

// int least_recently_used(){
//     return min(u2,min(u3,min(u4,min(u5,min(u6,u7)))));
// }

int load_into_register(string ident){ // load into register. If it is already there , then directly return , if full , replace with lru;
	time_lru++;
	for(int i=4;i<=11;i++){
		if(regs_replacement[i]==ident){
            //cout<<time_lru<<" "<<i<<" "<<regs_replacement[i]<<"$"<<endl;
			if(i==4){
                u4=time_lru;
                return i;
            }
			else if(i==5){
                u5=time_lru;
                return i;
            }
			else if(i==6){
                u6=time_lru;
                return i;
            }
			else if(i==7){
                u7=time_lru;
                return i;
            }
			else if(i==8){
                u8=time_lru;
                return i;
            }
			else if(i==9){
                u9=time_lru;
                return i;
            }
			else if(i==10){
                u10=time_lru;
                return i;
            }
			else if(i==11){
                u11=time_lru;
                return i;
            }
            else {
                break;
            }
		}
	}
	if(u4==0 || u5==0 || u6==0 || u7==0 || u8==0 || u9==0 || u10==0 || u11==0){
		if(u4==0){
			u4=time_lru;
			text.push_back("mov "+registers[4]+" , rbp");
			text.push_back("add "+registers[4]+" , "+ident);
			regs_replacement[4]=ident;
			return 4;
		}
		else if(u5==0){
			u5=time_lru;
			text.push_back("mov "+registers[5]+" , rbp");
			text.push_back("add "+registers[5]+" , "+ident);
			regs_replacement[5]=ident;
			return 5;
		}
		else if(u6==0){
			u6=time_lru;
			text.push_back("mov "+registers[6]+" , rbp");
			text.push_back("add "+registers[6]+" , "+ident);
			regs_replacement[6]=ident;
			return 6;
		}
		else if(u7==0){
			u7=time_lru;
			text.push_back("mov "+registers[7]+" , rbp");
			text.push_back("add "+registers[7]+" , "+ident);
			regs_replacement[7]=ident;
			return 7;
		}
		else if(u8==0){
			u8=time_lru;
			text.push_back("mov "+registers[8]+" , rbp");
			text.push_back("add "+registers[8]+" , "+ident);
			regs_replacement[8]=ident;
			return 8;
		}
		else if(u9==0){
			u9=time_lru;
			text.push_back("mov "+registers[9]+" , rbp");
			text.push_back("add "+registers[9]+" , "+ident);
			regs_replacement[9]=ident;
			return 9;
		}
		else if(u10==0){
			u10=time_lru;
			text.push_back("mov "+registers[10]+" , rbp");
			text.push_back("add "+registers[10]+" , "+ident);
			regs_replacement[10]=ident;
			return 10;
		}
		else if(u11==0){
			u11=time_lru;
			text.push_back("mov "+registers[11]+" , rbp");
			text.push_back("add "+registers[11]+" , "+ident);
			regs_replacement[11]=ident;
			return 11;
		}
	}
	else{	
        if(u4==least_recently_used()){
			u4=time_lru;
			text.push_back("mov "+registers[4]+" , rbp");
			text.push_back("add "+registers[4]+" , "+ident);
			regs_replacement[4]=ident;
			return 4;
		}
        else if(u5==least_recently_used()){
			u5=time_lru;
			text.push_back("mov "+registers[5]+" , rbp");
			text.push_back("add "+registers[5]+" , "+ident);
			regs_replacement[5]=ident;
			return 5;
		}	
        else if(u6==least_recently_used()){
			u6=time_lru;
			text.push_back("mov "+registers[6]+" , rbp");
			text.push_back("add "+registers[6]+" , "+ident);
			regs_replacement[6]=ident;
			return 6;
		}
        else if(u7==least_recently_used()){
			u7=time_lru;
			text.push_back("mov "+registers[7]+" , rbp");
			text.push_back("add "+registers[7]+" , "+ident);
			regs_replacement[7]=ident;
			return 7;
		}
        else if(u8==least_recently_used()){
			u8=time_lru;
			text.push_back("mov "+registers[8]+" , rbp");
			text.push_back("add "+registers[8]+" , "+ident);
			regs_replacement[8]=ident;
			return 8;
		}
        else if(u9==least_recently_used()){
			u9=time_lru;
			text.push_back("mov "+registers[9]+" , rbp");
			text.push_back("add "+registers[9]+" , "+ident);
			regs_replacement[9]=ident;
			return 9;
		}
        else if(u10==least_recently_used()){
			u10=time_lru;
			text.push_back("mov "+registers[10]+" , rbp");
			text.push_back("add "+registers[10]+" , "+ident);
			regs_replacement[10]=ident;
			return 10;
		}
        else{
			u11=time_lru;
			text.push_back("mov "+registers[11]+" , rbp");
			text.push_back("add "+registers[11]+" , "+ident);
			regs_replacement[11]=ident;
			return 11;
		}
	}
}


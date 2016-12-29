#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

void GenPerm(int digit, int sek, int dig_last,int dig_bef,string used,string res){
	string ss,temp_res=res,temp_used;
	
	if(sek >= digit){
		cout << res <<endl;
	}else{
		for(int a=1;a<=digit;a++){
			ss=to_string(a);
			
			if(used.find(ss) > used.length()){
				if(dig_bef > dig_last && dig_bef > a){
					GenPerm(digit,sek+1,dig_bef,a,used+ss,res+ss);
				}else if(dig_bef < dig_last && dig_bef < a){
					GenPerm(digit,sek+1,dig_bef,a,used+ss,res+ss);
				}
			}
		}
	}
}

int main(){
	int a;
	string kk,ll,res="",used="";
	cin >> a;
	
	if(a >= 3){
		for(int k=1;k<=a;k++){
			for(int l=1;l<=a;l++){
				if(k!= l){
					kk = to_string(k);
					ll = to_string(l);
					GenPerm(a,2,k,l,kk+ll,kk+ll);
				}
			}
		}
	}else if(a == 1){
		cout << 1 <<endl;
	}else if(a == 2){
		cout << 12 <<endl;
		cout << 21 <<endl;
	}
	
	return 0;
}

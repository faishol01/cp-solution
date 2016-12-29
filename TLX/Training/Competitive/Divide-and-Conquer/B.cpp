#include <iostream>
#include <cmath> 
#include <sstream> 
#include <iomanip> 
using namespace std; 
long long mod = pow(10,6),pg=4*pow(10,5); 
bool lbh=false;
 
int main(){
   	unsigned long long mm=1,base, exp;
   	string sss;
   	
   	cin >> base >> exp; 
   	if(exp>=pg)exp=exp%pg;
   	if(exp==0)exp=pg;
   	
   	for(int a=1;a<=exp;a++){
   		mm*=base;
   		if(mm>=mod){
   			mm=mm%mod;
   			lbh=true;
   		}
   	}
  	
   	ostringstream cnv;
   	cnv << mm;
   	sss=cnv.str();
   	
   	if(sss.length()<6 && lbh==true){
   		while(sss.length()<6){
   			sss="0"+sss;
   		}
   	}
   	
   	cout << sss<<endl;
   	return 0;
}

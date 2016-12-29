#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void Pin(int batas,int awal,int byk,int now,string hsl){
	string str;
	if(now == byk){
		cout << hsl << endl;
	}else {
		for(int a=awal+1;a<=batas;a++){
			str = hsl;
			str += " " + to_string(a);
			Pin(batas,a,byk,now+1,str);
		}
	}
}

int main(){
	int a,b;
	string hsl;
	
	cin >> a >> b;
	
	for(int k=1;k<=a;k++){
		hsl = to_string(k);
		Pin(a,k,b,1,hsl);
	}
	return 0;
}

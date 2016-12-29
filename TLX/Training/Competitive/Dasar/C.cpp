#include <iostream>
#include <string>
using namespace std;

void ubahSrc(string src, string& first, string& last){
	int a = src.find("*");
	first = src;
	last = src;
	
	if(a == src.length()-1){
		first.erase(a,1);
		last = "";
	}if (a==0){
		last.erase(0,1);
		first = "";
	}else{
		last.erase(0,a+1);
		first.erase(a,src.length()-a);
	}
	
}

void cek(string data[], int lengthArray, int a, string first, string last);

int main(){
	string src,first,last;
	int byk;
	
	cin >> src;
	ubahSrc(src,first,last);
	
	cin >> byk;
	string data[byk];
	
	for(int a=0;a<byk;a++){
		cin >> data[a];
	}
	
	cek(data,byk,0,first,last);
	
	return 0;
}

void cek(string data[], int lengthArray, int a, string first, string last){
	string hm = data[a];
	
	if(first == "" && last == ""){
		cout << data[a]<<endl;
	}else if (first != "" && last == ""){
		if(hm.find(first) == 0){
			cout << data[a] << endl;
		}
	}else if (first == "" && last != ""){
		if(hm.length() > last.length()){
			hm.erase(0,hm.length()-last.length());					
		}
			
		if (hm == last){
			cout << data[a] << endl;
		}
	}else{
		if(hm.find(first) == 0){
			hm.erase(0,first.length());
			if(hm.length() > last.length()){
				hm.erase(0,hm.length()-last.length());					
			}
			
			if (hm == last){
				cout << data[a] << endl;
			}
		}
	}
	
	if (a+1 < lengthArray){
		cek(data,lengthArray,a+1,first,last);			
	}
	
}

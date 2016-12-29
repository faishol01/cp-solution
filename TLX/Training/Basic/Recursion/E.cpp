#include <iostream>
using namespace std;

void biner(int a, string& b){

	if(a>1){
		if(a%2 == 1){
			 biner(a/2,b);
			 b += "1";
		}else{
			biner(a/2,b); 
			b += "0";			
		}
	}else{
		b+= "1";
	}
	
}

int main(){
	int angka;
	string hasil;
	cin >> angka;
	biner(angka,hasil);
	cout << hasil << endl;
	return 0;
}

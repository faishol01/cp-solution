#include <iostream>
using namespace std;

void cek(string& input, string& hasil){
	int a=input.length();
	
	if(a < 2){
		hasil = "YA";
	}else if(a >= 2){
		if(input[a-1] == input[0]){
			input.erase(a-1,1);
			input.erase(0,1);
			cek(input,hasil);
		}else{
			hasil = "BUKAN";
		}
	}
}

int main(){
	string a, hasil;
	cin >> a;
	cek(a,hasil);
	
	cout << hasil << endl;
	return 0;
}

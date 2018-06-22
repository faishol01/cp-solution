#include <iostream>
using namespace std;

void gambar(int a){
	
	if(a > 0){
		gambar(a-1);
		for(int b=0;b<a;b++){
			cout << "*";
		}
		cout << "\n";
		gambar(a-1);
	}
}

int main(){
	int a;
	cin >> a;
	gambar(a);
	return 0;
}

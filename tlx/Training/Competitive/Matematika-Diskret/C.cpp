#include <iostream>
#include <cmath>
using namespace std;

void cek_prima(long long bil,bool& stt){
	long long akar = ceil(sqrt(bil));
	
	if(bil%akar == 0){
		stt = false;
	}else{
		for(int a=2;a<akar;a++){
			if(bil%a == 0){
				stt = false;
				break;
			}
		}
	}
	
}

int main(){
	int tc,ke,x=77777,indeks=2;
	long long prima[x],bil=4;
	bool stt = true;
	prima[0] = 2;
	prima[1] = 3;

	while(indeks < x){
		stt = true;
		cek_prima(bil,stt);
		
		if(stt == true){
			prima[indeks] = bil;
			indeks++;
			bil++;
		}else{
			bil++;
		}
	}
	
	cin >> tc;
	for(int a=0;a<tc;a++){
		cin >> ke;
		cout << prima[ke-1] <<endl;
	}
	
	

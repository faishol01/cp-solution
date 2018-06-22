#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int banyak_faktor(int angka){
	int banyak=2, akar;
	akar = ceil(sqrt(angka));
	
	if(angka > 2){
		for(int a=akar;a > 1;a--){
				if(angka%a == 0 && angka/a != a){
					banyak = banyak + 2;
				}else if (angka%a == 0 && angka/a == a){
					banyak = banyak + 1;
				}
		}
	}else if(angka == 2){
		banyak = 2;
	}
	
	return banyak;
}

int main(){
	int faktor[49],angka,x, c=0;
	
	for(int a=0;a<49;a++){
		faktor[a] = {0};
	}
	
	cin >> angka;
	
	x = ceil(sqrt(angka));
	
	int prima[x];
	
	//CEK ANGKA Prima antar 2 s.d akar(input)
	for (int a=2;a<=x;a++){
		if(banyak_faktor(a) == 2){
			prima[c] = {a};
			c++;
		}
	}
	x=0;
	int a=0;
	//CEK FAKTORISASI PRIMAnya
	while(a < c){
		if(banyak_faktor(angka) == 2){
			faktor[x] = {angka};
			angka=1;
			x++;
			a=c;
		}else{
			if (angka == 1){
				a=c;
			}else if (angka%prima[a] == 0){
				angka = angka/prima[a];
				faktor[x] = {prima[a]};
				x++;
			}else if (angka%prima[a] != 0){
				a++;
			}
		}
	}
	//OUTPUT FAKTORISASI
	a=0;
	while(a<x){
		int b=x-1;
		while(faktor[a] != faktor[b]){
			b--;
		}
		cout << faktor[a];
		
		if (b-a +1 > 1){
			cout << "^" << b-a+1;
		}
		
		if(faktor[a] != faktor[x-1]){
			cout << " x ";
		}
		a=b+1;
		
	}
	
	cout << endl;
	return 0;
}

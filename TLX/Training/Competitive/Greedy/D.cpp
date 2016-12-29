#include <iostream>
#include <cmath>
using namespace std;
unsigned long long data[2][100002],
	duit,
	res=0;
int byk;

unsigned long long minim(unsigned long long a,unsigned long long b){
	if(duit/a>=b) return b;
	else return duit/a;
}

void beli(){
	unsigned long long minA=pow(10,19), maxB=0;
	int indeks=-1;
	
	for(int a=0;a<byk;a++){
		if(data[0][a] < minA && data[0][a] <= duit&&data[0][a]>0){
			indeks = a;
			minA = data[0][a];
			maxB=data[1][a];
		}else if(data[0][a]==minA && maxB < data[1][a]){
			indeks = a;
			maxB=data[1][a];
		}
	}
	
	if(indeks >-1){
		maxB = minim(minA,maxB);
		res += maxB;
		
		duit -= minA*maxB;
		data[0][indeks]=0;data[1][indeks]=0;
		beli();
	}
}

int main(){
	cin >> byk>>duit;
	
	for(int a=0;a<byk;a++){
		cin >> data[0][a]>>data[1][a];
	}
	beli();
	cout << res <<"\n";
	return 0;
}

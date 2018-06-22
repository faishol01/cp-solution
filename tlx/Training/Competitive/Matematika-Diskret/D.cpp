#include <iostream>
using namespace std;

int fpb(int a, int b){
	if (b==0){
		return a;
	}else{
		return fpb(b,a % b);
	}
}

int kpk(int a, int b){
	int hasil;
	hasil = a*b;
	hasil /= fpb(a,b);
	return hasil;	
}

int hitung(int array[], int lengthArray, int hsl){
	
	for(int a=2;a<lengthArray;a++){
		hsl = kpk(hsl, array[a]);
	}
	
	return hsl;
}

int main(){
	int byk;
	cin >> byk;
	int data[byk];
	
	for(int a=0;a<byk;a++){
		cin >> data[a];	
	}
	
	cout << hitung(data,byk,kpk(data[0],data[1])) << endl;
	
	return 0;
}

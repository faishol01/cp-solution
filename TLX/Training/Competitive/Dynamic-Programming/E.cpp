#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull unli=18446744073709551610;
ull harga[105][105],langkah[105][105],kali[104],matriks[105];
int byk,tanya;

ull pmax(ull a,ull b){
	if(a>b) return a;
	else return b;
}

void satu(){
	byk++;
	for(int a=1;a<=105;a++){
		harga[a][a]=0;
	}
	
	for(int l=2;l<byk;l++){
		for(int a=1;a<byk-l+1;a++){
			ull temp;
			int b=a+l-1;
			harga[a][b]=unli;
			
			for(int k=a;k<b;k++){
				temp=harga[a][k]+harga[k+1][b]+matriks[a-1]*matriks[k]*matriks[b];
				if(temp<harga[a][b])harga[a][b]=temp;	
			}
			
		}
	}
}

ull dua(){
	//ini yang salah
	byk++;
	for(int a=1;a<=105;a++){
		harga[a][a]=0;
		langkah[a][a]=1;
	}
	
	for(int l=2;l<byk;l++){
		for(int a=1;a<byk-l+1;a++){
			ull temp,x;
			int b=a+l-1;
			harga[a][b]=unli;
			
			for(int k=b-1;k>=a;k--){
				temp=harga[a][k]+harga[k+1][b]+matriks[a-1]*matriks[k]*matriks[b];
				
				if(temp<harga[a][b]){
					langkah[a][b]=langkah[a][k]*langkah[k+1][b];
					
					harga[a][b]=temp;
				}else if(temp==harga[a][b]){
					langkah[a][b]+=langkah[a][k]*langkah[k+1][b];								
				}	
			}
			
		}
	}
	
}

void tiga(int n){
	int b;
	for(int a=1;a<n;a++){
		b=n-a;
		if(kali[b]==0)tiga(b);
		if(kali[a]==0)tiga(a);
		
		kali[n]+=kali[a]*kali[b]%26101991;
	}
}

int main(){
	
	kali[0]=1;
	kali[1]=1;
	
	cin >> byk;
	
	for(int a=0;a<byk+1;a++){
		cin >> matriks[a];
	}

	cin >> tanya;
	if(tanya==1){
		satu();
		cout << harga[1][byk-1]<<endl;
	}else if(tanya==2){
		dua();
		cout << langkah[1][byk-1]%26101991<<endl;
	}else{
	
		tiga(byk);
		cout << kali[byk]%26101991<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int emas[1001],n;

int tukar(int gr){
	int a,b,c,tot=0;
	a=gr/2;b=gr/3;c=gr/4;
	
	if(emas[a]==-1){
		tukar(a);
		tot += emas[a];
	}else tot += emas[a];
	
	if(emas[b]==-1){
		tukar(b);
		tot += emas[b];
	}else tot += emas[b];
	
	if(emas[c]==-1){
		tukar(c);
		tot += emas[c];
	}else tot += emas[c];
	
	if(tot>gr) emas[gr] = tot;
	else emas[gr]=gr;
}

int main(){
	for(int a=0;a<=11;a++){
		emas[a]=a;
	}
	
	for(int a=12;a<1001;a++) emas[a]=-1;
	
	cin >> n;
	tukar(n);
	cout << emas[n]<<endl;
	return 0;
}

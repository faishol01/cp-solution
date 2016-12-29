#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector <ull> jabat(52,0);
int n;

void hitung(int tamu){
	int kir,temp=tamu;
	tamu-=2;
	
	for(int a=0;a<=tamu;a+=2){
		kir= tamu-a;
		if(jabat[kir]==0) hitung(kir);
		if(jabat[a]==0)hitung(a);
		
		jabat[temp]+= jabat[a]*jabat[kir];
	}
}

int main(){
	jabat[0]=1;
	cin >> n;
	
	if(n%2==0){
		hitung(n);
		cout << jabat[n]<<endl;
	}else cout << "0\n";
	return 0;
}

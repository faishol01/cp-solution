#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int byk,res=0,msk,cari;
long long hewan[100001],ss;

int binser(long long src){
	int kan=byk-1,kir=0,teng,hsl=-1;
	while(kir<=kan){
		teng=(kan+kir)/2;
		
		if(hewan[teng]>src){
			if(hewan[teng-1]<src){
				hsl=teng-1;
				break;
			}else if(hewan[teng-1]==src){
				hsl=teng-2;
				break;
			}else{
				kan=teng-1;
			}
		}else if(hewan[teng]<src){
			if(hewan[teng+1]==src){
				hsl=teng;
				break;
			}else if(hewan[teng+1]>src){
				hsl=teng;
				break;
			}else{
				kir=teng+1;
			}
		}else if(hewan[teng]==src){
			hsl=teng-1;
			break;
		}
	}
	
	return hsl+1;
}

int main(){
	int g=0;
	cin>>byk;
	for(int a=0;a<byk;a++){
		cin >> msk;
		ss+=msk;
		hewan[a]=ss;
	}
	
	cin>>cari;
	long long tanya[cari];
	
	for(int a=0;a<cari;a++){
		cin >> tanya[a];
		cout << binser(tanya[a])+1<<"\n";
	}
	return 0;
}

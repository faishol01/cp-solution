#include <bits/stdc++.h>
using namespace std;
long long tim,
		jadi,
		trg;
unsigned long long low=0,
					up=-1,
					res,
					mx=pow(2,61),
					bebek[263000];

long long parsel(unsigned long long suplai){
	long long res=0;
	for(int a=0;a<tim;a++){
		res+=suplai/bebek[a];
	}
	return res;
}

int main(){
	cin >> tim >> trg;
	for(int a=0;a<tim;a++) cin >> bebek[a];
	
	unsigned long long kir=1,kan=mx,teng;
	while(kir<=kan){
		teng=(kir+kan)/2;
		jadi=parsel(teng);
		
		if(jadi>trg){
			kan=teng-1;
		}else if(jadi<trg) kir=teng+1;
		else if(jadi==trg){
			if(parsel(teng-1)<trg){
				low=teng;
				break;	
			}
			else{
				kan=teng-1;
			}
		}
	}
	
	kir=low; kan=mx;
	while(kir<=kan){
		teng=(kir+kan)/2;
		jadi=parsel(teng);
		if(jadi>trg) kan=teng-1;
		else if(jadi<trg) kir=teng+1;
		else if(jadi==trg){
			if(parsel(teng+1)>trg){
				up=teng;
				break;
			}else{
				kir=teng+1;
			}
		}	
	}
	
	cout << up-low+1<<endl;
	return 0;
}

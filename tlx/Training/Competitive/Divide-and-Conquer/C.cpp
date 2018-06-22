#include <bits/stdc++.h>
using namespace std;
unsigned long long a,b,c,n,pn=1,ppn=1,d=5;
unsigned long long prim[200000];

bool cekprim(unsigned long long a){
	for(int g=0;g<d;g++){
		if(a%prim[g]==0)return false;
	}
	return true;
}

unsigned long long phi(unsigned long long a){
	unsigned long long hs=a,g=0,bef=-1;
	while(g<d){
		if(a%prim[g]==0){
			if(bef!=g){
				hs = (hs/prim[g])*(prim[g]-1);
				bef=g;
			}
			a/=prim[g];
		}else g+=1;	
		
		if(a==1) break;
	}
	
	if(g==99999){
		if(cekprim(a)) hs = (hs/a)*(a-1);
	}
	
	return hs;
}

unsigned long long fastpow(unsigned long long base,unsigned long long exp,unsigned long long mod){
	if(base==0)return 0;
		unsigned long long hs=base*base%mod;
			
	if(exp==0){
		return 1;
	}else if(exp%2==0){

		return fastpow(hs,exp/2,mod)%mod;
	}else{
		return base*fastpow(hs,(exp-1)/2,mod)%mod;
	}
}

int main(){
	//Generate prime numbers from 1-3300
	prim[0]=2;prim[1]=3;prim[2]=5;prim[3]=7;prim[4]=11;
	long long s=12;

	while(s<3300){
		if(cekprim(s)){
			prim[d]=s;
			d++;
		}
		s++;
	}
	
	cin >> a >> b >> c >> n;
	
	//pangkat
	pn=phi(n);
	ppn=phi(pn);
	
	a%=n;
		b%=pn;
		if(b==0)b=pn;
		
		c%=ppn; 
		
		b=fastpow(b,c,pn);
		if(b==0) b = pn;
		
		a=fastpow(a,b,n);
	
	cout << a+1<< endl;
	return 0;
}

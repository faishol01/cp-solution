#include <iostream>
using namespace std;
unsigned long long buyed,plat[10],money,harga[10],minim,ming;
int byk,indg=0,ind2=1;

void diprin(){
	cout << buyed << endl;
	int pr=0,i=byk-1;
	for(int a=byk-1;a>=0;a--){
		i=0;
		while(i<plat[a]){
			cout << a;
			i++;
			pr++;
			if(pr==50) break;
		}
		if(pr==50)break;
	}
	cout << endl;
	
	string res=""; pr=0;
	for(int a=0;a<byk;a++){
		i=0;
		while(i<plat[a]){
			res = char(a+48)+res;
			i++;
			pr++;
			if(pr==50)break;
		}
		if(pr==50)break;
	}
	cout << res << endl;
}

void diombrak(unsigned long long ktg[], int i){
	bool ombrak=false;
	unsigned long long beli=buyed,sat,dif;
	
	for(int a=0;a<i;a++){
		dif=harga[i]-harga[a];
		if(dif==0)sat=ktg[a];
		else sat=money/dif;
		
		if(ktg[a]<=sat)sat=ktg[a];
		
		if(ktg[a]>0&&sat>0){
	 		ombrak =true;
	 		ktg[a]-=sat;
	 		beli -=sat;
	 	
	 		money += harga[a]*sat;
	 	
	 		sat = money/harga[i];
	 		beli+=sat;
	 		money-=sat*harga[i];
	 		ktg[i]+=sat;
	 	}
	}
	
	if(ombrak&&beli>=buyed){
		buyed=beli;
		for(int a=0;a<=i;a++)plat[a]=ktg[a];
	}
}

int main(){
	for(int a=0;a<10;a++){
		plat[a]=0;harga[a]=0;
	}
	cin>> byk;
	byk+=1;
	for(int a=0;a<byk;a++){
		cin>>harga[a];
		if(harga[a]<=minim&&a>1){
			minim=harga[a];
			ind2=a;
		}else if(a==1)minim=harga[a];
		
		if(a==0)ming=harga[a];
		else if(harga[a]<=ming){
			ming=harga[a];
			indg=a;
		}
	}
	cin>> money;
	
	if(harga[ind2]<=money&&ind2<byk){
		buyed +=1;
		money-=harga[ind2];
		plat[ind2]+=1;
		
		//shopping
		unsigned long long kg;
		kg=money/harga[indg];
		buyed += kg;
		money-=harga[indg]*kg;
		plat[indg]+=kg;
		
			for(int a=byk-1;a>0;a--){
				diombrak(plat,a);
			}
		
		diprin();
		
	}else if(harga[indg]<=money){
		cout <<"1\n0\n0\n";
	}else cout <<"0\n";
	
	return 0;
}

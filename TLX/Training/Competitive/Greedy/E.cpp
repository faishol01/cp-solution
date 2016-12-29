#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int byk_s,byk_b,msk,res=0;
	cin >> byk_b>>byk_s;
	int htg[100000],sep[byk_s];
	
	for(int a=0;a<byk_b;a++){
		cin >> msk;
		htg[msk] += 1;
	}
	
	for(int a=0;a<byk_s;a++){
		cin >> sep[a];
	}
	
	stable_sort(sep,sep+byk_s);
	msk = 0;
	byk_s-=1;
	while(byk_s>=0){
		msk = sep[byk_s];
		if(htg[msk]>0){
			htg[msk]-=1;
			res+=1;
		}else if(htg[msk-1]>0){
			htg[msk-1]-=1;
			res+=1;
		}
		byk_s--;
	}
	cout << res << endl;
	return 0;
}

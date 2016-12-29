#include <bits/stdc++.h>
using namespace std;
int koin[500],uang,tbl[50000],byk;

int main(){
	tbl[0]=0;
	for(int a=1;a<50000;a++)tbl[a]=-2;
	
	cin >> byk;
	
	for(int a=0;a<byk;a++)cin>>koin[a];
	stable_sort(koin,koin+byk);
	
	cin >> uang;
	
	for(int a=1;a<=uang;a++){
		int ind=0,tmp,ubh=0;
		bool stt=false;
		
		while(ind<byk){
			ubh=0;
			if(koin[ind]<=a){
				ubh+=1;
				tmp=a-koin[ind];
				
				if(tbl[tmp]!=-1){
					stt = true;
					ubh += 	tbl[tmp];
					
					if(tbl[a]==-2) tbl[a]=ubh;
					else if(tbl[a]>ubh)tbl[a]=ubh;
				}
			}else break;
			
			ind++;
		}
		
		if(!stt) tbl[a]=-1;
	}
	
	cout << tbl[uang]<<endl;
	return 0;
}

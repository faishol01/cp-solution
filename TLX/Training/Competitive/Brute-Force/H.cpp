#include <bits/stdc++.h>
using namespace std;
int msk,byk,tim,ang,sis,frek[20002];
string stt="";
bool fin = false;

void reset(){
	for(int a=0;a<20002;a++) frek[a]=0;
}

bool valid(string jd,int arr[]){
	int x= tim-1,bef=0;
		while(x--){
			int d=jd.find('X');
			jd[d]='O';
			
			if(arr[d]==arr[d+1]){
				return false;
			}
		}
	return true;
}

void bagibagi(string hm,int tmb, int ke,int arr[],int ind){
	string hs=hm;
	if(ke<=tim&&ind<=byk){
		if(arr[ind-1] != arr[ind]){
			hs[ind-1]='X';
			
			if(tim-ke==tmb) bagibagi(hs,tmb-1,ke+1,arr,ind+ang+1);
			else{
				bagibagi(hs,tmb,ke+1,arr,ind+ang);
			
				if(tmb>0) bagibagi(hs,tmb-1,ke+1,arr,ind+ang+1);
			}
		}
	}else if(hm[byk-1]=='X'){
		if(fin==false){
			fin=true;
			int x= tim-1;
			while(x--){
				int d= hm.find('X');
				hm[d]='O';
				cout << arr[d]+1;
				if(x>0)cout << " ";
				else cout << "\n";
			}
			
		}
	}
}

int main(){
	reset();
	cin >> byk;
	
	int data[byk];
	for(int a=0;a<byk;a++){
		cin >> data[a];
		frek[data[a]] += 1;
		stt+="O";
	}
	
	stable_sort(data,data+byk);
	
	cin >> tim;
	ang = byk/tim;
	sis=byk%tim;
	bagibagi(stt,sis,0,data,ang);
	bagibagi(stt,sis-1,0,data,ang+1);
	
	return 0;
}

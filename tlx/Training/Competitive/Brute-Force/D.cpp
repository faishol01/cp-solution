#include <bits/stdc++.h>
using namespace std;
int nilai[21001],data1[10],byk,plh,tmb,juri,score;
char data2[10];

void nilaiya(string stt, int poin, bool gim, char bef,int ke){
	bool gg=false;
	string st1;
	int lolo;
	
	if(ke>plh){
		nilai[poin] += 1;
	}else{
		for(int a=0;a<byk;a++){
			if(stt[a] == 'O'){
				gg=gim;
				st1=stt;
				st1[a]='X';
								
				lolo = data1[a];
				if(bef=='L') lolo/=2;
				else if(bef=='P') lolo*=2;
				
				if(gim==true)lolo+=tmb;
				lolo += poin;
				
				if(data2[a]=='Y')gg=true;
				
				nilaiya(st1,lolo,gg,data2[a],ke+1);	
			}else continue;
		}	
	}
}

int main(){
	for(int a=0;a<21001;a++) nilai[a] = 0;
	
	string subsoal,stt="",st1;
	bool gg=false;
	
	getline(cin, subsoal);
	cin >> byk>>plh>>tmb>>juri;
	
	for(int a=0;a<byk;a++){
		cin >> data1[a] >> data2[a];
		stt += "O";	
	}
	
	//generate semua kemungkinan 
	
	for(int a=0;a<byk;a++){
		gg=false;
		
		st1=stt;
		st1[a]='X';
		
		score = data1[a];
		
		if(data2[a]=='Y')gg=true;
		nilaiya(st1,score,gg,data2[a],2);
	}
	
	//Cari result
	int src,res=0;
	while(juri--){
		res=0;
		cin >> src;
		if(src > 21000) cout << 0 <<endl;
		else{
			for(int a=src+1;a<21001;a++){
				res+=nilai[a];
			}
			cout << res << endl;
		}
	}
	
	return 0;
}

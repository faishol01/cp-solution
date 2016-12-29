#include <bits/stdc++.h>
using namespace std;
int col, row, arr[128][128],byk,tcol,trow;
string kode[16400];

void pendekatan(){
	int max;
	if(col>row)max=col;
	else max=row;
	
	for(int a=1;a<8;a++){
		int x=pow(2,a);
		
		if(x>max && x/2<max){
			max=x;
			break;
		}else if(x==max) break;	
	}
	
	col = max;
	row = max; 
}

void decode(int scol, int srow, int fcol, int frow,string adr){
	if(adr.length()==0){
		for(int a=srow;a<frow;a++){
			for(int b=scol;b<fcol;b++) arr[a][b]=1;
		}	
	}else{
		string temp;
		int col1=(scol+fcol)/2,
			row1=(srow+frow)/2;
		
		temp=adr;
		temp.erase(0,1);
		
		if(adr[0]=='0'){
			decode(scol,srow,col1,row1,temp);
		}else if(adr[0]=='1'){
			decode(col1,srow,fcol,row1,temp);			
		}else if(adr[0]=='2'){
			decode(scol,row1,col1,frow,temp);
		}else{
			decode(col1,row1,fcol,frow,temp);			
		}
		
	}
}

int main(){
	for(int a=0;a<128;a++){
		for(int b=0;b<128;b++)arr[a][b]=0;
	}
	
	cin >> byk;
	for(int a=0;a<byk;a++){
		cin>>kode[a];
		kode[a].erase(0,1);
	}
	
	cin>> row >> col;
	tcol=col;
	trow=row;
	
	if(byk==0){
		for(int a=0;a<row;a++){
			for(int b=0;b<col;b++){
				cout << 0;
				if(b==col-1)cout << endl;
				else cout << " ";
			}
		}
	}else if(byk==1&&kode[0]=="1"){
		for(int a=0;a<row;a++){
			for(int b=0;b<col;b++){
				cout << 1;
				if(b==col-1)cout << endl;
				else cout << " ";
			}
		}
	}else{
		pendekatan();
		
		for(int a=0;a<byk;a++){
			decode(0,0,col,row,kode[a]);
		}
		
		for(int a=0;a<trow;a++){
			for(int b=0;b<tcol;b++){
				cout << arr[a][b];
				if(b==tcol-1) cout << endl;
				else cout << " ";
			}
		}
	}
	
	return 0;
}

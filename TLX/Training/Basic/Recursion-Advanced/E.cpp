#include <bits/stdc++.h>
using namespace std;
int col, row, arr[128][128],tot=0;
string hasil[16400];
//ifstream fin("quadtree.in");

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

void quadtree(int scol,int srow, int fcol, int frow, string adr){
	bool stt =true;
	int acu=arr[srow][scol];
	
	for(int a=srow;a<frow;a++){
		for(int b=scol;b<fcol;b++){
			if(arr[a][b]!=acu){
				stt=false;
				break;
			}
		}
		if(!stt) break;
	}
	
	if(!stt){
		string temp;
		int col1=(scol+fcol)/2,
			row1=(srow+frow)/2;
			
		temp = adr+"0";
		quadtree(scol,srow,col1,row1,temp);
		
		temp = adr+"1";
		quadtree(col1,srow,fcol,row1,temp);
		
		temp = adr+"2";
		quadtree(scol,row1,col1,frow,temp);
		
		temp = adr+"3";
		quadtree(col1,row1,fcol,frow,temp);
				
	}else if(stt && acu == 1){
		hasil[tot] = "1"+adr;
		tot +=  1;
	}
}

int main(){
	string res;
	for(int a=0;a<128;a++){
		for(int b=0;b<128;b++) arr[a][b]=0;
	}
	
	cin>>row >> col;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++) cin>>arr[a][b];
	}
	
	pendekatan();
	
	quadtree(0,0,col,row,res);
	cout << tot << endl;
	
	if(tot>0){
		for(int a=0;a<tot;a++){
			cout << hasil[a] << endl; 
		}
	}
	return 0;
}

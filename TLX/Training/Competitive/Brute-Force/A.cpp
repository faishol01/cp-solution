#include <bits/stdc++.h>
using namespace std;
int m1[75][75],m2[75][75],col,row,row1;

bool sama(){
	int res=0;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			if(m1[a][b]==m2[a][b]) res+=1;
		}
	}
	if(res==col*row) return true;
	else return false;
}

bool vertikal(){
	bool stt=true;
	int col1=col-1;
	
	for(int a=0;a<row;a++){
		col1=col-1;
		for(int b=0;b<col;b++){
			if(m1[a][b]!=m2[a][col1]){
				stt=false;
			}
			col1-=1;
		}
		if(stt==false) return false;
	}
	
	return true;
}

bool horisontal(){
	bool stt=true;
	int roww=row-1;
	
	for(int a=0;a<col;a++){
		roww=row-1;
		for(int b=0;b<row;b++){
			if(m1[b][a]!=m2[roww][a]){
				stt=false;
			}
			roww-=1;
		}
		if(!stt) return false;
	}
	
	return true;
}

bool kan(){
	int cc=0,rr=0;
	bool stt=true;
	
	for(int a=0;a<col;a++){
		for(int b=0;b<row;b++){
			if(m1[a][b]!=m2[rr][cc]) stt=false;
			rr+=1;
		}
		cc+=1;
		rr=0;
		if(!stt) return false;
	}
	
	return true;
}

bool kir(){
	int cc=col-1,rr=row-1;
	bool stt=true;
	
	for(int a=0;a<col;a++){
		for(int b=0;b<row;b++){
			if(m1[a][b]!=m2[rr][cc]) stt=false;
			rr-=1;
		}
		cc-=1;
		rr=row-1;
		if(!stt) return false;
	}	
	return true;
}

int main(){
	cin >> col >> row;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++) cin >> m1[a][b];
	}
	
	cin >> col >> row;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			cin >> m2[a][b];	
		}
	}
	
	if(sama()==true) cout << "identik\n";
	else if(vertikal()==true) cout << "vertikal\n";
	else if(horisontal()==true) cout << "horisontal\n";
	else if(kan()==true)cout << "diagonal kanan bawah\n";
	else if(kir()==true) cout << "diagonal kiri bawah\n";
	else cout << "tidak identik\n";
	
	return 0;
}

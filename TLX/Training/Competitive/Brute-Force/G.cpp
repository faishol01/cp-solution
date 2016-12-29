#include <bits/stdc++.h>
using namespace std;
int col,
	row,
	m1[25][25],
	m2[25][25],
	stt1[25][25];

void dicopy(int dari[25][25],int ke[25][25]){
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++) ke[a][b]=dari[a][b];
	}
}

void print(int arr[25][25]){
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++) cout << arr[a][b];
		cout << endl;
	}
}

void runtuh(int arr[25][25]){
	for(int a=0;a<col;a++){
		for(int b=row-2;b>=0;b--){
			int indeks = b;
			if(arr[indeks]>0 && indeks+1 < row){	
				while((arr[indeks+1][a]==0)&&(indeks+1<row)){
					swap(arr[indeks][a],arr[indeks+1][a]);
					indeks++;
				}
			}
		}
	}
}

int floodfill(int arr[25][25],int stat[25][25],int pcol,int prow, int bola, int& res){
	if(arr[prow][pcol]==bola){
		res += 1;
		arr[prow][pcol]=0;
		stat[prow][pcol]=1;
		
		if(prow>0) floodfill(arr,stat,pcol,prow-1,bola,res);
		if(prow+1<row)floodfill(arr,stat,pcol,prow+1,bola,res);
		if(pcol>0)floodfill(arr,stat,pcol-1,prow,bola,res);
		if(pcol+1<col)floodfill(arr,stat,pcol+1,prow,bola,res);
	}
}

int ke2(int arr[25][25]){
	int res=0,max=0,stat[25][25],temp[25][25];
	
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			temp[a][b]=arr[a][b];
			stat[a][b]=0;
		}
	}
	
	dicopy(arr,temp);
	
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			res=0;
			if(stat[a][b]==0&&arr[a][b]>0){
				
				floodfill(arr,stat,b,a,arr[a][b],res);
				dicopy(temp,arr);
			}
			
			if(res>max) max=res;			
		}
	}
	
	return max*(max-1);
}

int main(){
	int max=0,temp;
	cin >> row >> col;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			cin >> m1[a][b];
			m2[a][b]=m1[a][b];
			stt1[a][b]=0;
		}
	}
	int ind2,ind1;
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++){
			temp=0;
			if(stt1[a][b]==0){
				floodfill(m1,stt1,b,a,m1[a][b],temp);
				runtuh(m1);
				temp*=(temp-1);
				temp += ke2(m1);
				
				dicopy(m2,m1);
			}
			
			if(temp>max){
				ind1=a;
				ind2=b;
				
				max=temp;
			}			
		}
	}
	
	cout << max<<endl;
	return 0;
}

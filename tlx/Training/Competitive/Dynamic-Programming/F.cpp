#include <bits/stdc++.h>
using namespace std;
double arena[502][502];
int col,row,byk;
/*
8 7 6				Expected Output : ?
2 3 2 3
8 2 8 4
8 6 8 7
6 4 6 6
4 4 4 4
4 6 4 6
*/

int main(){
	for(int a=0;a<502;a++){
		for(int b=0;b<502;b++) arena[a][b]=0;
	}
	
	cin >> row >> col >> byk;
	
	int kk,ll,mm,nn;
	while(byk--){
		cin >> kk >> ll >> mm >> nn;
		for(int a=kk;a<=mm;a++){
			for(int b=ll;b<=nn;b++){
				arena[a][b]= -1*(ll);
			}
		}
	}
	
//	for(int a=0;a<=row;a++){
//		for(int b=0;b<=col;b++) {
//			cout << arena[a][b]<<" ";	
//		}
//		cout << endl;
//	}
		
	for(int a=row-1;a>=0;a--){
		for(int b=col;b>=0;b--){
			if(arena[a][b]>=0){
				if(arena[a+1][b]<0){
					int x=(-1*arena[a+1][b])-1;
					if(arena[a+1][b+1]>=0) arena[a][b]=arena[a][b+1]+1+arena[a+1][x];
					else arena[a][b]=arena[a][b+1];
				}else{
					arena[a][b]=arena[a+1][b];
				}
			}
		}
	}
	unsigned long long mx=0;
	for(int b=0;b<=col;b++){
		if(arena[0][b]>mx)mx=arena[0][b];
	}
	cout << mx <<endl;		
	return 0;
}

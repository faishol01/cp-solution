#include <bits/stdc++.h>
using namespace std;
string msk;
int tc;

int solve(){
	int x =msk.length();
	int arr[x][x];
	
	//inisialisasi
	for(int a=0;a<x;a++){
		for(int b=0;b<x;b++){
			arr[a][b]=0;
		}
	}
	for(int a=0;a<x;a++) arr[a][a]=1;
	//end
	
	
	//Longest Palindrom Subsequence
	for(int l=1;l<x;l++){
		for(int a=0;a<x;a++){
			int b=a+l;
			
			if(b >= x)break;
			
			if(msk[a]==msk[b]){
				arr[a][b] = 2;				
				arr[a][b] += arr[a+1][b-1];
			}else{
				if(arr[a][b-1]>arr[a+1][b]) arr[a][b]=arr[a][b-1];
				else arr[a][b]=arr[a+1][b];
			}	
		}
	}
	//END
	
//	for(int a=0;a<x;a++){
//		for(int b=0;b<x;b++) cout << arr[a][b] << " ";
//		cout  << endl;
//	}
	
	return arr[0][x-1];
}

int main(){
	cin >>tc;
	while(tc--){
		cin >> msk;
		cout << solve()<<endl;
	}
	return 0;
}

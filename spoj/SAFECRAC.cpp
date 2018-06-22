#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int tc, n,batas=;
ull mod = pow(10,9)+7;
vector< vector<ull> > memo;

void iterasi(){
	for(int a=0;a<10;a++) memo[a].push_back(1);
	memo[10].push_back(10);
	
	memo[0].push_back(1);
	memo[1].push_back(2);
	memo[2].push_back(3);
	memo[3].push_back(2);
	memo[4].push_back(3);
	memo[5].push_back(4);
	memo[6].push_back(3);
	memo[7].push_back(3);
	memo[8].push_back(3);
	memo[9].push_back(2);
	memo[10].push_back(26);
}

ull miniSolve(int digit, int tombol){
	
	ull res=0;
	int row = (tombol-1)/3,
		col = (tombol-1)%3;
		
	//hmmm
	if(tombol == 0){
		res = memo[7][digit-1]%mod;
	}else{
		int gerak[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
		
		for(int i=0;i<4;i++){
			int tCol = col+gerak[i][0],
				tRow = row+gerak[i][1];
				
				if(0 <= tCol && tCol < 3 && 0 <= tRow && tRow < 3){
					int x = tRow*3 + tCol+1;
					res += memo[x][digit-1]%mod;
				}
		}
	}
	
	if(tombol == 7) res += memo[0][digit-1]%mod;
	
	return res%mod;	
}

void dpAja(){
	ull temp;
	for(int a=2;a<=100000;a++){
		temp=0;
		
		for(int i=0;i<10;i++){
			memo[i].push_back(miniSolve(a,i));
			temp+=memo[i][a]%mod;
		}
		
		memo[10].push_back(temp%mod);
	}
}

void solve(){
	if()
}

int main(){
	memo.resize(11);
	iterasi();
	dpAja();
	
	cin >> tc;
	while(tc--){
		cin >> n;
		
	//	for(int a=0;a<10;a++) cout << memo[a][n-1] << " ";
		cout << memo[10][n-1]%mod << endl;
	}
	return 0;
}


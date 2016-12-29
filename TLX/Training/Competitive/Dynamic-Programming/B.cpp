#include <bits/stdc++.h>
using namespace std;
int knapsack, byk,batu[2][2000];

int main(){
	vector<int> ans;
	cin >> knapsack>>byk;
	int memo[byk+1][knapsack+1];
	
	for(int a=0;a<byk;a++){
		cin >> batu[0][a]>>batu[1][a];
	}
	
	//dynamic programming
	for(int a=0;a<byk+1;a++){
		for(int b=0;b<knapsack+1;b++){
			if(a==0) memo[a][b]=0;
			else if(b==0)memo[a][b]=0;
			else{
				if(batu[0][a-1]>b) memo[a][b]=memo[a-1][b];
				else if(batu[0][a-1]<=b){
					int temp = batu[1][a-1]+memo[a-1][b-batu[0][a-1]];
					if(temp>memo[a-1][b]) memo[a][b] = temp;
					else memo[a][b]=memo[a-1][b];
				}
			}
		}
	}
	
	int i=byk,k=knapsack;
	while(i>0&&k>0){
			if(memo[i][k]!=memo[i-1][k]){
				ans.push_back(i);
				k-=batu[0][i-1];
			}
		i--;
	}
	
	for(int a=ans.size()-1;a>=0;a--){
		cout << ans[a] <<endl;
	}
	return 0;
}

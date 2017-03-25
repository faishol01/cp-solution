#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
/*
5 4
1 2
2 3
3 1
4 5
*/

ll n,m;
bool stt=true;

vector < vector<int> > adjList;
vector <bool> visit;

void DFS(int node){
	visit[node]=1;

	for(int i=0;i<adjList[node].size();i++){
		int x = adjList[node][i];
		
		if(!visit[x]){
			DFS(x);
		}
	}
}

int main(){
	cin >> n >> m;
	
	if(n-m != 1) stt = false;
	
	adjList.resize(n);
	visit.resize(n,0);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		adjList[a-1].push_back(b-1);
		adjList[b-1].push_back(a-1);
		
		if(a == b) stt = false;
	}
	
	if(stt){
		DFS(0);
		
		for(int i=0;i<n;i++){
			if(visit[i]==0){
				cout << "NO\n";
				return 0;
			}
		}
		
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
	
	return 0;
}


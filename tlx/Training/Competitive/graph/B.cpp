#include <bits/stdc++.h>
using namespace std;

int tc,node,edge,spone,dest, jenis=1, res=0;

vector < vector<int> > adjList;
vector < pair<int, int> >hubung;
vector <int> visit;
vector <int> special;
vector <int> frek; 

void DFS(int root){
	visit[root] = jenis;
	
	for(int i=0;i<adjList[root].size();i++){
		int x = adjList[root][i];
		
		if(visit[x] == -1){
			DFS(x);
		}
	}
}

void solve(){
	frek.resize(jenis,0);
	
	for(int i=0;i<spone;i++){
		int n,x;
		n = special[i]-1;
		x = visit[n];
		
		frek[x-1]++;
	}
	
	for(int i=0;i<jenis;i++){
		res += (spone-frek[i])*frek[i];
		spone -= frek[i];
	}	
}

int main(){
	cin >> tc;
	
	while(tc--){
		jenis=1; res=0;
		adjList.clear(); hubung.clear(); special.clear(); frek.clear(); visit.clear();
		
		cin >> node >> edge >> spone >> dest;
		
		adjList.resize(node);
		visit.resize(node,-1);
		
		for(int i=0;i<edge;i++){
			int x,y;
			cin >> x >> y;
			
			hubung.push_back({x,y});
		}
		
		for(int i=0;i<spone;i++){
			int x;
			cin >> x;
			
			special.push_back(x);
		}
		
		for(int i=0;i<dest;i++){
			int x;
			cin >> x;
			x--;
			
			hubung[x].first = -1; hubung[x].second = -1;
		}
		
		for(int i=0;i<edge;i++){
			if(hubung[i].first != -1){
				int x = hubung[i].first,
					y = hubung[i].second;
				
				adjList[x-1].push_back(y-1);
				adjList[y-1].push_back(x-1);
			}
		}
		
		for(int i=0;i<node;i++){
			if(visit[i] == -1){
				DFS(i);
				jenis++;
			}
		}
		
		solve();
	
		cout << res << endl;
	}
	
	return 0;
}

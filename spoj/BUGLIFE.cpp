#include <bits/stdc++.h>
using namespace std;

int tc, kumbang, nikah;
bool aneh=false;

vector <char> kelamin; //female = f, male = m, not visit = NULL
vector < vector<int> > adjList;

void jelajah(){
	for(int i=0;i<kumbang;i++){
		int x = adjList[i].size();
		
		if(kelamin[i] == NULL){
			kelamin[i] = 'm';
		}
		
		for(int j=0;j<x;j++){
			int pas = adjList[i][j];
			
			if(kelamin[pas] == NULL){
				if(kelamin[i] == 'm') kelamin[pas] = 'f';
				else kelamin[pas] = 'm';
			}else if(kelamin[i] == kelamin[pas]){
				aneh = true;
				break;
			}
		}
		
		if(aneh) break;
	}
}

int main(){
	cin >> tc;
	
	for(int a=1;a<=tc;a++){
		aneh = false;
		adjList.clear();
		kelamin.clear();
		
		cin >> kumbang >> nikah;
		
		adjList.resize(kumbang);
		kelamin.resize(kumbang);
		
		for(int i=0;i<nikah;i++){
			int kumA, kumB;
			cin >> kumA >> kumB;
			
			adjList[kumA-1].push_back(kumB-1);
			adjList[kumB-1].push_back(kumA-1);
		
		
		}
		
		if(!aneh) jelajah();
		
		cout << "Scenario #" << a << ":\n";
		if(aneh) cout << "Suspicious bugs found!\n";
		else cout << "No suspicious bugs found!\n";
	}	
	return 0;
}


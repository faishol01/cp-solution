#include <bits/stdc++.h>
using namespace std;

const int dR[] = {-1, 1, 0, 0};
const int dC[] = {0, 0, -1, 1};

#define BTW(a,x,y) (x) <= (a) && (a) <= (y) 

struct point{
	int pR, pC;
};

int T, C, R, pjk = 0;
char maze[25][25];
bool visited[25][25];
point mulai;
bool valid;

bool isPojok(int x, int a, int b){
	if(x == a || x == b) return 1;
	return 0;
}

void DFS(point pos){
	if(pos.pR != mulai.pR || pos.pC != mulai.pC){
		if(isPojok(pos.pR, 0, R-1) || isPojok(pos.pC, 0, C-1)){
			valid = 1;
			return;
		}
	}

	for(int i=0;i<4 && !valid;i++){
		point tmp;
		tmp.pR = pos.pR+dR[i];
		tmp.pC = pos.pC+dC[i];

		if(BTW(tmp.pC,0,C-1) && BTW(tmp.pR,0,R-1)){
			if(!visited[tmp.pR][tmp.pC] && maze[tmp.pR][tmp.pC]=='.'){
				visited[tmp.pR][tmp.pC] = 1;
				DFS(tmp);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> T;
	while(T--){
		pjk = 0;
		memset(visited, 0, sizeof visited);
		valid = 0;

		cin >> R >> C;
		for(int i=0;i<R;i++) for(int j=0;j<C;j++){
			cin >> maze[i][j];
			if(i==0 || i==R-1 || j==0 || j==C-1){
				if(maze[i][j] == '.'){
					pjk++;
					mulai.pR = i;
					mulai.pC = j;
				}
			}
		}

		visited[mulai.pR][mulai.pC] = 1;
		DFS(mulai);

		if(pjk == 2 && valid) cout << "valid" << endl;
		else cout << "invalid" << endl;
	}
}
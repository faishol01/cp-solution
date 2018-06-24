////////////////////////////////////////////////
//                                            //
//  Author: Muhammad Faishol Amirul Mukminin  //
//                                            //
////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef pair<pi,int> pii;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> pll;
typedef pair<double,double> pd;
typedef pair<pd,double> pdd;

#define FOR(i,x,y) for(int i=(x);i<(y);i++)
#define FORN(i,x,y) for(int i=(x);i<=(y);i++)
#define REV(i,a,b) for(int i=(a);i>(b);i--)
#define REVN(i,a,b) for(int i=(a);i>=(b);i--)
#define BTW(i,a,b) a <= i && i <= b

#define DB(x) cerr << #x << ": " << x << endl;

#define fi first
#define se second
#define PUB push_back
#define POB pop_back
#define PUF push_front
#define POF pop_front
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"

const double EPS = 1e-9;
const double PI = acos(-1);
const ll MOD = 1e9+7;
const int INF = 0x7FFFFFFF;
const ll LINF = 0x7FFFFFFFFFFFFFFFLL;
const ull UINF = 0xFFFFFFFFFFFFFFFFLL;
const int dCol[] = {0,+1,0,-1,+1,+1,-1,-1};
const int dRow[] = {-1,0,+1,0,-1,+1,+1,-1};

template <typename T>
inline void VIN(vector<T> &i){ T x; cin >> x; i.PUB(x); }
inline void FIO(string i){ freopen((i+".in").c_str(), "r", stdin); freopen((i+".out").c_str(), "w", stdout);}

struct Aelm{
	int mobil, r, c;
};

int N, K;
int maze[6][55];
vector<Aelm>ans;

void parkir(){
	FORN(i,1,N){
		if(maze[1][i] == maze[2][i] && maze[1][i] != 0){
			ans.PUB({maze[1][i], 1, i});
			maze[2][i] = 0;
			K--;
		}

		if(maze[3][i] == maze[4][i] && maze[3][i] != 0){
			ans.PUB({maze[3][i], 4, i});
			maze[3][i] = 0;
			K--;
		}
	}
}

void putar(){
	int pR = -1, pC = -1;
	FORN(i,2,3){
		FORN(j,1,N){
			if(maze[i][j]==0){
				pR = i;
				pC = j;
				break;
			}
		}

		if(pR != -1 && pC != -1) break;
	}

	int tR = pR, tC = pC;
	if(tR == 2){
		tC++;
		if(tC == N+1){
			tR = 3;
			tC = N;
		}
	}else{
		tC--;
		if(tC == 0){
			tR = 2;
			tC = 1;
		}
	}

	while(tR != pR || tC != pC){
		if(tR == 2){
			if(tC == 1){
				if(maze[tR][tC] != 0) ans.PUB({maze[tR][tC], 3, tC});
				swap(maze[2][tC], maze[3][tC]);
			}else{
				if(maze[tR][tC] != 0) ans.PUB({maze[tR][tC], tR, tC-1});
				swap(maze[tR][tC], maze[tR][tC-1]);
			}

			tC++;
			if(tC == N+1){
				tR = 3;
				tC = N;
			}
		}else{
			if(tC == N){
				if(maze[tR][tC] != 0) ans.PUB({maze[tR][tC], 2, tC});
				swap(maze[2][tC], maze[3][tC]);
			}else{
				if(maze[tR][tC] != 0) ans.PUB({maze[tR][tC], tR, tC+1});
				swap(maze[tR][tC], maze[tR][tC+1]);
			}

			tC--;
			if(tC == 0){
				tR = 2;
				tC = 1;
			}
		}
	}
}

bool bisaPutar(){
	FORN(i,1,N){
		if(maze[2][i]==0 || maze[3][i]==0) return 1;
	}
	return 0;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	FORN(i,1,4) FORN(j,1,N){
		cin >> maze[i][j];
	} 

	parkir();

	if(!bisaPutar()){
		cout << -1 << endl;
		return 0;
	}

	while(K > 0){
		putar();
		parkir();
	}

	cout << ans.size() << endl;
	for(Aelm elm:ans){
		cout << elm.mobil << " " << elm.r << " " << elm.c << endl;
	}
	return 0;
}
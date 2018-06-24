// WA
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
typedef pair<string, int> psi;
 
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

int R, C, cnt = 0,
	daerah[1005][1005];
char maze[1005][1005];
vector<int>total;

void floodfill(int id, int pR, int pC){
	total[id]++;
	daerah[pR][pC] = id;

	FOR(i,0,4){
		int tC = pC + dCol[i],
			tR = pR + dRow[i];
		if(BTW(tC,0,C-1) && BTW(tR,0,R-1)){
			if(maze[tR][tC] == '.' && daerah[tR][tC] == -1){
				floodfill(id, tR, tC);
			}
		}
	}
}

int solve(int pR, int pC){
	set<int>visit;

	int ret = 1;
	FOR(i,0,4){
		int tC = pC + dCol[i],
			tR = pR + dRow[i];
		if(BTW(tC,0,C-1) && BTW(tR,0,R-1)){
			if(daerah[tR][tC] != -1 && visit.find(daerah[tR][tC]) == visit.end()){
				ret += total[daerah[tR][tC]];
				visit.insert(daerah[tR][tC]);
			}
		}
	}

	return ret%10;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(daerah, -1, sizeof daerah);

	cin >> R >> C;
	FOR(i,0,R) FOR(j,0,C){
		cin >> maze[i][j];
	}

	FOR(i,0,R) FOR(j,0,C){
		if(daerah[i][j] == -1 && maze[i][j] == '.'){
			total.PUB(0);
			floodfill(cnt, i, j);
			cnt++;
		}
	}

	FOR(i,0,R) FOR(j,0,C){
		if(maze[i][j]=='*'){
			cout << solve(i,j);
		}else cout << '.';

		if(j==C-1) cout << endl;
	}
	
	return 0;
}
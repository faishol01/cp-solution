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

const int MAXN = 3e5+5;

int T, C, R;
int dist[200][200];
queue<pi>q;

void solve(){
	int step = 1;
	int byk_now = q.size(),
		byk_aft = 0;

	while(!q.empty()){
		if(byk_now == 0){
			swap(byk_aft, byk_now);
			step++;
		}

		int posR = q.front().fi,
			posC = q.front().se;
		q.pop();
		
		FOR(i,0,4){
			int tR = posR + dRow[i],
				tC = posC + dCol[i];

			if(BTW(tR,0,R-1) && BTW(tC,0,C-1)){
				if(dist[tR][tC] == -1){
					q.push({tR,tC});
					dist[tR][tC] = step;
					byk_aft++;
				}
			}
		}

		byk_now--;
	}
}

void print_ans(){
	FOR(i,0,R) FOR(j,0,C){
		cout << dist[i][j];

		if(j==C-1) cout << endl;
		else cout << " ";
	}
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while(T--){
		memset(dist, -1, sizeof dist);

		cin >> R >> C;
		FOR(i,0,R) FOR(j,0,C){
			char x;
			cin >> x;
			if(x == '1'){
				q.push({i,j});
				dist[i][j] = 0;
			}
		}

		solve();
		print_ans();
	}
	
	return 0;
}
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

int N, M, S;
vector<int>adjL[5005], unReach;
bitset<5005>isReach;
int visit_label[5005];

void DFS(int pos){
	for(auto nxt:adjL[pos]){
		if(!isReach[nxt]){
			isReach[nxt] = 1;
			DFS(nxt);
		}
	}
}

void DFS2(int pos, int id){
	for(auto nxt:adjL[pos]){
		if(!isReach[nxt] && visit_label[nxt] != id){
			visit_label[nxt] = id;
			DFS2(nxt, id);
		}
	}
}

void solve(){
	set<int>beda;
	int id = 1;

	for(auto elm:unReach){
		if(visit_label[elm] != 0) continue;
		
		visit_label[elm] = id;
		DFS2(elm, id);
		
		id++;
	}

	for(auto elm:unReach){
		beda.insert(visit_label[elm]);
	}

	cout << beda.size() << endl;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> S;
	FOR(i,0,M){
		int u, v;
		cin >> u >> v;
		adjL[u].PUB(v);
	}

	isReach[S] = 1;
	DFS(S);
	FORN(i,1,N){
		if(!isReach[i]) unReach.PUB(i);
	}

	if(unReach.size() == N) cout << 0 << endl;
	else solve();

	return 0;
}
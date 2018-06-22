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

int N, M, K, S;
int dist[100005][105];
vector<int>adjL[100005], goods[105];
queue<int>q;

void BFS(int tipe){
	int step = 1;
	int now = q.size(), child=0;

	while(!q.empty()){
		if(now == 0){
			step++;
			swap(now, child);
		}

		int pos = q.front();
		q.pop();

		for(auto nxt:adjL[pos]){
			if(dist[nxt][tipe] == -1){
				dist[nxt][tipe] = step;
				q.push(nxt);
				child++;
			}
		}

		now--;
	}
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	memset(dist, -1, sizeof dist);

	cin >> N >> M >> K >> S;
	FOR(i,0,N){
		int x;
		cin >> x;
		goods[--x].PUB(i);
		dist[i][x] = 0;
	}
	FOR(i,0,M){
		int x, y;
		cin >> x >> y;
		adjL[--x].PUB(--y);
		adjL[y].PUB(x);
	} 

	FOR(i,0,K){
		for(int elm:goods[i]) q.push(elm);
		BFS(i);
	}

	FOR(i,0,N){
		sort(dist[i], dist[i]+K);
		
		int coin = 0;
		FOR(j,0,S) coin += dist[i][j];

		cout << coin;

		if(i==N-1) cout << endl;
		else cout << " ";
	}
	return 0;
}
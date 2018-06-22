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

ll N, M, K, X, S, ans;
pl spell1[200005], spell2[200005];

int srcSpell2(ll uang){
	int l = 1, r = K, m;
	int ret = 0;

	while(l<=r){
		m = (l+r)/2;
		if(spell2[m].se <= uang){
			l = m+1;
			ret = m;
		}else r = m-1;
	}

	return ret;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K >> X >> S;
	
	spell1[0] = {X,0};
	FORN(i,1,M) cin >> spell1[i].fi;
	FORN(i,1,M) cin >> spell1[i].se;
	
	FORN(i,1,K) cin >> spell2[i].fi;
	FORN(i,1,K) cin >> spell2[i].se;

	ans = N*X;

	FORN(i,0,M){
		if(S-spell1[i].se < 0) continue;

		int ind = srcSpell2(S-spell1[i].se);
		ll tmp = max(0LL, N-spell2[ind].fi)*spell1[i].fi;
		
		ans = min(tmp, ans);
	}

	cout << ans << endl;

	return 0;
}
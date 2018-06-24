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

ll N, P, V, ans = LINF;

bool isValid(ll K){
	ll tN = N;
	P = 0; V = 0;

	while(tN > 0){
		if(tN > K){
			P += K;
			tN -= K;
		}else{
			P += tN;
			tN = 0;
		}

		V += floor(tN/10);
		tN -= floor(tN/10);
	}
	
	if(K < 100) cerr << K << " " << P << " " << V << endl;

	return P >= V;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	
	if(N<=40) cout << 1 << endl;
	else{
		ll l = 1, r = pow(10,18), m;
		while(l<=r){
			ll m = (l+r)/2;
			if(isValid(m)){
				ans = min(m, ans);
				r = m-1;
			}else l = m+1;
		}

		cout << ans << endl;
	}
	cerr << clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
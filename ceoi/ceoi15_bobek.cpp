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

int N;
ll M, ans = 0, tiket[43];
vector<ll>bayar[2];

void solve(int id, int awal, int fin){
	int pjg = fin-awal;
	FORN(i,0,pjg){
		vector<bool>stt(pjg-i,0);
		stt.resize(pjg,1);

		do{
			ll tmp = 0;

			FOR(i,0,pjg){
				if(stt[i])
					tmp += tiket[awal+i];
			}

			bayar[id].PUB(tmp);
		}while(next_permutation(stt.begin(), stt.end()));
	}
}

int binser(ll s){
	int ret = -1;
	int l = 0, r = bayar[1].size()-1;
	
	while(l <= r){
		int m = (l+r)/2;

		if(bayar[1][m] > s) r = m-1;
		else{
			ret = max(ret, m);
			l = m+1;
		}
	}

	return ret;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	FOR(i,0,N) cin >> tiket[i];
	
	solve(0,0,N/2);
	solve(1,N/2,N);
	
	FOR(i,0,2) sort(bayar[i].begin(), bayar[i].end());
	
    for(ll elm:bayar[0]){
		if(elm > M) break;
		ans += binser(M-elm)+1;
	}

	cout << ans << endl;
	
	return 0;
}
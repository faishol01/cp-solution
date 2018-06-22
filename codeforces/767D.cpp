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

int N, M, K, fridge[1000005];
pi toko[1000005];
vector<int>ans;

bool isValid(){
	int day = 0,
		cnt = 0,
		pos = 0;
	while(pos < N){
		if(fridge[pos] < day) return 0;
	
		pos++;
		cnt++;
	
		if(cnt == K){
			day++;
			cnt = 0;
		}
	}

	return 1;
}

void solve(){
	int day = 0,
		pToko = 0,
		pFridge = 0,
		cnt = 0;
	
	while(pFridge < N && pToko < M){
		while(toko[pToko].fi < day && pToko < M) pToko++;
		if(pToko == M) break;

		if(fridge[pFridge] == day){
			pFridge++;
			cnt++;
		}else{
			ans.PUB(toko[pToko].se);
			pToko++;
			cnt++;
		}

		if(cnt == K){
			day++;
			cnt = 0;
		}
	}

	while(pToko < M){
		if(toko[pToko].fi >= day){
			ans.PUB(toko[pToko].se);
			cnt++;
		}
		pToko++;
		if(cnt == K){
			day++;
			cnt = 0;
		}
	}
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	FOR(i,0,N){
		cin >> fridge[i];
	}
	FOR(i,0,M){
		cin >> toko[i].fi;
		toko[i].se = i+1;
	}

	sort(fridge, fridge+N);
	sort(toko, toko+M, less<pi>());

	if(!isValid()){
		cout << -1 << endl;
		return 0;
	}
	
	solve();

	cout << ans.size() << endl;
	for(auto elm:ans){
		cout << elm;

		if(elm == ans.back()) cout << endl;
		else cout << " ";
	}

	return 0;
}
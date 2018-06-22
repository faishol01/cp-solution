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

struct Qelm{
	int l, r, ind;
	Qelm(int _l, int _r, int _ind):l(_l), r(_r), ind(_ind){}
};

int N, Q, cnt = 0,
	data[30005], frek[1000001], block_sz, ans[200005];
vector <Qelm> Qdata;

void inc_range(int ind){
	frek[data[ind]]++;
	if(frek[data[ind]] == 1) cnt++;
}

void dec_range(int ind){
	frek[data[ind]]--;
	if(frek[data[ind]] == 0) cnt--;
}

void solve(){
	int l = 0,
		r = -1;
	FOR(i,0,Q){
		int lQ = Qdata[i].l,
			rQ = Qdata[i].r;

		while(r < rQ){
			r++;
			inc_range(r);
		}
		while(lQ < l){
			l--;
			inc_range(l);
		}
		while(l < lQ){
			dec_range(l);
			l++;
		}
		while(rQ < r){
			dec_range(r);
			r--;
		}

		ans[Qdata[i].ind] = cnt;
	}
}

bool mo_order(Qelm a, Qelm b){
	int id_a = a.l/block_sz,
		id_b = b.l/block_sz;
	
	if(id_a == id_b) return a.r < b.r;
	return id_a < id_b;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(frek, 0, sizeof frek);

	cin >> N;
	block_sz = sqrt(N);

	FOR(i,0,N)
		cin >> data[i];
	
	cin >> Q;
	FOR(i,0,Q){
		int x, y;
		cin >> x >> y;
		Qdata.PUB(Qelm(x-1, y-1, i));
	}

	sort(Qdata.begin(), Qdata.end(), mo_order);
	solve();

	FOR(i,0,Q){
		cout << ans[i] << endl;
	}

	return 0;
}
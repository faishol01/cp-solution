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

int K, N, data[200005];
ll summ;
bitset<200005>stt;
unordered_map<ll, pair<int,int> > sebelum;

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> K;
	FOR(i,0,K){
		summ = 0;
		stt.reset();

		cin >> N;
		FOR(j,0,N){
			cin >> data[j];
			summ += data[j];
		}

		FOR(j,0,N){
			if(stt[data[j]+10000]) continue;

			ll tmp_sum = summ-data[j];
			if(sebelum.find(tmp_sum) == sebelum.end()){
				sebelum.insert({tmp_sum, {i+1, j+1}});
			}else{
				cout << "YES" << endl;
				cout << sebelum[tmp_sum].fi << " " << sebelum[tmp_sum].se <<endl;
				cout << i+1 << " " << j+1 << endl;

				return 0;
			}

			stt[data[j]+10000] = 1;
		}
	}

	cout << "NO" << endl;

	return 0;
}
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

int T, N;
ll lima[16];
vector<ll>lucky;

void precomp(){
	// Cukup sampe 5^15, karena akan menghasilkan 15 elemen. Jumlah subhimpunannya ada 2^15
	for(int i=1;i<=15;i++){
		lima[i] = ll(pow(5,i));
	}

	for(int i=1;i<=15;i++){
		vector<bool> stt(15-i, 0);
		stt.resize(15,1);

		do{
			ll tmp = 0;
			for(int i=0;i<15;i++){
				if(stt[i]) tmp += lima[i+1];
			}

			lucky.PUB(tmp);
		}while(next_permutation(stt.begin(), stt.end()));
	}

	sort(lucky.begin(), lucky.end());
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	precomp();

	cin >> T;
	while(T--){
		cin >> N;
		cout << lucky[N-1] << endl;
	}
	
	return 0;
}
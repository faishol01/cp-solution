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

int T;
ll A, B, ans;

int get_pangkat(ll n){
	//return x that statisfy n = 2^x
	int ret = 0;
	while(n > 0){
		n >>= 1;
		ret++;
	}

	return ret;
}

int greedy(){
	ans = 0;

	if(A==B) ans = 0;
	else if(B==1 || B==0){
		if(B == 1 && A == 0) ans = 1;
		else ans = -1; 
	}else{
		int satu_A = __builtin_popcountll(A),
			satu_B = __builtin_popcountll(B);

		ll LSB_B = B & (-B),
		   LSB_A = A & (-A);
		
		if(satu_A > satu_B){
			int sisa_satu = satu_A-(satu_B-1),
				tmb = get_pangkat(LSB_B);

			if(sisa_satu > tmb-1){
				ans = 2;
			}else{
				ans += get_pangkat(LSB_B)-sisa_satu;
			}
		}else if(satu_A < satu_B){
			ans += (satu_B-1)-satu_A;
			ans += get_pangkat(LSB_B);
		}else{
			if(B&1){
				ans = 2;
			}else{
				ans = get_pangkat(LSB_B)-1;
			}
		}
	}
	
	return ans;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> T;
	while(T--){
		cin >> A >> B;
		cout << greedy() << endl;
	}
    
	return 0;
}
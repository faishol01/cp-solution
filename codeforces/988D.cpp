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

const ll MAXX = 1e9;

struct ans{
	ll utama, id, beda;
};

int N, byk = 0;
ll data[200005];
ans jwb;

bool isElementExist(ll src){
	int l = 0, r = N-1, m;
	while(l<=r){
		m = (l+r)/2;
		if(data[m]==src) return 1;
		else if(data[m] < src) l = m+1;
		else r = m-1;
	}

	return 0;
}

void printAns(){
	cout << jwb.utama;

	if(jwb.id == 0){
		FORN(i,1,2){
			if(isElementExist(jwb.utama-i*jwb.beda))
				cout << " " << jwb.utama-i*jwb.beda;
		}
	}else if(jwb.id == 1){
		if(isElementExist(jwb.utama+jwb.beda))
				cout << " " << jwb.utama+jwb.beda;
		
		if(isElementExist(jwb.utama-jwb.beda))
				cout << " " << jwb.utama-jwb.beda;
	}else{
		FORN(i,1,2){
			if(isElementExist(jwb.utama+i*jwb.beda))
				cout << " " << jwb.utama+i*jwb.beda;
		}
	}

	cout << endl;
}

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	cin >> N;
	FOR(i,0,N){
		cin >> data[i];
	}
	
	sort(data, data+N);

	FOR(i,0,N){
		for(int j=1;j <= MAXX; j*= 2){
			int len[3] = {1,1,1};

			if(isElementExist(data[i]+j) == 1){
				len[1]++;
				len[2]++;
			}
			if(isElementExist(data[i]+2*j) == 1){
				len[2]++;
			}
			
			if(isElementExist(data[i]-j) == 1){
				len[0]++;
				len[1]++;
			}
			if(isElementExist(data[i]-2*j) == 1){
				len[0]++;
			}

			FOR(k,0,3){
				if(byk < len[k]){
					byk = len[k];
					jwb.utama = data[i];
					jwb.id = k;
					jwb.beda = j;
				}
			}
		}
	}

	cout << byk << endl;
	printAns();

	return 0;
}
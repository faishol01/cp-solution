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

int N, K, L, byk;
ll data[100005], ans = 0;
deque<int>kecil;

int main(){
#ifndef LOCAL

#endif

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> N >> K >> L;
    
    byk = N*K;
    FOR(i,0,byk) cin >> data[i];
	sort(data, data+byk);

    kecil.PUB(data[0]);
    FOR(i,1,byk){
        if(abs(kecil.front()-data[i]) <= L){
            kecil.PUB(data[i]);
        }else break;
    }
    
    if(kecil.size() < N) cout << 0 << endl;
    else{
        int buang = kecil.size()-N;
        
        while(!kecil.empty()){
        //    cout << kecil.front() << endl;
            ans += kecil.front();
            kecil.POF();
        //    cout << "D:" <<  kecil.front() << endl;
            
            for(int i=1;i<K && buang > 0;i++){
                kecil.POF();
                buang--;
            }
        }

        cout << ans << endl;
    }

	return 0;
}
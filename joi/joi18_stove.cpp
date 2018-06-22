#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PUB push_back

int N, K;
ll data[100005], ans = 0;
vector<ll>selisih;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> data[i];
    
    for(int i=0;i<N-1;i++){
        selisih.PUB(data[i+1]-(data[i]+1));
        ans += selisih[i];
    }
    
    ans += N;

    sort(selisih.begin(), selisih.end());
    
    //for(ll i:selisih) cout << i << " ";
    //cout << endl;

    for(int i=1;i<K;i++){
        ans -= selisih.back();
        selisih.pop_back();
    }

    cout << ans << endl;
    return 0;
}
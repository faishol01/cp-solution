
#include  <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define PUB push_back
 
struct art{
    ll sz, val;
};
 
int N;
ll ans = 0, cnt = 0;
vector<art> data;

bool comp(art a, art b){
    if(a.sz == b.sz) return a.val < b.val;
    return a.sz < b.sz;
}

ll optimized(){
    cnt += data[1].val;
    ans = max(cnt, ans);

    for(int i=2;i<=N;i++){
        cnt += data[i].val-(data[i].sz-data[i-1].sz);
        
        if(cnt <= 0 || cnt < data[i].val){
            cnt = data[i].val;
        }
        
        ans = max(ans, cnt);
    }
} 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    data.PUB({0,0});
    for(int i=1;i<=N;i++){
        ll a, b;
        cin >> a >> b;
        data.PUB({a, b});
    }
 
    sort(data.begin(), data.end(), comp);
    
    optimized();
    cout << ans << endl;
}

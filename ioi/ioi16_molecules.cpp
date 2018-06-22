#include <bits/stdc++.h>
#include "molecules.h"
using namespace std;
 
typedef long long ll;
typedef pair<int,int> ii;
 
#define PUB push_back
#define fi first
#define se second
 
bool cmp(ii a, ii b){
    if(a.fi == b.fi) return a.se < b.se;
	return a.fi < b.fi;
}
 
std::vector<int> find_subset(int l, int u, std::vector<int> w) {
    int N = w.size(),
        ki = -1,
        ka = 0;
    ll  sum = 0;
    vector<int> ans;
    vector<ii>data;
 
    for(int i=0;i<w.size();i++) data.PUB({w[i],i});
 
    sort(data.begin(), data.end(), cmp);
    
	while(ki!=ka && ka < N && ki < N){
        if(l <= sum+data[ka].fi && sum+data[ka].fi <= u){
            sum += data[ka].fi;
            break;
        }else if(sum+data[ka].fi < l){
            sum += data[ka].fi;
            ka++;
        }else if(sum+data[ka].fi > u){
            sum -= data[ki+1].fi;
            ki++;
        }
    }
 
    if(l <= sum && sum <= u){
        ki++;
        while(ki<=ka){
            ans.PUB(data[ki].se);
            ki++;
        }
    }
 
    return ans;
}

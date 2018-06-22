////////////////////////////////////////////////
//                                            //
//  Author: Muhammad Faishol Amirul Mukminin  //
//                                            //
////////////////////////////////////////////////
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PUB push_back
#define POF pop_front

const int MAXE = 4e5+5;

struct child{
	deque<ll>sum;
	int pending;
};

int N, Q, K;
int plate[100005];
child segtree[MAXE];
ll ans;

void push_pending(int ind, int l, int r){
	if(segtree[ind].pending != 0){
		if(l != r){
			segtree[2*ind].pending += segtree[ind].pending;
			segtree[2*ind+1].pending += segtree[ind].pending;
		}
		
		while(segtree[ind].pending > 0 && !segtree[ind].sum.empty() && K > 1){
			segtree[ind].sum.POF();
			segtree[ind].pending--;
		}
		
		segtree[ind].pending = 0;
	}

}

void update_me(int ind, int l, int r){
	if(l != r){
		int mid = (l+r)/2;
		
		push_pending(2*ind, l, mid);
		push_pending(2*ind+1, mid+1, r);
	
		int sz_left = segtree[2*ind].sum.size(),
			sz_right = segtree[2*ind+1].sum.size();
		
		segtree[ind].sum.clear();

		for(int i=0; i < min(sz_left, sz_right); i++){
			ll tmp = segtree[2*ind].sum[i]+segtree[2*ind+1].sum[i];
			segtree[ind].sum.PUB(tmp);
		}
		for(int i = min(sz_left, sz_right); i < max(sz_left, sz_right); i++){
			
			if(i < sz_left) segtree[ind].sum.PUB(segtree[2*ind].sum[i]);
			if(i < sz_right) segtree[ind].sum.PUB(segtree[2*ind+1].sum[i]);
		}
		
		segtree[ind].pending = 0;
	}
}

void query1(int ind, int l, int r, int i_src, ll val){
	push_pending(ind, l, r);
	
	if(l == r){
		segtree[ind].sum.clear();
		while(val > 0){
			segtree[ind].sum.PUB(val);
			val /= K;
	
			if(K==1) break;
		}
	
		segtree[ind].pending = 0;
		return;
	}
	
	int mid = (l+r)/2;
	if(i_src <= mid) query1(2*ind, l, mid, i_src, val);
	else query1(2*ind+1, mid+1, r, i_src, val);
	
	update_me(ind, l, r);
}

void query2(int ind, int l, int r, int l_src, int r_src){
	if(r < l_src || l > r_src) return;
	
	push_pending(ind, l, r);
	
	if(l_src <= l && r <= r_src){
		segtree[ind].pending += 1;
		return;
	}
	
	int mid = (l+r)/2;
	query2(2*ind, l, mid, l_src, r_src);
	query2(2*ind+1, mid+1, r, l_src, r_src);
	
	update_me(ind, l, r);
}

void query3(int ind, int l, int r, int l_src, int r_src){
	push_pending(ind, l, r);

	if(r < l_src || l > r_src) return;

	if(l_src <= l && r <= r_src){
		if(!segtree[ind].sum.empty()) ans += segtree[ind].sum.front();
		return;
	}

	int mid = (l+r)/2;
	query3(2*ind, l, mid, l_src, r_src);
	query3(2*ind+1, mid+1, r, l_src, r_src);

	update_me(ind, l, r);
}

void build_segtree(int ind, int l, int r){
	if(l == r){
		ll tmp = plate[l];
		while(tmp > 0){
			segtree[ind].sum.PUB(tmp);
			tmp /= K;

			if(K == 1) break;
		}

		segtree[ind].pending = 0;
		return;
	}

	int mid = (l+r)/2;

	build_segtree(2*ind, l, mid);
	build_segtree(2*ind+1, mid+1, r);
	
	int sz_left = segtree[2*ind].sum.size(),
		sz_right = segtree[2*ind+1].sum.size();
	
	for(int i=0; i < min(sz_left, sz_right); i++){
		segtree[ind].sum.PUB(segtree[2*ind].sum[i]+segtree[2*ind+1].sum[i]);
	}
	for(int i = min(sz_left, sz_right); i < max(sz_left, sz_right); i++){
		if(i < sz_left) segtree[ind].sum.PUB(segtree[2*ind].sum[i]);
		if(i < sz_right) segtree[ind].sum.PUB(segtree[2*ind+1].sum[i]);
	}

	segtree[ind].pending = 0;
}

int main(){
	cin >> N >> Q >> K;
	for(int i=1;i<=N;i++)
		cin >> plate[i];

	build_segtree(1, 1, N);

	while(Q--){
		int id;
		ll a, b;
		cin >> id >> a >> b;
		
		if(id == 1){
			query1(1, 1, N, a, b);
		}else if(id == 2){
			query2(1, 1, N, a, b);
		}else{
			ans = 0;
			query3(1, 1, N, a, b);
			cout << ans << endl;
		}
	}

	return 0;
}
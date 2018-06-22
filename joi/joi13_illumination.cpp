#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define PUB push_back
#define fi first
#define se second

int N, ans;
bool asli[100005];
vector<pi>satu, nol;

void solve(bool lampu, vector<pi>& data){
	int lst = -1;
	for(int i=0;i<N;i++){
		if(asli[i]==lampu){
			if(lst == -1) lst = i;
		}else{
			if(lst != -1){
				data.PUB({lst, i-1});
				lst = -1;
			}
		}

		lampu ^= 1;	
	}
	
	if(lst != -1) data.PUB({lst, N-1});
}

int hitung(vector<pi>data){
	if(data.empty()) return N;

	int ret = 0;
	ret = data[0].se+1;

	for(int i=1;i<data.size();i++){
		ret = max(ret, data[i].se-data[i-1].fi+1);
	}
	ret = max(ret, (N-1)-data.back().se+1);
	return ret;
}

int main(){
	cin >> N;
	for(int i=0;i<N;i++) cin >> asli[i];

	solve(0, nol);
	solve(1, satu);
	
	cout << max(hitung(satu), hitung(nol)) << endl;
}
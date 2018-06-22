#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;

int N, K, T;
ll fibo[100005];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	fibo[0] = fibo[1] = 1;
	for(int i=2;i<100005;i++) fibo[i] = (fibo[i-1]+fibo[i-2])%MOD;

	cin >> T;
	while(T--){
		cin >> N >> K;
		if(K == 0){
			if(N != 0) K = 2;
			else{
				cout << 1 << endl;
				continue;
			}
		}
		
		if(N-K < 0) cout << 0 << endl;
		else cout << fibo[N-K] << endl;
	}
}
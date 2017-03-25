#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

vector <ull> panglim;
ull x=1,n, res=0,i=0;

int tc;

int main(){
	while(x<1000000000){
		x*=5;
		panglim.push_back(x);
	}
	
	x*= 5;
	panglim.push_back(x);
	
	cin >> tc;
	while(tc--){
		res = 0;
		i = 0;
		cin >> n;
		
		while(n>=panglim[i]){
			res += n/panglim[i];
			
			i++;
		}
		
		cout << res << endl;
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int tc, kk, res;
string msg;
char msk;

void solve(){
	while(msg.find('E') < msg.length()){
		int x = msg.find('E');
		
		res += x*(kk-x);
		
		msg.erase(x,1);
	}
}

int main(){
	cin >> tc;
	getchar();
	
	while(tc--){
		msg = "";
		kk=0;
		res=0;
		
		while(msk = getchar()){
			if(msk=='\n'||msk==EOF) break;
			else if(msk == 'K'){
				msg+=msk;
				kk++;
			}else if(msk == 'E'){
				msg+=msk;
			} 
		}
		
		solve();
		
		cout << res << endl;
	}
	return 0;
}


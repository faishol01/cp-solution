#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull a,b;
int tc;

bool prima(ull bil){
	if(bil <= 1) return false;
	
	for(ull i=2;i<=sqrt(bil);i++){
		if(bil%i == 0) return false;
	}
	
	return true;
}

int main(){
	cin >> tc;
	for(int i=0;i<tc;i++){
		cin >> a >> b;
		
		for(ull j=a;j<=b;j++){
			if(prima(j)) cout << j << endl;
		}
		
		if(i<tc-1) cout << endl;
	}	
	
	return 0;
}


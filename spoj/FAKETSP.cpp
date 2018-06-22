#include <bits/stdc++.h>
using namespace std;

char msk, sp, punc;
double x,y,befX,befY, tot=0;
bool awal=true;

void solve(){
	if(!awal){
		tot += sqrt(pow(abs(befX-x),2)+pow(abs(befY-y),2));
		cout << "The salesman has traveled a total of " <<
				 fixed << setprecision(3) << tot << " kilometers." << endl;
	}else awal = 0;
	
	befX = x;
	befY = y;
}

int main(){
	while(msk=getchar()){
		if(msk == EOF) break;
		else if(msk == '('){
			cin >> x >> msk >> y;
			solve();
		}
		
	}
	return 0;
}


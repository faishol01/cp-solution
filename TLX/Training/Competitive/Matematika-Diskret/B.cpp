#include <bits/stdc++.h>
using namespace std;

uint64_t fpb(uint64_t a, uint64_t b){
if(b==0)return a;
else return fpb(b,a%b);
}

int main() {
    uint64_t a,b,c,d,e,f,ta,tc;
    cin >> a >> b >> c >> d;

    f=fpb(a,b); a/=f; b/=f;
    f=fpb(c,d); c/=f; d/=f;
    
	f = fpb(b,d);
	f = b/f*d;
	
	ta=f/b; tc=f/d;
	a*=ta; c*= tc;
    e = a+c;
    
    ta = fpb(e,f);
    if(ta==0) ta=1;
    e /= ta; f/=ta;
    
    cout << e << " " << f << "\n";
	return 0;
}

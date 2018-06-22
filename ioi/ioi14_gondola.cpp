#include <bits/stdc++.h>
#include "gondola.h"
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pi;
 
#define fi first
#define se second
#define PUB push_back
 
set<int>ada;
 
int valid(int n, int inputSeq[])
{	
	int isValid;
	int ind_min;
 
	ada.clear();
 
	isValid = 1; ind_min = 0;
 
	for(int i=0;i<n;i++){
		if(inputSeq[i] < inputSeq[ind_min]) ind_min = i;
		if(ada.find(inputSeq[i]) != ada.end()){
			isValid = 0;
		}
 
		ada.insert(inputSeq[i]);
	}
	
	int str = ind_min,
		fin = ind_min-1,
		cnt = inputSeq[ind_min];
 
	if(fin<0) fin = n-1;
	//cerr << str << " " << fin << " " << cnt << endl;
	while(str != fin){
		if(inputSeq[str] <= n && inputSeq[str] != cnt){
			isValid = 0;
			break;
		}
 
		str++; cnt++;
		if(str>=n) str = 0;
	}
	
	return isValid;
}
 
//----------------------
 
bool cmp1(pi a, pi b){
	return a.fi < b.fi;
}
 
int replacement(int n, int gondolaSeq[], int replacementSeq[])
{
	int ret=0,
		ind=0,
		tmp=0,
		cnt_chg=n+1,
		cnt = 1,
		nmr = 0;
 
	vector<pi>data;
 
	for(int i=0;i<n;i++){
		if(gondolaSeq[i] < gondolaSeq[ind]) ind = i;	
	}
 
	if(gondolaSeq[ind] <= n){
		ind = ind-gondolaSeq[ind]+1;
		if(ind < 0) ind += n;
	}
	
	while(cnt <= n){
		if(gondolaSeq[ind]>n) data.PUB({gondolaSeq[ind],cnt});
		
		ind++; cnt++;
		if(ind>=n) ind = 0;
	}
 
	sort(data.begin(), data.end(), cmp1);
 
	for(int i=0;i<data.size();i++){
		while(data[i].se != data[i].fi){
			replacementSeq[nmr] = data[i].se;
			
			data[i].se = cnt_chg;
 
			cnt_chg++;
			nmr++;
		}
	}
 
	ret = nmr;
	return ret;
}
 
//----------------------
const int MOD = 1e9+9;
int modexp(int bwh, int pgk){
	ll 	b = bwh,
		e = pgk;
 
	ll r = 1;
	while(e>0){
		if(e&1) r = r*b%MOD;
 
		e>>=1;
		b = b*b%MOD;
	}
	
	r %= MOD;
 
	return (int) r;
}
 
int countReplacement(int n, int inputSeq[])
{
	ll ret=1;
	int cnt=n+1;
	vector<int>data;
 
	if(valid(n,inputSeq)==0) return 0;
 
	for(int i=0;i<n;i++){
		if(inputSeq[i] > n) data.PUB(inputSeq[i]);
	}
 
	sort(data.begin(), data.end());
 
	if(data.size()==n) ret *= n;
 
	for(int i=0;i<data.size();i++){
		//cerr << (data.size()-i) <<" " << (data[i]-cnt) << " " << modexp((data.size()-i),(data[i]-cnt),MOD) << endl; 
		//cerr << i << " " << ret << endl;
		
		if(data[i]-cnt > 0)
			ret = ret*modexp((data.size()-i),(data[i]-cnt))%MOD;
	
		cnt = data[i]+1;
	}
 
	ret %= MOD;
	
	return (int) ret;
}

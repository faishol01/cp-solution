#include <bits/stdc++.h>
using namespace std;
int byk,mx,mn,df,msk;
long long res=0;
deque <int> antre;
vector <int> data;
int main(){
	cin>>byk;
 
	for(int a=0;a<byk;a++){
		cin>>msk;
        data.push_back(msk);
	}
 
	for(int a=byk-1;a>=0;a--){
		df=data[a];
		if(a==byk-1)antre.push_back(data[a]);
		else{
			mx=antre.back();
			mn=antre.front();
 
			if(df>mx){
				antre.clear();
				antre.push_back(data[a]);
			}else{
				if(df>mn){
					for(int b=0;b<byk;b++){
						antre.pop_front();
						if(antre.front()>=df)break;
					}
					antre.push_front(df);
				}else{
					antre.push_front(df);
				}
			}
		}
		res+=antre.size();
	}
	cout<<res<<endl;
	return 0;
}

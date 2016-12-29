#include <bits/stdc++.h>
using namespace std;
vector <int> data;
int op,msk;
string per;
int main(){
	cin >> op;
	
	while(op--){
		cin>> per;
		
		if(per=="push_back"){
			cin >>msk;
			data.push_back(msk);
		}else if(per=="push_front"){
			cin>>msk;
			data.insert(data.begin(),msk);
		}else if(per=="pop_front"){
			data.erase(data.begin());
		}else{
			data.pop_back();
		}
	}
	for(int a=0;a<data.size();a++){
		cout << data[a]<<endl;
	}
	return 0;
}

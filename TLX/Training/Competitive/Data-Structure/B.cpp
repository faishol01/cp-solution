#include <bits/stdc++.h>
using namespace std;

deque <int> data;
vector <int> balik;
int opr,x,y,id;
string pp;
/*
void reve(){
	while(data.size()>0){
		balik.push_back(data.front());
		data.pop();	
	}
	for(int a=balik.size()-1;a>=0;a--){
		data.push(balik[a]);
	}
	balik.clear();
	//data.swap(balik);
}
*/
int main(){
	id=0;
	cin>>opr;
	while(opr--){
		cin >> pp;
		if(pp=="add"){
			if(id==0){
			cin >> x >>y;
			
			for(int a=0;a<y;a++) data.push_back(x);
			cout << data.size()<<endl;
			}else{
				cin >> x >>y;
			
			for(int a=0;a<y;a++) data.push_front(x);
			cout << data.size()<<endl;	
			}
		}else if(pp=="del"){
			cin>>y;
			if(id==0){
			cout << data.front()<<endl;
			for(int a=0;a<y;a++){
				data.pop_front();
				if(data.empty()) break;	
			}
			}else{
			cout << data.back()<<endl;
			for(int a=0;a<y;a++){
				data.pop_back();
				if(data.empty()) break;	
			}	

			}
		}else{
			if(id==0)id=1;
			else id=0;
		}
	} 
	return 0;
}

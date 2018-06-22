#include <bits/stdc++.h>
using namespace std;
int byk,x,y,ket=0;
string ope;
stack<int> data;
stack<int>tambah;

int main(){
	cin>>byk;
	while(byk--){
		cin>>ope;
		if(ope=="add"){
			cin>>x>>y;
			for(int a=0;a<y;a++){
				data.push(x);tambah.push(0);
			}
			cout<<data.size()<<endl;
		}else if(ope=="del"){
			ket=0;
			cin>>y;
			cout<<data.top()+tambah.top()<<endl;
			for(int a=0;a<y;a++){
				ket+=tambah.top();
				tambah.pop();
				data.pop();
				if(data.empty()) break;
			}
			if(!data.empty()){
				ket+=tambah.top();
				tambah.pop();
				tambah.push(ket);
			}
		}else if(ope=="adx"){
			cin>>x;
			ket=x+tambah.top();
			tambah.pop();
			tambah.push(ket);
		}else{
			cin>>x;
			ket=tambah.top()-x;
			tambah.pop();
			tambah.push(ket);
		}																																																																																																																																							
	}
}

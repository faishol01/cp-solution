#include <bits/stdc++.h>
using namespace std;
int byk,teman[2][100000],res=0;

struct apa{
	int awal;
	int selesai;
	bool operator<(const apa& rhs) const{return selesai < rhs.selesai; }
};

int main(){
	apa * data=new apa[100000];
	
	cin >> byk;
	for(int a=0;a<byk;a++){
		cin >> data[a].awal >>data[a].selesai;
		data[a].selesai +=data[a].awal;
	}
	
	//sorting
	stable_sort(data,data+byk);
	
	//choose by first finish
	int ind=0,last=-1;
	while(ind<byk){
		if(data[ind].awal>=last){
			last=data[ind].selesai;
			res+=1;
		}
		ind++;
	}
	//<2-7><9-12><9-16><15-21>
	cout << res <<endl;
	return 0;
}

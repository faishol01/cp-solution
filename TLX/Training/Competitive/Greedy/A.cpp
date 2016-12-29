#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int byk,res=0;
	long long max;
	cin>> byk>>max;
	long long data[byk], tot=0;
	
	for(int a=0;a<byk;a++){
		cin >> data[a];
	}
	stable_sort(data,data+byk);
	byk-=1;
	while(tot<max){
		tot+=data[byk];
		byk--;
		res+=1;
	}
	cout << res << endl;
	return 0;
}

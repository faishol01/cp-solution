#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	int byk;
	cin>>byk;
	double v1[byk],v2[byk];
	double res=0;
	
	for(int a=0;a<byk;a++) cin>> v1[a];
	for(int a=0;a<byk;a++) cin >> v2[a];
	
	stable_sort(v1,v1+byk); 
	stable_sort(v2,v2+byk);
	
	for(int a=0;a<byk;a++){
		res += v1[a]*v2[byk-(1+a)];
	}
	cout << fixed << setprecision(0)<<res << endl;
	return 0;
}

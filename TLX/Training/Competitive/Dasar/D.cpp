#include <iostream>
using namespace std;

int main(){
	string a,b, hasil;
	int ua,ub;
	
	ua = 0;
	ub = 0;
	
	cin >> a >> b;
	
	if (a.length() - b.length() == 1){
		while (ub < b.length()){
			if (b[ub] != a[ua]){
				ua++;
			}else if (b[ub] == a[ua]){
				ua++;
				ub++;
			}
			
			if (ua - ub >= 2){
				hasil = "Wah, tidak bisa :(";
				ub = b.length();
			} else if (ua - ub <= 1){
				hasil = "Tentu saja bisa!";
			}
			
		}
	}else
		hasil =  "Wah, tidak bisa :(";
	
	cout << hasil << endl;
	return 0;
}

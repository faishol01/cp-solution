#include <iostream>
using namespace std;

int fungsi(int a, int b,int k, int c){
	int r = c;
	
	if(k > 0){
		r = a*fungsi(a,b,k-1,c) + b;
		
		if (r < 0){
			r *= -1;
		}
	}
	return r;
}

int main(){
	int A, B, K, x;
	cin >> A >> B >> K >> x;
	
	cout << fungsi(A,B,K,x) <<endl;
	return 0;
}

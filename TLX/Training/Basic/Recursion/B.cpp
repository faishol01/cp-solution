#include <iostream>
using namespace std;

int faktorial(int a){
	int hasil=1;
	
	if(a > 0 ){
		if(a%2 ==1){
			hasil = a * faktorial(a-1); 
		}else{
			hasil = a/2 * faktorial (a-1);
		}
	}
	
	return hasil;
}

int main(){
	int a;
	cin >> a;
	cout <<faktorial(a) <<endl;
	return 0;
}

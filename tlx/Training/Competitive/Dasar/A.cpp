#include <iostream>
using namespace std;

int main(){
	int tc, byk, sel;
	
	cin >> tc;
	string out[tc],src;
	
	for(int a=0;a<tc;a++){
		cin >> byk >> sel >> src;
		string nama[byk], lolos[sel]; 
		int nilai[3][byk], max, j;
		out[a] = "TIDAK";
		
		for(int b=0;b<byk;b++){
			cin >> nama[b] >> nilai[0][b] >> nilai[1][b] >> nilai[2][b];
		}
		
		for(int b=0;b<sel;b++){
			j=0;
			for(int c=0;c<byk;c++){
				if(c>0){
					if(nilai[2][c] > max){
						max = nilai[2][c];
						j=c;	
					}else if(nilai[2][c] == max){
						if(nilai[1][c] > nilai[1][j]){
							j=c;		
						}else if(nilai[1][c] == nilai[1][j]){
							if(nilai[0][c] > nilai[0][j]){
								j=c;	
							}
						}
					}
				}else{
					max = nilai[2][0];
					j=0;
				}
			}
			nilai[0][j] = -1;
			nilai[1][j] = -1;
			nilai[2][j] = -1;
			
			if(nama[j] == src){
				out[a] = "YA";
				break;
			}
		}
		
	}
	
	for(int a=0;a<tc;a++){
		cout << out[a] <<endl;
	}
	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

void swap(string& a, string& b){
	string temp;
	temp = a;
	a=b;
	b=temp;
}

int main(){
	int kolom, baris,batas = -1,count = 0, j;
	cin >> baris >> kolom;
	string matriks[baris][kolom];
	string x;
	
	for(int a=0;a<baris;a++){
		cin >> x;
		for(int b=0;b<kolom;b++){
			matriks[a][b] = x[b];
		}
	}
	
	while(kolom >= 0){
		count = 0;
		batas = -1;
		
		for(int a=baris-1;a>=0;a--){
			for(int b=0;b<kolom;b++){
				if (matriks[a][b] == "0" ){
					break;
				}
				
				if(b==kolom-1 && matriks[a][b] == "1"){
					count += 1;
					for(int c=0;c<kolom;c++){
						matriks[a][c] = "0";
					}
					
					if(batas == -1){
						batas = a;
					}
				}
			}
		}
		
		if(count == 0){
			break;
		}
		
		for(int a=0;a<kolom;a++){
			for(int b=batas;b>=0;b--){
				j=b;
				if (matriks[b][a] == "1"){
					while(j>=0){
						if(matriks[j+1][a] == "0"){
							swap(matriks[j][a],matriks[j+1][a]);
							j++;
						}else{
							break;
						}
						
						if(j+1 >= baris){
							break;
						}
					}
				}
			}
		}
	}
	
	for(int a=0;a<baris;a++){
		for(int b=0;b<kolom;b++){
			cout << matriks[a][b];
		}
		cout << "\n";
	}
	
	return 0;
}

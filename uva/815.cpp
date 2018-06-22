#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

int N, M, byk, tenggelam, tc = 1;
double tanah[905], air;
double tinggi, sum;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	while(cin >> N >> M){
		if(N==0 && M==0) break;
		
		byk = N*M;
		tenggelam = 1;
		sum = 0;

		for(int i=0;i<byk;i++) cin >> tanah[i];
		cin >> air;
		air /= 100;
		sort(tanah, tanah+byk);

		for(int i=0;i<byk;i++){
			sum += tanah[i];
			double tinggi_tmp = (air+sum)/(i+1);

			if(i==0) tinggi = tinggi_tmp;
			else{
				if(tinggi_tmp-tinggi > EPS){
					break;
				}else{
					tinggi = tinggi_tmp;
					tenggelam++;
				}
			}
		}

		cout << "Region " << tc << "\n";
		cout << fixed << setprecision(2) << "Water level is " << tinggi << " meters.\n";
		cout << fixed << setprecision(2) << tenggelam*100/(double)byk << " percent of the region is under water.\n";
		cout << "\n";
		tc++;
	}
}
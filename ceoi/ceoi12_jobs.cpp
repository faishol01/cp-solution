#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
const int MAXM = 1e6+5;

struct job{
	int ind, day;
};

int N, D, M, mesin_ans = MAXM;
job data[MAXM];

bool isJobCompleted(int mesin){
	int pos = 0;

	for(int i=1;i<=N;i++){
		for(int j=0;j < mesin && data[pos].day <= i && pos < M;j++){
			if(i > data[pos].day+D) return 0; 
			pos++;
		}
	}

	return 1;
}

void print_ans(){
	int pos = 0;

	cout << mesin_ans << endl;
	for(int i=1;i<=N;i++){
		for(int j=0;j < mesin_ans && data[pos].day <= i && pos < M;j++){
			cout << data[pos].ind << " ";
			pos++;
		}

		cout << 0 << endl;
	}
}

bool cmp(job a, job b){
	if(a.day == b.day) return a.ind < b.ind;
	return a.day < b.day;
}

int main(){

	cin >> N >> D >> M;
	for(int i=0;i<M;i++){
		cin >> data[i].day;
		data[i].ind = i+1;
	}
	
	sort(data, data+M, cmp);

	int l = 1,
		r = M;
	while(l<=r){
		int mid = (l+r)/2;
		
		if(isJobCompleted(mid)){
			mesin_ans = min(mid, mesin_ans);
			r = mid-1;
		}else l = mid+1;	
	}

	print_ans();

	return 0;
}
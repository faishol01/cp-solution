#include <bits/stdc++.h>
using namespace std;
struct apa{
	int pcol,prow;
};
int langkah=0,
		col,row,
		scol,srow,
        arena[100][100];
apa point,sek;

deque <apa> koor;
deque <int> anak;
		
void BFS(){
	int an=0,byk;
	bool finish=false;
	
	while(!finish){
		an=0;
		langkah++;
		
		byk=anak.back();
		anak.pop_back();
		
		while(byk>0&&!finish){
			sek.pcol=koor.back().pcol;
			sek.prow=koor.back().prow;
			koor.pop_back();
			if(sek.prow==0||sek.prow==row-1){
				finish=true;
			}else if(sek.pcol==0||sek.pcol==col-1){
				finish=true;
			}else if(arena[sek.prow][sek.pcol]==0){
				if(sek.prow>0&&arena[sek.prow-1][sek.pcol]==0){
				an++;
				sek.prow--;
				koor.push_front(sek);
				sek.prow++;
				}
				
				if(sek.pcol>0&&arena[sek.prow][sek.pcol-1]==0){
				an++;
				sek.pcol--;
				koor.push_front(sek);
				sek.pcol++;
				}
				
				if(sek.prow<row-1&&arena[sek.prow+1][sek.pcol]==0){
				an++;
				sek.prow++;
				koor.push_front(sek);
				sek.prow--;
				}
					if(sek.pcol<col-1&&arena[sek.prow][sek.pcol+1]==0){
				an++;
				sek.pcol++;
				koor.push_front(sek);
				sek.pcol--;
				}
				arena[sek.prow][sek.pcol]=1;
			}
			
			byk--;
		}
		anak.push_front(an);
	}
}

int main(){
//	freopen("input.in","r",stdin);
	cin>>row>>col;
	
	for(int a=0;a<row;a++){
		for(int b=0;b<col;b++) cin>>arena[a][b];
	}
	
	cin>>point.prow>>point.pcol;
	point.prow--; point.pcol--;
	
	koor.push_front(point);
	anak.push_front(1);

	BFS();
	
	cout<<langkah<<endl;
	return 0;
}

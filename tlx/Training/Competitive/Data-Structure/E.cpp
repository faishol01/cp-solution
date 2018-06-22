#include <bits/stdc++.h>
using namespace std;
struct serah{
	int nilai;
	int kan;
	int kir;
	int i_nil;
	int i_kan;
	int i_kir;
	
	bool operator<(const serah& rhs) const{
		if(nilai==rhs.nilai){
			return i_nil<rhs.i_nil;
		}else return nilai < rhs.nilai;
	}
};
long long res=0;
int msk,byk;

int binser(int src,int i_src, int bgn, serah arr[]){
	int left=bgn,right=byk-1,mid;
	
	while(left<=right){
		mid=(left+right)/2;
		
		if(arr[mid].nilai>src)right=mid-1;
		else if(arr[mid].nilai<src) left=mid+1;
		else{
			if(arr[mid].i_nil==i_src)return mid;
			else if(arr[mid].i_nil<i_src)left = mid+1;
			else right = mid-1;
		}
	}
	
}

int main(){
	cin>>byk;
	
	serah urutan[byk];
	
	urutan[0].kir=-1; urutan[byk-1].kan=-1;
	urutan[0].i_kir=-1; urutan[byk-1].i_kan=-1;
	for(int a=0;a<byk;a++){
		cin>>msk;
		urutan[a].nilai=msk;
		urutan[a].i_nil=a;
		if(a<byk-1)urutan[a+1].kir=msk,urutan[a+1].i_kir=a;
		if(a>0) urutan[a-1].kan=msk,urutan[a-1].i_kan=a;
	}
	stable_sort(urutan,urutan+byk);
	
	for(int a=0;a<byk-1;a++){
		int x,y,d;
		if(urutan[a].kir>0&&urutan[a].kan>0){
			d = min(urutan[a].kir,urutan[a].kan);
			res+=d;
			
			x=binser(urutan[a].kir,urutan[a].i_kir,a+1,urutan);
			urutan[x].i_kan = urutan[a].i_kan;
			urutan[x].kan = urutan[a].kan;
			
			y=binser(urutan[a].kan,urutan[a].i_kan,a+1,urutan);
			urutan[y].i_kir = urutan[a].i_kir;
			urutan[y].kir = urutan[a].kir;
		}else{
			d= max(urutan[a].kir,urutan[a].kan);
			res+=d;
			if(urutan[a].kir>urutan[a].kan){
				x=binser(urutan[a].kir,urutan[a].i_kir,a+1,urutan);
				urutan[x].i_kan = urutan[a].i_kan;
				urutan[x].kan = urutan[a].kan;
			}else{
				y=binser(urutan[a].kan,urutan[a].i_kan,a+1,urutan);
				urutan[y].i_kir = urutan[a].i_kir;
				urutan[y].kir = urutan[a].kir;	
			}
		}
		
	}
	
//	for(int a=0;a<byk;a++){
//		cout << urutan[a].kir << " "<< urutan[a].nilai<<" "<<urutan[a].kan<<endl;
//		cout << urutan[a].i_kir << " "<< urutan[a].i_nil<<" "<<urutan[a].i_kan<<endl;
//		cout << endl;
//	}
	
	cout << res << endl;
	return 0;
}

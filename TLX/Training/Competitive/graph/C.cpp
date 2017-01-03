#include <bits/stdc++.h>
using namespace std;

struct apa{
	string dep, bel;
	
	bool operator<( const apa& rhs) const
	{
		if(dep == rhs.dep)return bel<rhs.bel;
		else return dep<rhs.dep;
	}
};

int spesies, hubung;
string msk, awal, akhir;

bool ketemu = false;

vector <string> daftar;
vector <apa> data;

vector <string> nama;
vector <int> indeks;

int binser(string src);
void putus();
void DFS();

int main(){
	cin >> spesies >> hubung;
	getchar();
	
	for(int a=0; a<hubung;a++){
		getline(cin, msk);
		daftar.push_back(msk);
	}
	
	sort(daftar.begin(),daftar.end());
	
	putus();
	
	cin >> awal >> akhir;
	
	//ayo telusuri
	int x=binser(awal);
	
	nama.push_back(awal);
	indeks.push_back(x);
	
	if(x!=-1) DFS();
	
	if(!ketemu){
		
		nama.clear(); indeks.clear();
		
		string temp=awal;
		awal = akhir;
		akhir = temp;
		
		x=binser(awal);
	
		nama.push_back(awal);
		indeks.push_back(x);
	
		if(x!=-1) DFS();
	}
	//selesai menelusur
	
	if(!ketemu) cout << "TIDAK MUNGKIN\n";
	else{
		for(int i=0;i<nama.size();i++)cout << nama[i] << endl;
	}
	
	return 0;
}

int binser(string src){
	int right=hubung-1, left=0, teng;
	
	while(left<=right){
		teng = (left+right)/2;
		
		if(data[teng].dep > src) right = teng-1;
		else if (data[teng].dep < src) left = teng+1;
		else{
			if(teng==0) return teng;
			else if(data[teng-1].dep == src){
				right = teng-1;
			}else return teng;
			
		}
	}
	return -1;
}

void putus(){
	apa temp;
	
	for(int i=0; i<hubung; i++){
		temp.dep = temp.bel = daftar[i];
		
		temp.dep.erase(temp.dep.find(" "),temp.dep.length()-1);
		temp.bel.erase(0,temp.bel.find(" ")+1);
		
		data.push_back(temp);
	}
}

void DFS(){
	int hsl_cari;
	
	while(!nama.empty()){
		hsl_cari = binser(data[indeks.back()].bel);
		
		if(data[indeks.back()].bel == akhir){
			ketemu=true;
			nama.push_back(akhir);
			break;
		}else if(hsl_cari==-1){
			if(indeks.back()==hubung-1){
				nama.pop_back();
				indeks.pop_back();
				
				while(!nama.empty()){
					if(indeks.back() == hubung-1){
						nama.pop_back();
						indeks.pop_back();
					}else if(data[indeks.back()+1].dep == nama.back()){
						indeks.back()+=1;
						break;
					}else{
						nama.pop_back();
						indeks.pop_back();
					}
				}
			}
			else if(data[indeks.back()+1].dep == nama.back()) indeks.back()+=1;
			else{
				nama.pop_back();
				indeks.pop_back();
				
				while(!nama.empty()){
					if(indeks.back() == hubung-1){
						nama.pop_back();
						indeks.pop_back();
					}else if(data[indeks.back()+1].dep == nama.back()){
						indeks.back()+=1;
						break;
					}else{
						nama.pop_back();
						indeks.pop_back();
					}
				}
			}
		}else{
			indeks.push_back(hsl_cari);
			nama.push_back(data[hsl_cari].dep);
		}
	}
	
}

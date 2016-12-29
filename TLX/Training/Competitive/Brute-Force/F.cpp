#include <iostream>
using namespace std;
int total = 0,
	maxi=0,
	maxX,
	maxY,
	data[26][26],
	data2[26][26],
	data3[26][26],
	x,y;
	
int lacak(int id,int x, int y){
    if(data[y][x] == id){
		total += 1;
		data[y][x] = 0;
		data2[y][x]=1;
        
        if(x > 0) lacak(id,x-1,y); 
        if(x<maxX) lacak(id,x+1,y);
        if(y>0) lacak(id,x,y-1); 
        if(y<maxY) lacak(id,x,y+1);
    }
}

int lacak2(int id,int x, int y){
    if(data3[y][x] == id){
		data3[y][x] = 0;
        
        if(x > 0) lacak2(id,x-1,y); 
        if(x<maxX) lacak2(id,x+1,y);
        if(y>0) lacak2(id,x,y-1); 
        if(y<maxY) lacak2(id,x,y+1);
    }
}

void swap(int& a, int& b){
	int temp;
	temp =a;
	a=b;
	b=temp;
}

void runtuh(){
	for(int a=0;a<maxX;a++){
		for(int b=maxY-2;b>=0;b--){
			int indeks = b;
			if(data3[indeks]>0 && indeks+1 < maxY){	while((data3[indeks+1][a]==0)&&(indeks+1<maxY)){
					swap(data3[indeks][a],data3[indeks+1][a]);
					indeks++;
				}
			}
		}
	}
}

int main(){
    cin >> maxY >> maxX;
    for(int a=0;a<maxY;a++){
        for(int b=0;b<maxX;b++){
            cin >> data[a][b];
            data3[a][b] = data[a][b];
            data2[a][b]=0;
        }
    }
    
    for(int a=0;a<maxY;a++){
        for(int b=0;b<maxX;b++){
            total = 0;
            if(data2[a][b] == 0) lacak(data[a][b],b,a);
            if(total>maxi){ x=b;y=a; maxi = total;}
        }
    }
    
	lacak2(data3[y][x],x,y);
	runtuh();
	for(int a=0;a<maxY;a++){
		for(int b=0;b<maxX;b++){
			if(data3[a][b] == 0) cout << ".";
			else cout << data3[a][b];
			
			if(b<maxX-1)cout << " ";
			else cout << "\n";
		}
	}
	
    return 0;
}

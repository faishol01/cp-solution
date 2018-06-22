#include <iostream>
using namespace std;
int total = 0,
	maxi=0,
	maxX,
	maxY,
	data[26][26],
	data2[26][26];
	
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

int main(){
    cin >> maxY >> maxX;
    for(int a=0;a<maxY;a++){
        for(int b=0;b<maxX;b++){
            cin >> data[a][b];
            data2[a][b]=0;
        }
    }
    
    for(int a=0;a<maxY;a++){
        for(int b=0;b<maxX;b++){
            total = 0;
            if(data2[a][b] == 0) lacak(data[a][b],b,a);
            if(total>maxi) maxi = total;
        }
    }
    cout << maxi*(maxi-1)<< endl;
    return 0;
}

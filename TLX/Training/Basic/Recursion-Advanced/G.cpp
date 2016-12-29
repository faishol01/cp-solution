#include <bits/stdc++.h>
using namespace std;
int total =0,maxX,maxY,data[26][26];
int lacak(int id,int x, int y){
    if(data[y][x] == id){
total += 1;
data[y][x] = 0;
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
        }
    }
    int x,y,id;
    cin>>y>>x;
    id = data[y][x];
   lacak(id,x,y);
    cout << total*(total-1)<< endl;
    return 0;
}

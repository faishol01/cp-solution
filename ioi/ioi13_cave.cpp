////////////////////////////////////////////////
//                                            //
//  Author: Muhammad Faishol Amirul Mukminin  //
//                                            //
////////////////////////////////////////////////
#include "cave.h"

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
#define PUB push_back

vector<bool> benar(5005,0);

bool isOpen(int pintu, int* S, int N){
    for(int i=0;i<N;i++){
        if(!benar[i]) S[i] = 0;
    }

    int tertutup = tryCombination(S);
    if(tertutup == -1 || pintu < tertutup) return 0;
    return 1;
}

int srcTombol(int pintu, int id, int* S, int N){
    vector<int>tmp;
    for(int i=0;i<N;i++) if(!benar[i]) tmp.PUB(i);

    int l = 0,
        r = tmp.size()-1;
    for(int i=l;i<=r;i++) S[tmp[i]] = id^1;
    
    while(l<r){
        int m = (l+r)/2;

        for(int i=l;i<=m;i++) S[tmp[i]] = id;

        int tertutup = tryCombination(S);
        for(int i=l;i<=m;i++) S[tmp[i]] = id^1;
        
        if(tertutup == -1 || pintu < tertutup){
            r = m;
        }else{
            l = m+1;
        }
    }

    return tmp[l];
}

void exploreCave(int N) {
    int tombol_door[N], tombol_id[N];
    memset(tombol_door, -1, sizeof tombol_door);
    memset(tombol_id, 0, sizeof tombol_id);

    for(int i=0;i<N;i++){
        int id = isOpen(i, tombol_id, N);
        int ans_tombol = srcTombol(i, id, tombol_id, N);

        tombol_door[ans_tombol] = i;
        tombol_id[ans_tombol] = id;
        benar[ans_tombol] = 1;
    }

    answer(tombol_id, tombol_door);
}

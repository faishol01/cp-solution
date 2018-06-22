#include <bits/stdc++.h>
using namespace std;

int N, frek[100005], ans = 1;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        frek[x]++;
    }

    for(int i=2;i<=100000;i++){
        int tmp = 0;
        for(int j=i;j<=100000;j+=i){
            tmp += frek[j];
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;
}
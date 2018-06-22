#include "grader.h"
#include "cluedo.h"

void Solve(){
    int respon = 3,
        tebak[3] = {1,1,1};
    while(respon != 0){
        respon = Theory(tebak[0], tebak[1], tebak[2]);
        tebak[respon-1]++;
    }
}

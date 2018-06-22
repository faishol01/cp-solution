#include <iostream>
using namespace std;

//DATABASE SKOR
int data[3][2],data2[30][3],data3[730][4],data4[59100][5];
//END

void Compute(int timA,int timB,int max, int stt,int array[],int& res){
	int temp[max];
	
	for(int k=0;k<max;k++){
		temp[k] = array[k];
	}		
	
	if(timA > max-2){
		if(stt == 1){
			for(int k=0;k<max;k++){
				if(max == 2){
					data[res][k] = array[k];
				}else if(max == 3){
					data2[res][k] = array[k];
				}else if(max == 4){
					data3[res][k] = array[k];
				}else{
					data4[res][k] = array[k];
				}
			}
			res += 1;
		}
	}else{
		if(stt == 1){
			temp[timA] += 3;
		}else if(stt == 2){
			temp[timA] += 1;
			temp[timB] += 1;
		}else if(stt == 3){
			temp[timB] += 3;		
		}
	
		timB += 1;
		if(timB >= max){
			timA += 1;
			timB = timA+1;
		}
		
		Compute(timA,timB,max,1,temp,res);
		Compute(timA,timB,max,2,temp,res);
		Compute(timA,timB,max,3,temp,res);
	}
}

int main(){
	//// PRECOMPUTE SKOR SEPAK BOLA ////
	int tc,res=0,res2=0,res3=0,res4=0;
	
	int array[2];
	for(int a=0;a<2;a++){
		array[a] = 0;
	}
	Compute(0,1,2,1,array,res);
	Compute(0,1,2,2,array,res);
	Compute(0,1,2,3,array,res);

	int arra[3];
	for(int a=0;a<3;a++){
		arra[a] = 0;
	}
	Compute(0,1,3,1,arra,res2);
	Compute(0,1,3,2,arra,res2);
	Compute(0,1,3,3,arra,res2);

	int arry[4];
	for(int a=0;a<4;a++){
		arry[a] = 0;
	}
	Compute(0,1,4,1,arry,res3);
	Compute(0,1,4,2,arry,res3);
	Compute(0,1,4,3,arry,res3);
	
	int aray[5];
	for(int a=0;a<5;a++){
		aray[a] = 0;
	}
	Compute(0,1,5,1,aray,res4);
	Compute(0,1,5,2,aray,res4);
	Compute(0,1,5,3,aray,res4);	
	///// FINISH PRE COMPUTE ////

	//// START PENGECEKAN TESTCASE /////
	cin >> tc;
	for(int a=0;a<tc;a++){
		string hsl = "YES";
		int id;
		cin >> id;
		int msk[id];
		
		for(int b=0;b<id;b++){
			cin >> msk[b];
		}
		
		if(id == 2){
			for(int k=0;k<res;k++){
				if(data[k][0] == msk[0] && data[k][1] == msk[1]){
					break;
				}else if(k == res-1){
					hsl = "NO";
				}
			}	
		}else if (id == 3){
			for(int k=0;k<res2;k++){
				if(data2[k][0] == msk[0] && data2[k][1] == msk[1] && data2[k][2] == msk[2]){
					break;
				}else if(k == res2-1){
					hsl = "NO";
				}
			}
		}else if(id == 4){
			for(int k=0;k<res3;k++){
				if(data3[k][0] == msk[0] && data3[k][1] == msk[1] && data3[k][2] == msk[2]&& data3[k][3] == msk[3]){
					break;
				}else if(k == res3-1){
					hsl = "NO";
				}
			}
		}else if(id == 5){
			for(int k=0;k<res4;k++){
				if(data4[k][0] == msk[0] && data4[k][1] == msk[1] && data4[k][2] == msk[2]&& data4[k][3] == msk[3]&& data4[k][4] == msk[4]){
					break;
				}else if(k == res4-1){
					hsl = "NO";
				}
			}			
		}
		
		cout << hsl << endl;
	}
	//// FINISH PENGECEKAN TESTCASE /////

	return 0;
}

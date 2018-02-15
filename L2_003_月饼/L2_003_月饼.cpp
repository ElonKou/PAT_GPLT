//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_003_月饼.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 13 Feb 2018 10:53:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef struct{
	int amount;
	int maxNeed;
	long double aver;
	int order;
}Data;

Data* findMax(Data *info,int count){
	// find the max average price Data object and return it.
	Data *max = &info[0];
	int j = 0;
	while(max -> order != 0){
		max = &info[j++];
	}
	for(int i = 0;i < count;i++){
		if(info[i].order == 0 && max->aver < info[i].aver){
			max = &info[i];
		}
	}
	max -> order = 1;
	return max;
}

int checkFull(Data *info,int count){
	int status = 0;
	for(int i = 0;i < count ;i++){
		if(info[i].order == 1){
			status++;
		}
	}
	if(status == count){
		status = 1;
	}else{
		status = 0;
	}
	return status;
}

void calculate(Data *info,int count,int sum){
	long double price = 0.0;
	int need = 0;
	while(sum > 0){
		if(checkFull(info,count) == 1){
			break;
		}
		Data *data = findMax(info,count);
		need = min(data -> amount , sum);
		sum -= need;
		price += data -> aver * need;
		
		//cout << "max:" << data -> amount << "\tneed:" << need << "\tsum:" << sum << endl;
	}
	if(price > 0){
		cout << setprecision(2) << std::fixed << price;
	}else{
		cout << 0;
	}
}

void inputInfo(Data *info,int count){
	for(int i = 0;i < count;i++){
		cin >> info[i].amount;
		info[i].order = 0;
	}
	for(int i = 0;i < count;i++){
		cin >> info[i].maxNeed;
		info[i].aver = info[i].maxNeed*1.0/info[i].amount;
	}
	// output
	//for(int i = 0; i< count ;i++){
		//cout<< "amount:" << info[i].amount 
			//<< "\tMaxNeed:" << info[i].maxNeed
			//<< "\taver:" << info[i].aver
			//<< endl;
	//}
}

int main(){
	int count,sum;
	cin >> count >> sum;
	Data info[count];
	inputInfo(info,count);
	calculate(info,count,sum);
    return 0;
}


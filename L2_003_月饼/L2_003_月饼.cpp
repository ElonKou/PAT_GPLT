//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_003_月饼.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 13 Feb 2018 10:53:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef struct{
	float amount;
	float maxNeed;
	double aver;
}Data;

int com(Data a,Data b){
	return a.aver > b.aver;
}

float mymin(int a,float b){
	return (a<b)?(float)a:b;
}

void calculate(Data *info,int count,int sum){
	sort(info,info+count,com);
	double price = 0.0;
	for(int i = 0;i < count;i++){
		if(sum > 0){
			float need = mymin(sum,info[i].amount);
			sum -= need;
			price += need * 1.0 * info[i].maxNeed/info[i].amount;
		}else{
			break;
		}
	}
	cout << setprecision(2) << std::fixed << price;
}

void inputInfo(Data *info,int count){
	for(int i = 0;i < count;i++){
		cin >> info[i].amount;
	}
	for(int i = 0;i < count;i++){
		cin >> info[i].maxNeed;
		info[i].aver = info[i].maxNeed*1.0/info[i].amount;
	}
}

int main(){
	int count,sum;
	cin >> count >> sum;
	Data info[count];
	inputInfo(info,count);
	calculate(info,count,sum);
    return 0;
}


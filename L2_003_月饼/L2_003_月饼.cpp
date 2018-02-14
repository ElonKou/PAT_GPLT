//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_003_月饼.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 13 Feb 2018 10:53:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <algorithm>
using namespace std;

typedef struct data{
	int amount;
	int maxNeed;
}Data;

void sort(){
	//
}

void calculate(int count,int sum){
	//
}

template <int count>
void inputInfo(Data (&info)[count]){
	// input the price.
	for(int i = 0;i < count;i++){
		cin >> info[0][i];
	}
	// input the mount of goods.
	for(int i = 0;i < count;i++){
		cin >> info[1][i];
	}
}

int main(){
	int count,sum;
	cin >> count >> sum;
	Data info[count];
	inputInfo(info);
	calculate(count,sum);
    return 0;
}


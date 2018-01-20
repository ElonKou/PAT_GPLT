//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_047_装睡.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 01:33:30 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void checkSleep(void){
	int count;
	cin >> count;
	string names[count];
	int index = 0;
	for(int i = 0;i < count;i++){
		string name;
		int breathe;
		int pulse;
		cin >> name;
		cin >> breathe;
		cin >> pulse;
		if(pulse < 50||pulse > 70||breathe < 15 || breathe > 20){
			names[index++] = name;
		}
	}
	int i = 0;
	for(i = 0;i < index-1;i++ ){
		cout << names[i] << endl;
	}
	cout << names[i];
}

int main(){
	// 检查是否装睡
	checkSleep();
    return 0;
}


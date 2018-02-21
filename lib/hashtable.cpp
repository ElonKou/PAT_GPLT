//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  hashtable.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 21 Feb 2018 09:14:19 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#define MAX_ 100010

using namespace std;

int main(){
	int cnt;
	bool hashTable[MAX_] = {false};
	int inputNumber;
	for(int i = 0; i < cnt;i++){
		cin >> inputNumber;
		hashTable[inputNumber] = true;
	}
    return 0;
}


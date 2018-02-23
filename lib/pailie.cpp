//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  pailie.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 22 Feb 2018 02:19:07 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#define MAXN 11

using namespace std;
int P[MAXN];
bool hashTable[MAXN] = {false};
int num;

void pailie(int index){
	if(index == 1 + num){
		for(int i = 1;i <= num;i++){
			cout << P[i];
		}
		cout << endl;
		return ;
	}
	for(int x = 1;x <= num;x ++){
		if(hashTable[x] == false){
			P[index] = x;
			hashTable[x] = true;
			pailie(index + 1);
			hashTable[x] = false;
		}
	}
}

int main(){
	cin >> num;
	pailie(1);
    return 0;
}


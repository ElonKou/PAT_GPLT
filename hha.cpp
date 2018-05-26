//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  hha.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 07 Mar 2018 05:35:00 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
	int x;
	cin >> x;
	int count = 0;
	while(x){
		count ++;
		x = x&(x-1);
		cout << x << endl;
	}
	cout << count;
    return 0;
}


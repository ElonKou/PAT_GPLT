//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  digui.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 22 Feb 2018 01:29:08 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

long F(int n){
	if(n == 0){
		return 1;
	}else{
		return n * F(n-1);
	}
}

int main(){
	int num;
	cin >> num;
    cout << F(num);
	return 0;
}


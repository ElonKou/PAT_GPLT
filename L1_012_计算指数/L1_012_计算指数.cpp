//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_012_计算指数.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 19 Jan 2018 10:35:57 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
	// 输出指数的值,太简单了
	int multi = 1;
	int count = 0;
	cin >> count;
	int temp = count;
	while(count -- >0){
		multi*=2;
	}
	cout << "2^"<< temp << " = " << multi;
    return 0;
}


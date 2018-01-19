//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_015_跟奥巴马一起画方块.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 01:51:32 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
	// 跟奥巴马一起画方块,难度太低了
	int number;
	char c;
	cin >> number;
	cin >> c;
	for(int i = 0;i<(number+1)/2;i++){
		for (int j =0;j < number;j++){
			cout << c;
		}
		cout << endl;
	}
    return 0;
}


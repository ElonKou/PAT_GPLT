//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_029_是不是太胖了.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 11:37:19 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
using namespace std;

void check(int height){
	float weight = (height-100)*0.9*2;
	cout << setiosflags(ios::fixed) 
		 << setprecision(1)
		 << weight;
}

int main(){
	//
	int height;
	cin >> height;
	check(height);
    return 0;
}


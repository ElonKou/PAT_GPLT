//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  test.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 19 Jan 2018 08:02:02 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void dosome(char *str){
	cout << str << endl;
	str[5] = 127;
	cout << str << endl;
}
void doothers(string str){
	str[5] = 0;
	cout << str << endl;
}

int main(){
	//string strr;
	//cin >> strr;
	//doothers(strr);
	//cout << strr<< endl;	

	char str[10];
	cin.getline(str,10);
	dosome(str);
	cout << str<< endl;	
    return 0;
}


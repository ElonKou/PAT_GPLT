//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_046_整除光棍.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 16 Feb 2018 04:38:46 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
	int num,length = 0,result = 1,index = 0;
	char data[1001];
	cin >> num;
    while(result % num != 0){
		if(result / num != 0 || index != 0){
			data[index++] = '0' + result / num;
		}
		result %= num;
		result = (result*10)+1;
		length ++;
	}
	data[index++] = '0' + result / num;
	data[index] = '\0';
	cout << data << " " << length+1;
	return 0;
}


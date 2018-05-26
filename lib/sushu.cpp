//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  sushu.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 02 Mar 2018 10:17:50 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;
//18446744073709551615


int main(){
	for(unsigned long i = 2;i < 18446744073709551615;i++){
		bool is = true;
		for(unsigned long j = 2;j * j <= i ;j ++){
			if(i % j == 0){
				is = false;
				break;
			}
		}
		if(is){
			cout << i << endl;
		}
	}
    return 0;
}


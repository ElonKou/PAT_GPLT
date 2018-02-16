//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_006_连续因子.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 16 Feb 2018 05:46:10 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
#define MAX_ 12					// the 2^31 won't larger MAX_!
using namespace std;

long long multi(int start,int end){
	long long res = 1;
	for(;start < end;start++){
		res *= start;
	}
	return res;
}

void print(int index,int len,int num){
	long long result = 1;
	//cout << len - index +1<< endl;
	//cout << index << " " << len << endl;
	for(int i = index;i<len+1;i++){
		result *= i;
		if(i != index){
			cout << "*" << i;
		}else{
			cout << i;
		}
	}
	cout << " = " << result;
	if(num % result == 0){
		cout << "是";
	}
	cout << endl;
}

int main(){
	// we can use loop to bilud  some array numwers,and chacek it if will out of the input number.
	// the most shortest array containes longest number set.
    int num,top;
	cin >> num;
	top = sqrt(num+1);
	int loop = 1;
	int isOk = 0;
	for(int len = MAX_;len > 1 ;len--,loop++){
		for(int index = 2;index < loop+2;index ++){
			//cout << index << " " << index - loop + MAX_ -1<< endl;
			int end = index - loop + MAX_ -1;
			long long result = multi(index,end);
				print(index,end,num);
			//if(num % result == 0 && result !=1){
				//print(index,end);
				//isOk = 1;
				//if(isOk == 1){
					//return 0;
				//}
			//}
		}
	}
	return 0;
}


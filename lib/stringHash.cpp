//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  stringHash.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 21 Feb 2018 09:40:18 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

long long shash(char *data,int len){
	// 52进制的转换方式
	long long result = 0;
	for(int i = 0;i < len ;i++){
		if(data[i] >= 'A' && data[i] <= 'Z'){
			result = result * 26 + (data[i] - 'A');
		}else if (data[i] >= 'a' && data[i] <= 'z'){
			result = result * 62 + (data[i] - 'a') + 26;
		}else if (data[i] >= '0' && data[i] <= '9'){
			result = result * 10 + (data[i] - '0');
		}
	}
	return result;
}

int main(){
	char str[] = {'B','C','D','4'};
	cout << shash(str,4);
    return 0;
}


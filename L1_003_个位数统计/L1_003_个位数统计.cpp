//L1_003_个位数统计.cpp
//Author:elonkou
//E-mail:elonkou@ktime.cc
//Date  :Tue 16 Jan 2018 09:31:40 PM CST

#include <iostream>
#include <string>
using namespace std;

void count (int *length,string str){
	int number = str.length();
	while(number>=0){
		length[str[--number]-'0'] ++;
	}
}

void printArray(int *length,int len){
	for (int i=0;i<len;i++){
		if(length[i] != 0){
			cout << i << ":" << length[i] << endl;
		}
	}
}

int main(){
	string str;
	cin >> str;
	int length[10] = {0};
	count (length,str);
	printArray(length,10);
    return 0;
}


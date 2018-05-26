//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  n_queen.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 24 Feb 2018 04:55:08 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
#define n 8
using namespace std;

int count = 0;
int list[n + 1] = {0};				// 包含所有的全排列的组合情形
bool flag = false;					// 检查是否符合n皇后的问题排布
bool targetTable[n] = {false};		// 是否已经使用

bool checkIsOk(){
	// 检查是否是一个合法的n皇后问题的排列顺序
	// 接收的输入问题就是当前的list数组
	bool isOK = true;
	for(int i = 1;i <= n;i++){
		for(int j = i+1;j <= n;j++){
			if(abs(i - j) == abs(list[i] - list[j])){
				isOK = false;
			}
		}
	}
	return isOK;
}

void print(){
	for(int i = 0;i < n;i++){
		for(int j = 1;j <= n;j++){
			if(list[i+1] == j){
				cout << j << j;
			}else{
				cout << "**";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void generateP(int index){
	if(index == n + 1){
		if(checkIsOk() == true){
			count ++;
			print();
		}
	}
	for(int i = 1;i <= n;i++){
		if(targetTable[i] == false){
			list[index] = i;
			targetTable[i] = true;
			generateP(index + 1);
			targetTable[i] = false;
		}
	}
}

int main(){
	generateP(1);
	cout << count;
    return 0;
}


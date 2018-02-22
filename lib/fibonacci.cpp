//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  fibonacci.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 22 Feb 2018 01:34:06 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int Fibonacci(int n){
	if(n == 0 || n == 1){
		return 1;
	}else{
		return Fibonacci(n-2) + Fibonacci(n-1);
	}
}

int main(){
	int num;
	cin >> num;
	// 使用递归函数求解斐波那契数列
	//for(int i = 0 ;i < num;i++){
		//int pre = Fibonacci(i);
		//int aft = Fibonacci(i + 1);
		//double x = double(pre)/double(aft);
		//printf("Fibonacci(%d) = %d\t%.20f\n",i,pre,x);
	//}
	// 使用函数循环进行求解斐波那契数列
	long old = 0,now = 1,future = 0;
	for(int i = 0;i < num;i++){
		old = now;
		now = future;
		future = old + now;
		double x = double(now)/double(future);
		printf("Fibonacci(%d) = %ld\t%.20lf\n",i,future,x);
	}
    return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_008_求整数段和.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 02:14:08 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdio>

using namespace std;

int countBlanks(int num,int step){
	// 计算在总共长度为step的情况下,每个字符所占的空格数量
	// int num	:输入的数字
	// int step :每个数字所占字符中空白数量
	int len = 1;			// len:	表示每个数字所占的宽度
	if(num <0){len++;}		// 负数由于有了'-'符号,因此要++
	while(num/10 != 0){
		num /= 10;
		len++;
	}
	return step-len;
}

int sum(int min,int max){
	// 计算下界min到上界max(包含两界)的数字之和
	int sum = 0;
	while(min <= max){
		sum += min++;
	}
	return sum;
}

void output(int min,int max,int step){
	// 接收从min到max的范围,按照格式输出
	// int min	:下界
	// int max 	:上界
	// int step :字符宽度
	int length = max-min+1;								// int length	:从min-max在包含边界的情况下的总长度
	for(int index = 0;index < length;index ++){
		int blanks = countBlanks(index+min,step);		// 调用计算每个字符中空格数量
		for(int i = 0;i<blanks;i++){
			cout << " ";
		}
		cout << min+index;								
		if((index+1)%step == 0 && (index+min) != max){	// 分别考虑在step结束时候以及所有数字输完之后末尾是否要换行
			cout << endl;
		}
	}
	cout << endl << "Sum = " << sum(min,max);			// 调用输出总和
}

int main(){
	// 接受输入的最小值和最大值按格式输出中间所有的数(包含两端)
	// min	:下界
	// max	:上界
	// step :每个数字所占的字符长度

	int min,max,step = 5;
	cin >> min;
	cin >> max;
	output(min,max,step);
    return 0;
}


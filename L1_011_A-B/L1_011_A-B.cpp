//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_011_A-B.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 19 Jan 2018 06:39:45 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstring>

using namespace std;

void printString(int *words,char *origin){
	// 根据words的信息,对每一位origin字符判断是否需要输出
	// int *words	:ascii码数组
	// cahr *origin	:被减去的字符串
	int len = strlen(origin);
	for(int i =0;i<len;i++){
		if(words[origin[i]-0] != 0){
			continue;
		}
		cout <<  origin[i];
	}
}

void checkPattern(char *pattern,int *words){
	// 将pattern中有的字符所对应的ascii码置1
	// char *pattern	:需要减去的字符串
	// int *words		:减去的字符所对应的ascii码为1
	int len = strlen(pattern);
	for(int i = 0;i<len;i++){
		words[pattern[i]-0] = 1;
	}
}

int main(){
	// 这道题实现从字符串A中去除模式串B的所有字符,并且输出剩余的内容
	// 分析问题是,发现数据规模比较大,因此要做一些减少计算量的工作
	// 首先对pattern字符数组进行检查,将每一个字符对应的words数组中的位置置为1
	// 表示pattern中有这个字符,不需要输出
	// 其次将origin源字符串与words对比,查到words里面对应的位置的值为0,表示pattern中没有
	// 因此才可以输出origin中的字符序列
	// 简单高效,复杂度为线性
	char origin[10001];						// 源字符串
	char pattern[10001];					// 模式字符串
	int words[256] = {0};					// 用1存储该位置对应的ascii码是否属于pattern中

	cin.getline(origin,10001);
	cin.getline(pattern,10001);

	checkPattern(pattern,words);			// 根据pattern对words进行初始化
    printString(words,origin);				// 根据words和origin进行打印
	return 0;
}


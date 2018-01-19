//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_010_比较大小.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 19 Jan 2018 06:04:42 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#define NUM 3
using namespace std;

void getNum(int *numa,int *numb,int *numc){
	// 得到三个数的地址,并对其地址进行输入数据
	cin >> *numa;
	cin >> *numb;
	cin >> *numc;
}

void switchNum(int *numa,int *numb){
	// 简单的交换算法,对两个指针指向的数据进行交换
	*numa = *numa + *numb;
	*numb = *numa - *numb;
	*numa = *numa - *numb;
}

void sortNum(int *numa,int *numb,int *numc){
	// 因为只有三个数进行排序,就不用使用什么排序算法了
	// 使用条件语句判断来排序简单粗暴效率高
	if(*numa > *numb){
		switchNum(numa,numb);
	}
	if(*numa > *numc){
		switchNum(numa,numc);
	}
	if(*numb > *numc){
		switchNum(numb,numc);
	}
}

void printNum(int numa,int numb,int numc){
	cout << numa << "->" << numb << "->" << numc << endl;
}

int main(){
	// 这道题太简单了,是刚学C语言的时候的难度吧
	// 但还是为了让这道题有点意思,使用指针吧,而且输入,排序,输出分开
	// 这样结构清晰点,代码干净点
	int numa,numb,numc;				// 定义数据
	getNum(&numa,&numb,&numc);		// 接收输入的数据
	sortNum(&numa,&numb,&numc);		// 排序数据
	printNum(numa,numb,numc);		// 打印数据
	return 0;
}


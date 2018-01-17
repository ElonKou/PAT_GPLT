//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_005_考试座位号.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 17 Jan 2018 12:07:45 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <climits>
#include <cstdio>

using namespace std;

typedef struct data{
	long id;		// 长整形id表示学号
	int testSeat;	// 测试座位
	int examSeat;	// 考试座位
}Data;

void inputInfo(Data **info,int *infoCount,int *checkCount,int **checkNumber){
	// 该函数负责所有的输入内容的输入
	// Data ** info:		指针的的指针,用于替换主函数中指针变量info的地址
	// int * infoCount :	输入的info的元素的数量
	// int * checkCount: 	需要查询的元素的数量
	// int ** checkNumber:	指针的指针,替换主函数中定义的需要查询的信息列表

	// info 信息的录入
	cin >> *infoCount;
	*info = new Data[*infoCount]();
	for(int i=0;i<*infoCount;i++){
		cin >> (*info)[i].id;
		cin >> (*info)[i].testSeat;
		cin >> (*info)[i].examSeat;
	}

	// checkNumber 信息的录入
	cin >> *checkCount;
	*checkNumber = new int [*checkCount];
	for (int i = 0;i < *checkCount;i++){
		cin >> (*checkNumber)[i];
	}
}

void printInfo(Data cell){
	// 按照格式输入一行内容
	cout << cell.id << " " << cell.examSeat;
}

void checkAndPrint(Data *info,int infoCount,int checkCount,int *checkNumber){
	// 检查每一个需要查询的数据,并且分别在info数组中进行遍历
	// 符合条件的元素则传递给printInfo函数进行打印

	for (int i = 0;i < checkCount;i++){
		// 对每一个需要查询的数据进行遍历
		for(int index = 0;index < infoCount; index++){
			// 遍历每个存储的结构体是否符合条件,符合则输出
			if(info[index].testSeat == checkNumber[i]){
				printInfo(info[index]);		// 调用打印,传递对应的结构体内容
				if(i < (checkCount-1)){		// 换行内容需要单独打印
					cout << endl;
				}	
			}
		}
	}
}


int main(){
	// 查询结构体学号,测试座位号,考试座位号内容,并且进行输出
	Data *info;				// 使用Data自定义的结构体类型进行存储数据
	int infoCount;			// 输入的人数
	int checkCount;			// 需要查询输出的人数
	int *checkNumber;		// 查询信息保存在列表中
	inputInfo(&info,&infoCount,&checkCount,&checkNumber);	// 得到屏幕上所有的输入
	checkAndPrint(info,infoCount,checkCount,checkNumber);	// 进行检查输出
    return 0;
}



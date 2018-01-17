//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_006_连续因子.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 17 Jan 2018 05:00:10 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <math.h>
#define MAX_SIZE 100
#define MAX_LENGTH 32

using namespace std;

void printl(int i,int arr[]){
	cout << i <<":";
	int index = 0 ;
	while(arr[index] != 0){
		cout << arr[index] << "*";
		index++;
	}
	cout << endl;
}


int cauLength(int *array){
	int len = 0;
	while(array[len]!=0){
		len++;
	}
	return len;
}


void printMax(long data,int result[][MAX_LENGTH],int length){
	//
	int max = 0;
	int maxPos = 0;
	int i = 0;
	for(int i = 0;i<length;i++){
		if(max < cauLength(result[i])){
			max = cauLength(result[i]);
			maxPos = i;
		}
	}
	cout << max << endl;
	for (i = 0;result[maxPos][i+1]!=0;i++){
		cout << result[maxPos][i] << "*";
	}
	cout << result[maxPos][i];
}

long product(int arr[]){
	long result = 1;
	int i = 0;
	while(arr[i]!=0){
		result *= arr[i];
		i++;
	}
	return result;
}

int ifOverflow(long data,int arr[],int nextdata){
	int isOver = 0;
	if(data < product(arr)*nextdata){
		isOver = 1;
	}
	return isOver;
}

int checkPrint(long data,int factors[],int length,int result[][MAX_LENGTH]){
	// 组合形成最大的因式
	int count = 0;
	//printl(0,factors);
	for (int i = 0;i<length;i++){
		int bias = 0;
		//把连续的数字复制到result中
		result[i][bias] = factors[i];
		while((factors[bias+i+1]-factors[i+bias])==1){
			bias++;
			result[i][bias] = factors[i+bias];
			if(ifOverflow(data,result[i],factors[bias+i+1])!= 0){
				break;
			}
		}
		//printl(factors[i],result[i]);
		//cout << "=" << product(&result[i]) << endl;
	}
	printMax(data,result,length);
}

void getAllFactor(long data,int *list,int * factors,int *length){
	long factorMax  = (long)sqrt(data);
	int step = (data%2==1)?2:1;		// 设置循环步长,奇数步长:2,偶数步长:1(作用:减少循环次数)
	int index = (data%2==0)?2:3;	// 设置起始的下标,奇数为3,偶数为2(作用:减少循环次数)
	int divisor = index;			// 除数
	long quotient = 0;				// 商
	int count = 0;
	int noName = 1;

	//cout << "factor:" << factorMax << endl;
	//cout << "step  :" << step << endl;
	//cout << "index :" << index << endl;
	
	for ( count; index <= factorMax ; index += step){
		divisor = index;
		quotient = (data%divisor == 0)?(data/divisor):0;
		if(quotient != 0 && (divisor <= quotient)){
			//cout << divisor <<":"<< quotient <<endl;
			factors[count++] = divisor;
			if(divisor != quotient){
				factors[count] = quotient;
			}else{
				noName = 0;
			}
		}else if(divisor > quotient && quotient != 0){
			*length = count+noName;
			break;
		}
	}
	*length = count+noName;
}

int main(){
	long data = 0;
	int factors[MAX_LENGTH] = {0};
	int length = 0;
	cin >> data;
	int list[MAX_SIZE] = {0};
	getAllFactor(data,list,factors,&length);
	int results[length][MAX_LENGTH] = {0};
    int count = checkPrint(data,factors,length,results);
	
	return 0;
}


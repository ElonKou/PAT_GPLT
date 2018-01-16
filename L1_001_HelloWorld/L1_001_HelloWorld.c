//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//FileName: l1-002.c
//Author  : elonkou
//E-mail  : elonkou@ktime.cc
//Date    : Tue 16 Jan 2018 05:08:55 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>
#include <stdlib.h>


void printl(int line ,int len,char c){
	for (int i= 0;i<line;i++){
		printf(" ");
	}
	for(int i =0;i<len;i++){
		printf("%c",c);
	}
	//for(int i =0;i<line;i++){
	//	printf(" ");
	//}
}

int main(){
	int data = 0;
	char c = '*';
	int i = 0;
	scanf("%d %c",&data,&c);
	int da = data +1;
	while((da-(i*2+1)*2)>=0){
		da -=(i*2+1)*2;
		i++;
	}
	int len = (i*2-1)>0?(i*2-1):0 ;
	//printf("%d",len);
	int half = (len-1)/2;
	for (int j=0;j<len;j++){
		int count = j>half?(2*half-j):j;
		int l= len-2*count;
		printl(count,l,c);
		printf("\n");
	}
	int used = (half+1)*(half+1)*2-1;
	printf("%d",(data-used)>0?(data-used):0);
    return 0;
}


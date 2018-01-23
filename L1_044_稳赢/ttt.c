//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// FileName: ttt.c
// Author  : elonkou
// E-mail  : elonkou@ktime.cc
// Date    : Tue 23 Jan 2018 08:29:34 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>
#include <stdlib.h>

int main(){
    //int *arr = malloc(sizeof(int)*1);
    int ** arr = malloc(sizeof(int));
    //arr[4] = 10;
    //*arr[4] = 14;
    int num = 1;
    
    printf("&arr = %p\n",&arr);
    printf("arr = %p\n",arr);
    printf("*arr = %p\n",*arr);
    printf("arr[2] = %p\n\n",arr[2]);
    
    printf("num = %p\n",num);
    printf("&num = %p\n",&num);
    return 0;
}



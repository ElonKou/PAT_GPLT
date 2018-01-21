//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_027_出租.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 01:33:34 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#define PHONE_COUNT 11      // 电话号码的长度11位
#define NUMBER_COUNT 10     // 从0-9总共十个数字
using namespace std;

void print(int *arr,int size){
    cout << "debug:" << endl;
    for(int i = 0;i < size;i++){
        cout << arr[size] <<" ";
    }
    cout << endl;
}

int main(){
    //
    string phoneNumber;
    int arr[NUMBER_COUNT] = {0};       // 存储是否有该数字
    int index[PHONE_COUNT] = {0};       // 存储电话号码
    cin >> phoneNumber;
    for(int i = 0;i < PHONE_COUNT;i++){
        arr[phoneNumber[i]-'0'] = 1;
    }
    for(int i = 0;i < PHONE_COUNT;i++){
        int pos = -1;
        for(int j = NUMBER_COUNT-1;j >= 0;j--){
            if(arr[j] != 0){
                pos++;
            }
            if((phoneNumber[i]-'0') == j){
                index[i] = pos;
                break;
            }
        }
    }
    cout << "int[] arr = new int[]{";
    int i = NUMBER_COUNT-1;
    while(arr[i--] == 0){}
    cout << i+1;
    for(;i >= 0;i--){
        if(arr[i] == 1){
            cout << "," << i;
        }
    }
    cout << "};" << endl;
    
    cout << "int[] index = new int[]{";
    for(i = 0;i < PHONE_COUNT-1;i++){
        cout << index[i] << ",";
    }
    cout << index[PHONE_COUNT-1] << "};" << endl;
    return 0;
}


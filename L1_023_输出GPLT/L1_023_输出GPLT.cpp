//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_023_输出GPLT.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 27 Jan 2018 06:07:23 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int arr[4] = {0};
    int len = str.length();
    for(int i = 0;i < len;i++){
        if(str[i] == 'G' || str[i] == 'g'){
            arr[0] ++;
        }
        if(str[i] == 'P' || str[i] == 'p'){
            arr[1] ++;
        }
        if(str[i] == 'L' || str[i] == 'l'){
            arr[2] ++;
        }
        if(str[i] == 'T' || str[i] == 't'){
            arr[3] ++;
        }
    }
    int index = 0;
    while(arr[0] != 0 || arr[1] != 0 || arr[2] != 0 || arr[3] != 0){
        if(arr[0] != 0){
            cout << "G";
            arr[0]--;
        }
        if(arr[1] != 0){
            cout << "P";
            arr[1]--;
        }
        if(arr[2] != 0){
            cout << "L";
            arr[2]--;
        }
        if(arr[3] != 0){
            cout << "T";
            arr[3]--;
        }
    }
    return 0;
}


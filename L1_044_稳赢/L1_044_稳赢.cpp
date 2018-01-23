//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_044_稳赢.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 23 Jan 2018 05:41:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
using namespace std;

void calculate(){
    //
    int num = 0;
    cin >> num;
    string arr[3] = {"Bu","JianDao","ChuiZi"};

    int list[10000];        // 此处可能会被测试多个数据
    int index = 0;
    string str;
    cin >> str;
    while(str != "End"){
        int result = 0;
        for(int i =0;i < 3;i++){
            if(str == arr[i]){
                result = i;
            }
        }
        //cout << endl << ":"<< index<<"+" << result <<"+";
        if((index+1)%(num+1) != 0 || index == 0){
            result = (result+1)%3;
        }
        //cout << result <<":";
        list [index] = result;
        index ++;
        cin >> str;
    }
    for(int i= 0;i < index;i++){
        cout << arr[list[i]];
        if(i != index){
            cout << endl;
        }
    }
}

int main(){
    calculate();
    return 0;
}


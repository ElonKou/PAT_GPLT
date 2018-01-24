//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_028_判断素数.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 23 Jan 2018 11:03:32 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>
using namespace std;

long multi(int *list){
    int i = 0;
    long result = 1;
    while(list[i] != 0){
        result *= list[i++];
    }
    return result;
}

void suList(int *list){
    // init the list of su.
    int i = 2;
    for(i;i < 100;i++){
        //
    }
    while(multi(list) <= 2^31){
        i++;
    }
}

int isSu(long number,int bound){
    if(number %2 == 0&& number !=2 || number == 1){
        return 0;
    }else if(number == 2 ){
        return 1;
    }else{
        //判断是否是素数
        for(long i = 2;i < bound+1;i ++){
            if(number%i == 0){
                return 0;
            }
        }
        return 1;
    }
}



int main(){
    int num;
    cin >> num;
    int result[num] = {0};
    long number;
    
    int list[100];
    for(int i = 0;i<num;i++){
        cin >> number;
        int bound = sqrt(number);
        result[i] = isSu(number,bound);
    }
    for(int i=0;i<num-1;i++){
        if(result[i] == 1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    if(result[num-1] == 1){
        cout << "Yes";
    }else{
        cout << "No";
    }
    return 0;
}


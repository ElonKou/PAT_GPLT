//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_019_谁先倒.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 10:55:09 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
    int aAcount;
    int bAcount;
    int num;
    cin >> aAcount;
    cin >> bAcount;
    cin >> num;

    int a = 0;  // A喝了多少杯
    int b = 0;  // B喝了多少杯
    for(int i = 0;i < num ;i++){
            int ahan;
            int ahua;
            int bhan;
            int bhua;
            cin >> ahan;
            cin >> ahua;
            cin >> bhan;
            cin >> bhua;
            if(ahua == ahan+bhan && bhua != ahan+bhan){
                a++;
            }
            if(ahua != ahan+bhan && bhua == ahan+bhan){
                b++;
            }
            // 
            if(a == aAcount+1){
                cout<< "A" 
                    << endl
                    << b;
                    break;
            }
            if(b == bAcount+1){
                cout<< "B" 
                    << endl
                    << a;
                    break;
            }
    }
    return 0;
}


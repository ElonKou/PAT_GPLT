//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_037_A除以B.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 10:38:59 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int fenzi;
    int fenmu;
    cin >> fenzi;
    cin >> fenmu;
    cout<< fenzi
        << "/";
    if(fenmu == 0){
        cout<< fenmu << "=Error";
    }else{
        if(fenmu < 0){
            cout << "(";
        }
        cout << fenmu;
        if(fenmu < 0){
            cout << ")";
        }
        cout<< "="
            << setiosflags(ios::fixed) << setprecision(2)
            << fenzi/(fenmu*1.0);
    }
    
    
    return 0;
}


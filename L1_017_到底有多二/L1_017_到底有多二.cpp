//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_017_到底有多二.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 10:07:24 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    string str;
    cin >> str;
    int num = 0;
    int minus = 0;
    int even = 0 ;
    float times = 1;
    int count = 0;
    if(str[0] == '-'){
        minus = 1;
        str = str.substr(1,50);
    }
    int len = str.length();
    if((str[len-1]-'0')%2 == 0){
        even = 1;
    }
    for(int i = 0;i<len;i++){
        if((str[i]-'0')==2){
            count ++;
        }
    }
    times = (minus == 1)?((times+0.5)*(times+even)):(times+even);
    //cout<< "len:"<< len <<"mins:" <<minus << "even:" << even << "count:"<<count << "times:" << times << endl;
    float rate = (1.0)*count/len*times*100;
    cout << setiosflags(ios::fixed) << setprecision(2);
    cout << rate <<"%";
    return 0;
}


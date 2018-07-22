//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_056_猜数字.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 27 May 2018 03:53:20 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int num[cnt];
    // char name[cnt][8];
    string name[cnt];
    int sum = 0;
    for (int i = 0; i < cnt; i++) {
        cin >> name[i] >> num[i];
        sum += num[i];
    }
    float ave = sum * 1.0 / cnt / 2;
    int max = 0;
    float maxa = abs(num[0] - ave);
    for (int i = 0; i < cnt; i++) {
        if (abs(num[i] - ave) < maxa) {
            maxa = abs(num[i] - ave);
            max = i;
        }
    }
    cout << int(ave) << " " << name[max];
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_050_倒数第N个字符串.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 26 May 2018 10:37:03 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int len;
    long num;
    cin >> len;
    cin >> num;
    num--;
    int temp = 0;
    char cc[len];
    while (len > 1) {
        len--;
        temp = int(num / pow(26, len));
        num -= int(pow(26, len)) * temp;
        temp = 25 - temp;
        printf("%c", char(temp + 97));
    };
    temp = 25 - num;
    printf("%c", char(temp + 97));
    return 0;
}

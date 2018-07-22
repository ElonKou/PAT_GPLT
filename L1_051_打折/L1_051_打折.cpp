//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_051_打折.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 26 May 2018 11:51:23 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int price;
    int zhe;
    cin >> price >> zhe;
    printf("%.2f", price * zhe * 1.0 / 10);
    return 0;
}

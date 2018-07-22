//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_013_计算阶乘和.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 19 Jan 2018 10:42:22 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <climits>
#include <iostream>
using namespace std;

int main() {
    // 这题太简单
    int sum = 0;
    int count = 0;
    cin >> count;
    int temp = count;
    int subTemp = 0;

    // 两个循环分别计算求和和求阶乘
    while (temp > 0) {
        int subTemp = temp--;
        int sumTemp = 1;
        while (subTemp > 0) {
            sumTemp *= subTemp--;
        }
        sum += sumTemp;
    }
    cout << sum;
    return 0;
}

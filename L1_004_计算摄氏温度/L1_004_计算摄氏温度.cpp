// L1_004_计算摄氏温度.cpp
// Author:elonkou
// E-mail:elonkou@ktime.cc
// Date  :Tue 16 Jan 2018 10:19:23 PM CST

#include <iostream>
using namespace std;

int getCTemperature(int f) {
    // int f:	华氏温度
    return (int)5 * (f - 32) / 9;
}

int main() {
    // 华氏温度转摄氏温度
    int f;
    cin >> f;
    // 调用计算函数进行打印
    cout << "Celsius = " << getCTemperature(f);
    return 0;
}

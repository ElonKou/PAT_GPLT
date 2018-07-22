//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_042_日期格式化.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 01:56:58 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void printDate(void) {
    // 接收数据并且格式化输出
    string date;
    cin >> date;
    string month = date.substr(0, 2);
    string day = date.substr(3, 2);
    string year = date.substr(6, 4);
    cout << year << "-" << month << "-" << day;
}

int main() {
    // 格式化输出日期
    printDate();
    return 0;
}

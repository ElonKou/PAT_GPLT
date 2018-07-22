//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_021_重要的话说三遍.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 01:23:25 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#define TIMES 3
using namespace std;

void printThreeTimes() {
    for (int i = 0; i < TIMES - 1; i++) {
        cout << "I'm gonna WIN!" << endl;
    }
    cout << "I'm gonna WIN!";
}

int main() {
    // 重要的话说三遍
    printThreeTimes();
    return 0;
}

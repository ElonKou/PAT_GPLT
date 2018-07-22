//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_041_寻找250.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 23 Jan 2018 10:53:46 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    int number;
    cin >> number;
    int count = 1;
    while (number != 250) {
        count++;
        cin >> number;
    }
    cout << count;
    return 0;
}

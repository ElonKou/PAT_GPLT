//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_055_谁是赢家.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 27 May 2018 03:19:52 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    int pa, pb;
    int a, b, c;
    cin >> pa >> pb >> a >> b >> c;
    if (pa > pb && (a == 0 || b == 0 || c == 0)) {
        cout << "The winner is a: " << pa << " + " << 3 - a - b - c;
    } else if (pa < pb && (a == 0 && b == 0 && c == 0)) {
        cout << "The winner is a: " << pa << " + " << 3 - a - b - c;
    } else {
        cout << "The winner is b: " << pb << " + " << a + b + c;
    }
    return 0;
}

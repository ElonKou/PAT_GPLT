//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_024_后天.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 11:49:39 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    int today = 0;
    cin >> today;
    if ((today + 2) % 7 == 0) {
        cout << 7;
    } else {
        cout << (today + 2) % 7;
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_035_情人节.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 28 Jan 2018 12:26:34 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    string list[14];
    string str;
    cin >> str;
    int i = 0;
    while (str != ".") {
        if (i < 14) {
            list[i] = str;
        }
        i++;
        cin >> str;
    }
    if (i >= 14) {
        cout << list[1] << " and " << list[13]
             << " are inviting you to dinner...";
    } else if (i >= 2) {
        cout << list[1] << " is the only one for you...";
    } else {
        cout << "Momo... No one is for you ...";
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_026_I_Love_GPLT.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 10:53:53 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    string str = "I Love GPLT";
    int i = 0;
    for (i = 0; i < str.length() - 1; i++) {
        cout << str[i] << endl;
    }
    cout << str[i];
    return 0;
}

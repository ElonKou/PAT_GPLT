//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_031_到底是不是太胖了.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 27 Jan 2018 08:02:37 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <iostream>
using namespace std;

int isPang(int height, int weight) {
    int res = 0;
    float standard = (height - 100) * 0.9 * 2;
    if (abs(weight - standard) / standard > 0.1 && weight > standard) {
        res = 1;
    }
    if (abs(weight - standard) / standard > 0.1 && weight < standard) {
        res = -1;
    }
    return res;
}

int main() {
    // 到底是不是太胖了
    int num;
    cin >> num;
    int result[num];
    int height;
    int weight;
    for (int i = 0; i < num; i++) {
        //
        cin >> height;
        cin >> weight;
        result[i] = isPang(height, weight);
    }
    for (int i = 0; i < num; i++) {
        if (result[i] == 0) {
            cout << "You are wan mei!";
        }
        if (result[i] == 1) {
            cout << "You are tai pang le!";
        }
        if (result[i] == -1) {
            cout << "You are tai shou le!";
        }
        if (i != num - 1) {
            cout << endl;
        }
    }
    return 0;
}

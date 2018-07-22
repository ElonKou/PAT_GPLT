//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_018_大笨钟.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 11:00:58 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int hour = 0;
    int mins = 0;
    scanf("%d:%d", &hour, &mins);
    int times = 0;
    times = (hour > 12) ? (hour - 12) : 0;
    times = (hour >= 12 && mins > 0) ? (times + 1) : times;
    if (times != 0) {
        for (int i = 0; i < times; i++) {
            cout << "Dang";
        }
    } else {
        cout << "Only ";
        cout.width(2);
        cout.fill('0');
        cout << hour << ":";
        cout.width(2);
        cout.fill('0');
        cout << mins << ".  Too early to Dang.";
    }
    return 0;
}

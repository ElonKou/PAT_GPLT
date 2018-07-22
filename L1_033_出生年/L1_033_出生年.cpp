//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_033_出生年.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 25 Jan 2018 10:06:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int isNum(int year, int num) {
    //
    int arr[10] = {0};
    for (int i = 0; i < num; i++) {
        arr[year % ((int)pow(10, i + 1)) / (int)(pow(10, i))] = 1;
        // arr[year%(10^(i+1))/10^i] = 1;
    }
    int count = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int year;
    int num;
    cin >> year;
    cin >> num;
    int count = 0;
    for (; isNum(year, 4) != num;) {
        count++;
        year++;
    }
    printf("%d %04d", count, year);
    return 0;
}

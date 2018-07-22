//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_022_奇偶分家.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 11:34:01 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    // 奇数偶数分家
    int even = 0;
    int odd = 0;
    int count = 0;
    cin >> count;
    int number;
    for (int i = 0; i < count; i++) {
        cin >> number;
        if (number % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    cout << odd << " " << even;
    return 0;
}

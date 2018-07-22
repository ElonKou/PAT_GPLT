//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_006_连续因子.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Fri 16 Feb 2018 05:46:10 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <iostream>
#define MAX_ 12  // the 2^31 won't larger MAX_!
using namespace std;

int main() {
    // we can use loop to bilud  some array numwers,and chacek it if will out of
    // the input number. the most shortest array containes longest number set.
    int num, top;
    cin >> num;
    top = sqrt(num);
    for (int len = MAX_; len >= 1; len--) {
        for (int index = 2; index <= top; index++) {
            long long int result = 1;
            for (int i = index; i - index <= len - 1; i++) {
                result *= i;
            }
            if (num % result == 0) {
                cout << len << endl << index;
                for (int i = index + 1; i - index <= len - 1; i++) {
                    cout << "*" << i;
                }
                return 0;
            }
        }
    }
    cout << 1 << endl << num;
    return 0;
}

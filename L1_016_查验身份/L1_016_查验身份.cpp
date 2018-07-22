//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_016_查验身份.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 02:01:54 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int check(string str, int const* weight, char const* checkCode) {
    int sum = 0;
    int ok = 1;
    for (int i = 0; i < 17; i++) {
        if (str[i] != 'X') {
            sum += (str[i] - '0') * weight[i];
        } else {
            ok = 0;
        }
    }
    // cout << sum << ":" << sum%11 <<endl;
    // cout << ":" << checkCode[sum%11] <<":" << endl;
    if (ok != 1 || checkCode[sum % 11] != str[17]) {
        ok = 0;
        // cout << str << endl;
    }
    return ok;
}

void checkAndPrint(int count) {
    string strs[count];
    int oks[count];
    int const weight[17] = {7, 9, 10, 5,  8, 4, 2, 1, 6,
                            3, 7, 9,  10, 5, 8, 4, 2};
    char const checkCode[11] = {'1', '0', 'X', '9', '8', '7',
                                '6', '5', '4', '3', '2'};
    for (int i = 0; i < count; i++) {
        cin >> strs[i];
        oks[i] = check(strs[i], weight, checkCode);
    }
    int okNumber = 0;
    for (int i = 0; i < count; i++) {
        okNumber += oks[i];
    }
    if (okNumber == count) {
        cout << "All passed";
    } else {
        for (int i = 0; i < count; i++) {
            if (oks[i] == 0) {
                cout << strs[i] << endl;
            }
        }
    }
}

int main() {
    // 查验身份证信息
    int count = 0;
    cin >> count;
    checkAndPrint(count);
    return 0;
}

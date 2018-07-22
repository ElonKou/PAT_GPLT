//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_040_最佳情侣身高差.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 02:25:39 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    // 计算最佳情侣身高差
    int count;
    float height;
    char sex;
    cin >> count;
    float result[count];
    for (int i = 0; i < count; i++) {
        cin >> sex;
        cin >> height;
        if (sex == 'M') {
            result[i] = height / 1.09;
        } else {
            result[i] = height * 1.09;
        }
    }
    int i = 0;
    for (i = 0; i < count - 1; i++) {
        cout << setiosflags(ios::fixed) << setprecision(2) << result[i] << endl;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << result[i];
    return 0;
}

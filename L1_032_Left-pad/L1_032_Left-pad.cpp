//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_032_Left-pad.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 27 Jan 2018 10:18:55 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    int num;
    char c;
    string str;  // 存储源字符串的内容
    cin >> num;  // 对所有的源数据进行输入
    cin >> c;
    cin.get();
    getline(cin, str);
    int len = str.length();  // 获得需要循环的长度
    char st[num];            // 存放修改之后的字符串
    if (len >= num) {
        // 复制最后几位的字符串
        for (int i = 0; i < num; i++) {
            st[num - i - 1] = str[len - i - 1];
        }
    } else {
        int i = 0;
        for (i = 0; i < len; i++) {
            st[num - i - 1] = str[len - i - 1];
        }
        for (i; i < num; i++) {
            st[num - i - 1] = c;
        }
    }
    // 输出所输入的数组
    for (int i = 0; i < num; i++) {
        cout << st[i];
    }
    return 0;
}

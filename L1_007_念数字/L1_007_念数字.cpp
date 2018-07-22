//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_007_念数字.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 01:34:36 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void printNum(string data) {
    // string data:	接收的字符串因为需要进行转换为对应字典的下标,
    // 因此用字符串存储比较方便

    const char* dict[] = {"ling", "yi",  "er", "san", "si",
                          "wu",   "liu", "qi", "ba",  "jiu"};
    int index = 0;

    // 打印单独的'-'号,index需要自增1进行重定位
    if (data[index] == '-') {
        cout << "fu ";
        index++;
    }
    cout << dict[data[index] - '0'];
    while (++index < data.length()) {
        cout << " " << dict[data[index] - '0'];
    }
}

int main() {
    // 输出一行数字对应的拼音
    string data;
    cin >> data;
    printNum(data);  // 调用函数进行输出
    return 0;
}

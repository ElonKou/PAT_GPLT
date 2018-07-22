//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_044_稳赢.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 23 Jan 2018 05:41:29 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cstdlib>
#include <iostream>
using namespace std;

void calculate() {
    // 接收参数并且进行处理
    int num = 0;
    cin >> num;
    string arr[3] = {
        "Bu", "JianDao",
        "ChuiZi"};  // 存储所需要的数据,该数组的设置有技巧,按照书顺序进行输入,后一个总是会赢前一个,方便计算赢家
    int list[10000];  // 此处可能会被测试多个数据
    int index = 0;    // 用于标记访问的位置,计算总共有多少输入
    string str;
    cin >> str;             // str存储每次的输入结果
    while (str != "End") {  // 检查是否是结束标志,否知继续进行
        int result = 0;
        for (int i = 0; i < 3; i++) {  // 该for循环负责处理所有的输入数据
            if (str == arr[i]) {
                result = i;
            }
        }
        if ((index + 1) % (num + 1) != 0 ||
            index == 0) {  // 对每个数据进行检查,计算该输入项所对应的数据的下标
            result = (result + 1) % 3;  // result为必赢的方式
        }
        list[index] = result;
        index++;
        cin >> str;
    }
    for (int i = 0; i < index; i++) {  // 该循环将每次的输入结果转换为输出结果
        cout << arr[list[i]];  // 依次输出
        if (i != index) {
            cout << endl;
        }
    }
}

int main() {
    calculate();  // 接收到输入的数据并且进行计算处理
    return 0;
}

// L1_003_个位数统计.cpp
// Autuor:elonkou
// E-mail:elonkou@ktime.cc
// Date  :Tue 16 Jan 2018 09:31:40 PM CST

#include <iostream>
#include <string>
using namespace std;

void count(int* length, string str) {
    // int *lenth:	指向每个位出现信息的数组的指针,在该函数中会进行修改
    // string str:	输入的字符串
    int number = str.length();
    while (number >= 0) {
        // 每个位都是一个ACSII的字符,减去'0'的ACSII码即可得到该位的数，
        // 注意在实际应用中应该考虑其他超过0-9的有可能越界
        length[str[--number] - '0']++;
    }
}

void printArray(int* length, int len) {
    // 对数组进行遍历并打按照格式打印
    // int *length:	数组指针
    // int len:		数组长度
    for (int i = 0; i < len; i++) {
        if (length[i] != 0) {
            cout << i << ":" << length[i] << endl;
        }
    }
}

int main() {
    // 统计一个很长的数数每个位出现的个数,并且按照D :M的格式打印
    // 注:由于数据很长,不能用一般的整型数据进行存放,所以可以将整个
    // 数作为一个字符串,通过字符串解决输入的问题
    // Examples:
    // [2619691]
    // 1 :2
    // 2 :1
    // 6 :2
    // 9 :2
    string str;
    cin >> str;
    int length[10] = {0};    //存放每个位的出现的次数的数组
    count(length, str);      //统计每个位出现次数
    printArray(length, 10);  //按照格式打印
    return 0;
}

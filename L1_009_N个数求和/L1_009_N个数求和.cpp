//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_009_N个数求和.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 06:50:11 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <cmath>
#include <iostream>
#include <sstream>

#define WIDTH 2
#define RESULT 3

using namespace std;

void writeOne(long (*data)[WIDTH],
              int row,
              int start,
              int separate,
              int end,
              string str) {
    int mid = (separate == start) ? end : separate;
    string substr = "";
    for (int index = start; index < mid; index++) {
        substr += str[index];
    }
    stringstream ss;
    ss << substr;
    ss >> data[row][0];
    //
    if (separate == start) {
        //
        data[row][1] = 1;
    } else {
        //
        string substrr = "";
        for (int index = separate + 1; index < end; index++) {
            substrr += str[index];
        }
        stringstream sss;
        sss << substrr;
        sss >> data[row][1];
    }
    // cout << data[row][0] << "/" << data[row][1] << endl;
}

void inputOne(string str, int* start, int* separate, int* end) {
    //
    int len = str.length();
    int index = 0;
    *start = 0;
    *separate = 0;
    *end = 0;
    for (index = 0; index < len; index++) {
        if (str[index] == '/') {
            *separate = index;
        }
    }
    *end = index;
}

void getInput(long (*data)[WIDTH], int size) {
    //
    for (int i = 0; i < size; i++) {
        int start = i;
        int separate = i;
        int end = i;
        string str;
        cin >> str;
        inputOne(str, &start, &separate, &end);
        // 得到起始位置,分隔符位置,终点位置,调用函数转换为整型数据
        writeOne(data, i, start, separate, end, str);
    }
}

void switchNumber(long* a, long* b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

long getMaxFactor(long numa, long numb) {
    // 得到最大公约数
    // cout << endl << numa << "--" << numb <<endl ;
    long max = 1;
    if (numb == numa) {
        max = numa;
    }
    // cout << "numa:" << numa << ": numb" << numb ;
    while (numb != numa) {
        if (numa < numb) {
            switchNumber(&numa, &numb);
        }
        //
        if (numa % numb == 0) {
            max = numb;
            break;
        }
        numa = numa % numb;
    }
    // cout << max << endl;
    return max;
}

long getMinFactor(int numa, int numb) {
    // 计算最小公倍数
    // 先计算最大公约数
    // long multi = numa * numb;
    long max = getMaxFactor(numa, numb);
    // 求出了公约数,明天继续
    // cout << max << ":" << multi/max << endl;
    return numa / max * numb;
}

void readyCalculate(long (*data)[WIDTH], int size) {
    // 将所有的的输入结果进行通分
    long minMultiple = data[0][1];
    for (int i = 1; i < size; i++) {
        minMultiple = getMinFactor(minMultiple, data[i][1]);
    }
    // cout << ":" << minMultiple << endl;
    // 得到了最小公倍数之后
    for (int i = 0; i < size; i++) {
        data[i][0] = minMultiple / data[i][1] * data[i][0];
        data[i][1] = minMultiple;
        // cout << data[i][0] << "->" << data[i][1] << endl;
    }
}

void calculate(long (*data)[WIDTH], int size, long* result) {
    // 求出分子是之和
    long sumUp = 0;
    for (int i = 0; i < size; i++) {
        sumUp += data[i][0];
    }
    int type = (sumUp > 0) ? 1 : -1;
    // cout<< "sum:" << sumUp << endl;
    sumUp = abs(sumUp);
    // 得到最大公约数,进行约分
    long factor;
    if (sumUp != 0) {
        factor = getMaxFactor(sumUp, data[0][1]);
    } else {
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
        return;
    }
    // cout<< "factor:" << factor << endl;
    sumUp = type * sumUp / factor;
    // cout<< "sum:" << sumUp << endl;
    result[2] = data[0][1] / factor;
    result[1] = sumUp % result[2];
    result[0] = sumUp / result[2];
}

void printResult(long* result) {
    if (result[0] != 0) {
        cout << result[0];
        if (result[1] != 0) {
            cout << " ";
        }
    }
    if (result[1] != 0) {
        cout << result[1] << "/";
        cout << result[2];
    }
    if (result[0] == 0 && result[1] == 0 && result[2] == 0) {
        cout << "0";
    }
}

int main() {
    int size = 0;
    cin >> size;
    long dataSet[size][WIDTH];
    long result[RESULT];

    getInput(dataSet, size);
    readyCalculate(dataSet, size);
    calculate(dataSet, size, result);
    printResult(result);
    return 0;
}

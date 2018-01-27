//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_034_点赞.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 27 Jan 2018 11:12:54 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    // 点赞的数量统计 
    int num;
    cin >> num;
    int info[1001] = {0};
    int width;
    for(int i =0;i < num;i++){
        // 输入每个数据
        cin >> width;
        for(int j = 0;j < width; j++){
            int temp;
            cin >> temp;
            info[temp] ++;
        }
    }
    // 检查最大的数据进行输出
    int max = 0;
    int maxNum = 0;
    for(int i = 1;i <= 1000;i++){
        if(maxNum <= info[i]){
            max = i;
            maxNum = info[i];
        }
    }
    cout << max << " " << maxNum;
    return 0;
}


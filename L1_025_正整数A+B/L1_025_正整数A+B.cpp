//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_025_正整数A+B.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 27 Jan 2018 06:21:33 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <string>
using namespace std;

int isNum(string str){
    // 检查字符串是否是是正整数
    // 是则返回1
    // 不是则返回0
    int is = 1;
    int len = str.length();
    for(int i = 0;i < len;i++){
        if((str[i]-'0') < 0 || (str[i] - '0') >9){
            is = -1;
            break;
        }
    }
    // 转换为int数字
    if(is != -1){
        is = atoi(str.c_str());
    }
    // 检查是否超出最大范围
    if(is < 1 || is > 1000){
        is = -1;
    }
    return is;
}

int main(){
    string input;
    getline(cin,input);
    int length = input.length();
    int i = 0;
    for(i = 0;i < length;i++){
        if(input[i] == ' '){
            break;
        }
    }
    string a = input.substr(0,i);
    string b = input.substr(i+1,length-i-1);
    // 需要检查是否是空字符
    int numa = isNum(a);
    int numb = isNum(b);
    //
    if(numa != -1){
        cout << numa ;
    }else{
        cout << "?";
    }
    cout << " + ";
    if(numb != -1){
        cout << numb ;
    }else{
        cout << "?";
    }
    cout << " = ";
    if(numa !=-1 && numb != -1){
        cout << numa+numb;
    }else{
        cout << "?";
    }
    //cout << ":";
    return 0;
}


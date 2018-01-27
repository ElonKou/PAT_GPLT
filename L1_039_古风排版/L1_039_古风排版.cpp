//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_039_古风排版.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 28 Jan 2018 01:04:43 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main(){
    // 输入古文格式的文字,并且进行排版
    int height;
    cin >> height;
    cin.get();
    string str;
    getline(cin,str); 
    int len = str.length();
    int width = (len+height-1)/height;
    char arr[height][width] = {" "};
    int index = 0;
    for(int i = width-1;i >= 0;i--){
        for(int j = 0;j< height;j++){
            if(index < len){
                arr[j][i] = str[index++];
            }else{
                arr[j][i] = ' ';
            }
        }
    }
    for(int i = 0; i<height;i++){
        for(int j = 0;j< width;j++){
            cout << arr[i][j];
        }
        if(i != height-1){
            //
            cout << endl;
        }
    }
    return 0;
}


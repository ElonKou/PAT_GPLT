//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_046_整除光棍.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 08:58:18 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <sstream> 
#define WIDTH 1024

using namespace std;

int getLength(int number){
    // 得到一个数字的长度
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str.length();
}

void print(int *temp){
    // 打印一个数组的信息
    cout << endl;
    for(int i = 0;i<64;i++){cout << "++";}
    for(int i = 0;i < WIDTH ; i++){
        if(i%64 == 0){
            cout << "+" << endl;
        }
        cout << temp[i] << " ";
    }
    cout << "+" << endl << "+";
    for(int i = 0;i<64;i++){cout << "++";}
}


void initArr(int *temp){
    // 初始化数组
    for(int i = 0;i<WIDTH;i++){
        temp [i] = 1;
    }
    print(temp);
}

void initNum(int *num,int number,int length){
    stringstream ss;
    ss << number;
    string str = ss.str();
    for(int i = 0;i<length;i++){
        num[i] = str[length-i-1];
    }
}

int sumHeight(int (*arr)[WIDTH],int length,int pos){
    // 计算一个数组的高度
    int sum = 0;
    for(int i = 1;i < length+1;i++){
        sum +=arr[pos][i];
    }
    return sum;
}

int getFirst(int result,int){
    //
}

int check(int *arr,int pos,int sum){
    // 检查是否足够减去,是否需要借位,如果是则进行借位
    int borrow = 0;
    for(;(borrow*10+arr[pos]-sum) < 0;){
        borrow++;
    }
    return borrow;
}

int Multiplicatived(int numa,int numlast,int *numb){
    // 计算被乘数
    int jiewei = 0;
    for(int jiewei =0;jiewei < 10;jiewei++){
        if((jiewei*10+numa)%numlast == 0){
            break;
        }
    }
    *numb = (jiewei*10+numa)/numlast;
    return jiewei;
}

void updateOthers(int *arr,int pos,int numa,int numb,int bias){
    arr[pos+bias] = (numa * numb)%10;
    arr[pos+1+bias] = (numa * numb)/10;
}

void updateOne(int (*arr)[WIDTH],int length,int pos,int sum,int num[]){
    // 更新第一行的一个元素
    int jiewei = arr[length+2][pos];                        // 当前的借位
    int borrow = check(*arr+length+1,pos,sum+jiewei);       // 计算下一步的借位
    arr[length+2][pos+1] = borrow;                          // 写入下一步的借位
    arr[1][pos] = borrow*10+arr[length+1][pos] - sum - jiewei;    // 计算借位之后的数值
    // 根据当前位置的数字和乘数,计算新的被乘数
    int anotherJiewei = Multiplicatived(arr[1][pos],num[0],&arr[0][pos]);
    for(int i = 0;i<length;i++){
        updateOthers(*arr+1+i,pos,num[i],arr[0][pos],i);
    }

}

void inputAndCalucate(){
    int number;
    cin >> number;
    int length = getLength(number);
    int num[length] = {0};
    initNum(num,number,length);
    int height = length + 3;
    int arr[height][WIDTH] = {0};           // 该数组存储所有的信息
    initArr(*arr+length+1);
    for(int i = 0 ; i < WIDTH;i ++){
        int sum = sumHeight(arr,length,i);  // 计算该列的和
        updateOne(arr,length,i,sum,num);    // 计算更新每一列
    }
    //cout << arr[0];
    print(arr[0]);
}

int main(){
    // 整除光棍
    // 这道题比较有有意思
    inputAndCalucate();
    return 0;
}


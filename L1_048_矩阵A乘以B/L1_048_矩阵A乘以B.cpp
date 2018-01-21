//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_048_矩阵A乘以B.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 03:44:54 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void printArr(int ** arr,int row,int col){
    //arr[2][11] = 9;
    //*((int *)arr+2*col+11) = 9;
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout << *((int *)arr+i*col+j);
            if(j != (col-1)){
                cout << " ";
            }
        }
        if(i != (row-1)){
            cout << endl;
        }
    }
}

void multiSum(int **arr,int **brr,int ra,int cb,int len,int **result){
    // 求乘积之和
    for(int i = 0;i < ra;i++){
        for(int j = 0;j < cb;j++){
            int sum = 0;
            for(int k = 0;k<len;k++){
                //sum += (arr[i][k]) * (brr[k][j]);
                sum +=  (*((int *)arr+i*len+k)) * (*((int *)brr+k*cb+j));
            }
            *((int *)result+i*cb+j) = sum;
        }
    }
}

int main(){
    int ra,ca;
    cin >> ra;
    cin >> ca;
    int arr[ra][ca] = {0};
    
    for(int i = 0;i < ra; i++){
        for(int j = 0;j < ca; j++){
            cin >> arr[i][j];
        }
    }

    int rb,cb;
    cin >> rb;
    cin >> cb;
    int brr[rb][cb] = {0};
    for(int i = 0;i < rb;i++){
        for(int j = 0;j < cb;j++){
            cin >> brr[i][j];
        }
    }
    // 开始处理
    int result[ra][cb] = {0};
    if(ca != rb){
        cout << "Error: " << ca <<" != " << rb;
    }else{
        // 计算
        multiSum((int **)arr,(int **)brr,ra,cb,ca,(int **)result);
        cout << ra <<" "<< cb << endl;
        printArr((int **)result,ra,cb);
    }
    return 0;
}


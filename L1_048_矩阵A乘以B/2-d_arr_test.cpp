//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  2-d_arr_test.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 21 Jan 2018 05:24:28 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>

using namespace std;


void noname(int ** arr,int row,int col){
    //arr[2][11] = 9;
    *((int *)arr+2*col+11) = 9;
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            cout << *((int *)arr+i*col+j);
        }
        cout << endl;
    }
}

int main(){
    // 传递二维数组的指针,并且对其在子函数中进行修改 
    int arr[10][20] = {111};
    int row = 4;
    int col = 20;

    cout << arr[2][11] << endl;
    noname((int **)arr,row,col);
    cout << "after:" <<endl;
    cout << arr[2][11] << endl;

    //double zzz[i][j] = *((double*)zzz+i*col+j);

    return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_020_帅到没朋友.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 03:18:04 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct {
    int num;
    int arr[1000];
}quan;

typedef struct all{
    int quanNum;
    quan list[100];
}*allList;

int check(allList L,int num){
    int handsome = 0;
    int isin = 0;
    for(int i = 0;i< (L->quanNum);i++){
        for(int j = 0;j < (L->list[i].num);j++){
            if(num == L->list[i].arr[j] && L->list[i].num > 1){
                isin = 1;
            }
        }
    }
    if(isin == 0){
        handsome = 1;
    }
    return handsome;
}

void reduceduplicate(int *result,int *output,int size){
    for(int i =0;i<size;i++){
        for(int j = 0;j<i;j++){
            if(output[i] == output[j]){
                result[i] = 0;
                break;
            }
        }
    }
}

int main(){
    allList L =(allList)malloc(sizeof(all));
    cin >> L->quanNum;
    for(int i =0 ;i<L->quanNum;i++){
        cin >> (L->list[i]).num;
        for(int j =0;j < (L->list[i]).num;j++){
            cin >> (L->list[i]).arr[j];
        }
    }
    // 输入查询数据
    int checkNum;
    cin >> checkNum;
    int checkList[checkNum];        // 需要查询的数
    int result[checkNum];           // 查询到的结果
    int output[checkNum];
    
    int index = 0;
    for(int i = 0;i < checkNum;i++){
        cin >> checkList[i];
        int res = check(L,checkList[i]);
        if(res == 1){
            output[index] = checkList[i];
            result[index ++] = res;
        }
    }
    reduceduplicate(result,output,index);
    int start = 0;
    if(result[index] == 0){
        cout << "No one is handsome";
        return 0;
    }else{
        cout << output[start++];
    }

    for(int i = start;i < index ;i++){
        if(result[i] != 0 ){
            cout << " " << output[i];
        }
    }
    // 进行查询输出
    return 0;
}


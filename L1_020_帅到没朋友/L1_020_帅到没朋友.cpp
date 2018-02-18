//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_020_帅到没朋友.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 03:18:04 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct {
    int num;
    int arr[1001];
}quan;

typedef struct all{
    int quanNum;
    quan list[100];
}*allList;

int checkHandsome(int num,int *target){
	// 检查是否和作者一样帅气
	if(target[num] == 0 || target[num] == 1){	// 朋友圈数量为1表示只有一个人,0表示没有加入任何朋友圈
		target[num] = 2;					// 朋友圈数量设置为2,防止重复进行检查的时候多次输出
		return 1;
	}
	return 0;
}

int main(){
    allList L = new all;
    int target[100000] = {0};				// 标记每个人所在朋友圈的人数,使用标记数组有效降低规模变化带来的指数爆炸效应
	cin >> L->quanNum;

    for(int i = 0 ;i < L->quanNum;i++){
        cin >> (L->list[i]).num;
        for(int j =0;j < (L->list[i]).num;j++){
			int data = 0;
			cin >> data ; 
            L->list[i].arr[j] = data;
			target[data] = max(target[data],L->list[i].num);	// 将每个人所加入的最多的朋友圈的个数作为最终个数,可以建多个重复的数组存储在一起不影响最后结果
        }
    }
	
	int checkNum;							// 查询的所有人的数量
    cin >> checkNum;
    int checkList[checkNum];        		// 输入需要查询的数
    for(int i = 0;i < checkNum;i++){		// 依次输入
		cin >> checkList[i];
    }

    int count = 0;    						// 统计帅气的小伙子的数量,用于控制输出
	for(int i = 0;i < checkNum;i++){
		int res = checkHandsome(checkList[i],target);
		if(res == 1){
			count ++;
			if(count == 1){
				cout << setw(5) << setfill('0') << checkList[i];
			}else{
				cout << " " << setw(5) << setfill('0') << checkList[i];
			}
		}
	}
	if(count == 0){
		cout << "No one is handsome";
	}
    return 0;
}


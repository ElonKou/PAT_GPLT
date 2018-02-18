//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_020_帅到没朋友.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 24 Jan 2018 03:18:04 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cstdlib>
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

int check(allList L,int num,int *target){
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

void reduceduplicate(int *output,int *target,int size){
    for(int i = 0;i < size;i++){
        target[output[i]] = 1;
		//for(int j = i+1;j<size;j++){
            //if(output[i] == output[j]){
                //output[j] = -1;
                //break;
            //}
        //}
    }
}


int main(){
    //allList L =(allList)malloc(sizeof(all));
    allList L = new all;
    cin >> L->quanNum;
    for(int i = 0 ;i<L->quanNum;i++){
        cin >> (L->list[i]).num;
        for(int j =0;j < (L->list[i]).num;j++){
            cin >> (L->list[i]).arr[j];
        }
    }
    // 输入查询数据
    int checkNum;
    cin >> checkNum;
    int checkList[checkNum];        // 输入需要查询的数
    int output[checkNum];			// 计算得到handsome的数据
    int target[100000] = {0};		// 进行标记的数组,防止大规模的数据计算的时候,计算时间非常高
    
    int index = 0;
    for(int i = 0;i < checkNum;i++){
        int num;
		cin >> num;
		checkList[i] = num;
		target[num] = 1;
        int res = check(L,checkNum,target);
		//
        if(res == 1){
            output[index++] = checkList[i];
        }
    }
    reduceduplicate(output,target,index);

    int count = 0;
    
	for(int i = 0;i < index ;i++){
		if(target[output[i]] == 1){
			count ++;
			target[output[i]] --;
			
			if(count == 1){
				cout << setw(5) << setfill('0');
				cout << output[i];
			}else{
				cout << " " << setw(5) << setfill('0') << output[i];
			}
		}

		//if(output[i] != -1){
			//count ++;
			//if(count == 1){
				//cout << setw(5) << setfill('0');
				//cout << output[i];
			//}else{
				//cout << " " << setw(5) << setfill('0') << output[i];
			//}
		//}	
	}
	if(count == 0){
		cout << "No one is handsome";
	}
    return 0;
}


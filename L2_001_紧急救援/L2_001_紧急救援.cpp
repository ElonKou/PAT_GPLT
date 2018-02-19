//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_001_紧急救援.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 18 Feb 2018 05:51:38 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

struct road{
	int start,end,length;
};

struct city{
	int aidCnt;
};

void print(road r[500][500]){
	for(int i = 0;i < 4;i++){
		for(int j = 0;j < 4;j++){
			if(r[i][j].length == 0){
				cout << "*";
			}else{
				cout << r[i][j].length;
			}
		}
		cout << endl;
	},
}

void min(road *info,int length,int &start,int &end,int data){
	// 计算条路径上的最小值,对其中的出发地点进行修改
	for(int i = 0;i < length;i++){
		if(info[i].length != 0 && info[i].length < data){
			start = jide;
		}
	}
}

void dijkstra(int start,int end,road (*info)[500][500],int cityCnt){
	for(){
		//
	}
}

int main(){
	int cityCnt;
	int roadCnt;
	int start,end;
	cin >> cityCnt >> roadCnt >> start >> end;
	road info[500][500] = {0};
    city cities[cityCnt] = {{0}};
	// input 
	for(int i = 0;i < cityCnt;i++){
		cin >> cities[i].aidCnt;
	}
	for(int i = 0;i < roadCnt;i++){
		road r;
		cin >> r.start >> r.end >> r.length;
		info[r.start][r.end] = info[r.end][r.start] = r;
	}
	//print(info);
	dijkstra(start,end,info,cityCnt);
	return 0;
}


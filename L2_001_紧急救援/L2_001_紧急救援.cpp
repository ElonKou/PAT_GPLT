//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_001_紧急救援.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Mon 29 Jan 2018 11:12:58 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

typedef struct road{
   int start;       // 开始id
   int end;         // 结束id
   int length;      // 道路长度
   road *next;
}road;

typedef struct{
    int id;         // id
    int count;      // 救援队数量
    road *roads;    // 指向的道路数量
    road *endRoad;
}city;

void calculate(city cities[],int cityNum,int roadNum,int start, int end){
    // 计算路径数量和人数
    int dist[cityNum] = {0};        // 使用dijkstra算法进行求解最短路径
    int path[cityNum];              // 记录经过的路径
    //int count// 
    for(int i =0;i < cityNum;i++){
        //for(){
            ////
        //}
    }
}

int main(){
    // 紧急救援
    int cityNum;
    int roadNum;
    int start,end;
    cin >> cityNum >> roadNum >> start >> end;
    // 获得所有的城市信息的输入
    // 并且将所有城市呢道路信息的初始化
    city cities[cityNum];
    for(int i = 0; i < cityNum;i++){
        cities [i].id = i;
        cin >> cities[i].count;
        road *r = (road *)malloc(sizeof(road));     // 创建一个新的空指针指向初始位置
        r -> next = NULL;
        cities[i].roads = r;
        cities[i].endRoad = r;
    }
    // 获得所有的road信息
    for(int i = 0 ;i < roadNum;i++){
        int st,en,le;
        cin >> st >> en >> le;
        
        road *r = (road *)malloc(sizeof(road));
        r -> start = st;
        r -> end = en;
        r -> length = le;
        r -> next =NULL;
        cities[st].endRoad->next = r;
        cities[st].endRoad = r;
        
        r = (road *)malloc(sizeof(road));
        r -> start = en;
        r -> end = st;
        r -> length = le;
        r -> next =NULL;
        cities[en].endRoad->next = r;
        cities[en].endRoad = r;
    }
    return 0;
}


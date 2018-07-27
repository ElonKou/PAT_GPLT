//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File   :dijistra.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :2018年07月25日 星期三 14时40分15秒
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#define LEN 6
using namespace std;

void printPath(string (&path)[LEN]) {
    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            // cout << path[i][j];
            if (path[i][j] > 0) {
                char c = path[i][j] + 1;
                cout << c;
            }
        }
        cout << endl;
    }
}

void dijistra(int (&arc)[LEN][LEN],
              string (&path)[LEN],
              int (&dis)[LEN],
              int start) {
    bool tag[LEN];
    for (int i = 0; i < LEN; i++) {
        dis[i] = arc[start][i];
        path[i] = to_string(start) + to_string(i);
    }

    dis[start] = 0;
    tag[start] = true;
    int cnt = 1;
    while (cnt != LEN) {
        int minValue = INT_MAX;
        int minPath = 0;
        for (int j = 0; j < LEN; j++) {
            if (!tag[j] && dis[j] < minValue) {
                minValue = dis[j];
                minPath = j;
            }
        }
        cnt++;
        tag[minPath] = true;
        for (int j = 0; j < LEN; j++) {
            if (!tag[j] && arc[minPath][j] != INT_MAX &&
                (dis[minPath] + arc[minPath][j]) < dis[j]) {
                dis[j] = dis[minPath] + arc[minPath][j];
                path[j] = path[minPath] + to_string(j);
            }
        }
    }
}

int main() {
    int arc[LEN][LEN] = {
        {INT_MAX, INT_MAX, 10, INT_MAX, 30, 100},
        {INT_MAX, INT_MAX, 5, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 50, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 10},
        {INT_MAX, INT_MAX, INT_MAX, 20, INT_MAX, 60},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}};
    int start = 0;
    int dis[LEN];
    string path[LEN];
    dijistra(arc, path, dis, start);
    printPath(path);
    return 0;
}

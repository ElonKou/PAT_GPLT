//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_001_紧急救援.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 18 Feb 2018 05:51:38 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#define LEN 500
using namespace std;

// void print(int (&roads)[LEN][LEN]) {
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 4; j++) {
//             if (roads[i][j] == INT_MAX) {
//                 cout << "∞";
//             } else {
//                 cout << roads[i][j];
//             }
//         }
//         cout << endl;
//     }
// }

int calcCost(int (&aids)[LEN], string path) {
    int len = 0;
    for (int i = 0; i < path.size(); i++) {
        // cout << path[i] << ":" << endl;
        len += aids[path[i] - '0'];
    }
    return len;
}

void run(int (&roads)[LEN][LEN],
         int (&aids)[LEN],
         int (&dis)[LEN],
         int (&pathCnt)[LEN],
         int roadCnt,
         int cityCnt,
         string (&path)[LEN],
         int start) {
    bool tag[LEN];
    for (int i = 0; i < cityCnt; i++) {
        path[i] = to_string(start);
        dis[i] = roads[start][i];
    }
    int cnt = 0;
    // tag[start] = true;
    dis[start] = 0;
    pathCnt[start] = 1;
    while (cnt != cityCnt) {
        int minPath = 0;
        int minValue = INT_MAX;
        for (int i = 0; i < cityCnt; i++) {
            if (!tag[i] && dis[i] < minValue) {
                minValue = dis[i];
                minPath = i;
            }
        }
        tag[minPath] = true;
        cnt++;
        for (int i = 0; i < cityCnt; i++) {
            if (!tag[i] && roads[minPath][i] != INT_MAX &&
                (roads[minPath][i] + dis[minPath]) < dis[i]) {
                dis[i] = dis[minPath] + minValue;
                path[i] = path[minPath] + to_string(i);
                pathCnt[i] = pathCnt[minPath];
            }
            if (!tag[i] && roads[minPath][i] != INT_MAX &&
                (roads[minPath][i] + dis[minPath]) == dis[i]) {
                string pathA = path[i];
                string pathB = path[minPath] + to_string(i);
                int costA = calcCost(aids, pathA);
                int costB = calcCost(aids, pathB);
                if (costA < costB) {
                    path[i] = pathB;
                }
                pathCnt[i] = pathCnt[i] + pathCnt[minPath];
            }
        }
    }
}

int main() {
    int cityCnt;
    int roadCnt;
    int start, end;
    int aids[LEN] = {0};
    int roads[LEN][LEN] = {{0}};
    int dis[LEN] = {0};
    int pathCnt[LEN] = {0};
    string path[LEN];
    cin >> cityCnt >> roadCnt >> start >> end;
    for (int i = 0; i < cityCnt; i++) {
        cin >> aids[i];
    }
    for (int i = 0; i < roadCnt; i++) {
        int start, end, length;
        cin >> start >> end >> length;
        roads[start][end] = roads[end][start] = length;
    }
    for (int i = 0; i < cityCnt; i++) {
        for (int j = 0; j < cityCnt; j++) {
            if (roads[i][j] == 0) {
                roads[i][j] = INT_MAX;
            }
        }
    }

    run(roads, aids, dis, pathCnt, roadCnt, cityCnt, path, start);
    // cout << pathCnt[end] << " " << calcCost(aids, path[end]) << endl;
    // for (int i = 0; i < path[end].size(); i++) {
    //     cout << path[end][i] - '0';
    //     if (i != path[end].size() - 1) {
    //         cout << " ";
    //     }
    // }
    printf("%d %d\n", pathCnt[end], calcCost(aids, path[end]));
    for (int i = 0; i < path[end].size(); i++) {
        printf("%d", path[end][i] - '0');
        if (i != path[end].size() - 1) {
            printf(" ");
        }
    }
    return 0;
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_054_福到了.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 27 May 2018 12:09:52 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int main() {
    char c;
    int cnt;
    cin >> c;
    cin >> cnt;
    cin.get();
    char arr[cnt][cnt + 1];
    for (int i = 0; i < cnt; i++) {
        cin.getline(arr[i], cnt + 1);
        cin.sync();
    }
    // for (int i = 0; i < cnt; i++)
    // {
    //     for (int j = 0; j < cnt; j++)
    //     {
    //         cout << arr[i][j];
    //     }
    //     // cout << arr[i];
    //     cout << endl;
    // }
    char last[cnt][cnt];
    int tag = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            last[i][j] = arr[cnt - i - 1][cnt - j - 1];
            if (arr[i][j] == arr[cnt - i - 1][cnt - j - 1]) {
                tag += 1;
            }
        }
    }
    if (tag == cnt * cnt) {
        cout << "bu yong dao le" << endl;
    }
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < cnt; j++) {
            if (last[i][j] != ' ') {
                cout << c;
            } else {
                cout << ' ';
            }
        }
        if (i != cnt - 1) {
            cout << endl;
        }
    }
    return 0;
}

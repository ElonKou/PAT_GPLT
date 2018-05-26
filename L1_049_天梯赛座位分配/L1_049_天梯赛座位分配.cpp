//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_049_天梯赛座位分配.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 26 May 2018 06:06:43 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <vector>
using namespace std;

int isone(int num[], int cnt)
{
    int sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (num[i] != 0)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    int cnt;
    int all = 0;
    cin >> cnt;
    int num[cnt];
    for (int i = 0; i < cnt; i++)
    {
        cin >> num[i];
        num[i] = num[i] * 10;
        all += num[i];
    }
    vector<vector<int> > result(cnt);
    int index = 0;
    for (int i = 0; i < all; i++)
    {
        for (int j = 0; j < cnt; j++)
        {
            if (num[j] > 0)
            {
                if (result[j].size() > 0 && result[j][result[j].size() - 1] == index)
                {
                    index += 2;
                }
                else
                {
                    index++;
                }
                result[j].push_back(index);
                num[j]--;
            }
        }
    }
    vector<int>::iterator it;
    for (int i = 0; i < cnt; i++)
    {
        cout << "#" << i + 1 << endl;
        int line = 0;
        for (it = result[i].begin(); it != result[i].end(); it++)
        {
            cout << *it;
            line++;
            if (line == 10)
            {
                line = 0;
                cout << endl;
            }
            else
            {
                cout << " ";
            }
        }
    }
    return 0;
}

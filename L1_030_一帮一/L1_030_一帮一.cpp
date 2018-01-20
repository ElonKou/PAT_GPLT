//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_030_一帮一.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sat 20 Jan 2018 02:41:15 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

void inputAndCheckPrint(void){
	int count;
	cin >> count;
    char names[count][20];
    int sexs[count];
	for(int i =0;i < count;i++){
        cin >> sexs[i];
        cin >> names[i];

        //cout << sexs[i] << ":";
        //cout << names[i] << endl;
	}
    int maleindex = count-1;
    int femaleindex = count-1;
    for(int i = 0;i < count/2;i++){
        if(sexs[i] == 0){
            for(int j = maleindex;j > 0;j--){
                if(sexs[j] == 1){
                    maleindex = j-1;
                    cout << names[i] << " " << names[j];
                    break;
                }
            }
        }else{
            for(int j = femaleindex;j > 0;j--){
                if(sexs[j] == 0){
                    femaleindex = j-1;
                    cout << names[i] << " " << names[j];
                    break;
                }
            }
        }
        if(i < count/2-1){
            cout << endl;
        }
    }
}

int main(){
	// 配对..
	inputAndCheckPrint();
	return 0;
}


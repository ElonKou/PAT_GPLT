//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_043_阅览室.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 28 Jan 2018 02:01:01 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

typedef struct record{
    int code;
    char type;
    int hour;
    int mins;
    record *next;
}record;

typedef struct{
    int length;
    record *list;
    record *last;
}day;

int checkOk(record *r ,day * d){
    int ok;
    //for(){
        ////
    //}
    return ok;
}

int isOk(day *d,record *r){
    // 检查是否符合要求
    int ok = 0;
    record * temp = NULL;
    record * rr = d->list->next;
    while(rr != NULL){
        // 找到上次访问的记录
        if(rr -> code == r -> code){
            temp = rr;
            rr = rr -> next;
        }else{
            rr = rr -> next;
        }
    }
    if(temp == NULL){
        if(r -> type == 'E'){
            ok = 0;
        }else{
            ok = 1;
        }
    }else{
        if(temp ->type == 'S' && r -> type == 'E'){
            // 前借后还,ok
            ok = 1;
        }
        if(temp -> type == 'S' && r -> type == 'S'){
            // 两次连续借书,no
            ok = 0;
        }
        if(temp -> type == 'E' && r ->type == 'S'){
            // 还掉之后再借,ok
            ok = 1;
        }
        if(temp ->type == 'E' && r -> type == 'E'){
            // 两次连续还书,no
            ok = 0;
        }
    }
    return ok;
}

void calculate(day days[],int num){
    int result[num][2] = {0};
    for(int i = 0;i <num;i++){
        record *r = days[i].list->next;
        while(r != NULL){
            // 循环每个元素
            // 找到每个和之相匹配的元素
            record * temp = NULL;
            record * rr = days[i].list->next;
            while(rr != NULL && rr != r){
                // 找到上次访问的记录
                if(rr -> code == r -> code){
                    temp = rr;
                    rr = rr -> next;
                }else{
                    rr = rr -> next;
                }
            }
            // 写入
            if(temp != NULL){
                // 找到了匹配的选项,进行计算
                if(temp ->code == r -> code && temp -> type == 'S' && r -> type == 'E'){
                    result[i][0] ++;
                    result[i][1] += (r->hour-temp->hour-1) *60+(60+r->mins-temp->mins);
                }
            }
            r = r->next;
        }
        if(result[i][0] == 0){
            cout << "0 0";
        }else{
            cout << result[i][0] << " " << (result[i][1]+result[i][0]-1)/result[i][0];
        }
        if(i != num-1){
            cout << endl;
        }
    }
}

int main(){
    // 阅览室的座位的查询
    int num;
    cin >> num;
    day days[num];
    // 对结构体成员进行初始化
    for(int i = 0;i< num;i++){
        days[i].length = 0;
        record * r = (record *)malloc(sizeof(record));
        r->next = NULL;
        days[i].list = r;
        days[i].last = r;
    }
    // 进行输入
    for(int i = 0;i < num;i++){
        string str;
        // 创建一个元素
        record * r = (record *)malloc(sizeof(record));
        cin >> r->code;
        cin >> r->type;
        cin >>  str;
        r->hour = atoi(str.substr(0,2).c_str());
        r->mins = atoi(str.substr(3,2).c_str());
        r->next = NULL;
            
        while(r->code != 0){
            //cout<< r ->code << " "
                //<< r ->type << " "
                //<< r ->hour << " "
                //<< r ->mins << endl;
            // 添加到末尾
            if(isOk(&days[i],r) == 1){
                // 如何输入合法,并且不与已有的借书矛盾,则加入到列表中
                //cout << "-add-" << r->code << endl;
                days[i].last->next = r;
                days[i].last = r;
                days[i].length ++;
            }
            // 继续输入
            r = (record *)malloc(sizeof(record));
            cin >> r->code;
            cin >> r->type;
            cin >>  str;
            r->hour = atoi(str.substr(0,2).c_str());
            r->mins = atoi(str.substr(3,2).c_str());
            r->next = NULL;
        }
    }
    //cout << days[0].length << endl;
    //cout << days[1].length << endl;
    //cout << days[2].length << endl;
    //cout << days[0].list->next->hour << endl;
    //cout << days[2].list->next->hour << endl;
    //for(int i = 0;i < num;i++){
        //record *r = days[i].list ->next ;
        //while(r!=NULL){
            //cout<< r ->code << " "
                //<< r ->type << " "
                //<< r ->hour << " "
                //<< r ->mins << endl;
            //r = r->next;
        //}
    //}
    calculate(days,num);
    return 0;
}


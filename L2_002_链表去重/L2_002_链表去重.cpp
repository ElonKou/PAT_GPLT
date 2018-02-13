//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L2_002_链表去重.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Wed 31 Jan 2018 09:46:37 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <cmath>

using namespace std;

typedef struct cell{            // 定义元素的数据类型
    int pre,data,next;          // pre,next分别是前后元素的整型"指针"
    cell *printNext,*n;         // n是指向之后cell的指针,printNext,指向下一个要打印的变量
                                // 只在extra中使用,用于在不改变位置下,指向按照顺序排列的元素链表的下一个
}*Cell;

int isOk(Cell list,Cell cc){
    // 检查输入的节点的绝对值是否重复
    int ok = 1;                 // 存储是否重复,重复为0,不重复为1
    Cell index = list->n;
    while(index != NULL){
        if(abs(cc->data) == abs(index->data)){
            ok = 0;
            break;
        }
        index = index->n;
    }
    return ok;
}

Cell findCell(Cell list,Cell cc){
    // 查找后一个节点
    // 返回寻找到的节点的地址
    Cell index = list->n;
    while(index != NULL){
        if(index -> pre == cc->next){
            break;
        }
        index = index ->n;      // 没找到继续向后走
    }
    return index;
}

void insert(Cell list,Cell cc){
    // 将传入的cc元素按照书书顺序插入到list列表中
    Cell index = list;
    Cell pre = list;
    // 在末尾插入
    while(pre->n != NULL){
        pre = pre->n;      
    }
    pre -> n = cc;          // 末尾插入,只处理后指针
}

void print(Cell list,int start){
    Cell index = list->n;
    while(index != NULL){
        cout << index -> pre
             << " "
             << index ->data
             << " "
             << index -> next;
        if(index -> next != -1){
            cout << endl;
        }
        index = findCell(list,index);
    }
}

void sortPrint(Cell extra){
    Cell index = extra->n;
    Cell pre = NULL;
    while(index != NULL){
        Cell next = findCell(extra,index);
        if(next -> next != -1){
            index ->printNext = next;
            cout << index ->pre << " "<< endl;
        }
        index = index -> n;
    }
    //while(){
        ////
    //}
}

int main(){
    int start,num;
    cin >> start >> num;
    Cell input = (Cell)malloc(sizeof(cell));       // 保存所有输入的元素
    Cell extra = (Cell)malloc(sizeof(cell));       // 保存所有多余的元素
    input -> n = NULL;                             // 初始化
    input -> printNext = NULL;                     // 初始化
    extra -> n = NULL;
    extra -> printNext = NULL;
    // 对所有数据进行输入工作
    for(int i = 0 ;i < num ;i++){
        Cell cc = (Cell)malloc(sizeof(cell));
        cin >> cc->pre >> cc-> data >> cc->next;
        cc -> n = NULL;
        cc -> printNext = NULL;
        if(isOk(input,cc) == 1){
            insert(input,cc);
        }else{
            insert(extra,cc);
        }
    }
    // 分别对两个链表进行排序和输出
    print(input,start);
    sortPrint(extra);
    return 0;
}


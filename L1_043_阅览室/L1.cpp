//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 18 Feb 2018 04:29:20 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

typedef struct book{
	int code;
	int hour,mins;		// 借书时间
	int time;			// 每天总共阅读的时间
	int cnt; 			// 每天阅读次数
	char type;			// 当前的借阅状态
}*Book;

typedef struct day{
	book books[1000];	// 指向当天所有阅读的书的数组地址
	int bookNum;		// 当天阅读的不同书本的数量
}*Day;				

void getBook(book & b){
	string str;
	cin >> b.code;
	cin >> b.type;
	cin >> str;
	b.hour = atoi(str.substr(0,2).c_str());
	b.mins = atoi(str.substr(3,2).c_str());
}

int checkAddBook(day &d,book &b){
	//cout<< b.code 
		//<< " "
		//<< b.type
		//<< " "
		//<< b.hour
		//<< ":"
		//<< b.mins
		//<< endl;
	int ok = 0;
	if(b.type == 'S'){				// 借书
		b.time += d.books[b.code].time;
		b.cnt = ++d.books[b.code].cnt;
		d.books[b.code] = b;
	}else{							// 还书之后需要对每本书进行检查,剔除不合规的书,并且计算时间
		//while(){
			//
		//}
	}
}

void updateBook(day d,book b){
	//
}

int main(){
	int days;
	cin >> days;
	day allDay[days] = {0};

	for(int i = 0; i < days ;i++){
		book b;
		getBook(b);
		while(b.code != 0){
			//
			checkAddBook(allDay[i],b);
			getBook(b);
		}
	}
    return 0;
}


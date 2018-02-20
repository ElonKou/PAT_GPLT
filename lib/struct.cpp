//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  struct.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Tue 20 Feb 2018 01:33:36 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

struct Info{
	int id;
	int name;
	Info(int _id,int _name):id(_id),name(_name){}
	void print(){
		cout << "id:" << id
			 << "\tname:" << name
			 << endl;
	}
}p[10](12,23);

int main(){
	//Info info(12,"elonkou");
	//info.print();
	//Info info2(23,"kouzi");
	//info2.print();

    return 0;
}


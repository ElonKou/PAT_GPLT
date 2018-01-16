//L2_002_打印沙漏.cpp
//Author:elonkou
//E-mail:elonkou@ktime.cc
//Date  :Tue 16 Jan 2018 07:22:11 PM CST

#include <iostream>
using namespace std;

void printLine(int countBlank ,int stars,char c){
	// 该函数打印沙漏的一行
	// int blank:	空格的数量
	// int length:	字符的数量
	// char c:		要打印的字符
	for(int i = 0;i<countBlank;i++){
		cout << " ";
	}
	for(int i = 0;i<stars;i++){
		cout << c ;
	}
	cout << endl;
	// -_- 下面三行代码导致丢了16分(显示格式错误,沙漏的每行末尾不需要显示空格)
	//for(int i =0;i<line;i++){
	//	cout << ' ';
	//}
}

int getHeight(int count){
	// 根据沙漏元素的个数得到沙漏的高度(宽度)
	// 假设沙漏为完美形状(中间显示两行*符号),则count需要自增1
	// count每次减去两倍的符号数量,直到非零之前,height即为所求的高度
	// count:	组成符号的数量
	// height:	返回的高度
	int height = 0;
	count++;
	while((count-(height*2+1)*2)>=0){
		count -=(height*2+1)*2;
		height++;
	}
	height = height*2-1;
	height = height>0?height:0 ;	//height为非负数
	return height;
}

int numOfBlank(int half,int row){
	// 计算每行需要显示的空格的数量
	// 第0行显示0个字符,第1行显示...,大于行长一半的通过2*half-row得到
	return row>half?(2*half-row):row;
}

int main(){
	// 主函数,接收一个整型数据和字符,显示沙漏形状,并且打印剩余符号的数量
	// Example:	[]表示输入的内容
	// [19 *] 
	// *****
	//  ***
	//   *
	//  ***
	// *****
	// 2

	int count = 0;	// 用于接收整型数据,表示要输出的沙漏符号的数量
	char c = '*';	// 沙漏由该符号组成
	int i = 0;	
	cin >> count;
	cin >> c;

	int height = getHeight(count);	// 调用getHeight得到高度,注:高度也是宽度
	int stars = 0;					// 显示的符号的数量
	int half = (height-1)/2;		// 向下取整一半的高度
	for (int row =0;row < height;row ++){
		int countBlank = numOfBlank(half,row);	// 得到空白符数量
		stars = height-2*countBlank;			// 得到符号数量
		printLine(countBlank,stars,c);			// 调用打印一行以及换行
	}
	int used = (half+1)*(half+1)*2-1;			// 计算未被使用的符号
	cout << (count - used)>0?(count - used):0;	// 打印未被使用的符号熟练
    return 0;
}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  L1_009_N个数求和.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 06:50:11 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
#include <sstream>
#include <cmath>

#define WIDTH 2
#define RESULT 3

using namespace std;

void writeOne(long (*data)[WIDTH],int row,int start,int separate,int end,string str){
	// 接收二维数组的地址,以及每个字符串,字符串的分子起始,除号,分母结束的位置
	// 将字符串进行解码,转换为对应的整型数据,并对其中的不合法数据进行转换(比如:0,3等)
    
	// 以下8行代码对字符串中的分子部分拆分到substr中,并且使用stringstream对象对其转换为整型
	// 并将分子写入到data二维数组的第0行中
	int mid = (separate == start)?end:separate;				
	string substr = "";										
	for (int index = start;index < mid;index ++){
		substr += str[index];
	}
	stringstream ss;
	ss << substr;
	ss >> data[row][0];

	// 以下几行代码会对字符串的分母部分拆分到substrr中,同样进行转换为整型数据
	// 其中需要考虑分母不存在(即除号不存在)的情况
	if(separate == start){
		data[row][1] = 1;
	}else{
		string substrr = "";
		for (int index = separate+1;index < end;index ++){
			substrr += str[index];
		}
		stringstream sss;
		sss << substrr;
		sss >> data[row][1];
	}
}

void inputOne(string str,int *start,int *separate,int *end){
	// 根据得到的字符串进行解析,得到对应的分数的分子,分母,除号的位置
	// string str	:传入的字符串
	// int *start	:分子开始的位置,传入的指针,该函数会对其内容进行修改
	// int *separate:除号的位置,指针类型,会被修改
	// int *end		:分母结束的位置,指针类型,会被修改
	int len = str.length();
	int index = 0;
	*start = 0;
	*separate = 0;
	*end = 0;
	// 循环找到分隔符的位置
	// 若找不到,则认为该字符是整数,不是分数
	for (index = 0;index < len;index++){
		if(str[index] == '/'){
			*separate = index;
		}
	}
	*end = index;
}

void getInput (long (*data)[WIDTH],int size){
	// 该函数根据要输入的数据长度,从缓冲区读取size组的数据,每组数据都为字符串
	// long (data)[WIDTH]	:得到二维数组的指针,将缓冲区得到的数据写到该数组中
	// int size				:输入数据的组数

	for(int i = 0;i < size;i++){
		int start = i;			// 每组数据分子开始的位置
		int separate = i;		// 每组数据分号的位置
		int end = i;			// 每组数据分母结束的位置
		string str;
		cin >> str;
		inputOne(str,&start,&separate,&end);		// 对每组数据进行处理,传入start,separate,end的指针,并对其进行修改
		writeOne(data,i,start,separate,end,str);	// start,separate,end得到了相应数据,将该三项数据写到二维数组中
	}
}

void switchNumber(long *a,long *b){
	// 单纯的交换两个数的算法,没什么特别的
	// 不爱国传入的是两个数的地址
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

long getMaxFactor(long numa,long numb){
	// 使用碾转相除法得到最大公约数,具体方法可以Google
	// long numa	:数1
	// long numb	:数2
	long max = 1;		// 存放最大公约数
	if(numb == numa){	// 该判断语句为了考虑两数相等情况下,最大公约数就是它们本身
		max = numa;
	}					
	while(numb != numa){				// 该for循环实现了碾转相除法的内容
		if(numa < numb){
			switchNumber(&numa,&numb);	// 其中为了保证除法的正确性,调用了switch函数保证了numa>numa
		}
		if(numa % numb == 0){
			max = numb;
			break ;
		}
		numa = numa % numb;
	}
	return max;
}

long getMinFactor(int numa,int numb){
	// 该函数计算两个非负数的最小公倍数
	// 先计算最大公约数,两数之积/最大公约数=最小公倍数
	long max = getMaxFactor(numa,numb);		// 调用函数求得最大公倍数
	return numa/max*numb;					// 求得最大公约数并且返回(注意:先除再乘,防止出现先乘积之后超过long的范畴)
}

void readyCalculate(long (*data)[WIDTH],int size){
	// 该函数负责的任务是将数据进行规整处理,即对所有分数进行加法操作之前需要的通分

	long minMultiple = data[0][1];								// minMultiple	:最小公倍数
	for(int i = 1;i<size;i++){									// 循环处理得到所有分母的最小公倍数
		minMultiple = getMinFactor(minMultiple,data[i][1]);		// 调用函数求最小公倍数
	}
	for(int i= 0;i<size ;i++){									// 该循环会根据分母的最小公倍数,对所有分数进行通分
		data[i][0] = minMultiple/data[i][1]*data[i][0];			// 存放通分后的分子
		data[i][1] = minMultiple;								// 存放通分后的分母
	}
}

void calculate(long (*data)[WIDTH],int size,long *result ){
	// data数组此时已经被规格化(也就是所有数据都被通分,符号保存在分子中)
	// 该函数目的是为了计算data二维数组中分子之和,并对其和分母进行约分得到简分数sumUp
	// 约分之后,将该分数转换为整数部分+分数部分的形式,分数部分由分子+分母组成
	// 将三个数据分别存放在result之中
	// long (*data)[WIDTH]	:没什么可说的,原先的二维数据,传入的是指针,为了修改内容
	// int size				:组数
	// long *result			:保存结果的数组,同样是指针

	long sumUp = 0;					// 存放所有分子之和
	for(int i =0;i < size;i++){		// 该循环进行分子求和
		sumUp += data[i][0];
	}
	int type = (sumUp>0)?1:-1;		// 处理分子为负数情况,type存放分子的符号,临时使用的变量
	sumUp = abs(sumUp);				// 取得绝对值,因为求最大公约数的函数接收的是正数
	long factor;					// 所有数据求和之后,分子和分母的化简,需要最小公约数
	if(sumUp != 0){
		factor = getMaxFactor(sumUp,data[0][1]);
	}else{							// 非常重要,处理分数整个的和为0的时候的特殊情况,否则会报浮点错误,血的教训
		result[0] = 0;
		result[1] = 0;
		result[2] = 0;
		return ;
	}
	
	sumUp = type*sumUp/factor;		// 对分子的符号进行还原
	result[2] = data[0][1]/factor;	// 以下三行分别将约分之后的整数部分,分子部分,分母部分,写入result数组中
	result[1] = sumUp%result[2];
	result[0] = sumUp/result[2];
}

void printResult(long *result){
	// 最后执行的函数,打印result的结果内容,按照格式进行输出,不放在主函数是为了MVC模式中view的分离,便于调试和阅读
	if(result[0] != 0){				// 处理整数部分不为0的情况
		cout << result[0];			// 打印整数部分
		if(result[1] != 0){			// 如果分子部分不为0,即分数部分存在
			cout << " ";
		}
	}

	if(result[1] != 0){				// 处理分子为0(也就是分布部分不存在)
		cout << result[1] << "/";
		cout << result[2];
	}

	if(result[0] == 0&& result[1] == 0 && result[2] == 0){		// 该条件语句用于处理三个数都为0(即整个分数的和为0)的情况
		cout << "0";
	}
}

int main(){
	// 该题目进项分数计算求和,并且对求得的和进行约分,格式化输出
	// 注意1:考虑输入带有字符,因此要用string类型来接受数据
	// 注意2:考虑到输入数据中可能没有分号,需要单独处理,例如:输入2
	// 注意3:考虑到输入可能为0
	// 注意4:考虑输入可能数据非常大,造成乘法计算时候超过int最大值.因此用long
	// 注意5:考虑输入数据进行求和得到的结果可能为附属或0

	int size = 0;
	cin >> size ;
	long dataSet[size][WIDTH] = {0};	// 该二维数组存储输入的数据,分子在dataSet[*][0]中,对应的分母在dataSet[*][1]中
	long result[RESULT];				// 该数组存储求和得到的值,其中
										// result[0]:分数的整数部分
										// result[1]:分子;
										// result[2]:分母

	getInput(dataSet,size);				// 得到输入的结果,并且存储到dataSet数组中
	readyCalculate(dataSet,size);		// 预先处理,对得到的每组数据进行格式化,并且转换为long 类型
	calculate(dataSet,size,result);		// 计算处理,求和(其中需要约分处理)
	printResult(result);				// 格式化输出结果


	// PS:这是一段没有什么用的文字,其实可以用c语言中的格式化输入语句scanf的,直接读到的数据就是整型的
	// 没有必要通过c++进行读取字符串,然后转换为整数的,但是这个刷题的主要目的之一是为了学习c++
	// 而且到此为止学习c++不到一周,还不会使用,而且不知道c++有什么方式可以按照格式输入(除了调用c的输入)

	// 整个代码将近有一半多都在是为了得到一个整型数据,效率太低了,代码量庞大,但结构还算清洗,以后有空再使用
	// c的方式写一个简单的版本吧,没时间就不写了
    return 0;
}


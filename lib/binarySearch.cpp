//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  erfen_find.cpp
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Sun 25 Feb 2018 10:17:38 AM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int data){
	int mid;
	while(start <= end){
		mid = (start + end)/2;
		if(arr[mid] == data){ 
			return mid;
		}else if(arr[mid] < data){
			start = mid + 1;
		}else{
			end = mid -1;
		}
	}
	return -1;
}

int main(){
	int arr[10] = {3,7,8,11,15,21,33,52,66,88};
    cout << "index(8) = " << binarySearch(arr,0,9,8) << endl;
    cout << "index(2) = " << binarySearch(arr,0,9,2) << endl;
    cout << "index(21) = " << binarySearch(arr,0,9,21) << endl;
    cout << "index(66) = " << binarySearch(arr,0,9,66);
	return 0;
}


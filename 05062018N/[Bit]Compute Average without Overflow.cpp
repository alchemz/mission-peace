/*
Position: System Software Engineer 
1. 计算两个数的average， 要求用多种方法
bit manipulation, 直接左移来做除以2的操作
follow-up:
分析溢出、code经过compiler之后的效率等问题，比如要尽量避免if else等，因为在assembly里面是branch。
https://www.geeksforgeeks.org/compute-average-two-numbers-without-overflow/
*/
#include <iostream>
using namespace std;

int computeAverage(int a, int b){
	//return (a+b)/2; //overflow problem
	//return (a / 2) + (b / 2) + ((a % 2 + b % 2) / 2);//does not cause overflow
	return ((a >> 1) + (b >> 1) +((a&1) & (b&1)));//second method
}

int main(){
	int a=INT_MAX, b=INT_MAX;
	cout<<"Computed Average: "<<computeAverage(a, b); 
	return 0;
}
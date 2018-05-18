/*
Binary Search, 注意更新以mid为基准
O(logn)
https://leetcode.com/problems/sqrtx/description/

注意用mid 和 x/mid比较，防止溢出
*/
#include <iostream>
using namespace std;

int mySqrt(int x) {
    if(x==0 || x==1) return x;
    int left=0, right=x;
    while(left<=right){
        int mid = left + (right-left)/2;
        cout<<"Left: "<<left<<" Right: "<<right <<" Mid: "<<mid<<" x/mid: "<< x/mid<<endl;
        if(mid == x/mid){
            return mid;
        }
        else if(mid < x/mid){
            left=mid+1;
        }
        else{
            right=mid-1;
        }

    }
    
    return right;
}
int main() {
	int x=8;
	cout<<mySqrt(8);
	return 0;
}
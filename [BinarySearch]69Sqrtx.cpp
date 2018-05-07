class Solution {
public:
    int mySqrt(int x) {
        int left=0, right=x;
        if(x<=1) return x;
        
        while(left<right){
            int mid=left + (right-left)/2;
            if(mid==x/mid) return mid;
            else if(mid<x/mid)
                left = mid+1;
            else
                right = mid;
        }
        return right-1;
    }
};

/*
lc:https://leetcode.com/problems/sqrtx/description/
*/
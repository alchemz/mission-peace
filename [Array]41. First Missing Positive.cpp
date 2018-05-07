class Solution {
public:
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-first-missing-positive.html
    //1. A[i]<1 or A[i]>n, not first missing positive, i++
    //2. A[i]=i+1, A[i] is at right position, i++
    //3. A[i]!=i+1, and 0<A[i]<=n; swap(A[i], A[A[i-1]])
    //4. A[i]=A[A[i-1]], i++
    int firstMissingPositive(vector<int>& A) {
        int n=A.size();
        int i=0;
        while(i<n) {
            if(A[i]!=i+1 && A[i]>0 && A[i]<=n && A[i]!=A[A[i]-1])
                swap(A[i],A[A[i]-1]);
            else
                i++;
        }
        for(int i=0; i<n; i++) {
            if(A[i]!=i+1) return i+1;
        }
        return n+1;
    }
};
http://www.cnblogs.com/grandyang/p/4395963.html
https://leetcode.com/problems/first-missing-positive/description/
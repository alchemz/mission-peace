class Solution {
public:
    int search(int A[], int n, int target) {
        if (n == 0) return -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (A[mid] == target) return mid;
            else if (A[mid] < A[right]) {
                if (A[mid] < target && A[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else {
                if (A[left] <= target && A[mid] > target) right = mid - 1;
                else left = mid + 1;
            }
        }
        return -1;
    }
};
/*
http://www.cnblogs.com/grandyang/p/4325648.html
https://leetcode.com/problems/search-in-rotated-sorted-array/description/
*/
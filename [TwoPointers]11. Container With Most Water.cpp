class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            res = max(res, min(height[i], height[j]) * (j - i));
            height[i] < height[j] ? ++i : --j;
        }
        return res;
    }
};
/*
lc:https://leetcode.com/problems/container-with-most-water/description/
sol:http://www.cnblogs.com/grandyang/p/4455109.html
*/
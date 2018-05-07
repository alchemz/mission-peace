class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            int first  = 0, last = res.size() - 1;
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};
http://www.cnblogs.com/grandyang/p/7519466.html
https://leetcode.com/problems/find-k-closest-elements/description/
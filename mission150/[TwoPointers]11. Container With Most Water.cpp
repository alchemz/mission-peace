/*
水罐里面的水由两边低的那端决定
左边低，向右移
后变低，向左移
https://leetcode.com/problems/container-with-most-water/description/
time: O(n)
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n= height.size();
        // int max_Area=0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         int cur_Area = (j-i) * min(height[i], height[j]);
        //         max_Area = max(max_Area, cur_Area);
        //     }
        // }
        int max_Area=0;
        int left=0, right=height.size()-1;
        while(left < right){
            int cur_Area = min(height[left], height[right]) * (right-left);
            max_Area = max(max_Area, cur_Area);
            
            if(height[left]<height[right]){
                left++;
            }
            else if(height[left]>height[right]){
                right--;
            }else{
                left++;
                right--;
            }
            
        }
        return max_Area;
    }
};
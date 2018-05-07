class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()||height.size()<3) return 0;
        int max=0;
        //two pointers
        int leftmax=0, rightmax=0;
        int i=0, j=height.size()-1;
        while(i<j){
            leftmax=std::max(leftmax, height[i]);
            rightmax=std::max(rightmax, height[j]);
            if(leftmax<rightmax){
                //left指针的左边水量确定
                max+=leftmax-height[i];
                i++;
            }else{
                max+=rightmax-height[j];
                j--;
            }
        }
        return max;
    }
};

/*
2. 给了一个foo的class， 然后有一个pointer指向这个class的一个object，
如果这个pointer的值是a，问foo+5的值是什么。
答案是a+5*sizeof（foo）
*/
/*
3. lc sort colors. 要求必须O(n)时间复杂度
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size_=nums.size();
        int left = 0, right = size_-1;
        int i=0; 
        while(i<=right){
            if(nums[i]==0){
                swap(nums[i++], nums[left++]);
            }
            else if(nums[i]==1){
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i], nums[right--]);
            }
        }
    }
};
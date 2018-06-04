/*
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

思路是我们维护一个栈和一个变量third，其中third就是第三个数字，也是pattern 132中的2，
栈里面按顺序放所有大于third的数字，也是pattern 132中的3，
那么我们在遍历的时候，如果当前数字小于third，即pattern 132中的1找到了，我们直接返回true即可，

*/
bool find132pattern(vector<int>& nums) {
    int s3 = INT_MIN;
    stack<int> st;
    for( int i = nums.size()-1; i >= 0; i -- ){
        if( nums[i] < s3 ) return true;
        else while( !st.empty() && nums[i] > st.top() ){ 
          s3 = st.top(); st.pop(); 
        }
        st.push(nums[i]);
    }
    return false;
}
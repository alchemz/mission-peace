#include<bits/stdc++.h>
using namespace std;
 
vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto d : nums) {
            q.push(a * d * d + b * d + c);
        }
        while (!q.empty()) {
            res.push_back(q.top()); q.pop();
        }
        return res;
}

// Driver code
int main()
{
   vector<int> nums={-4, -2, 2, 4};
   int a = 1, b = 3, c = 5;
   vector<int> ans=sortTransformedArray(nums, a, b, c);
   for(vector<int>::iterator i=ans.begin(); i!=ans.end(); i++)
    cout<<*i<<", ";
   return 0;
}

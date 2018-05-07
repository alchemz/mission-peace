// Prints first k pairs with least sum from two
// arrays.
#include<bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        for (int i = 0; i < min((int)nums1.size(), k); ++i) {
            for (int j = 0; j < min((int)nums2.size(), k); ++j) {
                res.push_back({nums1[i], nums2[j]});
            }
        }
        sort(res.begin(), res.end(), [](pair<int, int> &a, pair<int, int> &b){return a.first + a.second < b.first + b.second;});
        int n=res.size();
        if (n > k) res.erase(res.begin() + k, res.end());
        return res;
}
 
// Driver code
int main()
{
    vector<int> n1={1,7,11};
    vector<int> n2={2,4,6};
    int k=3;
    vector<pair<int, int>> ans=kSmallestPairs( n1,n2, k);
    for(unsigned i=0; i<ans.size(); i++)
        cout<<ans[i].first<<", "<<ans[i].second<<endl;
    return 0;
}

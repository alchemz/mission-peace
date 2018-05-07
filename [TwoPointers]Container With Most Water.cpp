#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int mxArea=0;
    int left =0, right= height.size()-1;
    while(left < right){
        int curArea = min(height[left], height[right])*(right-left);
        mxArea = max(curArea, mxArea);
        cout<<left <<", "<<right<<endl;
        cout<<mxArea<<endl;
        if(height[left]<height[right])
            left++;
        else if(height[left]>height[right])
            right--;
        else{
            left++;
            right--;
        }
    }
    return mxArea;
  
}
     
int main(){
  vector<int> height={0,3,7,2,5,4};
  cout<<maxArea(height);
  // for(int i=0; i<(int)res.size(); i++)
  //   cout<<res[i]<<", ";
  return 0;
}
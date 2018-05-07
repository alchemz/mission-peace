//http://bangbingsyb.blogspot.com/2014/11/leetcode-spiral-matrix-i-ii.html
#include<bits/stdc++.h>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        //lastRow=m-1-i, lastCol=n-1-i;
        vector<int> ans;
        if(matrix.empty()|| matrix[0].empty()) return ans;
        int nlvl = (min(m,n)+1)/2;
        for(int i=0; i<nlvl; i++){
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow==i){
                for(int j=i; j<=lastCol; j++)
                    ans.push_back(matrix[i][j]);
            }
            else if(lastCol==i){
                for(int j=i; j<lastRow; j++)
                    ans.push_back(matrix[j][i]);
            }
            else{
                for(int j=i; j<lastCol; j++)
                    ans.push_back(matrix[i][j]);
                for(int j=i; j<lastRow; j++)
                    ans.push_back(matrix[j][lastCol]);
                for(int j=lastCol; j>i; j--)
                    ans.push_back(matrix[lastRow][j]);
                for(int j=lastRow; j>i; j--)
                    ans.push_back(matrix[j][i]);
            }
        }
        return ans;
}

int main(){
  //test case
  vector<vector<int>> test={{ 1, 2, 3 },{ 4, 5, 6 },{ 7, 8, 9 }};
  vector<int> ret=spiralOrder(test);
  for(unsigned int i=0; i<ret.size(); i++)
    cout<<ret[i]<<", ";
  return 0;
}

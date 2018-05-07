/*
You are given an n x n 2D matrix representing an image.
You have to rotate the image in-place
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

https://leetcode.com/problems/rotate-image/description/
*/
#include<bits/stdc++.h>
using namespace std;

class RotateImg {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++ ){
                //transpose
                swap(matrix[i][j], matrix[j][i]);
            }
            //reverse each row
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main(){
  RotateImg r;
  vector<vector<int>> img={{1,2,3,},{4,5,6},{7,8,9}};

  for(unsigned i=0; i<img.size(); i++){
    for(unsigned j=0; j<img[0].size(); j++){
      cout<<img[i][j]<<", ";
    }
    cout<<endl;
  }
  r.rotate(img);
  return 0;
}
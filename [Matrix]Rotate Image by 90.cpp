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
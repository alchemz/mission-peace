#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
  if (M.empty() || M[0].empty()) return {};
  int m = M.size(), n = M[0].size();
  vector<vector<int>> res = M, dirs{{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
  for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
          int cnt = M[i][j], all = 1;
          for (auto dir : dirs) {
              int x = i + dir[0], y = j + dir[1];
              if (x < 0 || x >= m || y < 0 || y >= n) continue;
              ++all;
              cnt += M[x][y];
          }
          res[i][j] = cnt / all;
      }
  }
  return res;
}


int main()
{
  vector<vector<int>> image={{1,1,1},{1,0,1},{1,1,1}};
  int m=image.size(), n=image[0].size();
  //vector<vector<in>> res(m, vector<int>(n,0));
  vector<vector<int>>res=imageSmoother(image);
  
  for( int i=0; i<m; i++){
    for( int j=0; j<n; j++){
      cout<<res[i][j]<<", ";
    }
    cout<<endl;
  }
  return 0;
}

/*
http://www.cnblogs.com/grandyang/p/7535354.html
*/
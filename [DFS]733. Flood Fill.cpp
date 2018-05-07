#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int m = image.size(), n = image[0].size(), color = image[sr][sc];
    vector<vector<int>> res = image;
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    queue<pair<int, int>> q{{{sr, sc}}};
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto t = q.front(); q.pop();
            res[t.first][t.second] = newColor;
            for (auto dir : dirs) {
                int x = t.first + dir[0], y = t.second + dir[1];
                if (x < 0 || x >= m || y < 0 || y >= n || res[x][y] != color) continue;
                q.push({x, y});
            }
        }
    }
    return res;
}


int main()
{
  vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
  int sr=1, sc=1, newColor=2;
  int m=image.size(), n=image[0].size();
  //vector<vector<in>> res(m, vector<int>(n,0));
  vector<vector<int>>res=floodFill(image, sr, sc, newColor);
  
  for( int i=0; i<m; i++){
    for( int j=0; j<n; j++){
      cout<<res[i][j]<<", ";
    }
    cout<<endl;
  }
  return 0;
}

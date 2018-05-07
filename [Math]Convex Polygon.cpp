/*
凸多边形定义：
1. 所有内角小于180度
2. 任何连个顶点间的线段位于多边形的内部或者边界上

判断是否凸多边形，计算每三个相邻点的法向量方向，同正，或者同负
当前的法线方向，与之前的方向比较，如果不同，返回false,
如果为0，直接跳过。
http://www.cnblogs.com/grandyang/p/6146986.html
*/

#include<bits/stdc++.h>
using namespace std;

class ConvexPolygon{
public:
  bool isConvex(vector<vector<int>>& points){
    long long n = points.size(), pre=0, cur=0;
    for(int i=0; i<n; i++){
      int dx1 = points[(i+1) % n][0] - points[i][0]; cout<<dx1<<", ";
      int dx2 = points[(i+2) % n][0] - points[i][0]; cout<<dx2<<endl;

      int dy1 = points[(i+1) % n][1] - points[i][1]; cout<<dy1<<", ";
      int dy2 = points[(i+2) % n][1] - points[i][1]; cout<<dy2<<endl;

      cur = dx1 * dy2 - dx2 * dy1; cout<<"cur: "<<cur<<" pre: "<<pre<<endl;//法线方向 
      if(cur !=0){
        if(cur * pre <0) return false;
        else pre = cur;
      }
    }
    return true;
  }
};

int main(){
  ConvexPolygon cp;
  vector<vector<int>> test=
  //{{0,0},{0,1},{1,1},{1,0}};
  {{0,0},{2,0},{3,1},{2,2},{0,2}};
  bool res = cp.isConvex(test);
  if(res)
    cout<<"It is convex polygon";
  else
    cout<<"It is not";
  return 0;
}
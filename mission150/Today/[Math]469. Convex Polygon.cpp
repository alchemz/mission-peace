/*
Given a list of points that form a polygon when joined sequentially, 
find if this polygon is convex
凸多边形

而相邻的三个点就是最基本的单位，我们可以算由三个点组成的一小段曲线的法线方向，
而凸多边形的每个三个相邻点的法向量方向都应该相同，要么同正，要么同负。

*/
class Solution{
public:
	bool isConvex(vector<vector<int>>& points){
		long long n = points.size(), pre=0, cur=0;
		for(int i=0; i<n; i++){
			int dx1 = points[(i+1) % n][0] - points[i][0];
			int dx2 = points[(i+2) % n][0] - points[i][0];

			int dy1 = points[(i+1) % n][1] - points[i][1];
			int dy2 = points[(i+2) % n][1] - points[i][1];

			cur = dx1 * dy2 - dx2 * dy1;
			if(cur !=0){
				if(cur * pre <0) return false;
				else pre = cur;
			}
		}
		return true;
	}
};
#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Fence {
public:  
    vector<Point> outerTrees(vector<Point>& points) {  
        if(points.size() < 3) 
            return points;  
 
        auto cmp = [](Point& a, Point& b) -> bool {  
            return a.x < b.x || (a.x == b.x && a.y < b.y);  
        };  
        sort(points.begin(), points.end(), cmp);  
        vector<Point> stack;  
        stack.push_back(points[0]), stack.push_back(points[1]);  
        for(unsigned i = 2; i < points.size(); ++i) {    //left to right;  
            while(stack.size() > 1) {  
                auto &t1 = stack.back();  
                auto &t2 = stack[stack.size() - 2];  
                if(isRightTurn(t2, t1, points[i]))  break;  
                else stack.pop_back();  
            }  
            stack.push_back(points[i]);  
        }  
        int n = stack.size();  
        if((unsigned)n == points.size()) {  
            return stack; //check if linear  
        }  
        stack.push_back(points[points.size() - 2]);  
        for(unsigned i = points.size() - 3; i >= 0; --i) {   //right to left;  
            while((int)stack.size() > n) {  
                auto &t1 = stack.back();  
                auto &t2 = stack[stack.size() - 2];  
                if(isRightTurn(t2, t1, points[i])) {  
                    break;  
                }  
                else {  
                    stack.pop_back();  
                }  
            }  
            stack.push_back(points[i]);  
        }  
        stack.pop_back();  
        return stack;  
    }  
private:  
    bool isRightTurn(Point &a, Point &b, Point &c) {  
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) <= 0;  
    }  
};

int main(){
  Fence fence;
  Point p1(1,1);
  Point p2(2,2);
  Point p3(2,0);
  Point p4(2,4);
  Point p5(3,3);
  Point p6(4,2);
  vector<Point> points={p1, p2, p3, p4, p5, p6};
  
  vector<Point> stack=fence.outerTrees(points);
  return 0;
}
//https://blog.csdn.net/magicbean2/article/details/78941296
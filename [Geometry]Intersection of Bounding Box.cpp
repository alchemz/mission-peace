#include<bits/stdc++.h>
using namespace std;
struct Point{
    float x, y;
};
float IOD(Point A, Point B, Point C, Point D){
    float intersection=(max(A.x, C.x) - min(B.x, D.x))
                    *(max(A.y, C.y) - min(B.y, D.y));
    float areaA= (A.x-B.x)*(A.y-B.y);
    float areaB= (C.x-D.x)*(C.y-D.y);
    float areaUnion = areaA+areaB-intersection;
    return intersection/areaUnion;
}

int main(){
    Point A={2,2};
    Point B={5,7};
    Point C={3,4};
    Point D={6,9};
    cout<<IOD(A, B, C, D);
    return 0;
}

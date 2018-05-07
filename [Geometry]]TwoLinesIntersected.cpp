#include <iostream>
using namespace std;

struct Point{
  double x, y;
};

double det(double v1, double v2, double v3, double v4){
  return (v1*v4-v2*v3);
}

bool intersect3(Point aa, Point bb, Point cc, Point dd)  
{  
    double delta = det(bb.x-aa.x, cc.x-dd.x, bb.y-aa.y, cc.y-dd.y);  
    if ( delta<=(1e-6) && delta>=-(1e-6) )  // delta=0，表示两线段重合或平行  
    {  
        return false;  
    }  
    double namenda = det(cc.x-aa.x, cc.x-dd.x, cc.y-aa.y, cc.y-dd.y)/delta;  
    if ( namenda>1 || namenda<0 )  
    {  
        return false;  
    }  
    double miu = det(bb.x-aa.x, cc.x-aa.x, bb.y-aa.y, cc.y-aa.y)/delta;  
    if ( miu>1 || miu<0 )  
    {  
        return false;  
    }  
    return true;  
}  

int main(){
  //not: (0,0),(3,3),(2,3),(2,4); 
  //yes: (1,4),(3,0),(0,1),(4,3);
  //parallel not: (-1,2),(0,0),(3,0),(1,4);
  Point p1, p2, p3, p4;
  p1.x = 0;  
  p1.y = 0;  
  p2.x = 3;  
  p2.y = 3;  
  p3.x = 2;  
  p3.y = 3;  
  p4.x = 2;  
  p4.y = 4;  
  // p1.x = 1;  
  // p1.y = 4;  
  // p2.x = 3;  
  // p2.y = 0;  
  // p3.x = 0;  
  // p3.y = 1;  
  // p4.x = 4;  
  // p4.y = 3; 
  // p1.x = -1;  
  // p1.y = 2;  
  // p2.x = 0;  
  // p2.y = 0;  
  // p3.x = 3;  
  // p3.y = 0;  
  // p4.x = 1;  
  // p4.y = 4; 
  
  bool flag = false;  
  flag = intersect3(p1, p2, p3, p4);  
  if(flag)
    cout<<"two lines are intersected";
  else
    cout<<"two lines are not intersected";
  
  return 0;
}

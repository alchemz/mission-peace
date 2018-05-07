#include<bits/stdc++.h>
using namespace std;

class MovingAverage{
public:
  MovingAverage(int size){
    this->size = size;
    sum = 0;
  }
  
  double next(int value){
    if((int)q.size() >= size){
      sum -= q.front();
      q.pop();
    }
    
    sum += value;
    q.push(value);
    cout<< sum/q.size()<<endl;
    return sum/q.size();
  }
  
private:
  int size;
  double sum;
  queue<int> q;
};
int main(){
  MovingAverage m(4);
  m.next(1);
  m.next(10);
  m.next(2);
  m.next(3);
  m.next(7);
  return 0;
}

/*
http://www.cnblogs.com/grandyang/p/5450001.html
queue: first in, first out
*/
#include<iostream>
using namespace std;

#define MAX 1000

class Queue
{
private:
  int A[MAX];
  int front, rear;
  
public:
  Queue(){front=-1;rear=-1;}
  void insert(int value);
  void deleteItem();
  void display();
};


void Queue::insert(int value){
  if(rear>MAX-1){
    cout<<"queue overflow"<<endl;
    front=rear=-1;
    return;
  }
  A[++rear]=value;
  cout<<value<<" inserted"<<endl;
}

void Queue::deleteItem(){
  if(front==rear){
    cout<<"queue underflow"<<endl;
    return;
  }
  cout<<"deleted"<<A[++front]<<endl;
}

void Queue::display(){
  if(front==rear){
    cout<<"queue empty"<<endl;
    return;
  }
  for(int i=front+1;i<=rear; i++)
    cout<<A[i]<<" ";
  cout<<endl;
}


int main(){
  Queue q;
  q.display();
  q.insert(10);
  q.insert(20);
  q.insert(30);
  q.display();
  q.deleteItem();
  q.deleteItem();
  q.display();
  return 0;
}

  


  

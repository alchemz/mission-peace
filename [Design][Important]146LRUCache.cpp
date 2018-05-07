/*
Use stl container list as a double ended queue to store the cache keys.
Time: O(n)

Optimized: store a reference(iterator) to each key in a hash map
*/
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    list<int> dp;
    unordered_map<int, list<int>::iterator> ma;
    int csize;//maximum capacity of cache
    
public:
    LRUCache(int);
    void refer(int);
    void display();
};

LRUCache::LRUCache(int n){
    csize=n;
}

void LRUCache::refer(int x){
    if(ma.find(x)==ma.end()){
        if(dp.size()==csize){
            //delete least recently used element
            int last = dp.back();
            dp.pop_back();
            ma.erase(last);
        }
    }
    else
        dp.erase(ma[x]);
        
    //udpate reference
    dp.push_front(x);
    ma[x] = dp.begin();
}

void LRUCache::display(){
    for(auto it=dp.begin(); it!=dp.end(); it++)
        cout<<*it<<" ";
    cout<<endl;
}

int main(){
    LRUCache ca(4);
    
    ca.refer(1);
    ca.refer(2);
    ca.refer(3);
    ca.refer(1);
    ca.refer(4);
    ca.refer(5);
    ca.display();
    
    return 0;
}

/*
Use stl container list as a double ended queue to store the cache keys.
Time: O(n)

Optimized: store a reference(iterator) to each key in a hash map
*/
#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> m_;
    
public:
    LRUCache(int);
    int get(int);
    void put(int, int);
    void display();
  
};

LRUCache::LRUCache(int capacity) {
        capacity_ = capacity;
}

int LRUCache::get(int key){
    const auto it = m_.find(key);
    // If key does not exist
    if (it == m_.cend()) return -1;
 
    // Move this key to the front of the cache
    cache_.splice(cache_.begin(), cache_, it->second);
    return it->second->second;
}

void LRUCache::put(int key, int value){
    const auto it = m_.find(key);
        
    // Key already exists
    if (it != m_.cend()) {
            // Update the value
            it->second->second = value;
            // Move this entry to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
    }
        
    // Reached the capacity, remove the oldest entry
    if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first);
            cache_.pop_back();
    }
        
    // Insert the entry to the front of the cache and update mapping.
    cache_.emplace_front(key, value);
    m_[key] = cache_.begin();
}

void LRUCache::display(){
    for(auto it=cache_.begin(); it!=cache_.end(); it++)
        cout<<it->second<<" ";
    cout<<endl;
}
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
int main(){
    LRUCache obj(4);
    obj.put(1,1);
    obj.put(2,2);
    obj.put(3,3);
    obj.put(4,1);
    obj.put(5,4);
    obj.put(6,5);
    
    obj.display();
    return 0;
}

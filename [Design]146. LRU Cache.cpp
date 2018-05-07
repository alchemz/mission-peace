class LRUCache {
private:
    int capacity_;
    //cache
    list<pair<int,int>>cache_;
    //map
    unordered_map<int, list<pair<int, int>>::iterator>ma;
public:
    LRUCache(int capacity) {
        capacity_=capacity;
    }
    
    int get(int key) {
        //check, if key does not exist
        const auto it=ma.find(key);
        if(it==ma.cend()) return -1;
        //if existed, move the key to front
        cache_.splice(cache_.begin(), cache_, it->second);
        //return value
        return it->second->second;        
    }
    
    void put(int key, int value) {
        //check, if key does exits
        const auto it=ma.find(key);
        if(it!=ma.cend()){
            //update value
            it->second->second=value;
            //move to front
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        //if reached capacity
        if(cache_.size()==capacity_){
            const auto& node=cache_.back();
            ma.erase(node.first);
            cache_.pop_back();
        }
        //if not reached capacity, insert the entry to front
        cache_.emplace_front(key, value);
        ma[key]=cache_.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
/*
lc:https://leetcode.com/problems/lru-cache/description/
sol:http://www.cnblogs.com/grandyang/p/4587511.html
*/
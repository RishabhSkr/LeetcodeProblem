class LRUCache {
public:
// Brute force 
// 1st optimisation-> unordered_map(loc,key) O(n)->O(1)(reducing search )
// 2nd Optimisation deleting (O(n)->O(1)) by using list(linked list) (doubly linked list why becuse we need to update the pointers of prev also )
// dll(key1)->dll(key2)->dll(key3)->
// dll.begin() front address
// dll.back() back address
// dll.erase(iterator or address)(mp[key].first)->O(1),second->val
// dll.pop_back()->(O(1))
    list<int>dll;// key
    map<int,pair<list<int>::iterator,int>>mp; //(logn~O(1))
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyUsed(int &key){
        auto keyAdd = mp[key].first;
        dll.erase(keyAdd);
        dll.push_front(key);
        auto newAdd= dll.begin();
        mp[key].first = newAdd;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        // if found make recently used and push it forward and reutrn val
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
       if(mp.find(key)!=mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
       }else{
            // if not present 
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
       }
        //    check if full  
        if(n<0){// full
            // delete the last elemen least used
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
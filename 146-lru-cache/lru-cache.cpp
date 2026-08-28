class LRUCache {
public:
    list<int>dll; // key
    map<int,pair<list<int>::iterator,int>>m; // key , (address,value)
    int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) return -1;
        dll.erase(m[key].first);
        dll.push_front(key);
        m[key].first = dll.begin();
        return m[key].second;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            dll.erase(m[key].first);
            dll.push_front(key);
            m[key] = {dll.begin(),value};
        }
        else{
            if(dll.size() == n){
                // evict
                int oldkey = dll.back();
                dll.pop_back();
                dll.push_front(key);
                m.erase(oldkey);  
                m[key] = {dll.begin(),value};
            }
            else{
                dll.push_front(key);
                m[key] = {dll.begin(),value};
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
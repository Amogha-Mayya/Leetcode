class LRUCache {
public:
vector<pair<int,int>>v;
int n;
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for(auto it = v.begin();it!=v.end();it++){
            if(it->first == key){
                int value = it->second;
                v.erase(it);
                v.push_back({key,value});
                return value;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(auto it = v.begin();it!=v.end();it++){
            if(it->first == key){
                v.erase(it);
                v.push_back({key,value});
                return;
            }
        }
        if(v.size() + 1 > n){
            v.erase(v.begin());
            v.push_back({key,value});
        }
        else{
            v.push_back({key,value});
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
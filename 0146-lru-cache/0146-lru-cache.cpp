class LRUCache {
public:
//double ll
list<int>l;
unordered_map<int, pair<list<int>::iterator, int>> mp;
int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int val=mp[key].second;
           
           l.erase(mp[key].first);
           l.push_front(key);
           mp[key]={l.begin(),val};

           return val;

        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
           
            l.erase(mp[key].first);
            l.push_front(key);
            mp[key]={l.begin(),value};
            return;
        }
        if(mp.size()>=n){
            mp.erase(l.back());
            l.pop_back(); 
        }
        l.push_front(key);
        mp[key]={l.begin(),value};

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
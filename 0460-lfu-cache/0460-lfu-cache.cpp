class LFUCache {
public:
    int n;
    list<pair<int, int>> l;
    map<int, list<vector<int>>> freq; // counter->{key,val,counter}
    unordered_map<int, list<vector<int>>::iterator> mp; // key->adress
    LFUCache(int capacity) { n = capacity; }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            auto vec = (*(mp[key])); //{key,val,count}
            int res = vec[1];
            int count = vec[2];

    freq[count].erase(mp[key]);

               if(freq[count].empty())
        freq.erase(count);

           
            freq[count + 1].push_front({key, res, count + 1});
            mp[key] = freq[count + 1].begin();
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if(n==0)
    return;

        if (mp.find(key) != mp.end()) {
            auto vec = (*(mp[key])); //{key,val,count}
            int count = vec[2];
            
            freq[count].erase(mp[key]);

             if (freq[count].empty())
                freq.erase(count);
                
            freq[count + 1].push_front({key, value, count + 1});
            mp[key] = freq[count + 1].begin();

            return;
        }
        if (mp.size() >= n) {
            // lfu->lru{priority}
            int key_curr = freq.begin()->second.back()[0];
            int count = freq.begin()->second.back()[2];

            freq.begin()->second.pop_back();

            mp.erase(key_curr);

           
            if (freq[count].empty())
                freq.erase(count);

              
        }
        freq[1].push_front({key, value, 1});
        mp[key] = freq[1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
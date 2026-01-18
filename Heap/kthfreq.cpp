class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Frequency map
        unordered_map<int,int> mp;
        for (int x : nums) {
            mp[x]++;
        }

        // Min heap:
        // pair = {frequency, element}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Push into heap
        for (auto it : mp) {

            // FIX: pair must be pushed using make_pair
            pq.push({it.second, it.first});

            // Keep heap size limited to k
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract result
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};

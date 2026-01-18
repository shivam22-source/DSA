class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        // Max heap: {distance, value}
        priority_queue<pair<int,int>> pq;

        // Push all elements
        for (int i = 0; i < arr.size(); i++) {

            pq.push({abs(arr[i] - x), arr[i]});

            // Keep only k closest elements
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

        // Result must be sorted
        sort(res.begin(), res.end());

        return res;
    }
};


///IMPORTENT LINE
// Every element is processed
// Heap decides automatically whether to keep or discard***
// No manual condition needed

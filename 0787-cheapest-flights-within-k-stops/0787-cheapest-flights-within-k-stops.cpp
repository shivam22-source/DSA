class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<int> res(n, INT_MAX);
        res[src] = 0;
        
        for (int i = 0; i < k + 1; i++) {
            vector<int> temp = res;
            for (int j = 0; j < flights.size(); j++) {
                int u = flights[j][0];
                int v = flights[j][1];
                int price = flights[j][2];

                if (res[u] != INT_MAX) {
                    temp[v] = min(temp[v], res[u] + price);
                }
            }
            res = temp;
        }

        if (res[dst] == INT_MAX)
            return -1;
        return res[dst];
    }
};
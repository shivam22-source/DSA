class Solution {
public:
    int x[4] = {1, -1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    bool vailid(int i, int j, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++) {
            vector<int> t(m, INT_MAX);
            res[i] = t;
        }
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq; //{dis,{row,col}}
        pq.push({0, {0, 0}});
        res[0][0] = 0;
        while (!pq.empty()) {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            if (d > res[row][col])
                continue;
            for (int i = 0; i < 4; i++) {
                int r = row + x[i];
                int c = col + y[i];
                if (!vailid(r, c, n, m))
                    continue;
                int ab = abs(heights[row][col] - heights[r][c]);
                int new_dif = max(d, ab);
                if (new_dif < res[r][c]) {
                    res[r][c] = new_dif;
                    pq.push({new_dif, {r, c}});
                }
            }
        }
        return res[n - 1][m - 1];
    }
};
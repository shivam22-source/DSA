class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    bool vailid(int x, int y, int n, int m) {
        if (x >= 0 && x < n && y >= 0 && y < m)
            return true;
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;
        int ma_t = 0;
        while (!pq.empty()) {
            int cur_time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return cur_time;

            for (int i = 0; i < 4; i++) {
                int xn = x[i] + row;
                int yn = y[i] + col;
                if (vailid(xn, yn, n, m) && !vis[xn][yn]) {
                    ma_t = max(grid[xn][yn], cur_time);
                    pq.push({ma_t, {xn, yn}});
                    vis[xn][yn] = true;
                }
            }
        }
        return ma_t;
    }
};
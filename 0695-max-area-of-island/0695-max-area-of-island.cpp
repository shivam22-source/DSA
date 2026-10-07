class Solution {
public:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, 1, -1};

    bool vailid(int i, int j, int n, int m) {
        if (i >= 0 && i < n && j >= 0 && j < m)
            return true;

        return false;
    }

    int fun(vector<vector<int>>& grid, int i, int j,
            int n, int m, vector<vector<int>>& vis) {

        if (!vailid(i, j, n, m) || vis[i][j] || grid[i][j] == 0)
            return 0;

        vis[i][j] = 1;

        int area = 1;

        for (int k = 0; k < 4; k++) {
            area += fun(grid, i + x[k], j + y[k],
                        n, m, vis);
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxar = 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vailid(i, j, n, m) &&
                    vis[i][j] == 0 &&
                    grid[i][j] == 1) {

                    maxar = max(maxar,
                                fun(grid, i, j, n, m, vis));
                }
            }
        }

        return maxar;
    }
};
class Solution {
public:
    int fun(vector<vector<int>>& grid, int col, int row,
            int n, int m, vector<vector<int>>& dp) {

        if (row == n - 1)
            return grid[row][col];

        if (dp[row][col] != -1000)
            return dp[row][col];

        int ans = INT_MAX;

        for (int nextCol = 0; nextCol < m; nextCol++) {
            if (nextCol == col) continue;

            ans = min(ans,
                      grid[row][col] +
                      fun(grid, nextCol, row + 1, n, m, dp));
        }

        return dp[row][col] = ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

     
        if (n == 1)
            return *min_element(grid[0].begin(), grid[0].end());

        vector<vector<int>> dp(n, vector<int>(m, -1000));

        int ans = INT_MAX;

        for (int col = 0; col < m; col++) {
            ans = min(ans, fun(grid, col, 0, n, m, dp));
        }

        return ans;
    }
};
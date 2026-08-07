class Solution {
public:
    int fun(string s, int i, int n, vector<int>& dp) {
        if (i == n)
            return 1;
        if (dp[i] != -1)
            return dp[i];

        if (s[i] == '0')
            return dp[i] = 0;
        int ways = fun(s, i + 1, n, dp); // single
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0'); // take two digit
            if (num >= 10 && num <= 26) {
                ways += fun(s, i + 2, n, dp);
            }
        }
        return dp[i] = ways;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return fun(s, 0, s.size(), dp);
    }
};
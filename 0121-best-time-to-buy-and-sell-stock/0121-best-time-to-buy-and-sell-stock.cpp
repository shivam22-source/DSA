class Solution {
public:
    // int fun(vector<int>& a, int i, int k, int n,vector<vector<int>>&dp) {
    //     if (i == n)
    //         return 0;
    //     if(dp[i][k]!=-1)return dp[i][k];
    //     if (k == 0)
    //         return 0;
    //     if (k == 2) {
    //         int c1 = -a[i] + fun(a, i + 1, k - 1, n,dp);
    //         int c2 = fun(a, i + 1, k, n,dp);
    //         return dp[i][k]= max(c1, c2);
    //     } else {
    //         int c1 = a[i] + fun(a, i + 1, k - 1, n,dp);
    //         int c2 = fun(a, i + 1, k, n,dp);
    //         return dp[i][k]= max(c1, c2);
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int k = 2;
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,0));
       
        for(int i=n-1;i>=0;i--){
            for(int j=2;j>=0;j--){
                if(j==0)continue;
                if(j==2){
                    dp[i][j]=max(-prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
                else {
                     dp[i][j]=max(prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][2];
    }
};
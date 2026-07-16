class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
    int m=2*k;
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
       
        for(int i=n-1;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(j==0)continue;
                if(j%2==0){
                    dp[i][j]=max(-prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
                else {
                     dp[i][j]=max(prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][m];
    }
};
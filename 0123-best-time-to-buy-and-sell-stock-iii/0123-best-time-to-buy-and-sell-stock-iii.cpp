class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 4;
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
       
        for(int i=n-1;i>=0;i--){
            for(int j=4;j>=0;j--){
                if(j==0)continue;
                if(j%2==0){
                    dp[i][j]=max(-prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
                else {
                     dp[i][j]=max(prices[i]+dp[i+1][j-1],dp[i+1][j]);
                }
            }
        }
        return dp[0][4];
    }
};
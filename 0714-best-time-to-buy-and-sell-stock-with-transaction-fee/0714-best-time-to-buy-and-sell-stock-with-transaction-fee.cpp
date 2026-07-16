class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
                     dp[i][j]=max(prices[i]-fee+dp[i+1][2],dp[i+1][j]);
                }
            }
        }
        return dp[0][2];
    }
};
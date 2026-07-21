class Solution {
public:
int fun(vector<int>&coins, int amount, int i,int n,vector<vector<int>>&dp){
     if(amount<0)return 1e9;
    if(i==n){
        if(amount==0)return 0;
        return 1e9;
    }
    if(dp[i][amount]!=-2)return dp[i][amount];

   
   int c1=1+fun(coins,amount-coins[i],i,n,dp);
   int c2=fun(coins,amount,i+1,n,dp);

   return dp[i][amount]= min(c1,c2);
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-2));
        int ans= fun(coins,amount,0,n,dp);
        if(ans==1e9)return -1;

        return ans;
    }
};
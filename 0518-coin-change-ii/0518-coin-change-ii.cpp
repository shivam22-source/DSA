class Solution {
public:
int fun(int amount, vector<int>&coins , int i, int n, vector<vector<int>>&dp){
    if(amount<0)return 0;
    if(i==n){
        if(amount==0)return 1;
        return 0;
    }
if(dp[i][amount]!=-1)return dp[i][amount];
    int c1=fun(amount-coins[i],coins,i,n,dp);
    int c2=fun(amount,coins,i+1,n,dp);

    return dp[i][amount]= c1+c2;

}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(amount,coins,0,n,dp);
    }
};
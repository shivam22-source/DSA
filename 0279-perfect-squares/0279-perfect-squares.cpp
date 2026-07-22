class Solution {
public:
int fun(int n,vector<int>&dp){
    if(n==0)return 0;
    if(dp[n]!=-1)return dp[n];
    int Min=INT_MAX;
    for(int i=1;i*i<=n;i++){
        
        int c=1+fun(n-i*i,dp);
        Min=min(Min,c);
    }
    return dp[n]= Min;
}
    int numSquares(int n) {
        vector<int>dp(10001,-1);
        return fun(n,dp);
    }
};
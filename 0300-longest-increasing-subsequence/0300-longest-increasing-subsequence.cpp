class Solution {
public://dp memosiation
int fun(vector<int>& nums, int i, int n, int prev,vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][prev+1]!=-1)return dp[i][prev+1];
    if(prev==-1 || nums[prev]<nums[i]){
        int c1=1+fun(nums,i+1,n,i,dp);
        int c2=fun(nums,i+1,n,prev,dp);

        return dp[i][prev+1]= max(c1,c2);
    }
    else {
        return dp[i][prev+1]=fun(nums,i+1,n,prev,dp);
    }

}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        dp[n][n]=0;
        return fun(nums,0,n,-1,dp);
    }
};
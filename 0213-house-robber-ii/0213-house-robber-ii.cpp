class Solution {
public:
int fun(vector<int>& nums,int i,int end,vector<int>&dp){
    if(i>end)return 0;

    if(dp[i]!=-1)return dp[i];

    int c1=nums[i]+fun(nums,i+2,end,dp);
    int c2=fun(nums,i+1,end,dp);
    return dp[i]=max(c1,c2);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1),dp2(n,-1);
        return max(fun(nums,0,n-2,dp1),fun(nums,1,n-1,dp2));
    }
};
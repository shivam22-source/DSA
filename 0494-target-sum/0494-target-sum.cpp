class Solution {
public:
int fun(vector<int>& nums,int i, int target,vector<vector<int>>&dp,int sum){
    if(target<-sum || target>sum)return 0;
    if(i==nums.size()){
        if(target==0)return 1;
        return 0;
    }
    if(dp[i][target+sum]!=-1)return dp[i][target+sum];
    int c1=fun(nums,i+1,target-nums[i],dp,sum);
    int c2=fun(nums,i+1,target+nums[i],dp,sum);
    return dp[i][target+sum]= c1+c2;
}
    int findTargetSumWays(vector<int>& nums, int target) {
    int n=nums.size();
    int sum=0;
    for(auto it:nums)sum+=it;
    vector<vector<int>>dp(n+1,vector<int>(2*sum+1,-1));
        return fun(nums,0,target,dp,sum);
    }
};
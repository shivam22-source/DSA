class Solution {
public:
int fun(vector<int>nums,int i,int j,vector<vector<int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int i_th=nums[i]+min(fun(nums,i+2,j,dp),fun(nums,i+1,j-1,dp));
    int j_th=nums[j]+min(fun(nums,i+1,j-1,dp),fun(nums,i,j-2,dp));
  return dp[i][j]= max(i_th,j_th);
}
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int p1= fun(nums,0,n-1,dp);
    int val=0;
    for(auto it:nums)val+=it;
    val=val-p1;
    return val<=p1;
    }
};
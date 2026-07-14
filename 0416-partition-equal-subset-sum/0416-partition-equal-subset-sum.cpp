class Solution {
public:
bool fun(vector<int>&arr,int sum){
        //tabulation
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(sum+1,false));
    dp[n][0]=true;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=sum;j++){
            if(arr[i]>j){
                dp[i][j]=dp[i+1][j];
            }
            else 
            dp[i][j]=(dp[i+1][j-arr[i]])||(dp[i+1][j]);
        }
    }
    return dp[0][sum];
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)sum+=nums[i];
        if(sum%2!=0)return false;
        return fun(nums,sum/2);
    }
};
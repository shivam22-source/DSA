class Solution {
public:

int fun(vector<vector<int>>&arr,int i,int n,vector<int>&dp){
if(i >= n)
    return 0;
if(dp[i]!=-1)return dp[i];

int curr_end_idx=arr[i][1];
int l=i+1;
int r=n-1;
int next_idx=n;

int res=0;
while(l<=r){
    int mid=(l+r)/2;
    if(arr[mid][0]>=curr_end_idx){
next_idx=mid;
r=mid-1;
    }
    else {
        l=mid+1;
    }
}
int c1=arr[i][2]+fun(arr,next_idx,n,dp);
int c2=fun(arr,i+1,n,dp);
return dp[i]= max(c1,c2);

}


    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(arr.begin(),arr.end());
int res=0;
vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++){
            int ans=fun(arr,i,n,dp);
            res=max(ans,res);

        }
        return res;

    }
};
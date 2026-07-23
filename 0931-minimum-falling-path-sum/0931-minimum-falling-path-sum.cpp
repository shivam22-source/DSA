class Solution {
public:


int fun(vector<vector<int>>& matrix,int i, int j,int m, int n,vector<vector<int>>&dp){
    if(i==n)return 0;
    if(dp[i][j]!=-10000)return dp[i][j];


   int ans=matrix[i][j]+fun(matrix,i+1,j,m,n,dp);

   if(j-1>=0){
    ans=min(ans,matrix[i][j]+fun(matrix,i+1,j-1,m,n,dp));
   }
   if(j+1<m){
    ans=min(ans,matrix[i][j]+fun(matrix,i+1,j+1,m,n,dp));
   }
   return dp[i][j]= ans;

    
}

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-10000));
       for(int j=0;j<m;j++){
        ans=min(ans,fun(matrix,0,j,m,n,dp));
       }
return ans;
    }
};
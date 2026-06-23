class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,-1,1};

bool vaild(int i,int j, int m, int n){
    if(i>=0&&i<n && j>=0&&j<m)return true;
    return false;
}

void dfs(vector<vector<char>>& grid,vector<vector<bool>>&vis,int m, int n, int i, int j){
    vis[i][j]=1;
    for(int k=0;k<4;k++){
        int row=i+x[k];
        int col=j+y[k];
        if(vaild(row,col,m,n)&&!vis[row][col]&& grid[row][col]=='1'){
            dfs(grid,vis,m,n,row,col);
        }
    }
    return;
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;

        vector<vector<bool>>vis(n,vector<bool>(m,0));
       

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vaild(i,j,m,n)&& !vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,m,n,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
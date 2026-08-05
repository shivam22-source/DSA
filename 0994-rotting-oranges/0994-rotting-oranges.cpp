class Solution {
public:
int x[4]={-1,1,0,0};
int y[4]={0,0,1,-1};
int time;

bool vailid(int i,int j,int n,int m){
    if(i>=0 && i<n && j>=0 && j<m)return true;
    return false;
}

void bfs(vector<vector<int>>& grid,int n,int m,queue<pair<int, int>>&q,int &fresh){
    while(!q.empty()&& fresh>0){
        int size=q.size();
        while(size--){
       
            int h=q.front().first;
            int v=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int X=x[i]+h;
                int Y=y[i]+v;
                if(vailid(X,Y,n,m)&&grid[X][Y]==1){
                    grid[X][Y]=2;
                    q.push({X,Y});
                    fresh--;
                }
            }
                
        }
         time++;
    }
    

}
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        time=0;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        bfs(grid,n,m,q,fresh);

        if(fresh!=0)return -1;
        return time;
    }
};
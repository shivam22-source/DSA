class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       
        vector<int>result(n+1,INT_MAX);
        result[k]=0;
         pq.push({0,k});
         
         while(!pq.empty()){
             int d=pq.top().first;
             int node=pq.top().second;
             pq.pop();
             for(auto &v:adj[node]){
                 int dist=v.second;
                 int node_s=v.first;
                 if(d+dist<result[node_s]){
                     result[node_s]=d+dist;
                     pq.push({d+dist,node_s});
                 }
             }
             
         }
         
         int ans=0;

        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX)return -1;
            ans=max(ans,result[i]);
        }
        return ans;
    }
};
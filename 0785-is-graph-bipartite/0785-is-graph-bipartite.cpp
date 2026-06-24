class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph, int node, int col, vector<int>& colr) {
        colr[node] = col;
        for (int i = 0; i < graph[node].size(); i++) {
            int neigh = graph[node][i];
            if (colr[neigh] != -1) {
                if (colr[neigh] == col) {
                    res = false;
                   
                }
            } else {
                    dfs(graph, neigh, 1 - col, colr);

                }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> colr(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++) {
            if (colr[i] == -1) {
                dfs(graph, i, 0, colr);
            }
        }
        return res;
    }
};
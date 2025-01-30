class Solution {

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<bool> visited(n, false);
        vector<int> color(n, 0);

        bool ans = true;
        for (int i = 0; i < n; i++) {
            if (!color[i]) {
                color[i] = 1;
                dfs(i, color, graph, ans);
            }
        }

        return ans;
    }

private:
    void dfs(int node, vector<int>&color, vector<vector<int>>& graph, bool& ans) {
        if(color[node] == 1){
            for(auto adj:graph[node]){
                if(color[adj] == 0) {
                    color[adj] = 2;
                    dfs(adj,color,graph,ans);
                }
                else if(color[adj] == 1) ans = false;
            }
        } else if(color[node] == 2){
            for(auto adj:graph[node]){
                if(color[adj] == 0) {
                    color[adj] = 1;
                    dfs(adj,color,graph,ans);
                }
                else if(color[adj] == 2) ans = false;
            }
        }
    }
};
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        int m = adj[0].size();
        vector<bool> visited(n,false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<vector<int>> q;
                q.push({i, -1});
                while(!q.empty()){
                    vector<int> nodes = q.front();
                    q.pop();
                    int parent = nodes[1];
                    int val = nodes[0];
                    visited[val] = true;
                    for(auto i:adj[val]){
                        if(visited[i] and i!=parent) return true;
                        if(!visited[i]) q.push({i, val});
                    }
                }
            }
        }
        return false;
    }
};
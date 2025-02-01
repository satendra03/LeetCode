class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        stack<int> store;
        for(int node = 0; node < n; node++){
            if(!visited[node]) dfs(node, store, visited, adj);
        }
        vector<int> topo;
        while(!store.empty()){
            int node = store.top();
            store.pop();
            topo.push_back(node);
        }
        return topo;
    }
private:
    void dfs(int node, stack<int>& store, vector<bool>& visited, vector<vector<int>>& adj){
        visited[node] = true;
        for(auto friends:adj[node]){
            if(!visited[friends]) dfs(friends, store, visited, adj);
        }
        store.push(node);
    }
};
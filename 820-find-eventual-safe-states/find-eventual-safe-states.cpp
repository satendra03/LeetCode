class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            for(auto node:graph[i]) adj[node].push_back(i);
        }

        vector<int> indegree(n, 0);
        for(auto nodes:adj) for(auto node:nodes) indegree[node]++;

        queue<int> q;
        for(int i=0; i<n; i++) if(!indegree[i]) q.push(i);

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            indegree[node] = -1;
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
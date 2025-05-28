class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        // int n = edges1.size(), m = edges2.size();

        // int maxNode = 0;
        // for (auto& edge : edges2) {
        //     maxNode = max({maxNode, edge[0], edge[1]});
        // }
        // maxNode++; // because nodes start from 0
        int n = 0, m = 0;

        for(auto& edge:edges1) n=max({n, edge[0], edge[1]});
        n++;

        for(auto& edge : edges2) m=max({m, edge[0], edge[1]});
        m++;

        vector<vector<int>> graph(n);
        vector<vector<int>> adj(m);
        for(auto& edge:edges1) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(auto& edge:edges2) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> distN(n, 0), distM(m, 0); 
        for(int i=0; i<n; i++){
            vector<bool>visited(n, false);
            distN[i]=getNodes(graph, i, visited, k);
        }
        for(int i=0; i<m; i++){
            vector<bool>visited(m, false);
            distM[i]=getNodes(adj, i, visited, k-1);
        }
        int val = *max_element(distM.begin(), distM.end());


        vector<int> answer(n, 0);
        for (int i=0; i<n;i++) {
            for(int j=0; j<m; j++){
                answer[i]=distN[i]+val;
            }
        }
        return answer;
    }

private:
    int getNodes(vector<vector<int>>& adj, int node, vector<bool>& visited,
                 int k) {
        if (visited[node])
            return 0;
        if (k < 0)
            return 0;
        visited[node] = true;
        int ans = 0;
        for (auto& n : adj[node]) {
            if (!visited[n])
                ans += getNodes(adj, n, visited, k - 1);
        }
        return ans + 1;
    }
};
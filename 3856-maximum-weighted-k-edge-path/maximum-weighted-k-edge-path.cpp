class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    vector<vector<unordered_map<int, int>>> dp;
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        graph.resize(n);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1], w = edge[2];
            graph[u].emplace_back(v,w);
        }
        dp.assign(n, vector<unordered_map<int, int>>(k + 1));

        int sum = -1;
        for(int i=0; i<n; i++){
            int ans = dfs(i, 0, k, t);
            sum = max(sum, ans);
        }
        return sum;
    }
private:
    int dfs(int node, int sum, int k, int t) {
        if(k==0) return sum < t ? sum : -1;

        if(dp[node][k].count(sum)) return dp[node][k][sum];
        
        int ans = -1;
        for (auto& [v,w]: graph[node]) {
            int newSum = sum + w;
            if (newSum < t) {
                int tempAns = dfs(v, newSum, k-1, t);
                if(tempAns != -1) ans = max(ans, tempAns);
            }
        }

        return dp[node][k][sum] = ans;
    }
};
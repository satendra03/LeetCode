class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> insertTime(n), lowestInsertTime(n);
        vector<bool> vis(n, false);
        vector<vector<int>> bridges;

        vector<vector<int>> graph(n);
        for(auto connection:connections){
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        for(int node=0; node<n; node++){
            if(!vis[node]) dfs(node, graph, insertTime, lowestInsertTime, vis, time, n+1, bridges);
        }

        return bridges;
    }
private:
    int time = 0;
    void dfs(int node, vector<vector<int>>& graph, 
        vector<int>& insertTime, vector<int>& lowestInsertTime, 
        vector<bool>& vis, int time, int parent, vector<vector<int>>& bridges){
        vis[node] = true;
        insertTime[node] = time;
        lowestInsertTime[node] = time;
        time++;
        for(auto i:graph[node]) {
            if(i == parent) continue;
            else if(!vis[i]) {
                dfs(i, graph, insertTime, lowestInsertTime, vis, time, node, bridges);
                lowestInsertTime[node] = min(lowestInsertTime[node], lowestInsertTime[i]);
                if(insertTime[node] < lowestInsertTime[i]) bridges.push_back({node, i});
            }
            else lowestInsertTime[node] = min(lowestInsertTime[node], lowestInsertTime[i]);
        }
    }
};
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n, false);
        vector<bool> isAns(n, false);
        unordered_set<int> path;

        for(int i=0; i<n; i++) if(!visited[i]) dfs(i, graph, visited, path, isAns);

        vector<int> ans;
        for(int i=0; i<n; i++) if(isAns[i]) ans.push_back(i);
        return ans;
    }
private:
    bool dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, unordered_set<int>& path, vector<bool>& isAns) {
        visited[node] = true;
        path.insert(node);
        isAns[node] = false;
        for(auto i:graph[node]){
            if(!visited[i]) {
                bool isValid = dfs(i, graph, visited, path, isAns);
                if(isValid) {
                    isAns[i] = false;
                    return true;
                }
            }
            else if(path.count(i)) {
                    isAns[i] = false;
                    return true;
                }
        }

        isAns[node] = true;
        path.erase(node);
        return false;
    }
};
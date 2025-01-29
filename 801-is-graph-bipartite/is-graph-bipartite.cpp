class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        unordered_set<int> A;
        unordered_set<int> B;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                insert(i, graph, A, B, visited);
            }
        }

        for (auto i : A)
            if (B.count(i))
                return false;

        return true;
    }

private:
    void insert(int node, vector<vector<int>>& graph, unordered_set<int>& A,
                unordered_set<int>& B, vector<bool>& visited) {

        queue<tuple<int, bool>> q;
        visited[node] = true;
        A.insert(node);
        q.push({node, true});

        while (!q.empty()) {
            auto [i, isFromA] = q.front();
            visited[i] = true;
            q.pop();

            if (isFromA) {
                for (auto elem : graph[i]) {
                    if (!visited[elem]) {
                        B.insert(elem);
                        q.push({elem, false});
                    }
                }
            } else {
                for (auto elem : graph[i]) {
                    if (!visited[elem]) {
                        A.insert(elem);
                        q.push({elem, true});
                    }
                }
            }
        }
    }
};
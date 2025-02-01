class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> toDoThisIhaveToCompleteThese(n);
        vector<int> indegree(n);
        for (auto pre : prerequisites) {
            int a = pre[0];
            int b = pre[1];
            indegree[a]++;
            toDoThisIhaveToCompleteThese[b].insert(a);
        }

        queue<int> q;
        vector<int> ans;
        for(int i=0; i<n; i++) if(!indegree[i]) q.push(i);

        if(q.empty()) return false;

        while(!q.empty()){
            int node  = q.front();
            q.pop();
            ans.push_back(node);
            indegree[node] = -1;
            for(auto i:toDoThisIhaveToCompleteThese[node]){
                if(indegree[i] > 0) indegree[i]--;
                if(!indegree[i]) q.push(i);
            }
        }
        return ans.size() == n;
    }
};
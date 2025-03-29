class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> graph;
        for(int i=0; i<times.size(); i++){
            int src = times[i][0];
            int dst = times[i][1];
            int time = times[i][2];
            graph[src].push_back({dst, time});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;

        set<pair<int, int>> pq;
                // time, node
        pq.insert({0, k});

        while(!pq.empty()){
            pair<int, int> data = *pq.begin();
            pq.erase(data);
            int Time = data.first;
            int node = data.second;

            for(auto& i:graph[node]){
                int friendNode = i[0];
                int friendTime = i[1];
                if( Time + friendTime < dist[friendNode] ){
                    dist[friendNode] = Time + friendTime;
                    pq.insert({dist[friendNode], friendNode});
                }
            }
        }

        int ans = INT_MIN;
        for(int i=1; i<n+1; i++){
            if (dist[i] == INT_MAX) return -1;
            else ans = max(ans, dist[i]);
        }
        return ans;
    }

};
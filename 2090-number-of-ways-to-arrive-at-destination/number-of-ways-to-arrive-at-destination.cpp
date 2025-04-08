typedef long long ll;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        map<ll, vector<vector<ll>>> graph;
        for(auto& road:roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<ll> dist(n,LLONG_MAX);
        vector<ll> ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        
        set<pair<ll,ll>> pq;
        pq.insert({0, 0});
            // distance, node
        
        while(!pq.empty()){
            pair<ll,ll> it = *pq.begin();
            pq.erase(it);
            ll distance = it.first;
            ll node = it.second;
            if(distance > dist[node]) continue; 
            for(auto& i:graph[node]){
                ll Distance = i[1];
                ll Node = i[0];
                ll newDistance = distance + Distance;
                if(newDistance < dist[Node]){
                    dist[Node] = newDistance;
                    ways[Node] = ways[node];
                    pq.insert({dist[Node], Node});
                }
                else if(distance + Distance == dist[Node]) {
                    ways[Node] = (ways[Node] + ways[node]) % 1000000007;
                }
            }
        }

        return ways[n-1];
    }
};
class Solution {
public:
    int n, m;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        int ans = INT_MAX;
        set<pair<int, pair<int, int>>> pq;
            //{ diff ,  {x,y} }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.insert({0, {0,0}});
        while(!pq.empty()){
            auto it = pq.begin();
            pair<int, pair<int, int>> data = *it;
            pq.erase(it);
            int diff = data.first;
            int x = data.second.first;
            int y = data.second.second;

            if(x==n-1 and y==m-1) return diff;
            
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 and newX<n and newY>=0 and newY<m){
                    int newDiff = max(
                        abs(heights[newX][newY] - heights[x][y]),
                        diff
                    );
                    if(newDiff < dist[newX][newY]){
                        dist[newX][newY] = newDiff;
                        pq.insert({newDiff, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};
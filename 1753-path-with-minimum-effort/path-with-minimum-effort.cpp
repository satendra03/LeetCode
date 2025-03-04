class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        dist[0][0] = 0;
        pq.push({0,0,0});
        while(!pq.empty()){
            auto [maxEffortOfRoute, x, y] = pq.top();
            pq.pop();

            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX>=0 and newX<n and newY>=0 and newY<m){
                    // this is the effort that I have to do to clim to this newX, newY
                    int effortForThisHeight = abs(heights[x][y] - heights[newX][newY]);

                    // if this Effort is the max of the effort till now, for the route then we will take this 
                    // or else we will continue with the max effort 
                    // in short we will take the max effort of route ()
                    int newMaxEffortOfRoute = max(effortForThisHeight, maxEffortOfRoute);

                    // if this new Effort is less than the current effort for this coordinate then
                    // we will consider this
                    if(newMaxEffortOfRoute < dist[newX][newY]){
                        dist[newX][newY] = newMaxEffortOfRoute;
                        pq.push({newMaxEffortOfRoute, newX, newY});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};
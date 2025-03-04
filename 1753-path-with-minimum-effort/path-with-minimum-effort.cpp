class Solution {
public:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        int l = 0, r = 1e6, ans = r;

        auto isPath = [&](int limitEffort){
            using T = tuple<int,int>;
            queue<T> q;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            q.push({0,0});
            visited[0][0] = true;

            while(!q.empty()){
                auto [x,y] = q.front();
                q.pop();

                if(x==n-1 and y==m-1) return true;

                for(int i=0; i<4; i++){
                    int newX = x + dx[i];
                    int newY = y + dy[i];
                    if(newX>=0 and newX<n and newY>=0 and newY<m){
                        int effort = abs(heights[x][y] - heights[newX][newY]);
                        if(effort <= limitEffort and !visited[newX][newY]){
                            visited[newX][newY] = true;
                            q.push({newX, newY});
                        }
                    }
                }
            }

            return false;    
        };

        while(l <= r){
            int mid = (l+r) / 2;
            if(isPath(mid)){
                ans = mid;
                r = mid - 1;
            } else l = mid + 1;
        }

        return ans;
    }
};
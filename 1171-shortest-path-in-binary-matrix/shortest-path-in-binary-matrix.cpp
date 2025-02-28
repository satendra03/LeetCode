class Solution {
public:
    struct Comp {
        bool operator()(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) const {
            if (a.first != b.first) return a.first < b.first;
            if (a.second.first != b.second.first) return a.second.first > b.second.first;
            return a.second.second > b.second.second;
        }
    };
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        set<pair<int, pair<int,int>>, Comp> q;

        q.insert({1, {0,0}});
        int ans = INT_MAX;
        visited[0][0] = true;

        while(!q.empty()){
            pair<int, pair<int,int>> data = *q.begin();
            int dist = data.first;
            int x = data.second.first;
            int y = data.second.second;
            visited[x][y] = true;
            if(x==n-1 and y==n-1) ans = min(ans, dist);
            q.erase(data);

            for(int i=0; i<8; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 and newX < n and newY >= 0 and newY < n and !grid[newX][newY] and !visited[newX][newY]){
                    q.insert({dist+1, {newX, newY}});
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);

    }
};
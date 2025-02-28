class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]) return -1;
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({1, {0, 0}});
        dist[0][0] = 1;

        while (!pq.empty()) {
            auto [d, cell] = pq.top();
            int x = cell.first, y = cell.second;
            pq.pop();

            if (x == n - 1 && y == n - 1) return d;

            for (int i = 0; i < 8; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
                    if (d + 1 < dist[newX][newY]) {  
                        dist[newX][newY] = d + 1;
                        pq.push({d + 1, {newX, newY}});
                    }
                }
            }
        }
        return -1;
    }
};

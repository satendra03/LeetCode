class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] and grid[i][j] == '1') {
                    queue<vector<int>> q;
                    q.push({i, j});
                    ans++;
                    while (!q.empty()) {
                        vector<int> point = q.front();
                        q.pop();
                        if (visited[point[0]][point[1]])
                            continue;
                        visited[point[0]][point[1]] = true;
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = point[0] + dx[dir]; // New row
                            int ny = point[1] + dy[dir]; // New column
                            if (nx >= 0 and nx < n and ny >= 0 and ny < m) {
                                if (grid[nx][ny] == '1') {
                                    if (!visited[nx][ny])
                                        q.push({nx, ny});
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
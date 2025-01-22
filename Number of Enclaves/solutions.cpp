class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        vector<int> row = {0, m - 1};
        vector<int> col = {0, n - 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (grid[row[j]][i]==1) {
                    dfs(row[j], i, visited, grid);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                if (grid[i][col[j]]==1) {
                    dfs(i, col[j], visited, grid);
                }
            }
        }

        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] and grid[i][j]) count++;
            }
        }
        return count;
    }
private:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& grid){
        visited[i][j] = true;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int dir=0; dir<4; dir++){
            int x = i + dx[dir];
            int y = j + dy[dir];
            if(x>=0 and x<grid.size() and y>=0 and y<grid[0].size()){
                if(!visited[x][y] and grid[x][y]){
                    dfs(x,y,visited,grid);
                }
            }
        }
    }
};
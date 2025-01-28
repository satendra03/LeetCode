struct Vector2DComparator {
    bool operator()(const vector<vector<int>>& a, const vector<vector<int>>& b) const {
        return a < b;
    }
};
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        set<vector<vector<int>>, Vector2DComparator> data;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] and !visited[i][j]){
                    vector<vector<int>> path;
                    dfs(i,j,visited,grid,path,i,j);
                    data.insert(path);
                }
            }
        }
        
        return data.size();
    }
    
private:
    void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<int>>& grid, vector<vector<int>>& path,int orgX, int orgY){
        int n = grid.size();
        int m = grid[0].size();
        
        if(visited[i][j]) return;
        visited[i][j] = true;
        
        path.push_back({i-orgX,j-orgY});
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        for(int dir = 0; dir < 4; dir++){
            int x = i + dx[dir];
            int y = j + dy[dir];
            if(x >= 0 and x < n and y >= 0 and y < m and grid[x][y] and !visited[x][y]){
                dfs(x,y,visited,grid,path,orgX,orgY);
            }
        }
    }
};
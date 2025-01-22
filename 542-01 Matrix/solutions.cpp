class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        //  up, right, down, left

        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<vector<int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push({i,j,0});
                    visited[i][j] = true;
                }
            }
        }

        int dist = 0; 
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                vector<int> node = q.front();
                q.pop();
                dist = max(dist, node[2]);
                for (int i = 0; i < 4; i++) {
                    int x = node[0] + dx[i];
                    int y = node[1] + dy[i];
                    if (x >= 0 and x < n and y >= 0 and y < m) {
                        if (!visited[x][y] and ans[x][y] == INT_MAX) {
                            q.push({x, y, dist+1});
                            visited[x][y] = true;
                            ans[x][y] = dist+1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
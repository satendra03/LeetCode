class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;

        int toChange = image[sr][sc];

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        //  up, right, down, left

        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(), false));

        queue<vector<int>> q;
        q.push({sr,sc});
        while(!q.empty()){
            vector<int> node = q.front();
            q.pop();
            if(visited[node[0]][node[1]]) continue;
            visited[node[0]][node[1]] = true;
            image[node[0]][node[1]] = color;
            for(int i=0; i<4; i++){
                int x = node[0] + dx[i];
                int y = node[1] + dy[i];
                if(x >= 0 and x < image.size() and y >= 0 and y < image[0].size()){
                    if(!visited[x][y] and image[x][y] == toChange) q.push({x,y});
                }
            }
        }
        return image;
    }
};
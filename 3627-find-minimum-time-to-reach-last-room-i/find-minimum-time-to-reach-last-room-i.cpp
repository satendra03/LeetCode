class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        ans[0][0] = 0;
        q.push({0,0,0}); // {time, x, y}
        while(!q.empty()){
            vector<int> curr = q.top();
            int time = curr[0], x = curr[1], y = curr[2];
            q.pop();

            if(time > ans[x][y]) continue;

            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >=0 and newX < n and newY >=0 and newY < m){
                    int nextTime = time + 1;
                    if (nextTime <= moveTime[newX][newY]) nextTime = moveTime[newX][newY] + 1;

                    if (nextTime < ans[newX][newY]) {
                        ans[newX][newY] = nextTime;
                        q.push({nextTime, newX, newY});
                    }
                }
            }
        }

        return ans[n-1][m-1];
    }
};
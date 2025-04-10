class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int limit) {
        vector<vector<int>> dist(n, vector<int> (n, 10001));
        for(auto& edge:edges) {
            int i=edge[0], j=edge[1], distance=edge[2];
            dist[i][j]=distance; 
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(i==j) dist[i][i]=0;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    dist[j][i] = dist[i][j];
                }
            }
        }

        vector<int> data(n, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j and dist[i][j] <= limit) data[i]++;
            }
        }
        int minVal = INT_MAX;
        for(auto& num:data) minVal = min(minVal, num);
        int ans;
        for(int i=n-1; i>=0; i--){
            if(data[i]==minVal) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};
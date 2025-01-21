class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count = max(m,n);
        unordered_map<int, vector<int>> data;
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                data[mat[i][j]] = {i,j};
            }
        
        for(int i=0; i<arr.size(); i++){
            vector<int> points = data[arr[i]];
            int x = points[0];
            int y = points[1];
            row[x]++;
            col[y]++;
            if(row[x]==n or col[y]==m) return i;
        }
        return arr.size()-1;
    }
};
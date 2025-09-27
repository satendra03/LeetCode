class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> ans;

        int left = 0, right = m-1;
        int top = 0, bottom = n-1;

        while(top <= bottom and left <= right){
            // left to right with fixed top
            for(int i=left; i<=right; i++) ans.push_back(matrix[top][i]);
            top++;

            // top to bottom with fixed right
            for(int i=top; i<=bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            if(top <= bottom) {
                // right to left with fixed bottom
                for(int i=right; i>=left; i--) ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            if(left <= right) {
                // bottom to top with fixed left
                for(int i=bottom; i>=top; i--) ans.push_back(matrix[i][left]);
                left++; 
            }
        }

        return ans;
    }
};
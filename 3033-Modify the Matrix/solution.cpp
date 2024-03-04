/*
Given a 0-indexed m x n integer matrix matrix, create a new 0-indexed matrix called answer. Make answer equal to matrix, then replace each element with the value -1 with the maximum element in its respective column.
Return the matrix answer.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxofcol(int row, int col, vector<vector<int>>& matrix) {
        int maxi = -1;
        for (int i = 0; i < row; i++) {
            if (matrix[i][col] > maxi)
                maxi = matrix[i][col];
        }
        return maxi;
    }
    
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> answer = matrix;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (answer[i][j] == -1) {
                    int temp = maxofcol(m, j, matrix);
                    answer[i][j] = temp;
                }
            }
        }
        return answer;
    }
};

// Test function
int main() {
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, -1}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> result = sol.modifiedMatrix(matrix);
    cout << "Modified Matrix:" << endl;
    for(const auto& row : result) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}
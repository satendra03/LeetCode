class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& data) {
        vector<vector<int>> ans;
        int n = arr.size();
        int x = data[0], y = data[1];

        int ptr = 0;
        while(ptr<n and x>arr[ptr][1]) {
            ans.push_back(arr[ptr]);
            ptr++;
        }

        int newStart = x, newEnd = y;
        while(ptr<n and y>=arr[ptr][0]){
            newStart = min(newStart, arr[ptr][0]);
            newEnd = max(newEnd, arr[ptr][1]);
            ptr++;
        }
        ans.push_back({newStart, newEnd});

        while(ptr<n) ans.push_back(arr[ptr++]);

        return ans;
    }
};
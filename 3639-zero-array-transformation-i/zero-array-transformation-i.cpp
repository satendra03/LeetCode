class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m=queries.size();
        sort(queries.begin(), queries.end());
        vector<int> data(n+1, 0);
        for(auto& qu:queries){
            data[qu[0]]++;
            data[qu[1]+1]--;
        }
        vector<int> sum(n+1, 0);
        sum[0] = data[0];
        for(int i=1; i<n+1; i++) sum[i] = sum[i-1] + data[i];
        for(int i=0; i<n; i++) if(sum[i] < nums[i]) return false;
        return true;
        
    }
};
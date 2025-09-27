class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int start = nums[0][0], end = nums[0][1];

        for(int i=1; i<n; i++){
            if(nums[i][0] <= end){
                // overlapping
                end = max(end, nums[i][1]);
            } else {
                ans.push_back({start, end});
                start = nums[i][0];
                end = nums[i][1];
            }
        }
        ans.push_back({start, end});

        return ans;
    }
};
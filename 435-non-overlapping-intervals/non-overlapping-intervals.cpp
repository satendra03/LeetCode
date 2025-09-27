class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [&](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });

        int ans = 0;
        int time = -1e9;

        for(int i=0; i<n; i++){
            if(nums[i][0] >= time){
                ans++;
                time = nums[i][1];
            }
        }
        return n - ans;
    }
};
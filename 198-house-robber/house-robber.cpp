class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];

        dp.resize(n, -1);
        return f(0, nums);
    }
private:
    vector<int> dp;
    int f(int i, vector<int>& nums){
        int n = nums.size();
        if( i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        
        int rob_current = nums[i] + f(i + 2, nums);
        int skip_current = f(i + 1, nums);

        return dp[i] = max(rob_current, skip_current);
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];

        // dp.resize(n, -1);
        // return f(0, nums);

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            int rob = nums[i], skip = 0;
            if(i-2 >=0) rob += dp[i-2];
            if(i-1 >=0) skip = dp[i-1];
            dp[i] = max(rob, skip);


        }
        return dp[n-1];
    }
private:
    vector<int> dp;
    int f(int i, vector<int>& nums){
        int n = nums.size();
        if( i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        
        int rob = nums[i] + f(i + 2, nums);
        int skip = f(i + 1, nums);

        return dp[i] = max(rob, skip);
    }
};
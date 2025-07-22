class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];

        dp.resize(n, -1);
        return max(nums[0]+f(0, nums), nums[1]+f(1, nums) );
    }
private:
    vector<int> dp;
    int f(int i, vector<int>& nums){
        int n = nums.size();
        if( i >= n) return 0;

        if(dp[i] != -1) return dp[i];
        
        int money = 0;
        for(int index=i+2; index<n; index++){
            int newMoney = INT_MIN;
            if(index < n){
                newMoney = nums[index] + f(index, nums);
            }
            money = max(money, newMoney);
        }

        return dp[i] = money;
    }
};
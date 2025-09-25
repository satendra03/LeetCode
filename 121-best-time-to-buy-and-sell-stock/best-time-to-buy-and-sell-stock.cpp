class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        int minPrice = nums[0];
        for(int i=1; i<n; i++){
            profit = max(profit, nums[i] - minPrice);
            minPrice = min(minPrice, nums[i]);
        }
        return profit;
    }
};
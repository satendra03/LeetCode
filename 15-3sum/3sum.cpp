class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> data;

        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            int target = -nums[i];

            int left = i+1, right = n-1;
            while(left<right) {
                int sum = nums[left]+nums[right];
                if(sum == target) {
                    data.insert({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
        vector<vector<int>> ans(data.begin(), data.end());
        return ans;
    }
};
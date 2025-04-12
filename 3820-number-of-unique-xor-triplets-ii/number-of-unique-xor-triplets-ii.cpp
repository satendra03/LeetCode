class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> one(nums.begin(), nums.end());
        unordered_set<int> two;

        for(int i=0; i<n; i++){
            for(auto& num:one) two.insert(nums[i]^num);
        }
        for(int i=0; i<n; i++){
            for(auto& num:two) one.insert(nums[i]^num);
        }

        return one.size();
    }
};
typedef __int128 lll;
typedef long long ll;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, ll target) {
        lll prod = 1;
        for(auto& num:nums) prod*=num;
        return prod == (lll)target*target;
    }
};
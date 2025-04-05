class Solution {
private:
    // int orarr(vector<int> & arr){
    //     int ans = 0;
    //     for(auto i:arr) ans|=i;
    //     return ans;
    // }
    void f(int index, vector<int>& nums, int& size, int& ans, int x) {
        if (index >= size) {
            ans += x;
            return;
        }
        f(index + 1, nums, size, ans, x);
        f(index + 1, nums, size, ans, x^nums[index]);
        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int x = 0;
        int size=nums.size();
        f(0, nums, size, ans, x);
        return ans;

        // Another Solution
        // int ans = orarr(nums);
        // return ans * pow(2, nums.size()-1);
    }
};
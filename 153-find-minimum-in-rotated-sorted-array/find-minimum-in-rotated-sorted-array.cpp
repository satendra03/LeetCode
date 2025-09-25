class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left=0, right=n-1;
        int mid=left+(right-left)/2;

        // the array is rotated in such a way, it became orignial
        if(nums[left]<nums[right]) return nums[left];

        while(left < right) {
            if(nums[mid] >= nums[0]) left=mid+1;
            else right=mid;
            mid=left+(right-left)/2;
        }
        return nums[mid];
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;

        while(left <= right){
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return mid;
             
             if(nums[left] <= nums[mid]){
                //  left is sorted
                if(nums[left] <= target and target <= nums[mid]) right = mid-1;
                else left = mid+1;
             } else {
                //  right is sorted 
                if(nums[mid] <= target and target <= nums[right]) left = mid+1;
                else right = mid-1;
             }
            mid = left+(right-left)/2;
        }

        return -1;
    }
};
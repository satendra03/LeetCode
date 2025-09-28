class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // instead think it as subarry with at most k zeros
        int n = nums.size();
        int left = 0, right = 0, maxLen = 0, zeros = 0;
        
        while(right < n){   
            if(!nums[right]) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            if(zeros <= k) maxLen = max(maxLen, right-left+1);
            right++;
        }

        return maxLen;
    }
};
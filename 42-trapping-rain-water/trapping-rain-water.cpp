class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int left = 0, right = n-1;
        int leftMax = arr[0], rightMax = arr[n-1];
        int total = 0;

        while(left < right){
            if(leftMax < rightMax) {
                left++;
                if(arr[left] < leftMax) total += leftMax - arr[left];
                leftMax = max(leftMax, arr[left]);
            } else {
                right--;
                if(arr[right] < rightMax) total += rightMax - arr[right];
                rightMax = max(rightMax, arr[right]);
            }
        }
        return total;
    }
};
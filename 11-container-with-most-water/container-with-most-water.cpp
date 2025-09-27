class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n-1; // pointer to left and right most

        while(left < right){
            int distance = right - left; // lenght of the rectangle
            int Height = min(height[left], height[right]); // breadth of the rectangle

            ans = max(ans, distance*Height);
            // lenght * breadth -> this would store the max area or we can say water, so we will just max the area
            // now only change the length and breadth when we find the max l or b

            // we'll find the next greater height again calculate the area
            if(height[left] < height[right]) left++;
            else right--;

        }
        return ans;

    }
};
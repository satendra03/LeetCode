class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1) return 1; 
        int first = 1, second = 1;
        int ans = 0;
        for(int i=2; i<=n; i++) {
            ans = first + second;
            first = second;
            second = ans;
        }
        return ans;
    }
};
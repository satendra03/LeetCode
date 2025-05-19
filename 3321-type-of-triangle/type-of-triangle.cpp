class Solution {
public:
    string triangleType(vector<int>& nums) {
        int first=nums[0];
        int second=nums[1];
        int third=nums[2];
        if( (first+second <= third) || (third+second <= first) || (first+third <= second)) return "none";
        else if(first==second && second==third) return "equilateral";
        else if(first==second || second==third || first==third) return "isosceles";
        else return "scalene";
    }
};
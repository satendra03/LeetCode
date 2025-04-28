class Solution {
    public int uniqueXorTriplets(int[] nums) {
        if(nums.length == 1) {
            return nums.length;
        }

        HashSet<Integer> s1 = new HashSet<>();
        HashSet<Integer> s2 = new HashSet<>();

        for(int i=0; i<nums.length-1; i++) {
            for(int j=i+1; j<nums.length; j++){
                s1.add(nums[i]^nums[j]);
            }
        }

        for(int am:s1){
            for(int s=0; s<nums.length; s++){
                int res = nums[s]^am;
                s2.add(res);
            }
        }

        return s2.size();
    }
}
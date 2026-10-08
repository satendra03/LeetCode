class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        int prevIndex = 0;
        int count = 0;
        int n = s.length();
        for(int i=0; i<n; i++) {
            char c = s.charAt(i);
            if(count == 0) {
                prevIndex = i;
                count++;
            }
            else if(c == '(') count++;
            else {
                count--;
                if(count == 0) {
                    ans.append(s, prevIndex+1, i);
                }
            }
        }
        return ans.toString();
    }
}
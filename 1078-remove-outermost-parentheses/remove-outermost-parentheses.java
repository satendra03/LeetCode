class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder ans = new StringBuilder();
        Stack<Integer> st = new Stack<>();
        int n = s.length();
        for(int i=0; i<n; i++) {
            char c = s.charAt(i);
            if(st.isEmpty() || c == '(') st.push(i);
            else {
                int prevIndex = st.pop();
                if(st.isEmpty()) {
                    ans.append(s, prevIndex+1, i);
                }
            }
        }
        return ans.toString();
    }
}
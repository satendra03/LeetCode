class Solution {
    public String evaluate(String s, List<List<String>> knowledge) {
        Map<String, String> data = new HashMap<>();
        for(List<String> entry : knowledge){
            String key = entry.get(0);
            String value = entry.get(1);
            data.put(key, value);
        }

        int len = s.length();
        StringBuilder ans = new StringBuilder("");
        for(int i=0; i<len; i++) {
            if(s.charAt(i) == '(') {
                int closingIndex = s.indexOf(')', i+1);
                String key = s.substring(i+1, closingIndex);
                ans.append(data.getOrDefault(key, "?"));

                i = closingIndex;
            } else ans.append(s.charAt(i));
        }

        return ans.toString();
    }
}
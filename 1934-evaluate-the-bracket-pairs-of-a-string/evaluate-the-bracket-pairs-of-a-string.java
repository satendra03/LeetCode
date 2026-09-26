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
        StringBuilder key = new StringBuilder("");
        Boolean makeKey = false;
        for(int i=0; i<len; i++) {
            if(s.charAt(i) == '(') {
                makeKey = true;
                continue;
            }
            if(s.charAt(i) == ')') makeKey = false;
            if(makeKey == true) key.append(s.charAt(i));
            if(makeKey == false) {
                if(key.length() != 0) {
                    String value = data.getOrDefault(key.toString(), "?");
                    System.out.println("Key:" + key.toString() +" Value:"+value);
                    ans.append(value);
                    key.setLength(0);
                }
                else ans.append(s.charAt(i));
            }
        }

        return ans.toString();
    }
}
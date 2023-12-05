class Solution {
    public int lengthOfLongestSubstring(String s) {
        char letters[] = s.toCharArray();
        int len = 0 ,max_len = 0 , max_index = 0;
        ArrayList<Character> substring = new ArrayList<>();

        for (int i = 0; i < letters.length; i++){
            if(!substring.contains(letters[i])){
                substring.add(letters[i]);
                len++;
                if(len > max_len){
                    max_len = len;
                    max_index = i-len+1;
                }
            }
            else{
                for (int j = substring.indexOf(letters[i]); j >= 0; j--)
                    substring.remove(j);
                substring.add(letters[i]);
                len = substring.size();
                System.out.print(substring);
            }
        }        
        return max_len;
    }
}
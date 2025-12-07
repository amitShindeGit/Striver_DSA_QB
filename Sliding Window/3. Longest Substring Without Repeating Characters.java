class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        if(n ==0) return 0;

        Map<Character, Integer> mpp = new HashMap<>();

        int l=0;
        int max = 0;

        for(int r=0; r<n; r++){
            char c = s.charAt(r);

            if(mpp.containsKey(c)){
                l = Math.max(l, mpp.get(c) + 1);
            }

            max = Math.max(r - l + 1, max);
            mpp.put(c, r);
        }

        return max;
    }
}
class Solution {
    private int expandFromCentre(String s, int left, int right){
        int n = s.length();
        while(left >=0 && right < n && s.charAt(left) == s.charAt(right)){
            left--;
            right++;
        }

        return right - left - 1;

    }


    public String longestPalindrome(String s) {
        int n = s.length();

        int start = 0; int end = 0;

        for(int i=0; i<n; i++){
            int oddLen = expandFromCentre(s, i, i);
            int evenLen = expandFromCentre(s, i, i+1);

            int currLen = Math.max(oddLen, evenLen);

            if(currLen > (end - start)){
                start = i - ((currLen-1) / 2);
                end = i + (currLen / 2);
            }

        }

        return s.substring(start, end+1);
    }
}
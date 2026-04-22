class Solution {
    private int longestPalindromSubsequence(String s, int idx1, String revS, int idx2, int[][] dp){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s.charAt(idx1) == revS.charAt(idx2)){
            return dp[idx1][idx2] =  1 + longestPalindromSubsequence(s, idx1-1, revS, idx2-1, dp);
        }else{
            return dp[idx1][idx2] = Math.max(longestPalindromSubsequence(s, idx1-1, revS, idx2, dp), longestPalindromSubsequence(s, idx1, revS, idx2-1, dp));
        }
    }

    public int minInsertions(String s) {
        String revS = new StringBuilder(s).reverse().toString();
        int n = s.length();
        int[][] dp = new int[n+1][n+1];

        for(int i=0; i<=n; i++){
            Arrays.fill(dp[i], -1);
        }

        int lenLPS = longestPalindromSubsequence(s, n-1, revS, n-1, dp);

        return n - lenLPS;
    }
}
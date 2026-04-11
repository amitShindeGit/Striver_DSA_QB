class Solution {
    private int longestCommonSubsequence(String s, int idx1, String revS, int idx2, int[][] dp){
        if(idx1 < 0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(s.charAt(idx1) == revS.charAt(idx2)){
            return dp[idx1][idx2] = 1 + longestCommonSubsequence(s, idx1-1, revS, idx2-1,dp);
        }else{
            return dp[idx1][idx2] = Math.max(longestCommonSubsequence(s, idx1-1, revS, idx2,dp),
                            longestCommonSubsequence(s, idx1, revS, idx2-1,dp));
        }
    }

    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        String reverseString = new StringBuilder(s).reverse().toString();
        int[][] dp = new int[n+1][n+1];

        for(int i=0; i<n+1; i++){
            Arrays.fill(dp[i], -1);
        }

        return longestCommonSubsequence(s, n-1, reverseString, n-1, dp);
    }
}
class Solution {
    private int longestCommonSubsequence(String w1, int idx1, String w2, int idx2, int[][] dp){
        if(idx1 <0 || idx2 < 0) return 0;

        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(w1.charAt(idx1) == w2.charAt(idx2)){
            return dp[idx1][idx2] = 1 + longestCommonSubsequence(w1, idx1-1, w2, idx2-1, dp);
        }else{
            return dp[idx1][idx2] = Math.max(longestCommonSubsequence(w1, idx1-1, w2, idx2, dp),
                            longestCommonSubsequence(w1, idx1, w2, idx2-1, dp));
        }
    }

    public int minDistance(String word1, String word2) {
        int n1 = word1.length();
        int n2 = word2.length();

        int[][] dp = new int[n1+1][n2+1];

        for(int i=0; i<=n1; i++){
            Arrays.fill(dp[i], -1);
        }

        int lcs = longestCommonSubsequence(word1, n1-1,word2, n2-1, dp);

        int count = 0;
        count += (n1 - lcs);
        count += (n2 - lcs);

        return count;
    }
}
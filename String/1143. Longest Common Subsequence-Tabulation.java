class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        int[][] dp = new int[n1 + 1][n2 + 1];

        for (int index1 = 1; index1 <= n1; index1++) {
            for (int index2 = 1; index2 <= n2; index2++) {
                if (text1.charAt(index1-1) == (text2.charAt(index2-1))) {
                    dp[index1][index2] = 1 + dp[index1 - 1][index2 - 1];
                } else {
                    dp[index1][index2] = Math.max(dp[index1 - 1][index2], dp[index1][index2 - 1]);
                }
            }
        }

        return dp[n1][n2];

    }
}
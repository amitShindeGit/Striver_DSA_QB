class Solution {
    private int getLongestCommonSubseq(String text1, int index1, String text2, int index2
                ,int[][] dp){
        if(index1 < 0 || index2 < 0){
            return 0;
        }

        if(dp[index1][index2] != -1) return dp[index1][index2];

        if(text1.charAt(index1) == (text2.charAt(index2))){
            return dp[index1][index2] =  1 + getLongestCommonSubseq(text1, index1-1, text2, index2-1,dp);
        }else{
            return dp[index1][index2] = Math.max(getLongestCommonSubseq(text1, index1-1, text2, index2,dp),
                            getLongestCommonSubseq(text1, index1, text2, index2-1,dp));
        }

    }


    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length()-1;
        int n2 = text2.length()-1;
        int[][] dp = new int[n1+1][n2+1];

        for(int i=0; i<=n1; i++){
            Arrays.fill(dp[i], -1);
        }

        return getLongestCommonSubseq(text1, n1, text2, n2, dp);
    }
}
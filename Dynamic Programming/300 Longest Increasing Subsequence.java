class Solution {
    private int getLengthOfLIS(int[] nums, int index, int prev, int[][] dp){
        int n = nums.length;
        if(index == n) return 0; 

        if(dp[index][prev+1] != -1) return dp[index][prev+1];

        int notTake = 0 + getLengthOfLIS(nums, index+1, prev, dp);
        int take = 0;
        if(prev == -1 || nums[prev] < nums[index]){
            take = 1 + getLengthOfLIS(nums, index+1,index, dp);
        }

        return dp[index][prev+1] = Math.max(notTake, take);
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        // n+1 because we're shifting prev by +1 in dp array since -1 index cannot be accessed
        int[][] dp = new int[n][n+1];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        return getLengthOfLIS(nums, 0, -1, dp);
    }
}
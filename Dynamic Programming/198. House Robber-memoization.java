class Solution {
    private int getMaxSum(int[] nums, int idx, int[] dp){
        if(idx < 0) return 0;

        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + getMaxSum(nums, idx-2, dp);
        int notTake = getMaxSum(nums, idx-1, dp);

        return dp[idx] = Math.max(take, notTake);
    }

    public int rob(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];

        for(int i=0; i<n; i++){
            dp[i] = -1;
        }
        int ans = getMaxSum(nums, n-1,dp);

        return ans;

    }
}
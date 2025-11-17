class Solution {
    private int getTargetSum(int index, int[] nums, int target, int currentSum, int[][] dp, int offset){
        if(index == 0){
            int ways = 0;
            if(currentSum + nums[0] == target) ++ways;
            if(currentSum - nums[0] == target) ++ways;
            return ways;
        }

        if(dp[index][currentSum + offset] != -1) return dp[index][currentSum + offset];

        int pos =  getTargetSum(index-1, nums, target, currentSum + nums[index], dp, offset);
        int neg =  getTargetSum(index-1, nums, target, currentSum - nums[index], dp, offset);

        // THis is done so that negative vaules can be adjusted in the array
        dp[index][currentSum + offset] = pos + neg;
        return pos + neg;
    }

    public int findTargetSumWays(int[] nums, int target) {
        int n = nums.length;
        int totalSum = Arrays.stream(nums).sum();
        int dp[][] = new int[n][2 * totalSum + 1];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        return getTargetSum(n-1, nums, target,0,dp,totalSum);
    }
}
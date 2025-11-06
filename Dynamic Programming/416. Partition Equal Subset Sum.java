class Solution {
    private boolean getPartition(int i, int[] nums, int target, int[][] dp){
        if(target == 0) return true;
        if(i == 0) return (nums[i] == target);

        if(dp[i][target] != -1){
            return dp[i][target] == 1;
        }

        boolean noTake = getPartition(i-1, nums, target,dp);
        boolean take = false;
        if(nums[i] <= target){
            take = getPartition(i-1, nums, target - nums[i], dp);
        }

        dp[i][target] = (take || noTake) ? 1 : 0;

        return take || noTake;

    }

    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = Arrays.stream(nums).sum();
        if(sum % 2 != 0){
            return false;
        }

        int target = (sum) / 2;
        int[][] dp = new int[n+1][sum];

        for(int i=0; i<n;i++){
            Arrays.fill(dp[i], -1);
        }


        return getPartition(n-1,nums,target, dp);
    }
}
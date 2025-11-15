class Solution {

    private int getMinimumCoins(int index,int[] coins, int amount, int[][] dp){        
        if(index == 0){
            if((amount % coins[0]) == 0) return (amount / coins[0]);
            return (int)1e9;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int noTake = 0 + getMinimumCoins(index-1, coins, amount, dp);
        int take = (int)1e9;
        if(coins[index] <= amount){
         take = 1 + getMinimumCoins(index, coins, amount - coins[index], dp);
        }

        dp[index][amount] = Math.min(noTake, take);
        return dp[index][amount];
    }

    public int coinChange(int[] coins, int amount) {
        int n = coins.length;
        int[][] dp = new int[n][amount+1];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        int ans = getMinimumCoins(n-1,coins, amount, dp);

        if(ans >= (int)1e9){
            return -1;
        }

        return ans;
    }
}
class Solution {
    private int getMaxProfit(int[] prices, int buy, int index, int[][] dp){
        int n = prices.length;
        if(index == n ) return 0;

        if(dp[index][buy] != -1) return dp[index][buy];

        int profit = 0;
        if(buy == 1){
            profit = Math.max(-prices[index] + getMaxProfit(prices, 0, index+1, dp),
                             0 + getMaxProfit(prices, 1, index+1, dp));
        }else{
            profit = Math.max(prices[index] + getMaxProfit(prices, 1, index+1, dp),
                             0 + getMaxProfit(prices, 0, index+1, dp));
        }

        return dp[index][buy] = profit;

    }

    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        return getMaxProfit(prices, 1, 0, dp);
    }
}
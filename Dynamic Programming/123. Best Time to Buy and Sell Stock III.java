class Solution {
    private int getMaxProfit(int[] prices, int buy, int index, int[][][] dp, int cap){
        int n = prices.length;
        if(cap == 0) return 0;
        if(index == n) return 0;

        if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

        int profit = 0;
        if(buy == 1){
            // Since I haven't bought so tranasction is not complete
            profit = Math.max(-prices[index] + getMaxProfit(prices, 0, index + 1, dp, cap),
                                0 + getMaxProfit(prices, 1, index+1, dp, cap));
        }else{
            // Since I sole stock so tranasction is complete
            profit = Math.max(prices[index] + getMaxProfit(prices, 1, index + 1, dp, cap-1),
                                0 + getMaxProfit(prices, 0, index+1, dp, cap));
        }

        return dp[index][buy][cap] = profit;
    }


    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][3];

        for(int i=0; i<n; i++){
            for(int j=0; j<2; j++){
                Arrays.fill(dp[i][j], -1);
            }
        }
        return getMaxProfit(prices, 1,0,dp, 2);
    }
}
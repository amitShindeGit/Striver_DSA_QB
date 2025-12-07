class Solution {
    public int maxProfit(int[] prices) {
	//Greedy
        if(prices.length == 0) return 0;
        
        int n = prices.length;
        int minBuy = prices[0];
        int profit = 0;

        for(int i=1; i<n; i++){
            int currentProfit = prices[i] - minBuy;
            if(currentProfit > 0){
                profit += currentProfit;
            }
            minBuy = prices[i];
        }

        return profit;
    }
}
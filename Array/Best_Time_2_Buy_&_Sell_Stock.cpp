class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowPrice=0;
        int highPrice=1;
        int profit = 0;
        
        while(highPrice <= prices.size()-1){
            int currentProfit = prices[highPrice] - prices[lowPrice];
            if(currentProfit > profit){
                    profit = currentProfit;
                }
            
            if(prices[highPrice] < prices[lowPrice]){
                lowPrice = highPrice;
                highPrice++;
            }else{
                highPrice++;
            }
        }
        
        return profit;
    }
};
import java.util.* ;
import java.io.*; 

public class Solution{
    private static int getKnapscak(int index,int[] weight, int[] value, int maxWeight, int[][] dp){
        if(maxWeight < 0) return 0;
        if(index == 0){
            if(weight[index] > maxWeight) return 0;
            return value[index];
        }

        if(dp[index][maxWeight] != -1) return dp[index][maxWeight];

        int notTake = getKnapscak(index-1, weight, value, maxWeight, dp);

        int take = 0;
        if(weight[index] <= maxWeight){
            take = value[index] + getKnapscak(index - 1, weight, value, maxWeight - weight[index], dp);
        }

        dp[index][maxWeight] = Math.max(take, notTake);

        return Math.max(take, notTake);
    }


    static int knapsack(int[] weight, int[] value, int n, int maxWeight) {

            /* Your class should be named Solution
            * Don't write main().
            * Don't read input, it is passed as function argument.
            * Change in the given tree itself.
            * No need to return or print the output.
            * Taking input and printing output is handled automatically.
            */
            int[][] dp = new int[n][maxWeight + 1];

            for(int i=0; i<n; i++){
                Arrays.fill(dp[i], -1);
            }

            return getKnapscak(n-1, weight, value, maxWeight, dp);

    }
}
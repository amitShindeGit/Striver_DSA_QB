import java.util.* ;
import java.io.*; 
public class Solution {
    private static boolean getSubsetSumToK(int i, int target, int arr[], int dp[][]){
        if(target == 0) return true;
        if(i == 0 ) return (arr[0] == target);

        if(dp[i][target] != -1) return dp[i][target] == 1;

        boolean noTake = getSubsetSumToK(i-1, target, arr, dp);
        boolean take = false;
        if(arr[i] <= target){
            take = getSubsetSumToK(i-1, target - arr[i], arr, dp);
        } 

        dp[i][target] = noTake || take ? 1 : 0;
        return noTake || take;
    }

    public static boolean subsetSumToK(int n, int k, int arr[]){
        // Write your code here.
        int[][] dp = new int[n][k + 1];


        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }
        return getSubsetSumToK(n-1, k, arr,dp);
    }
}

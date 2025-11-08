import java.util.*;
import java.io.*;

public class Solution {
    static final int MOD = 1000000007;

    private static int getSubArraySum(int index,int[] nums, int target, int[][] dp){
        
        if(index == 0){
            if(target == 0 && nums[index] == 0) return 2;
            if(target == 0 || nums[index] == target) return 1;

            return 0;
        }

        if(dp[index][target] != -1) return dp[index][target];

        int notTake = getSubArraySum(index-1, nums, target, dp);
        int take = 0;
        if(nums[index] <= target){
            take = getSubArraySum(index-1, nums, target - nums[index], dp);
        }

        dp[index][target] = (int)(((long)take + notTake) % MOD);

        return dp[index][target];
    }
    
    public static int findWays(int num[], int tar) {
        // Write your code here.
        int n = num.length;
        int[][] dp = new int[n][tar+1];

        for(int i=0; i<n; i++){
            Arrays.fill(dp[i], -1);
        }

        return getSubArraySum(n-1,num,tar,dp);
    }
}
import java.util.* ;
import java.io.*; 
public class Solution {
	final static int MOD = 1000000007;
	private static int getPartitions(int index, int d, int[] arr, int target, int[][] dp){
		if(index == 0){
			if((target == 0) && arr[index] == 0) return 2;
			if(target == 0 || arr[index] == target) return 1;
			return 0;
		}

		if(dp[index][target] != -1) return dp[index][target];


		int notTake = getPartitions(index-1, d,arr, target,dp);
		int take = 0;
		if(arr[index] <= target){
			take = getPartitions(index-1, d, arr, target - arr[index], dp);
		}

		dp[index][target] = (int)(((long)take + notTake) % MOD);

		return dp[index][target];
	}


	public static int countPartitions(int n, int d, int[] arr) {
		// Write your code here.

		int totalSum = 0;
		

		for(int i=0; i<n; i++){
			totalSum += arr[i];
		}

		if((totalSum - d) < 0 || ((totalSum - d) % 2 != 0) ){
			return 0;
		}

		int target = (totalSum - d) / 2;

		int[][] dp = new int[n][target + 1];

		for(int i=0; i<n; i++){
			Arrays.fill(dp[i], -1);
		}

		return getPartitions(n-1,d,arr,target, dp);
	}
}
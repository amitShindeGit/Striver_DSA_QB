#include <bits/stdc++.h> 

int getMinimumPathSum(vector<vector<int>>& triangle, int n, vector<vector<int>>& dp
,int i, int j){
	if(i == n-1){
		return triangle[n-1][j];
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}

	int down = triangle[i][j] + getMinimumPathSum(triangle, n,dp,i+1,j);
	int diagonalDown = triangle[i][j] + getMinimumPathSum(triangle, n,dp,i+1,j+1);
	dp[i][j] = min(down, diagonalDown);
	return min(down, diagonalDown);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n, vector<int>(n,-1));

	int result = getMinimumPathSum(triangle, n,dp,0,0);

	return result;
}
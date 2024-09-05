#include <bits/stdc++.h> 

int getMinimumTrianglePathSum (vector<vector<int>>& triangle, int triangleSize
,int row , int col, vector<vector<int>>& dp ) {

	if(row ==  triangleSize - 1){
		return triangle[row][col];
	}

	if(dp[row][col] != -1){
		return dp[row][col];
	}

	int down = triangle[row][col] + getMinimumTrianglePathSum(triangle, triangleSize,
	row+1, col,dp);

	int downRight = triangle[row][col] + getMinimumTrianglePathSum(triangle, triangleSize,
	row+1, col+1,dp);

	dp[row][col] = min(down,downRight);

	return min(down,downRight);
}


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), -1));;
	int answer = getMinimumTrianglePathSum(triangle, n,0,0,dp);

	return answer;
	
}
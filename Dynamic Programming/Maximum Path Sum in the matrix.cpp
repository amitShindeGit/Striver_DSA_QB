#include <bits/stdc++.h>

int getMaxSumOfAPath(vector<vector<int>> &matrix, int cols, int i, int j,vector<vector<int>> &dp) {
  if ( j < 0 || j >= cols) {
    return -1e9;
  }

  if (i == 0 ) {
    return matrix[i][j];
  }

  if(dp[i][j] != -1){
      return dp[i][j];
  }

  int up = matrix[i][j] + getMaxSumOfAPath(matrix, cols, i - 1, j,dp);
  int upLeft = matrix[i][j] + getMaxSumOfAPath(matrix, cols, i - 1, j - 1,dp);
  int upRight = matrix[i][j] + getMaxSumOfAPath(matrix, cols, i - 1, j + 1,dp);
  dp[i][j] = max({up, upLeft, upRight});
  return max({up, upLeft, upRight});
}

int getMaxPathSum(vector<vector<int>> &matrix) {
  //  Write your code here.
  int rows = matrix.size();
  int cols = matrix[0].size();
  int maxAns = -1e9;
  vector<vector<int>> dp(rows,vector<int>(cols,-1));
  for (int j = 0; j < cols; j++) {
    maxAns = max(maxAns, getMaxSumOfAPath(matrix, cols, rows - 1, j,dp));
  }
  return maxAns;
}
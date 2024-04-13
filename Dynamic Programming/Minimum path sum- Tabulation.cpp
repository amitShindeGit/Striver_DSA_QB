#include <bits/stdc++.h>
int getMinSumPath(vector<vector<int>> &grid, vector<vector<int>> &dp) {

  int upValue = 0;
  int leftValue = 0;
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[0].size(); j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = grid[0][0];
      } else {
        if (i > 0) {
          upValue = grid[i][j] + dp[i - 1][j];
        } else {
          upValue = 1e9;
        }
        if (j > 0) {
          leftValue = grid[i][j] + dp[i][j - 1];
        } else {
          leftValue = 1e9;
        }
        dp[i][j] = min(upValue, leftValue);
      }
    }
  }
  return dp[grid.size() - 1][grid[0].size() - 1];
}

int minSumPath(vector<vector<int>> &grid) {
  // Write your code here.
  if (!grid.size()) {
    return 0;
  }
  vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));

  return getMinSumPath(grid, dp);
}
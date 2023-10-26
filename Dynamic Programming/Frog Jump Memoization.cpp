#include <bits/stdc++.h>

int getMinJumps (int index, vector<int> &heights, vector<int> &dp) {

  if (index == 0) {
      return 0;
  }

  if (dp[index] != -1) {
      return dp[index];
  }

  int firstStep = getMinJumps(index - 1, heights, dp) + abs(heights[index] - heights[index-1]);
  int secondStep = INT_MAX;
  if (index > 1) {
      secondStep =
          getMinJumps(index - 2, heights, dp) + abs(heights[index] - heights[index - 2]);
  }

  dp[index] = min(firstStep, secondStep);

  return min(firstStep, secondStep);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    // Write your code here.
    return getMinJumps(n-1, heights, dp);
}
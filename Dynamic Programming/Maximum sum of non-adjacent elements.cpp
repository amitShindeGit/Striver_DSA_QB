#include <bits/stdc++.h>

int getMaxNonAdjSum(int index, vector<int> &nums, vector<int> &dp) {
  if (index == 0) {
    return nums[index];
  }

  if (index < 0) {
    return 0;
  }

  if (dp[index] != -1) {
    return dp[index];
  }

  int pick = nums[index] + getMaxNonAdjSum(index - 2, nums, dp);
  int notPick = 0 + getMaxNonAdjSum(index - 1, nums, dp);

  dp[index] = max(pick, notPick) ;
  return dp[index];
}

int maximumNonAdjacentSum(vector<int> &nums) {
  // Write your code here.
  int n = nums.size();
  vector<int> dp(n, -1);

  return getMaxNonAdjSum(n - 1, nums, dp);
}
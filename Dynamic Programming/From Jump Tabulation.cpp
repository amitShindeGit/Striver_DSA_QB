#include <bits/stdc++.h>

int frogJump(int n, vector<int> &heights) {
  vector<int> dp(n, 0);
  // Write your code here.
  //Tabulation
  dp[0] = 0;

  for (int i = 1; i < n; i++) {
    int firstStep = dp[i - 1] + abs(heights[i] - heights[i - 1]);

    int secondStep = INT_MAX;
    if (i > 1) {
      secondStep = dp[i - 2] +
                   abs(heights[i] - heights[i - 2]);
    }

    dp[i] = min(firstStep, secondStep);
  }
  return dp[n-1];
}
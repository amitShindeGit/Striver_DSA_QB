#include <bits/stdc++.h>

long long int getMaxValueInHouse(int index, vector<int> &valueInHouse, vector<long long int> &dp) {
  if (index == 0) {
    return valueInHouse[index];
  }

  if (index < 0) {
    return 0;
  }

  if (dp[index] != -1) {
      return dp[index];
  }

  long long int pick =
      valueInHouse[index] + getMaxValueInHouse(index - 2, valueInHouse, dp);
  long long int notPick = 0 + getMaxValueInHouse(index - 1, valueInHouse,dp);

  dp[index] = max(pick, notPick);
  return dp[index];

}

long long int houseRobber(vector<int> &valueInHouse) {
  // Write your code here.
  vector<int> newVec, newSecondVec;
    
  for (int i=0; i< valueInHouse.size(); i++) {
      if(i != 0) newVec.push_back(valueInHouse[i]);

      if(i != valueInHouse.size()-1) newSecondVec.push_back(valueInHouse[i]);
  }

  int n = newVec.size();
  int m = newSecondVec.size();

  vector<long long int> dp1(n,-1);
  vector<long long int> dp2(m, -1);

  if (valueInHouse.size() == 1) {
      return valueInHouse[0];
  }

  long long int ans1 = getMaxValueInHouse(n-1, newVec, dp1);
  long long int ans2 = getMaxValueInHouse(m-1, newSecondVec, dp2);


  return max(ans1, ans2);
}
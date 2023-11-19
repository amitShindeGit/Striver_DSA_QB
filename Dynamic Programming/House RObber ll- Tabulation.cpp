#include <bits/stdc++.h>

long long int getMaxValueInHouse(vector<int> &valueInHouse) {
  int n = valueInHouse.size();
  long long int prev = valueInHouse[0];
  long long int prev1 = 0;

  for (int i=1; i<n; i++) {
      long long int pick = valueInHouse[i];
      if (i>1) {
          pick += prev1;
      }

      long long int notPick = 0 + prev;

      long long int curri = max(pick, notPick);
      prev1 = prev;
      prev = curri;
  }

  return prev;
}

long long int houseRobber(vector<int> &valueInHouse) {
  // Write your code here.
  vector<int> newVec, newSecondVec;
    
  for (int i=0; i< valueInHouse.size(); i++) {
      if(i != 0) newVec.push_back(valueInHouse[i]);

      if(i != valueInHouse.size()-1) newSecondVec.push_back(valueInHouse[i]);
  }

  if (valueInHouse.size() == 1) {
      return valueInHouse[0];
  }

  return max(getMaxValueInHouse(newVec), getMaxValueInHouse(newSecondVec));
}
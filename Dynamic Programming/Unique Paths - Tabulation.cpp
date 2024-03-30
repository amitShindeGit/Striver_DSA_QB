#include <bits/stdc++.h>

int getUniquePaths(int m, int n, vector<vector<int>> &vec) {

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 && j == 0) {
        vec[i][j] = 1;
        continue;
      }

      int up = 0;
      int left = 0;

      if (i > 0) {
        up = vec[i - 1][j];
      }

      if (j > 0) {
        left = vec[i][j - 1];
      }

      vec[i][j] = up + left;
    }
  }

  return vec[m-1][n-1];
}

int uniquePaths(int m, int n) {
  // Write your code here.
  vector<vector<int>> vec(m, vector<int>(n, -1));

  // Indexed at 0 now
  int ans = getUniquePaths(m , n , vec);

  return ans;
}
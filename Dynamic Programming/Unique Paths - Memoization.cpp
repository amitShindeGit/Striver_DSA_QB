#include <bits/stdc++.h>

int getUniquePaths(int m, int n, vector<vector<int>> &vec ) {
	
	if(m == 0 && n ==0){
		return 1;
	}

	if(m < 0 || n < 0){
		return 0;
	}

	if(vec[m][n] != -1){
		return vec[m][n];
	}
	

	int up = getUniquePaths(m-1, n,vec);
	int left = getUniquePaths(m, n-1, vec);

	vec[m][n] = up + left;

	return up + left;
}

int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> vec (m, vector<int>(n,-1));

	//Indexed at 0 now
	int ans = getUniquePaths(m-1,n-1,vec);

	return ans;
}
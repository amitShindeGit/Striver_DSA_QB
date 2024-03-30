#include <bits/stdc++.h> 

int uniquePaths(int m, int n) {
	// Write your code here.
	//Indexed at 1, so base case is 1
	if(m == 1 && n ==1){
		return 1;
	}

	if(m < 1 || n < 1){
		return 0;
	}

	int up = uniquePaths(m-1, n);
	int left = uniquePaths(m, n-1);

	return up + left;
}
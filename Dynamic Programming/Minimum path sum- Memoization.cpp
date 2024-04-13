#include <bits/stdc++.h> 
int getMinSumPath(vector<vector<int>> &grid,vector<vector<int>> &dp, int up, int left ){
    if(up == 0 && left == 0){
        return grid[up][left];
    }

    if(up < 0 || left  < 0){
        return 1e9;
    }

    if(dp[up][left] != -1){
        return dp[up][left];
    }

    int upValue = grid[up][left] + getMinSumPath(grid, dp,up-1, left);
    int leftValue = grid[up][left] + getMinSumPath(grid, dp,up, left-1);
       
    dp[up][left] = min(upValue, leftValue);
    return min(upValue, leftValue) ;


}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    if(!grid.size()){
        return 0;
    }
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    int up = grid.size() - 1;
    int left = grid[0].size() - 1 ;

    return getMinSumPath(grid, dp, up, left);

}
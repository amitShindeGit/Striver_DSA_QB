class Solution {

    private int minSum(int i, int j, int[][] grid, int [][] dp){
        int n = grid.length;
        int m = grid[0].length;

        if(i == n-1 && j == m-1){
            return grid[i][j];
        }

        if(i >= n || j >= m){
            return (int)1e9;
        }

        if(dp[i][j] != 0){
            return dp[i][j];
        }

        int down = grid[i][j] + minSum(i+1,j,grid,dp);
        int right = grid[i][j] + minSum(i, j+1,grid,dp);

        dp[i][j] = Math.min(down, right);
        return dp[i][j];
    }

    public int minPathSum(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[][] dp = new int[n][m];

        return minSum(0, 0, grid, dp);
    }
}
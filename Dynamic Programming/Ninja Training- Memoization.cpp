int getNinjaTraining (int day, int last, vector<vector<int>> &points,vector<vector<int>> &dp) {
    if(dp[day][last] != -1){
        return dp[day][last];
    }
    
    if(day == 0){
        int maxi = 0;
        for(int i=0; i<3;i++){
          if (last != i) {
            maxi = max(points[0][i], maxi);
          }
        }

        return maxi;
    }

    int maxi = 0;
    for(int i=0;i<3;i++){
        if(i != last){
            int point = points[day][i] + getNinjaTraining(day-1, i, points, dp);
            maxi = max(point, maxi);
        }
    }

    return dp[day][last] = maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return getNinjaTraining(n-1,3 ,points, dp);
}
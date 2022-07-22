class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        for(int i=0; i<numRows; i++){
            ans[i].resize(i+1);     //size for eah row
            ans[i][0] = ans[i][i] = 1;
            
            for(int j=1; j<i; j++){ //start from second variable since 1st is 1 anyways
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        
        return ans;
    }
};
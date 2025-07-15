// User function Template for C++

class Solution {
  private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
    vector<pair<int, int>> &vec, int baseRow, int baseCol){
        vec.push_back({row - baseRow, col - baseCol});
        vis[row][col] = 1;
        
        int n = grid.size();
        int m = grid[0].size();
        
        int delRow[] = {-1, 0 ,1, 0};
        int delCol[] = {0, -1, 0, 1};
        
        for(int i=0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow >= 0 && nRow < n && nCol >= 0 &&  nCol < m  
            && !vis[nRow][nCol] && grid[nRow][nCol] == 1){
                dfs(nRow, nCol, grid, vis, vec, baseRow, baseCol);
            }
        }
    }
    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        if(n == 0 && m == 0){
            return 0;
        }
        
        vector<vector<int>> vis(n, vector<int> (m,0));
        set<vector<pair<int, int>>> st;
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
        
        
    }
};

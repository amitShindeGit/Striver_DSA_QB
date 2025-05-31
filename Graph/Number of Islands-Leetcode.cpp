class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int deltaRow = -1; deltaRow <= 1; deltaRow++){
                for(int deltaCol = -1; deltaCol <= 1; deltaCol++){
                    int neighborRow = row + deltaRow;
                    int neighborCol = col + deltaCol;

                    if(neighborRow >= 0 && neighborRow < n && neighborCol >= 0 && neighborCol < m 
                        && grid[neighborRow][neighborCol] == '1' && !vis[neighborRow][neighborCol] 
                        && (deltaRow == 0 || deltaCol == 0)){ // No Diagonal check
                            vis[neighborRow][neighborCol] = 1;
                            q.push({neighborRow,neighborCol});
                    }
                }
            }
        }
    }   

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    bfs(i, j,grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};
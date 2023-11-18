class Solution {
private:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>> &vis){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            int currentRow = q.front().first;
            int currentCol = q.front().second;
            q.pop();

            for(int delRow = -1; delRow<=1; delRow++){
                    int neigborRow = currentRow + delRow;
                    
                    if(neigborRow >= 0 && neigborRow < n && currentCol >=0 && currentCol < m
                        && grid[neigborRow][currentCol] == '1' && !vis[neigborRow][currentCol]
                    ){
                        vis[neigborRow][currentCol] = 1;
                        q.push({neigborRow,currentCol});
                    }
                
            }

            for(int delCol = -1; delCol<=1; delCol++){
                    int neigborCol = currentCol + delCol;
                    
                    if(currentRow >= 0 && currentRow < n && neigborCol >=0 && neigborCol < m
                        && grid[currentRow][neigborCol] == '1' && !vis[currentRow][neigborCol]
                    ){
                        vis[currentRow][neigborCol] = 1;
                        q.push({currentRow,neigborCol});
                    }
                
            }
        }
    }   


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));

        int count = 0;

        for(int row=0; row<n;   row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, grid, vis);
                }
            }
        }

        return count;
    }
};
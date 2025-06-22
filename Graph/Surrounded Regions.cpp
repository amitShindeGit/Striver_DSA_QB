class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& board,
    int delRow[], int delCol[]){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >=0 && nCol >=0 && nRow < n && nCol < m && !vis[nRow][nCol] 
            && board[nRow][nCol] == 'O'){
                dfs(nRow, nCol, vis, board, delRow, delCol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        //Find out who is at the border and travel all connected O's
        int n = board.size();
        int m = board[0].size();
        if (n <= 1 || m <= 1) return;
        
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m,0));

        // First and last row
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 'O') {
                dfs(0, j, vis, board, delRow, delCol);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board, delRow, delCol);
            }
        }

        // First and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board, delRow, delCol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board, delRow, delCol);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
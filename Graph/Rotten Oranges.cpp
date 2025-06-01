class Solution {
private:
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis,
            queue<pair<int, int>>& q) {
        int n = grid.size();
        int m = grid[0].size();
        int minutes = 0;
        int dR[4] = {-1, 0, 1, 0};
        int dC[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int levelSize = q.size();

            for (int k = 0; k < levelSize; k++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for (int dir = 0; dir < 4; ++dir) {
                    int neighborRow = row + dR[dir];
                    int neighborCol = col + dC[dir];

                    if (neighborRow >= 0 && neighborRow < n &&
                        neighborCol >= 0 && neighborCol < m &&
                        grid[neighborRow][neighborCol] == 1 &&
                        !vis[neighborRow][neighborCol]) {
                        vis[neighborRow][neighborCol] = 1;
                        q.push({neighborRow, neighborCol});
                    }
                }
            }

            if (!q.empty()) {
                minutes++;
            }
        }

        return minutes;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        int fresh = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    vis[i][j] = 1;
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0 && q.empty())
            return 0;

        int minutes = bfs(grid, vis, q);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }

        return minutes;
    }
};
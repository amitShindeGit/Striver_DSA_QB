class Solution {
private:
    void bfs(int row, int col,vector<vector<int>>& image,vector<vector<int>>& vis,int color, 
    int originalColor){
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row,col});
        int n = image.size();
        int m = image[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            image[row][col] = color;
            q.pop();
            
            for(int deltaRow = -1; deltaRow <=1; deltaRow++){
                for(int deltaCol = -1; deltaCol <=1; deltaCol++){
                    int neighborRow = row + deltaRow;
                    int neighborCol = col + deltaCol;

                    if(neighborRow >= 0 && neighborRow < n && neighborCol >= 0 && neighborCol < m 
                    &&  image[neighborRow][neighborCol] == originalColor && !vis[neighborRow][neighborCol]
                    && (deltaRow == 0 || deltaCol == 0)){
                        q.push({neighborRow,neighborCol});
                        vis[neighborRow][neighborCol] = 1;
                    }
                }
            }
        }
    }    

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int originalColor = image[sr][sc];
        bfs(sr,sc,image,vis,color,originalColor);

        return image;
    }
};
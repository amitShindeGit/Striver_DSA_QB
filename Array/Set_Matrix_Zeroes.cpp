class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col = 1;
        int row = matrix.size();
        int column = matrix[0].size();
        
        for(int i=0 ;i < row ; i++){
            if(matrix[i][0] == 0){  //if first column has any zero value
                col = 0;
            }
            
            for(int j=1; j < column; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        
        for(int i = row-1; i >= 0; i--){
            for(int j = column-1 ; j > 0 ; j--){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
            
            if(col == 0){ //for first column check
                matrix[i][0] = 0;
            }
        }
    }
};
class Solution {
public:
    void getTranspose(vector<vector<int>>& matrix){
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<=i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
            getTranspose(matrix);
            int i=0;
            int j=matrix.size()-1;
            int currRow = 0;
        
            while(currRow < matrix.size() ){
                if(i >= j){	//handles both odd and even number of columns
                    currRow+=1;
                    i = 0;
                    j = matrix.size()-1;
                    continue;
                }
                swap(matrix[currRow][i], matrix[currRow][j]);
                i++;
                j--;
                
            }
    }
};
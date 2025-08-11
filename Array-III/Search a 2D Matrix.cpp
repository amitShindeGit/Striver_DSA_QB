class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int n = matrix.length;
        int m = matrix[0].length;
        int low = 0;
        int high = (m * n) - 1;
        int mid = 0;
        int row = 0;
        int col = 0;

        while(low <= high){
            mid = (low + high ) / 2;
            row = mid / m; //treat 2d array like 1d array here
            col = mid % m;

            int currEle = matrix[row][col];
            if(currEle == target){
                return true;
            }else if(currEle < target){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }

        return false;
    }
}
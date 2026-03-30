class Solution {
    private boolean canAccomodatePages(int[] arr, int barrier, int k){
        int allocatedStudents = 1;
        int pages = 0;
        int n = arr.length;
        
        for(int i=0; i<n; i++){
            if(arr[i] > barrier) return false;
            
            if(arr[i] + pages <= barrier){
                pages += arr[i];
            }else{
                allocatedStudents += 1;
                pages = arr[i];
            }
        }
        
        if(allocatedStudents > k){
            return false;
        }
        
        return true;
    }
    
    public int findPages(int[] arr, int k) {
        // code here
        int n = arr.length;
        if(n < k) return -1;
        
        int low = arr[0];
        int high = Arrays.stream(arr).sum();
        int res = -1;
        
        
        while(low <= high){
            
            int mid = low + (high - low) / 2;
            if(canAccomodatePages(arr, mid, k)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        
        }
        

        
        return res;
    }
}